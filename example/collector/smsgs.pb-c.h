/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: smsgs.proto */

#ifndef PROTOBUF_C_smsgs_2eproto__INCLUDED
#define PROTOBUF_C_smsgs_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _SmsgsConfigReqMsg SmsgsConfigReqMsg;
typedef struct _SmsgsConfigRspMsg SmsgsConfigRspMsg;
typedef struct _SmsgsTrackingReqMsg SmsgsTrackingReqMsg;
typedef struct _SmsgsTrackingRspMsg SmsgsTrackingRspMsg;
typedef struct _SmsgsToggleLedReqMsg SmsgsToggleLedReqMsg;
typedef struct _SmsgsToggleLedRspMsg SmsgsToggleLedRspMsg;
typedef struct _SmsgsTempSensorField SmsgsTempSensorField;
typedef struct _SmsgsLightSensorField SmsgsLightSensorField;
typedef struct _SmsgsPressureSensorField SmsgsPressureSensorField;
typedef struct _SmsgsHumiditySensorField SmsgsHumiditySensorField;
typedef struct _SmsgsMsgStatsField SmsgsMsgStatsField;
typedef struct _SmsgsConfigSettingsField SmsgsConfigSettingsField;
typedef struct _SmsgsSensorMsg SmsgsSensorMsg;


/* --- enums --- */

/*
 *!
 *Message IDs for Sensor data messages.  When sent over-the-air in a message,
 *this field is one byte.
 */
typedef enum _SmsgsCmdIds {
  /*
   *! Configuration message, sent from the collector to the sensor 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_configReq = 1,
  /*
   *! Configuration Response message, sent from the sensor to the collector 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_configRsp = 2,
  /*
   *! Tracking request message, sent from the the collector to the sensor 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_trackingReq = 3,
  /*
   *! Tracking response message, sent from the sensor to the collector 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_trackingRsp = 4,
  /*
   *! Sensor data message, sent from the sensor to the collector 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_sensorData = 5,
  /*
   * Toggle LED message, sent from the collector to the sensor 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_toggleLedReq = 6,
  /*
   * Toggle LED response msg, sent from the sensor to the collector 
   */
  SMSGS_CMD_IDS__Smsgs_cmdIds_toggleLedRsp = 7
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(SMSGS_CMD_IDS)
} SmsgsCmdIds;
/*
 *!
 *Frame Control field states what data fields are included in reported
 *sensor data, each value is a bit mask value so that they can be combined
 *(OR'd together) in a control field.
 *When sent over-the-air in a message this field is 2 bytes.
 */
typedef enum _SmsgsDataFields {
  /*
   *! Temperature Sensor 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_tempSensor = 1,
  /*
   *! Light Sensor 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_lightSensor = 2,
  /*
   *! Humidity Sensor 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_humiditySensor = 4,
  /*
   *! Message Statistics 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_msgStats = 8,
  /*
   *! Config Settings 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_configSettings = 16,
  /*
   *! Pressure sensor
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_pressureSensor = 32,
  /*
   *! Suyash changed this to 0x300 from 0x200 Toggle Settings 
   */
  SMSGS_DATA_FIELDS__Smsgs_dataFields_toggleSettings = 48
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(SMSGS_DATA_FIELDS)
} SmsgsDataFields;
/*
 *!
 *Status values for the over-the-air messages
 */
typedef enum _SmsgsStatusValues {
  /*
   *! Success 
   */
  SMSGS_STATUS_VALUES__Smsgs_statusValues_success = 0,
  /*
   *! Message was invalid and ignored 
   */
  SMSGS_STATUS_VALUES__Smsgs_statusValues_invalid = 1,
  /*
   *!
   *Config message was received but only some frame control fields
   *can be sent or the reportingInterval or pollingInterval fail
   *range checks.
   */
  SMSGS_STATUS_VALUES__Smsgs_statusValues_partialSuccess = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(SMSGS_STATUS_VALUES)
} SmsgsStatusValues;

