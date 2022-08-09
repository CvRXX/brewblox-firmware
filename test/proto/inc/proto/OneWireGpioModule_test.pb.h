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
namespace blox_test {
namespace OneWireGpioModule {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class GpioModuleChannel;
class GpioModuleChannelDefaultTypeInternal;
extern GpioModuleChannelDefaultTypeInternal _GpioModuleChannel_default_instance_;
}  // namespace OneWireGpioModule
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::OneWireGpioModule::Block* Arena::CreateMaybeMessage<::blox_test::OneWireGpioModule::Block>(Arena*);
template<> ::blox_test::OneWireGpioModule::GpioModuleChannel* Arena::CreateMaybeMessage<::blox_test::OneWireGpioModule::GpioModuleChannel>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace OneWireGpioModule {

enum GpioDeviceType {
  GPIO_DEV_NONE = 0,
  GPIO_DEV_SSR_2P = 1,
  GPIO_DEV_SSR_1P = 2,
  GPIO_DEV_MECHANICAL_RELAY_2P = 3,
  GPIO_DEV_MECHANICAL_RELAY_1P_HIGH_SIDE = 4,
  GPIO_DEV_MECHANICAL_RELAY_1P_LOW_SIDE = 5,
  GPIO_DEV_COIL_2P = 6,
  GPIO_DEV_COIL_2P_BIDIRECTIONAL = 7,
  GPIO_DEV_COIL_1P_HIGH_SIDE = 8,
  GPIO_DEV_COIL_1P_LOW_SIDE = 9,
  GPIO_DEV_MOTOR_2P = 10,
  GPIO_DEV_MOTOR_2P_BIDIRECTIONAL = 11,
  GPIO_DEV_MOTOR_1P_HIGH_SIDE = 12,
  GPIO_DEV_MOTOR_1P_LOW_SIDE = 13,
  GPIO_DEV_LOAD_DETECT_2P = 14,
  GPIO_DEV_LOAD_DETECT_1P_PULL_DOWN = 15,
  GPIO_DEV_LOAD_DETECT_1P_PULL_UP = 16,
  GPIO_DEV_POWER_1P = 17,
  GPIO_DEV_POWER_1P_LOAD_DETECT = 18,
  GPIO_DEV_GND_1P = 19,
  GPIO_DEV_GND_1P_LOAD_DETECT = 20,
  GpioDeviceType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  GpioDeviceType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool GpioDeviceType_IsValid(int value);
const GpioDeviceType GpioDeviceType_MIN = GPIO_DEV_NONE;
const GpioDeviceType GpioDeviceType_MAX = GPIO_DEV_GND_1P_LOAD_DETECT;
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

class GpioModuleChannel : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.OneWireGpioModule.GpioModuleChannel) */ {
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

  // string name = 5 [(.nanopb) = {
  void clear_name();
  static const int kNameFieldNumber = 5;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // uint32 id = 1 [(.nanopb) = {
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // .blox_test.OneWireGpioModule.GpioDeviceType deviceType = 2;
  void clear_devicetype();
  static const int kDeviceTypeFieldNumber = 2;
  ::blox_test::OneWireGpioModule::GpioDeviceType devicetype() const;
  void set_devicetype(::blox_test::OneWireGpioModule::GpioDeviceType value);

  // uint32 pinsMask = 3 [(.nanopb) = {
  void clear_pinsmask();
  static const int kPinsMaskFieldNumber = 3;
  ::google::protobuf::uint32 pinsmask() const;
  void set_pinsmask(::google::protobuf::uint32 value);

  // uint32 width = 4 [(.nanopb) = {
  void clear_width();
  static const int kWidthFieldNumber = 4;
  ::google::protobuf::uint32 width() const;
  void set_width(::google::protobuf::uint32 value);

  // uint32 capabilities = 6 [(.nanopb) = {
  void clear_capabilities();
  static const int kCapabilitiesFieldNumber = 6;
  ::google::protobuf::uint32 capabilities() const;
  void set_capabilities(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.OneWireGpioModule.GpioModuleChannel)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint32 id_;
  int devicetype_;
  ::google::protobuf::uint32 pinsmask_;
  ::google::protobuf::uint32 width_;
  ::google::protobuf::uint32 capabilities_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_OneWireGpioModule_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.OneWireGpioModule.Block) */ {
 public:
  Block();
  virtual ~Block();

  Block(const Block& from);

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(Block&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Block& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Block* other);
  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Block* New() const final {
    return CreateMaybeMessage<Block>(NULL);
  }

  Block* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
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
  void InternalSwap(Block* other);
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

  // repeated .blox_test.OneWireGpioModule.GpioModuleChannel channels = 1 [(.nanopb) = {
  int channels_size() const;
  void clear_channels();
  static const int kChannelsFieldNumber = 1;
  ::blox_test::OneWireGpioModule::GpioModuleChannel* mutable_channels(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::OneWireGpioModule::GpioModuleChannel >*
      mutable_channels();
  const ::blox_test::OneWireGpioModule::GpioModuleChannel& channels(int index) const;
  ::blox_test::OneWireGpioModule::GpioModuleChannel* add_channels();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::OneWireGpioModule::GpioModuleChannel >&
      channels() const;

  // uint32 modulePosition = 2 [(.nanopb) = {
  void clear_moduleposition();
  static const int kModulePositionFieldNumber = 2;
  ::google::protobuf::uint32 moduleposition() const;
  void set_moduleposition(::google::protobuf::uint32 value);

  // uint32 moduleStatus = 3 [(.nanopb) = {
  void clear_modulestatus();
  static const int kModuleStatusFieldNumber = 3;
  ::google::protobuf::uint32 modulestatus() const;
  void set_modulestatus(::google::protobuf::uint32 value);

  // uint32 pullUpDesired = 4 [(.nanopb) = {
  void clear_pullupdesired();
  static const int kPullUpDesiredFieldNumber = 4;
  ::google::protobuf::uint32 pullupdesired() const;
  void set_pullupdesired(::google::protobuf::uint32 value);

  // uint32 pullUpStatus = 5 [(.nanopb) = {
  void clear_pullupstatus();
  static const int kPullUpStatusFieldNumber = 5;
  ::google::protobuf::uint32 pullupstatus() const;
  void set_pullupstatus(::google::protobuf::uint32 value);

  // uint32 pullUpWhenActive = 6 [(.nanopb) = {
  void clear_pullupwhenactive();
  static const int kPullUpWhenActiveFieldNumber = 6;
  ::google::protobuf::uint32 pullupwhenactive() const;
  void set_pullupwhenactive(::google::protobuf::uint32 value);

  // uint32 pullUpWhenInactive = 7 [(.nanopb) = {
  void clear_pullupwheninactive();
  static const int kPullUpWhenInactiveFieldNumber = 7;
  ::google::protobuf::uint32 pullupwheninactive() const;
  void set_pullupwheninactive(::google::protobuf::uint32 value);

  // uint32 pullDownDesired = 8 [(.nanopb) = {
  void clear_pulldowndesired();
  static const int kPullDownDesiredFieldNumber = 8;
  ::google::protobuf::uint32 pulldowndesired() const;
  void set_pulldowndesired(::google::protobuf::uint32 value);

  // uint32 pullDownStatus = 9 [(.nanopb) = {
  void clear_pulldownstatus();
  static const int kPullDownStatusFieldNumber = 9;
  ::google::protobuf::uint32 pulldownstatus() const;
  void set_pulldownstatus(::google::protobuf::uint32 value);

  // uint32 pullDownWhenActive = 10 [(.nanopb) = {
  void clear_pulldownwhenactive();
  static const int kPullDownWhenActiveFieldNumber = 10;
  ::google::protobuf::uint32 pulldownwhenactive() const;
  void set_pulldownwhenactive(::google::protobuf::uint32 value);

  // uint32 pullDownWhenInactive = 11 [(.nanopb) = {
  void clear_pulldownwheninactive();
  static const int kPullDownWhenInactiveFieldNumber = 11;
  ::google::protobuf::uint32 pulldownwheninactive() const;
  void set_pulldownwheninactive(::google::protobuf::uint32 value);

  // uint32 overCurrent = 12 [(.nanopb) = {
  void clear_overcurrent();
  static const int kOverCurrentFieldNumber = 12;
  ::google::protobuf::uint32 overcurrent() const;
  void set_overcurrent(::google::protobuf::uint32 value);

  // uint32 openLoad = 13 [(.nanopb) = {
  void clear_openload();
  static const int kOpenLoadFieldNumber = 13;
  ::google::protobuf::uint32 openload() const;
  void set_openload(::google::protobuf::uint32 value);

  // bool useExternalPower = 14;
  void clear_useexternalpower();
  static const int kUseExternalPowerFieldNumber = 14;
  bool useexternalpower() const;
  void set_useexternalpower(bool value);

  // bool clearFaults = 32;
  void clear_clearfaults();
  static const int kClearFaultsFieldNumber = 32;
  bool clearfaults() const;
  void set_clearfaults(bool value);

  // @@protoc_insertion_point(class_scope:blox_test.OneWireGpioModule.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::OneWireGpioModule::GpioModuleChannel > channels_;
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
  bool useexternalpower_;
  bool clearfaults_;
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

// uint32 id = 1 [(.nanopb) = {
inline void GpioModuleChannel::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::id() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.id)
  return id_;
}
inline void GpioModuleChannel::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.id)
}

