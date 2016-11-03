/******************************************************************************

 @file iot-gateway.js

 @brief IoT gateway

 Group: WCS LPC
 $Target Devices: Linux: AM335x, Embedded Devices: CC1310, CC1350$

 ******************************************************************************
 $License: BSD3 2016 $
  
   Copyright (c) 2015, Texas Instruments Incorporated
   All rights reserved.
  
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
   *  Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
  
   *  Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
  
   *  Neither the name of Texas Instruments Incorporated nor the names of
      its contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************
 $Release Name: TI-15.4Stack Linux x64 SDK$
 $Release Date: July 14, 2016 (2.00.00.30)$
 *****************************************************************************/
var AppClient = require("./appClient/appclient.js");
var CloudAdapter = require("./cloudAdapter/awsCloudAdapter.js");

/*!
 * @brief      Constructor for IoT gateway
 *
 * @param      none
 *
 * @return      none
 */
function Gateway() {
	var appClient = new AppClient();
	var cloudAdapter = new CloudAdapter();
	
	/* Used for network startup, wait until we receive a network
	 * info update and a device array before sending the first
	 * Network Information Message Type to the Cloud
	 */	
	var gotNwkUpdate = false;
	var gotDevArray = false;

	/* This functions checks every second to see if we've got the
	 * network and device information we need and also checks if we are
	 * connected to the cloud yet. Once all of that is true, we send
	 * the first Network Information Message Type to the Cloud and
	 * then clear the interval so the function won't repeat. 
	 */
	var intervalID = setInterval( function() {
		if (cloudAdapter.connected && gotNwkUpdate && gotDevArray){
			var nwkInfo = formatNwkInfoMsg(appClient.nwkInfo, appClient.connectedDeviceList);
			cloudAdapter.cloudAdapter_sendNetworkInfoMsg(nwkInfo);
			console.log('Visit the following url in your web browser to view the dashboard:');
			console.log('iotdash.stackbuilder.us/#/dashboard/home?net=' + nwkInfo.ext_addr);
			clearInterval(intervalID);
		}
	}, 1000);

	/* Allows the Cloud to open or close the wireless network for new devices joins */	
	cloudAdapter.on('updateNetworkState', function (data) {
		appClient.appC_setPermitJoin(data);
	});

	/* Allows the Cloud to sent toggleLED messages to devices in the wireless network */
	cloudAdapter.on('deviceActuation', function (data) {
		appClient.appC_sendToggle(data);
	});

	/* A nwkUpdate (with the updated state) is also sent when the state changes so we don't
	 * need to take any action here 
	 */
	appClient.on('permitJoinCnf', function (data) {
		console.log('gateway_permitJoinCnf');
	});

	/* Send Device Information Message to Cloud Adapter */
	appClient.on('connDevInfoUpdate', function (data) {
		var devInfo = formatDevInfoMsg(data);
		cloudAdapter.cloudAdapter_sendDeviceInfoMsg(devInfo, '0x' + appClient.nwkInfo.panCoord.extAddress.toString(16));
	});

	/* Send Network Information Message to Cloud Adapter */
	appClient.on('nwkUpdate', function () {
		gotNwkUpdate = true;
		var nwkInfo = formatNwkInfoMsg(appClient.nwkInfo, appClient.connectedDeviceList);
		cloudAdapter.cloudAdapter_sendNetworkInfoMsg(nwkInfo);
	});
	
	/* Send Network Information Message to Cloud Adapter */
	appClient.on('getdevArrayRsp', function () {
		gotDevArray = true;
		var nwkInfo = formatNwkInfoMsg(appClient.nwkInfo, appClient.connectedDeviceList);
		cloudAdapter.cloudAdapter_sendNetworkInfoMsg(nwkInfo);
	});

	/* The Network Information Message Type should be common across Cloud vendors. This function
	 * formats the message in a generic way. The CloudAdapter can make vendor specific 
	 * modifications before sending to the Cloud if necessary.
	 */
	function formatNwkInfoMsg(nwkInfo, conDevs) {
		var devices = [];
		var nwkAddress = '0x' + nwkInfo.panCoord.extAddress.toString(16);
		for(i = 0; i < conDevs.length; i++) {
			var short_addr = '0x' + conDevs[i].shortAddress.toString(16);
			var ext_addr = '0x' + conDevs[i].extAddress.toString(16);
			devices.push( {
				"name" : short_addr,
				"short_addr" : short_addr,
				"ext_addr" : ext_addr,
				"topic" : 'ti_iot_' + nwkAddress + '_' + ext_addr,
				"object_list" : conDevs[i].so.objectList()
			});
		}

		return {
			"name" : '0x' + nwkInfo.panCoord.shortAddress.toString(16),
			"channels" : nwkInfo.channel,
			"pan_id" : '0x' + nwkInfo.panCoord.panId.toString(16),
			"short_addr" : '0x' + nwkInfo.panCoord.shortAddress.toString(16),
			"ext_addr" : nwkAddress,
			"security_enabled" : nwkInfo.securityEnabled,
			"mode" : nwkInfo.networkMode,
			"state" : nwkInfo.state,
			"devices" : devices 	
		}
	}	
	
	/* The Device Information Message Type should be common across Cloud vendors. This function
	 * formats the message in a generic way. The CloudAdapter can make vendor specific 
	 * modifications before sending to the Cloud if necessary.
	 */
	function formatDevInfoMsg(dev) {
		return {
			"active" : dev.active,
			"ext_addr" : '0x' + dev.extAddress.toString(16),
			"rssi" : dev.rssi,
			"smart_objects" : dev.so.dump(function (err, data) {
						if (!err)
							return data;
					})
		}
	}
}

/* create gateway */
var gateway = new Gateway();

