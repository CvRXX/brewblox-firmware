// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OneWireGpioModule_test.proto

#ifndef PROTOBUF_INCLUDED_OneWireGpioModule_5ftest_2eproto
#define PROTOBUF_INCLUDED_OneWireGpioModule_5ftest_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_OneWireGpioModule_5ftest_2eproto 

namespace protobuf_OneWireGpioModule_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_OneWireGpioModule_5ftest_2eproto
namespace blox {
class GpioModuleChannel;
class GpioModuleChannelDefaultTypeInternal;
extern GpioModuleChannelDefaultTypeInternal _GpioModuleChannel_default_instance_;
class OneWireGpioModule;
class OneWireGpioModuleDefaultTypeInternal;
extern OneWireGpioModuleDefaultTypeInternal _OneWireGpioModule_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::GpioModuleChannel* Arena::CreateMaybeMessage<::blox::GpioModuleChannel>(Arena*);
template<> ::blox::OneWireGpioModule* Arena::CreateMaybeMessage<::blox::OneWireGpioModule>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

enum GpioDeviceType {
  GPIO_DEV_NONE = 0,
  GPIO_DEV_SSR_2P = 1,
  GPIO_DEV_SSR_1P = 2,
  GPIO_DEV_COIL_UNIDIRECTIONAL_2P = 3,
  GPIO_DEV_COIL_BIDIRECTIONAL_2P = 4,
  GPIO_DEV_COIL_HIGH_SIDE_1P = 5,
  GPIO_DEV_COIL_LOW_SIDE_1P = 6,
  GPIO_DEV_MOTOR_UNIDIRECTIONAL_2P = 7,
  GPIO_DEV_MOTOR_BIDIRECTIONAL_2P = 8,
  GPIO_DEV_MOTOR_HIGH_SIDE_1P = 9,
  GPIO_DEV_MOTOR_LOW_SIDE_1P = 10,
  GPIO_DEV_LOAD_DETECT_2P = 11,
  GPIO_DEV_LOAD_DETECT_PULL_DOWN_1P = 12,
  GPIO_DEV_LOAD_DETECT_PULL_UP_1P = 13,
  GPIO_DEV_POWER_LOAD_DETECT_1P = 14,
  GPIO_DEV_GND_LOAD_DETECT_1P = 15,
  GPIO_DEV_POWER_1P = 16,
  GPIO_DEV_GND_1P = 17,
  GpioDeviceType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  GpioDeviceType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool GpioDeviceType_IsValid(int value);
const GpioDeviceType GpioDeviceType_MIN = GPIO_DEV_NONE;
const GpioDeviceType GpioDeviceType_MAX = GPIO_DEV_GND_1P;
const int GpioDeviceType_ARRAYSIZE = GpioDeviceType_MAX + 1;

const ::google::protobuf::EnumDescriptor* GpioDeviceType_descriptor();
inline const ::std::string& GpioDeviceType_Name(GpioDeviceType value) {
  return ::google::protobuf::internal::NameOfEnum(
    GpioDeviceType_descriptor(), value);
}
inline bool GpioDeviceType_Parse(
    const ::std::string& name, GpioDeviceType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<GpioDeviceType>(
    GpioDeviceType_descriptor(), name, value);
}
enum GpioErrorFlags {
  GPIO_ERR_NONE = 0,
  GPIO_ERR_POWER_ON_RESET = 1,
  GPIO_ERR_OVERVOLTAGE = 2,
  GPIO_ERR_UNDERVOLTAGE = 4,
  GPIO_ERR_OVERCURRENT = 8,
  GPIO_ERR_OPEN_LOAD = 16,
  GPIO_ERR_OVERTEMPERATURE_WARNING = 32,
  GPIO_ERR_OVERTEMPERATURE_ERROR = 64,
  GPIO_ERR_SPI_ERROR = 128,
  GpioErrorFlags_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  GpioErrorFlags_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool GpioErrorFlags_IsValid(int value);
const GpioErrorFlags GpioErrorFlags_MIN = GPIO_ERR_NONE;
const GpioErrorFlags GpioErrorFlags_MAX = GPIO_ERR_SPI_ERROR;
const int GpioErrorFlags_ARRAYSIZE = GpioErrorFlags_MAX + 1;

const ::google::protobuf::EnumDescriptor* GpioErrorFlags_descriptor();
inline const ::std::string& GpioErrorFlags_Name(GpioErrorFlags value) {
  return ::google::protobuf::internal::NameOfEnum(
    GpioErrorFlags_descriptor(), value);
}
inline bool GpioErrorFlags_Parse(
    const ::std::string& name, GpioErrorFlags* value) {
  return ::google::protobuf::internal::ParseNamedEnum<GpioErrorFlags>(
    GpioErrorFlags_descriptor(), name, value);
}
// ===================================================================

class GpioModuleChannel : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.GpioModuleChannel) */ {
 public:
  GpioModuleChannel();
  virtual ~GpioModuleChannel();