// .blox_test.OneWireGpioModule.GpioDeviceType deviceType = 2;
inline void GpioModuleChannel::clear_devicetype() {
  devicetype_ = 0;
}
inline ::blox_test::OneWireGpioModule::GpioDeviceType GpioModuleChannel::devicetype() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.deviceType)
  return static_cast< ::blox_test::OneWireGpioModule::GpioDeviceType >(devicetype_);
}
inline void GpioModuleChannel::set_devicetype(::blox_test::OneWireGpioModule::GpioDeviceType value) {
  
  devicetype_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.deviceType)
}

// uint32 pinsMask = 3 [(.nanopb) = {
inline void GpioModuleChannel::clear_pinsmask() {
  pinsmask_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::pinsmask() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.pinsMask)
  return pinsmask_;
}
inline void GpioModuleChannel::set_pinsmask(::google::protobuf::uint32 value) {
  
  pinsmask_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.pinsMask)
}

// uint32 width = 4 [(.nanopb) = {
inline void GpioModuleChannel::clear_width() {
  width_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::width() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.width)
  return width_;
}
inline void GpioModuleChannel::set_width(::google::protobuf::uint32 value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.width)
}

// string name = 5 [(.nanopb) = {
inline void GpioModuleChannel::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GpioModuleChannel::name() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.name)
  return name_.GetNoArena();
}
inline void GpioModuleChannel::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.name)
}
#if LANG_CXX11
inline void GpioModuleChannel::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.OneWireGpioModule.GpioModuleChannel.name)
}
#endif
inline void GpioModuleChannel::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.OneWireGpioModule.GpioModuleChannel.name)
}
inline void GpioModuleChannel::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.OneWireGpioModule.GpioModuleChannel.name)
}
inline ::std::string* GpioModuleChannel::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.OneWireGpioModule.GpioModuleChannel.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GpioModuleChannel::release_name() {
  // @@protoc_insertion_point(field_release:blox_test.OneWireGpioModule.GpioModuleChannel.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GpioModuleChannel::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:blox_test.OneWireGpioModule.GpioModuleChannel.name)
}