/* --- messages --- */

/*
 *!
 *Configuration Request message: sent from controller to the sensor.
 */
struct  _SmsgsConfigReqMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID - 1 byte 
   */
  SmsgsCmdIds cmdid;
  /*
   *! Frame Control field - bit mask of Smsgs_dataFields 
   */
  uint32_t framecontrol;
  /*
   *! Reporting Interval 
   */
  uint32_t reportinginterval;
  /*
   *! Polling Interval 
   */
  uint32_t pollinginterval;
};
#define SMSGS_CONFIG_REQ_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_config_req_msg__descriptor) \
    , 0, 0, 0, 0 }


/*
 *!
 *Configuration Response message: sent from the sensor to the collector
 *in response to the Configuration Request message.
 */
struct  _SmsgsConfigRspMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID - 1 byte 
   */
  SmsgsCmdIds cmdid;
  /*
   *! Response Status - 1 byte 
   */
  SmsgsStatusValues status;
  /*
   *! Frame Control field - bit mask of Smsgs_dataFields 
   */
  uint32_t framecontrol;
  /*
   *! Reporting Interval 
   */
  uint32_t treportinginterval;
  /*
   *! Polling Interval 
   */
  uint32_t pollinginterval;
};
#define SMSGS_CONFIG_RSP_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_config_rsp_msg__descriptor) \
    , 0, 0, 0, 0, 0 }


/*
 *!
 *Tracking Request message: sent from controller to the sensor.
 */
struct  _SmsgsTrackingReqMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID 
   */
  SmsgsCmdIds cmdid;
};
#define SMSGS_TRACKING_REQ_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_tracking_req_msg__descriptor) \
    , 0 }


/*
 *!
 *Tracking Response message: sent from the sensor to the collector
 *in response to the Tracking Request message.
 */
struct  _SmsgsTrackingRspMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID 
   */
  SmsgsCmdIds cmdid;
};
#define SMSGS_TRACKING_RSP_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_tracking_rsp_msg__descriptor) \
    , 0 }


/*
 *!
 *Toggle Request message: sent from controller to the sensor.
 */
struct  _SmsgsToggleLedReqMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID - 1 byte 
   */
  SmsgsCmdIds cmdid;
};
#define SMSGS_TOGGLE_LED_REQ_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_toggle_led_req_msg__descriptor) \
    , 0 }


/*
 *!
 *Toggle Response message: sent from sensor to the controller.
 */
struct  _SmsgsToggleLedRspMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID - 1 byte 
   */
  SmsgsCmdIds cmdid;
  /*
   *! Response Status - 2 bytes 
   */
  uint32_t ledstate;
};
#define SMSGS_TOGGLE_LED_RSP_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_toggle_led_rsp_msg__descriptor) \
    , 0, 0 }


/*
 *!
 *Temp Sensor Field
 */
struct  _SmsgsTempSensorField
{
  ProtobufCMessage base;
  /*
   *!
   *Ambience Chip Temperature - each value represents a 0.01 C
   *degree, so a value of 2475 represents 24.75 C.
   */
  uint32_t ambiencetemp;
  /*
   *!
   *Object Temperature - each value represents a 0.01 C
   *degree, so a value of 2475 represents 24.75 C.
   */
  uint32_t objecttemp;
};
#define SMSGS_TEMP_SENSOR_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_temp_sensor_field__descriptor) \
    , 0, 0 }


/*
 *!
 *Light Sensor Field
 */
struct  _SmsgsLightSensorField
{
  ProtobufCMessage base;
  /*
   *! Raw Sensor Data read out of the OPT2001 light sensor 
   */
  uint32_t rawdata;
};
#define SMSGS_LIGHT_SENSOR_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_light_sensor_field__descriptor) \
    , 0 }