  GpioModuleChannel(const GpioModuleChannel& from);

  inline GpioModuleChannel& operator=(const GpioModuleChannel& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GpioModuleChannel(GpioModuleChannel&& from) noexcept
    : GpioModuleChannel() {
    *this = ::std::move(from);
  }

  inline GpioModuleChannel& operator=(GpioModuleChannel&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GpioModuleChannel& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GpioModuleChannel* internal_default_instance() {
    return reinterpret_cast<const GpioModuleChannel*>(
               &_GpioModuleChannel_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(GpioModuleChannel* other);
  friend void swap(GpioModuleChannel& a, GpioModuleChannel& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GpioModuleChannel* New() const final {
    return CreateMaybeMessage<GpioModuleChannel>(NULL);
  }

  GpioModuleChannel* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GpioModuleChannel>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GpioModuleChannel& from);
  void MergeFrom(const GpioModuleChannel& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GpioModuleChannel* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 id = 1 [(.nanopb_test) = {
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // .blox.GpioDeviceType deviceType = 2;
  void clear_devicetype();
  static const int kDeviceTypeFieldNumber = 2;
  ::blox::GpioDeviceType devicetype() const;
  void set_devicetype(::blox::GpioDeviceType value);

  // uint32 pinsMask = 3 [(.nanopb_test) = {
  void clear_pinsmask();
  static const int kPinsMaskFieldNumber = 3;
  ::google::protobuf::uint32 pinsmask() const;
  void set_pinsmask(::google::protobuf::uint32 value);

  // uint32 width = 4 [(.nanopb_test) = {
  void clear_width();
  static const int kWidthFieldNumber = 4;
  ::google::protobuf::uint32 width() const;
  void set_width(::google::protobuf::uint32 value);

  // .blox.ChannelConfig config = 5 [(.brewblox_test) = {
  void clear_config();
  static const int kConfigFieldNumber = 5;
  ::blox::ChannelConfig config() const;
  void set_config(::blox::ChannelConfig value);

  // .blox.DigitalState state = 6 [(.brewblox_test) = {
  void clear_state();
  static const int kStateFieldNumber = 6;
  ::blox::DigitalState state() const;
  void set_state(::blox::DigitalState value);

  // int32 pwmDuty = 7 [(.nanopb_test) = {
  void clear_pwmduty();
  static const int kPwmDutyFieldNumber = 7;
  ::google::protobuf::int32 pwmduty() const;
  void set_pwmduty(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox.GpioModuleChannel)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 id_;
  int devicetype_;
  ::google::protobuf::uint32 pinsmask_;
  ::google::protobuf::uint32 width_;
  int config_;
  int state_;
  ::google::protobuf::int32 pwmduty_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_OneWireGpioModule_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class OneWireGpioModule : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.OneWireGpioModule) */ {
 public:
  OneWireGpioModule();
  virtual ~OneWireGpioModule();

  OneWireGpioModule(const OneWireGpioModule& from);

  inline OneWireGpioModule& operator=(const OneWireGpioModule& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  OneWireGpioModule(OneWireGpioModule&& from) noexcept
    : OneWireGpioModule() {
    *this = ::std::move(from);
  }

  inline OneWireGpioModule& operator=(OneWireGpioModule&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const OneWireGpioModule& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const OneWireGpioModule* internal_default_instance() {
    return reinterpret_cast<const OneWireGpioModule*>(
               &_OneWireGpioModule_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(OneWireGpioModule* other);
  friend void swap(OneWireGpioModule& a, OneWireGpioModule& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline OneWireGpioModule* New() const final {
    return CreateMaybeMessage<OneWireGpioModule>(NULL);
  }

  OneWireGpioModule* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<OneWireGpioModule>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const OneWireGpioModule& from);
  void MergeFrom(const OneWireGpioModule& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(OneWireGpioModule* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .blox.GpioModuleChannel channels = 1 [(.nanopb_test) = {
  int channels_size() const;
  void clear_channels();
  static const int kChannelsFieldNumber = 1;
  ::blox::GpioModuleChannel* mutable_channels(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::GpioModuleChannel >*
      mutable_channels();
  const ::blox::GpioModuleChannel& channels(int index) const;
  ::blox::GpioModuleChannel* add_channels();
  const ::google::protobuf::RepeatedPtrField< ::blox::GpioModuleChannel >&
      channels() const;

  // uint32 modulePosition = 2 [(.nanopb_test) = {
  void clear_moduleposition();
  static const int kModulePositionFieldNumber = 2;
  ::google::protobuf::uint32 moduleposition() const;
  void set_moduleposition(::google::protobuf::uint32 value);

  // uint32 moduleStatus = 3 [(.nanopb_test) = {
  void clear_modulestatus();
  static const int kModuleStatusFieldNumber = 3;
  ::google::protobuf::uint32 modulestatus() const;
  void set_modulestatus(::google::protobuf::uint32 value);

  // uint32 pullUpDesired = 4 [(.nanopb_test) = {
  void clear_pullupdesired();
  static const int kPullUpDesiredFieldNumber = 4;
  ::google::protobuf::uint32 pullupdesired() const;
  void set_pullupdesired(::google::protobuf::uint32 value);

  // uint32 pullUpStatus = 5 [(.nanopb_test) = {
  void clear_pullupstatus();
  static const int kPullUpStatusFieldNumber = 5;
  ::google::protobuf::uint32 pullupstatus() const;
  void set_pullupstatus(::google::protobuf::uint32 value);

  // uint32 pullUpWhenActive = 6 [(.nanopb_test) = {
  void clear_pullupwhenactive();
  static const int kPullUpWhenActiveFieldNumber = 6;
  ::google::protobuf::uint32 pullupwhenactive() const;
  void set_pullupwhenactive(::google::protobuf::uint32 value);

  // uint32 pullUpWhenInactive = 7 [(.nanopb_test) = {
  void clear_pullupwheninactive();
  static const int kPullUpWhenInactiveFieldNumber = 7;
  ::google::protobuf::uint32 pullupwheninactive() const;
  void set_pullupwheninactive(::google::protobuf::uint32 value);

  // uint32 pullDownDesired = 8 [(.nanopb_test) = {
  void clear_pulldowndesired();
  static const int kPullDownDesiredFieldNumber = 8;
  ::google::protobuf::uint32 pulldowndesired() const;
  void set_pulldowndesired(::google::protobuf::uint32 value);

  // uint32 pullDownStatus = 9 [(.nanopb_test) = {
  void clear_pulldownstatus();
  static const int kPullDownStatusFieldNumber = 9;
  ::google::protobuf::uint32 pulldownstatus() const;
  void set_pulldownstatus(::google::protobuf::uint32 value);

  // uint32 pullDownWhenActive = 10 [(.nanopb_test) = {
  void clear_pulldownwhenactive();
  static const int kPullDownWhenActiveFieldNumber = 10;
  ::google::protobuf::uint32 pulldownwhenactive() const;
  void set_pulldownwhenactive(::google::protobuf::uint32 value);

  // uint32 pullDownWhenInactive = 11 [(.nanopb_test) = {
  void clear_pulldownwheninactive();
  static const int kPullDownWhenInactiveFieldNumber = 11;
  ::google::protobuf::uint32 pulldownwheninactive() const;
  void set_pulldownwheninactive(::google::protobuf::uint32 value);

  // uint32 overCurrent = 12 [(.nanopb_test) = {
  void clear_overcurrent();
  static const int kOverCurrentFieldNumber = 12;
  ::google::protobuf::uint32 overcurrent() const;
  void set_overcurrent(::google::protobuf::uint32 value);

  // uint32 openLoad = 13 [(.nanopb_test) = {
  void clear_openload();
  static const int kOpenLoadFieldNumber = 13;
  ::google::protobuf::uint32 openload() const;
  void set_openload(::google::protobuf::uint32 value);

  // uint32 moduleStatusClear = 16 [(.nanopb_test) = {
  void clear_modulestatusclear();
  static const int kModuleStatusClearFieldNumber = 16;
  ::google::protobuf::uint32 modulestatusclear() const;
  void set_modulestatusclear(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.OneWireGpioModule)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::GpioModuleChannel > channels_;
  ::google::protobuf::uint32 moduleposition_;
  ::google::protobuf::uint32 modulestatus_;
  ::google::protobuf::uint32 pullupdesired_;
  ::google::protobuf::uint32 pullupstatus_;
  ::google::protobuf::uint32 pullupwhenactive_;
  ::google::protobuf::uint32 pullupwheninactive_;
  ::google::protobuf::uint32 pulldowndesired_;
  ::google::protobuf::uint32 pulldownstatus_;
  ::google::protobuf::uint32 pulldownwhenactive_;
  ::google::protobuf::uint32 pulldownwheninactive_;
  ::google::protobuf::uint32 overcurrent_;
  ::google::protobuf::uint32 openload_;
  ::google::protobuf::uint32 modulestatusclear_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_OneWireGpioModule_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GpioModuleChannel

// uint32 id = 1 [(.nanopb_test) = {
inline void GpioModuleChannel::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::id() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.id)
  return id_;
}
inline void GpioModuleChannel::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.id)
}

// .blox.GpioDeviceType deviceType = 2;
inline void GpioModuleChannel::clear_devicetype() {
  devicetype_ = 0;
}
inline ::blox::GpioDeviceType GpioModuleChannel::devicetype() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.deviceType)
  return static_cast< ::blox::GpioDeviceType >(devicetype_);
}
inline void GpioModuleChannel::set_devicetype(::blox::GpioDeviceType value) {
  
  devicetype_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.deviceType)
}

// uint32 pinsMask = 3 [(.nanopb_test) = {
inline void GpioModuleChannel::clear_pinsmask() {
  pinsmask_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::pinsmask() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.pinsMask)
  return pinsmask_;
}
inline void GpioModuleChannel::set_pinsmask(::google::protobuf::uint32 value) {
  
  pinsmask_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.pinsMask)
}

// uint32 width = 4 [(.nanopb_test) = {
inline void GpioModuleChannel::clear_width() {
  width_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::width() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.width)
  return width_;
}
inline void GpioModuleChannel::set_width(::google::protobuf::uint32 value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.width)
}

// .blox.ChannelConfig config = 5 [(.brewblox_test) = {
inline void GpioModuleChannel::clear_config() {
  config_ = 0;
}
inline ::blox::ChannelConfig GpioModuleChannel::config() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.config)
  return static_cast< ::blox::ChannelConfig >(config_);
}
inline void GpioModuleChannel::set_config(::blox::ChannelConfig value) {
  
  config_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.config)
}

// .blox.DigitalState state = 6 [(.brewblox_test) = {
inline void GpioModuleChannel::clear_state() {
  state_ = 0;
}
inline ::blox::DigitalState GpioModuleChannel::state() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.state)
  return static_cast< ::blox::DigitalState >(state_);
}
inline void GpioModuleChannel::set_state(::blox::DigitalState value) {
  
  state_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.state)
}

// int32 pwmDuty = 7 [(.nanopb_test) = {
inline void GpioModuleChannel::clear_pwmduty() {
  pwmduty_ = 0;
}
inline ::google::protobuf::int32 GpioModuleChannel::pwmduty() const {
  // @@protoc_insertion_point(field_get:blox.GpioModuleChannel.pwmDuty)
  return pwmduty_;
}
inline void GpioModuleChannel::set_pwmduty(::google::protobuf::int32 value) {
  
  pwmduty_ = value;
  // @@protoc_insertion_point(field_set:blox.GpioModuleChannel.pwmDuty)
}

// -------------------------------------------------------------------

// OneWireGpioModule

// repeated .blox.GpioModuleChannel channels = 1 [(.nanopb_test) = {
inline int OneWireGpioModule::channels_size() const {
  return channels_.size();
}
inline void OneWireGpioModule::clear_channels() {
  channels_.Clear();
}
inline ::blox::GpioModuleChannel* OneWireGpioModule::mutable_channels(int index) {
  // @@protoc_insertion_point(field_mutable:blox.OneWireGpioModule.channels)
  return channels_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::GpioModuleChannel >*
OneWireGpioModule::mutable_channels() {
  // @@protoc_insertion_point(field_mutable_list:blox.OneWireGpioModule.channels)
  return &channels_;
}
inline const ::blox::GpioModuleChannel& OneWireGpioModule::channels(int index) const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.channels)
  return channels_.Get(index);
}
inline ::blox::GpioModuleChannel* OneWireGpioModule::add_channels() {
  // @@protoc_insertion_point(field_add:blox.OneWireGpioModule.channels)
  return channels_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::GpioModuleChannel >&
OneWireGpioModule::channels() const {
  // @@protoc_insertion_point(field_list:blox.OneWireGpioModule.channels)
  return channels_;
}

// uint32 modulePosition = 2 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_moduleposition() {
  moduleposition_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::moduleposition() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.modulePosition)
  return moduleposition_;
}
inline void OneWireGpioModule::set_moduleposition(::google::protobuf::uint32 value) {
  
  moduleposition_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.modulePosition)
}