// uint32 capabilities = 6 [(.nanopb) = {
inline void GpioModuleChannel::clear_capabilities() {
  capabilities_ = 0u;
}
inline ::google::protobuf::uint32 GpioModuleChannel::capabilities() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.GpioModuleChannel.capabilities)
  return capabilities_;
}
inline void GpioModuleChannel::set_capabilities(::google::protobuf::uint32 value) {
  
  capabilities_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.GpioModuleChannel.capabilities)
}

// -------------------------------------------------------------------

// Block

// repeated .blox_test.OneWireGpioModule.GpioModuleChannel channels = 1 [(.nanopb) = {
inline int Block::channels_size() const {
  return channels_.size();
}
inline void Block::clear_channels() {
  channels_.Clear();
}
inline ::blox_test::OneWireGpioModule::GpioModuleChannel* Block::mutable_channels(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.OneWireGpioModule.Block.channels)
  return channels_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::OneWireGpioModule::GpioModuleChannel >*
Block::mutable_channels() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.OneWireGpioModule.Block.channels)
  return &channels_;
}
inline const ::blox_test::OneWireGpioModule::GpioModuleChannel& Block::channels(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.channels)
  return channels_.Get(index);
}
inline ::blox_test::OneWireGpioModule::GpioModuleChannel* Block::add_channels() {
  // @@protoc_insertion_point(field_add:blox_test.OneWireGpioModule.Block.channels)
  return channels_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::OneWireGpioModule::GpioModuleChannel >&
Block::channels() const {
  // @@protoc_insertion_point(field_list:blox_test.OneWireGpioModule.Block.channels)
  return channels_;
}

// uint32 modulePosition = 2 [(.nanopb) = {
inline void Block::clear_moduleposition() {
  moduleposition_ = 0u;
}
inline ::google::protobuf::uint32 Block::moduleposition() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.modulePosition)
  return moduleposition_;
}
inline void Block::set_moduleposition(::google::protobuf::uint32 value) {
  
  moduleposition_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.modulePosition)
}