/*
 *!
 *Pressure Sensor Field
 */
struct  _SmsgsPressureSensorField
{
  ProtobufCMessage base;
  /*
   *! Temperature value read out of the BMP280 pressure sensor 
   */
  uint32_t tempvalue;
  /*
   *! Pressure value read out of the BMP280 pressure sensor 
   */
  uint32_t pressurevalue;
};
#define SMSGS_PRESSURE_SENSOR_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_pressure_sensor_field__descriptor) \
    , 0, 0 }


/*
 *!
 *Humidity Sensor Field
 */
struct  _SmsgsHumiditySensorField
{
  ProtobufCMessage base;
  /*
   *! Raw Temp Sensor Data from the TI HCD1000 humidity sensor. 
   */
  uint32_t temp;
  /*
   *! Raw Humidity Sensor Data from the TI HCD1000 humidity sensor. 
   */
  uint32_t humidity;
};
#define SMSGS_HUMIDITY_SENSOR_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_humidity_sensor_field__descriptor) \
    , 0, 0 }


/*
 *!
 *Message Statistics Field
 */
struct  _SmsgsMsgStatsField
{
  ProtobufCMessage base;
  /*
   *! total number of join attempts (associate request sent) 
   */
  uint32_t joinattempts;
  /*
   *! total number of join attempts failed 
   */
  uint32_t joinfails;
  /*
   *! total number of sensor data messages attempted. 
   */
  uint32_t msgsattempted;
  /*
   *! total number of sensor data messages sent. 
   */
  uint32_t msgssent;
  /*
   *! total number of tracking requests received 
   */
  uint32_t trackingrequests;
  /*
   *! total number of tracking response attempted 
   */
  uint32_t trackingresponseattempts;
  /*
   *! total number of tracking response success 
   */
  uint32_t trackingresponsesent;
  /*
   *!
   *Total number of Channel Access Failures.  These are indicated in MAC data
   *confirms for MAC data requests.
   */
  uint32_t channelaccessfailures;
  /*
   *!
   *Total number of MAC ACK failures. These are indicated in MAC data
   *confirms for MAC data requests.
   */
  uint32_t macackfailures;
  /*
   *!
   *Total number of MAC data request failures, other than channel access
   *failure or MAC ACK failures.
   */
  uint32_t otherdatarequestfailures;
  /*
   *! Total number of sync loss failures received for sleepy devices. 
   */
  uint32_t synclossindications;
};
#define SMSGS_MSG_STATS_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_msg_stats_field__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }


/*
 *!
 *Message Statistics Field
 */
struct  _SmsgsConfigSettingsField
{
  ProtobufCMessage base;
  /*
   *!
   *Reporting Interval - in millseconds, how often to report, 0
   *means reporting is off
   */
  uint32_t reportinginterval;
  /*
   *!
   *Polling Interval - in millseconds (32 bits) - If the sensor device is
   *a sleep device, this states how often the device polls its parent for
   *data. This field is 0 if the device doesn't sleep.
   */
  uint32_t pollinginterval;
};
#define SMSGS_CONFIG_SETTINGS_FIELD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_config_settings_field__descriptor) \
    , 0, 0 }


/*
 *!
 *Sensor Data message: sent from the sensor to the collector
 */
struct  _SmsgsSensorMsg
{
  ProtobufCMessage base;
  /*
   *! Command ID 
   */
  SmsgsCmdIds cmdid;
  /*
   *! Dummy value so we have a fixed item 
   */
  /*
   *uint16_t
   */
  uint32_t framecontrol;
  /*
   *!
   *Temp Sensor field 
   */
  SmsgsTempSensorField *tempsensor;
  /*
   *!
   *Light Sensor field
   *is set in frameControl.
   */
  SmsgsLightSensorField *lightsensor;
  /*
   *!
   *Humidity Sensor field
   */
  SmsgsHumiditySensorField *humiditysensor;
  /*
   *!
   *Message Statistics field
   */
  SmsgsMsgStatsField *msgstats;
  /*
   *!
   *Configuration Settings field
   */
  SmsgsConfigSettingsField *configsettings;
  /*
   *! 
   *Pressure Sensor Field 
   */
  SmsgsPressureSensorField *pressuresensor;
};
#define SMSGS_SENSOR_MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&smsgs_sensor_msg__descriptor) \
    , 0, 0, NULL, NULL, NULL, NULL, NULL, NULL }