// uint32 moduleStatus = 3 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_modulestatus() {
  modulestatus_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::modulestatus() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.moduleStatus)
  return modulestatus_;
}
inline void OneWireGpioModule::set_modulestatus(::google::protobuf::uint32 value) {
  
  modulestatus_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.moduleStatus)
}

// uint32 pullUpDesired = 4 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pullupdesired() {
  pullupdesired_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pullupdesired() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullUpDesired)
  return pullupdesired_;
}
inline void OneWireGpioModule::set_pullupdesired(::google::protobuf::uint32 value) {
  
  pullupdesired_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullUpDesired)
}

// uint32 pullUpStatus = 5 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pullupstatus() {
  pullupstatus_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pullupstatus() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullUpStatus)
  return pullupstatus_;
}
inline void OneWireGpioModule::set_pullupstatus(::google::protobuf::uint32 value) {
  
  pullupstatus_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullUpStatus)
}

// uint32 pullUpWhenActive = 6 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pullupwhenactive() {
  pullupwhenactive_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pullupwhenactive() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullUpWhenActive)
  return pullupwhenactive_;
}
inline void OneWireGpioModule::set_pullupwhenactive(::google::protobuf::uint32 value) {
  
  pullupwhenactive_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullUpWhenActive)
}