// uint32 moduleStatus = 3 [(.nanopb) = {
inline void Block::clear_modulestatus() {
  modulestatus_ = 0u;
}
inline ::google::protobuf::uint32 Block::modulestatus() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.moduleStatus)
  return modulestatus_;
}
inline void Block::set_modulestatus(::google::protobuf::uint32 value) {
  
  modulestatus_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.moduleStatus)
}

// uint32 pullUpDesired = 4 [(.nanopb) = {
inline void Block::clear_pullupdesired() {
  pullupdesired_ = 0u;
}
inline ::google::protobuf::uint32 Block::pullupdesired() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullUpDesired)
  return pullupdesired_;
}
inline void Block::set_pullupdesired(::google::protobuf::uint32 value) {
  
  pullupdesired_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullUpDesired)
}

// uint32 pullUpStatus = 5 [(.nanopb) = {
inline void Block::clear_pullupstatus() {
  pullupstatus_ = 0u;
}
inline ::google::protobuf::uint32 Block::pullupstatus() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullUpStatus)
  return pullupstatus_;
}
inline void Block::set_pullupstatus(::google::protobuf::uint32 value) {
  
  pullupstatus_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullUpStatus)
}

// uint32 pullUpWhenActive = 6 [(.nanopb) = {
inline void Block::clear_pullupwhenactive() {
  pullupwhenactive_ = 0u;
}
inline ::google::protobuf::uint32 Block::pullupwhenactive() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullUpWhenActive)
  return pullupwhenactive_;
}
inline void Block::set_pullupwhenactive(::google::protobuf::uint32 value) {
  
  pullupwhenactive_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullUpWhenActive)
}

// uint32 pullUpWhenInactive = 7 [(.nanopb) = {
inline void Block::clear_pullupwheninactive() {
  pullupwheninactive_ = 0u;
}
inline ::google::protobuf::uint32 Block::pullupwheninactive() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullUpWhenInactive)
  return pullupwheninactive_;
}
inline void Block::set_pullupwheninactive(::google::protobuf::uint32 value) {
  
  pullupwheninactive_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullUpWhenInactive)
}