/* SmsgsConfigReqMsg methods */
void   smsgs_config_req_msg__init
                     (SmsgsConfigReqMsg         *message);
size_t smsgs_config_req_msg__get_packed_size
                     (const SmsgsConfigReqMsg   *message);
size_t smsgs_config_req_msg__pack
                     (const SmsgsConfigReqMsg   *message,
                      uint8_t             *out);
size_t smsgs_config_req_msg__pack_to_buffer
                     (const SmsgsConfigReqMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsConfigReqMsg *
       smsgs_config_req_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_config_req_msg__free_unpacked
                     (SmsgsConfigReqMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsConfigRspMsg methods */
void   smsgs_config_rsp_msg__init
                     (SmsgsConfigRspMsg         *message);
size_t smsgs_config_rsp_msg__get_packed_size
                     (const SmsgsConfigRspMsg   *message);
size_t smsgs_config_rsp_msg__pack
                     (const SmsgsConfigRspMsg   *message,
                      uint8_t             *out);
size_t smsgs_config_rsp_msg__pack_to_buffer
                     (const SmsgsConfigRspMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsConfigRspMsg *
       smsgs_config_rsp_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_config_rsp_msg__free_unpacked
                     (SmsgsConfigRspMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsTrackingReqMsg methods */
void   smsgs_tracking_req_msg__init
                     (SmsgsTrackingReqMsg         *message);
size_t smsgs_tracking_req_msg__get_packed_size
                     (const SmsgsTrackingReqMsg   *message);
size_t smsgs_tracking_req_msg__pack
                     (const SmsgsTrackingReqMsg   *message,
                      uint8_t             *out);
size_t smsgs_tracking_req_msg__pack_to_buffer
                     (const SmsgsTrackingReqMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsTrackingReqMsg *
       smsgs_tracking_req_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_tracking_req_msg__free_unpacked
                     (SmsgsTrackingReqMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsTrackingRspMsg methods */
void   smsgs_tracking_rsp_msg__init
                     (SmsgsTrackingRspMsg         *message);
size_t smsgs_tracking_rsp_msg__get_packed_size
                     (const SmsgsTrackingRspMsg   *message);
size_t smsgs_tracking_rsp_msg__pack
                     (const SmsgsTrackingRspMsg   *message,
                      uint8_t             *out);
size_t smsgs_tracking_rsp_msg__pack_to_buffer
                     (const SmsgsTrackingRspMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsTrackingRspMsg *
       smsgs_tracking_rsp_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_tracking_rsp_msg__free_unpacked
                     (SmsgsTrackingRspMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsToggleLedReqMsg methods */
void   smsgs_toggle_led_req_msg__init
                     (SmsgsToggleLedReqMsg         *message);
size_t smsgs_toggle_led_req_msg__get_packed_size
                     (const SmsgsToggleLedReqMsg   *message);
size_t smsgs_toggle_led_req_msg__pack
                     (const SmsgsToggleLedReqMsg   *message,
                      uint8_t             *out);
size_t smsgs_toggle_led_req_msg__pack_to_buffer
                     (const SmsgsToggleLedReqMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsToggleLedReqMsg *
       smsgs_toggle_led_req_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_toggle_led_req_msg__free_unpacked
                     (SmsgsToggleLedReqMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsToggleLedRspMsg methods */
void   smsgs_toggle_led_rsp_msg__init
                     (SmsgsToggleLedRspMsg         *message);
size_t smsgs_toggle_led_rsp_msg__get_packed_size
                     (const SmsgsToggleLedRspMsg   *message);
size_t smsgs_toggle_led_rsp_msg__pack
                     (const SmsgsToggleLedRspMsg   *message,
                      uint8_t             *out);
size_t smsgs_toggle_led_rsp_msg__pack_to_buffer
                     (const SmsgsToggleLedRspMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsToggleLedRspMsg *
       smsgs_toggle_led_rsp_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_toggle_led_rsp_msg__free_unpacked
                     (SmsgsToggleLedRspMsg *message,
                      ProtobufCAllocator *allocator);
/* SmsgsTempSensorField methods */
void   smsgs_temp_sensor_field__init
                     (SmsgsTempSensorField         *message);
size_t smsgs_temp_sensor_field__get_packed_size
                     (const SmsgsTempSensorField   *message);
size_t smsgs_temp_sensor_field__pack
                     (const SmsgsTempSensorField   *message,
                      uint8_t             *out);
size_t smsgs_temp_sensor_field__pack_to_buffer
                     (const SmsgsTempSensorField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsTempSensorField *
       smsgs_temp_sensor_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_temp_sensor_field__free_unpacked
                     (SmsgsTempSensorField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsLightSensorField methods */
void   smsgs_light_sensor_field__init
                     (SmsgsLightSensorField         *message);
size_t smsgs_light_sensor_field__get_packed_size
                     (const SmsgsLightSensorField   *message);
size_t smsgs_light_sensor_field__pack
                     (const SmsgsLightSensorField   *message,
                      uint8_t             *out);
size_t smsgs_light_sensor_field__pack_to_buffer
                     (const SmsgsLightSensorField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsLightSensorField *
       smsgs_light_sensor_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_light_sensor_field__free_unpacked
                     (SmsgsLightSensorField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsPressureSensorField methods */
void   smsgs_pressure_sensor_field__init
                     (SmsgsPressureSensorField         *message);
size_t smsgs_pressure_sensor_field__get_packed_size
                     (const SmsgsPressureSensorField   *message);
size_t smsgs_pressure_sensor_field__pack
                     (const SmsgsPressureSensorField   *message,
                      uint8_t             *out);
size_t smsgs_pressure_sensor_field__pack_to_buffer
                     (const SmsgsPressureSensorField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsPressureSensorField *
       smsgs_pressure_sensor_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_pressure_sensor_field__free_unpacked
                     (SmsgsPressureSensorField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsHumiditySensorField methods */
void   smsgs_humidity_sensor_field__init
                     (SmsgsHumiditySensorField         *message);
size_t smsgs_humidity_sensor_field__get_packed_size
                     (const SmsgsHumiditySensorField   *message);
size_t smsgs_humidity_sensor_field__pack
                     (const SmsgsHumiditySensorField   *message,
                      uint8_t             *out);
size_t smsgs_humidity_sensor_field__pack_to_buffer
                     (const SmsgsHumiditySensorField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsHumiditySensorField *
       smsgs_humidity_sensor_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_humidity_sensor_field__free_unpacked
                     (SmsgsHumiditySensorField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsMsgStatsField methods */
void   smsgs_msg_stats_field__init
                     (SmsgsMsgStatsField         *message);
size_t smsgs_msg_stats_field__get_packed_size
                     (const SmsgsMsgStatsField   *message);
size_t smsgs_msg_stats_field__pack
                     (const SmsgsMsgStatsField   *message,
                      uint8_t             *out);
size_t smsgs_msg_stats_field__pack_to_buffer
                     (const SmsgsMsgStatsField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsMsgStatsField *
       smsgs_msg_stats_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_msg_stats_field__free_unpacked
                     (SmsgsMsgStatsField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsConfigSettingsField methods */
void   smsgs_config_settings_field__init
                     (SmsgsConfigSettingsField         *message);
size_t smsgs_config_settings_field__get_packed_size
                     (const SmsgsConfigSettingsField   *message);
size_t smsgs_config_settings_field__pack
                     (const SmsgsConfigSettingsField   *message,
                      uint8_t             *out);
size_t smsgs_config_settings_field__pack_to_buffer
                     (const SmsgsConfigSettingsField   *message,
                      ProtobufCBuffer     *buffer);
SmsgsConfigSettingsField *
       smsgs_config_settings_field__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_config_settings_field__free_unpacked
                     (SmsgsConfigSettingsField *message,
                      ProtobufCAllocator *allocator);
/* SmsgsSensorMsg methods */
void   smsgs_sensor_msg__init
                     (SmsgsSensorMsg         *message);
size_t smsgs_sensor_msg__get_packed_size
                     (const SmsgsSensorMsg   *message);
size_t smsgs_sensor_msg__pack
                     (const SmsgsSensorMsg   *message,
                      uint8_t             *out);
size_t smsgs_sensor_msg__pack_to_buffer
                     (const SmsgsSensorMsg   *message,
                      ProtobufCBuffer     *buffer);
SmsgsSensorMsg *
       smsgs_sensor_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   smsgs_sensor_msg__free_unpacked
                     (SmsgsSensorMsg *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*SmsgsConfigReqMsg_Closure)
                 (const SmsgsConfigReqMsg *message,
                  void *closure_data);
typedef void (*SmsgsConfigRspMsg_Closure)
                 (const SmsgsConfigRspMsg *message,
                  void *closure_data);
typedef void (*SmsgsTrackingReqMsg_Closure)
                 (const SmsgsTrackingReqMsg *message,
                  void *closure_data);
typedef void (*SmsgsTrackingRspMsg_Closure)
                 (const SmsgsTrackingRspMsg *message,
                  void *closure_data);
typedef void (*SmsgsToggleLedReqMsg_Closure)
                 (const SmsgsToggleLedReqMsg *message,
                  void *closure_data);
typedef void (*SmsgsToggleLedRspMsg_Closure)
                 (const SmsgsToggleLedRspMsg *message,
                  void *closure_data);
typedef void (*SmsgsTempSensorField_Closure)
                 (const SmsgsTempSensorField *message,
                  void *closure_data);
typedef void (*SmsgsLightSensorField_Closure)
                 (const SmsgsLightSensorField *message,
                  void *closure_data);
typedef void (*SmsgsPressureSensorField_Closure)
                 (const SmsgsPressureSensorField *message,
                  void *closure_data);
typedef void (*SmsgsHumiditySensorField_Closure)
                 (const SmsgsHumiditySensorField *message,
                  void *closure_data);
typedef void (*SmsgsMsgStatsField_Closure)
                 (const SmsgsMsgStatsField *message,
                  void *closure_data);
typedef void (*SmsgsConfigSettingsField_Closure)
                 (const SmsgsConfigSettingsField *message,
                  void *closure_data);
typedef void (*SmsgsSensorMsg_Closure)
                 (const SmsgsSensorMsg *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    smsgs_cmd_ids__descriptor;
extern const ProtobufCEnumDescriptor    smsgs_data_fields__descriptor;
extern const ProtobufCEnumDescriptor    smsgs_status_values__descriptor;
extern const ProtobufCMessageDescriptor smsgs_config_req_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_config_rsp_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_tracking_req_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_tracking_rsp_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_toggle_led_req_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_toggle_led_rsp_msg__descriptor;
extern const ProtobufCMessageDescriptor smsgs_temp_sensor_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_light_sensor_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_pressure_sensor_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_humidity_sensor_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_msg_stats_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_config_settings_field__descriptor;
extern const ProtobufCMessageDescriptor smsgs_sensor_msg__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_smsgs_2eproto__INCLUDED */