// uint32 pullUpWhenInactive = 7 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pullupwheninactive() {
  pullupwheninactive_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pullupwheninactive() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullUpWhenInactive)
  return pullupwheninactive_;
}
inline void OneWireGpioModule::set_pullupwheninactive(::google::protobuf::uint32 value) {
  
  pullupwheninactive_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullUpWhenInactive)
}

// uint32 pullDownDesired = 8 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pulldowndesired() {
  pulldowndesired_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pulldowndesired() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullDownDesired)
  return pulldowndesired_;
}
inline void OneWireGpioModule::set_pulldowndesired(::google::protobuf::uint32 value) {
  
  pulldowndesired_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullDownDesired)
}

// uint32 pullDownStatus = 9 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pulldownstatus() {
  pulldownstatus_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pulldownstatus() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullDownStatus)
  return pulldownstatus_;
}
inline void OneWireGpioModule::set_pulldownstatus(::google::protobuf::uint32 value) {
  
  pulldownstatus_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullDownStatus)
}

// uint32 pullDownWhenActive = 10 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pulldownwhenactive() {
  pulldownwhenactive_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pulldownwhenactive() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullDownWhenActive)
  return pulldownwhenactive_;
}
inline void OneWireGpioModule::set_pulldownwhenactive(::google::protobuf::uint32 value) {
  
  pulldownwhenactive_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullDownWhenActive)
}