// uint32 pullDownDesired = 8 [(.nanopb) = {
inline void Block::clear_pulldowndesired() {
  pulldowndesired_ = 0u;
}
inline ::google::protobuf::uint32 Block::pulldowndesired() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullDownDesired)
  return pulldowndesired_;
}
inline void Block::set_pulldowndesired(::google::protobuf::uint32 value) {
  
  pulldowndesired_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullDownDesired)
}

// uint32 pullDownStatus = 9 [(.nanopb) = {
inline void Block::clear_pulldownstatus() {
  pulldownstatus_ = 0u;
}
inline ::google::protobuf::uint32 Block::pulldownstatus() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullDownStatus)
  return pulldownstatus_;
}
inline void Block::set_pulldownstatus(::google::protobuf::uint32 value) {
  
  pulldownstatus_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullDownStatus)
}

// uint32 pullDownWhenActive = 10 [(.nanopb) = {
inline void Block::clear_pulldownwhenactive() {
  pulldownwhenactive_ = 0u;
}
inline ::google::protobuf::uint32 Block::pulldownwhenactive() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullDownWhenActive)
  return pulldownwhenactive_;
}
inline void Block::set_pulldownwhenactive(::google::protobuf::uint32 value) {
  
  pulldownwhenactive_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullDownWhenActive)
}

// uint32 pullDownWhenInactive = 11 [(.nanopb) = {
inline void Block::clear_pulldownwheninactive() {
  pulldownwheninactive_ = 0u;
}
inline ::google::protobuf::uint32 Block::pulldownwheninactive() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.pullDownWhenInactive)
  return pulldownwheninactive_;
}
inline void Block::set_pulldownwheninactive(::google::protobuf::uint32 value) {
  
  pulldownwheninactive_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.pullDownWhenInactive)
}

// uint32 overCurrent = 12 [(.nanopb) = {
inline void Block::clear_overcurrent() {
  overcurrent_ = 0u;
}
inline ::google::protobuf::uint32 Block::overcurrent() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.overCurrent)
  return overcurrent_;
}
inline void Block::set_overcurrent(::google::protobuf::uint32 value) {
  
  overcurrent_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.overCurrent)
}

// uint32 openLoad = 13 [(.nanopb) = {
inline void Block::clear_openload() {
  openload_ = 0u;
}
inline ::google::protobuf::uint32 Block::openload() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.openLoad)
  return openload_;
}
inline void Block::set_openload(::google::protobuf::uint32 value) {
  
  openload_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.openLoad)
}

// bool useExternalPower = 14;
inline void Block::clear_useexternalpower() {
  useexternalpower_ = false;
}
inline bool Block::useexternalpower() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.useExternalPower)
  return useexternalpower_;
}
inline void Block::set_useexternalpower(bool value) {
  
  useexternalpower_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.useExternalPower)
}

// bool clearFaults = 32;
inline void Block::clear_clearfaults() {
  clearfaults_ = false;
}
inline bool Block::clearfaults() const {
  // @@protoc_insertion_point(field_get:blox_test.OneWireGpioModule.Block.clearFaults)
  return clearfaults_;
}
inline void Block::set_clearfaults(bool value) {
  
  clearfaults_ = value;
  // @@protoc_insertion_point(field_set:blox_test.OneWireGpioModule.Block.clearFaults)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace OneWireGpioModule
}  // namespace blox_test

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox_test::OneWireGpioModule::GpioDeviceType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::OneWireGpioModule::GpioDeviceType>() {
  return ::blox_test::OneWireGpioModule::GpioDeviceType_descriptor();
}
template <> struct is_proto_enum< ::blox_test::OneWireGpioModule::GpioErrorFlags> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::OneWireGpioModule::GpioErrorFlags>() {
  return ::blox_test::OneWireGpioModule::GpioErrorFlags_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_OneWireGpioModule_5ftest_2eproto
