/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: llc.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "llc.pb-c.h"
void   llc_net_info__init
                     (LlcNetInfo         *message)
{
  static LlcNetInfo init_value = LLC_NET_INFO__INIT;
  *message = init_value;
}
size_t llc_net_info__get_packed_size
                     (const LlcNetInfo *message)
{
  assert(message->base.descriptor == &llc_net_info__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t llc_net_info__pack
                     (const LlcNetInfo *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &llc_net_info__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t llc_net_info__pack_to_buffer
                     (const LlcNetInfo *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &llc_net_info__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
LlcNetInfo *
       llc_net_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (LlcNetInfo *)
     protobuf_c_message_unpack (&llc_net_info__descriptor,
                                allocator, len, data);
}
void   llc_net_info__free_unpacked
                     (LlcNetInfo *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &llc_net_info__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   llc_device_list_item__init
                     (LlcDeviceListItem         *message)
{
  static LlcDeviceListItem init_value = LLC_DEVICE_LIST_ITEM__INIT;
  *message = init_value;
}
size_t llc_device_list_item__get_packed_size
                     (const LlcDeviceListItem *message)
{
  assert(message->base.descriptor == &llc_device_list_item__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t llc_device_list_item__pack
                     (const LlcDeviceListItem *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &llc_device_list_item__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t llc_device_list_item__pack_to_buffer
                     (const LlcDeviceListItem *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &llc_device_list_item__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
LlcDeviceListItem *
       llc_device_list_item__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (LlcDeviceListItem *)
     protobuf_c_message_unpack (&llc_device_list_item__descriptor,
                                allocator, len, data);
}
void   llc_device_list_item__free_unpacked
                     (LlcDeviceListItem *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &llc_device_list_item__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor llc_net_info__field_descriptors[3] =
{
  {
    "fh",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LlcNetInfo, fh),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "channel",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LlcNetInfo, channel),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "devInfo",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(LlcNetInfo, devinfo),
    &api_mac_device_descriptor__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned llc_net_info__field_indices_by_name[] = {
  1,   /* field[1] = channel */
  2,   /* field[2] = devInfo */
  0,   /* field[0] = fh */
};
static const ProtobufCIntRange llc_net_info__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor llc_net_info__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Llc_netInfo",
  "LlcNetInfo",
  "LlcNetInfo",
  "",
  sizeof(LlcNetInfo),
  3,
  llc_net_info__field_descriptors,
  llc_net_info__field_indices_by_name,
  1,  llc_net_info__number_ranges,
  (ProtobufCMessageInit) llc_net_info__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor llc_device_list_item__field_descriptors[3] =
{
  {
    "devInfo",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(LlcDeviceListItem, devinfo),
    &api_mac_device_descriptor__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "capInfo",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(LlcDeviceListItem, capinfo),
    &api_mac_capability_info__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rxFrameCounter",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT32,
    0,   /* quantifier_offset */
    offsetof(LlcDeviceListItem, rxframecounter),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned llc_device_list_item__field_indices_by_name[] = {
  1,   /* field[1] = capInfo */
  0,   /* field[0] = devInfo */
  2,   /* field[2] = rxFrameCounter */
};
static const ProtobufCIntRange llc_device_list_item__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor llc_device_list_item__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Llc_deviceListItem",
  "LlcDeviceListItem",
  "LlcDeviceListItem",
  "",
  sizeof(LlcDeviceListItem),
  3,
  llc_device_list_item__field_descriptors,
  llc_device_list_item__field_indices_by_name,
  1,  llc_device_list_item__number_ranges,
  (ProtobufCMessageInit) llc_device_list_item__init,
  NULL,NULL,NULL    /* reserved[123] */
};