// uint32 pullDownWhenInactive = 11 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_pulldownwheninactive() {
  pulldownwheninactive_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::pulldownwheninactive() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.pullDownWhenInactive)
  return pulldownwheninactive_;
}
inline void OneWireGpioModule::set_pulldownwheninactive(::google::protobuf::uint32 value) {
  
  pulldownwheninactive_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.pullDownWhenInactive)
}

// uint32 overCurrent = 12 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_overcurrent() {
  overcurrent_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::overcurrent() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.overCurrent)
  return overcurrent_;
}
inline void OneWireGpioModule::set_overcurrent(::google::protobuf::uint32 value) {
  
  overcurrent_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.overCurrent)
}

// uint32 openLoad = 13 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_openload() {
  openload_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::openload() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.openLoad)
  return openload_;
}
inline void OneWireGpioModule::set_openload(::google::protobuf::uint32 value) {
  
  openload_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.openLoad)
}

// uint32 moduleStatusClear = 16 [(.nanopb_test) = {
inline void OneWireGpioModule::clear_modulestatusclear() {
  modulestatusclear_ = 0u;
}
inline ::google::protobuf::uint32 OneWireGpioModule::modulestatusclear() const {
  // @@protoc_insertion_point(field_get:blox.OneWireGpioModule.moduleStatusClear)
  return modulestatusclear_;
}
inline void OneWireGpioModule::set_modulestatusclear(::google::protobuf::uint32 value) {
  
  modulestatusclear_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireGpioModule.moduleStatusClear)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox::GpioDeviceType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::GpioDeviceType>() {
  return ::blox::GpioDeviceType_descriptor();
}
template <> struct is_proto_enum< ::blox::GpioErrorFlags> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::GpioErrorFlags>() {
  return ::blox::GpioErrorFlags_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_OneWireGpioModule_5ftest_2eproto
