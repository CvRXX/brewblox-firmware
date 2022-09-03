// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SysInfo_test.proto

#ifndef PROTOBUF_INCLUDED_SysInfo_5ftest_2eproto
#define PROTOBUF_INCLUDED_SysInfo_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_SysInfo_5ftest_2eproto 

namespace protobuf_SysInfo_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_SysInfo_5ftest_2eproto
namespace blox_test {
namespace SysInfo {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace SysInfo
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::SysInfo::Block* Arena::CreateMaybeMessage<::blox_test::SysInfo::Block>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace SysInfo {

enum Platform {
  PLATFORM_UNKNOWN = 0,
  PLATFORM_GCC = 3,
  PLATFORM_PHOTON = 6,
  PLATFORM_P1 = 8,
  PLATFORM_ESP = 100,
  PLATFORM_SIM = 200,
  Platform_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Platform_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Platform_IsValid(int value);
const Platform Platform_MIN = PLATFORM_UNKNOWN;
const Platform Platform_MAX = PLATFORM_SIM;
const int Platform_ARRAYSIZE = Platform_MAX + 1;

const ::google::protobuf::EnumDescriptor* Platform_descriptor();
inline const ::std::string& Platform_Name(Platform value) {
  return ::google::protobuf::internal::NameOfEnum(
    Platform_descriptor(), value);
}
inline bool Platform_Parse(
    const ::std::string& name, Platform* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Platform>(
    Platform_descriptor(), name, value);
}
enum TemperatureUnit {
  TEMP_CELSIUS = 0,
  TEMP_FAHRENHEIT = 1,
  TemperatureUnit_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  TemperatureUnit_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool TemperatureUnit_IsValid(int value);
const TemperatureUnit TemperatureUnit_MIN = TEMP_CELSIUS;
const TemperatureUnit TemperatureUnit_MAX = TEMP_FAHRENHEIT;
const int TemperatureUnit_ARRAYSIZE = TemperatureUnit_MAX + 1;

const ::google::protobuf::EnumDescriptor* TemperatureUnit_descriptor();
inline const ::std::string& TemperatureUnit_Name(TemperatureUnit value) {
  return ::google::protobuf::internal::NameOfEnum(
    TemperatureUnit_descriptor(), value);
}
inline bool TemperatureUnit_Parse(
    const ::std::string& name, TemperatureUnit* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TemperatureUnit>(
    TemperatureUnit_descriptor(), name, value);
}
// ===================================================================

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.SysInfo.Block) */ {
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
    0;

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

  // bytes deviceId = 1 [(.nanopb) = {
  void clear_deviceid();
  static const int kDeviceIdFieldNumber = 1;
  const ::std::string& deviceid() const;
  void set_deviceid(const ::std::string& value);
  #if LANG_CXX11
  void set_deviceid(::std::string&& value);
  #endif
  void set_deviceid(const char* value);
  void set_deviceid(const void* value, size_t size);
  ::std::string* mutable_deviceid();
  ::std::string* release_deviceid();
  void set_allocated_deviceid(::std::string* deviceid);

  // string version = 2 [(.nanopb) = {
  void clear_version();
  static const int kVersionFieldNumber = 2;
  const ::std::string& version() const;
  void set_version(const ::std::string& value);
  #if LANG_CXX11
  void set_version(::std::string&& value);
  #endif
  void set_version(const char* value);
  void set_version(const char* value, size_t size);
  ::std::string* mutable_version();
  ::std::string* release_version();
  void set_allocated_version(::std::string* version);

  // string protocolVersion = 7 [(.nanopb) = {
  void clear_protocolversion();
  static const int kProtocolVersionFieldNumber = 7;
  const ::std::string& protocolversion() const;
  void set_protocolversion(const ::std::string& value);
  #if LANG_CXX11
  void set_protocolversion(::std::string&& value);
  #endif
  void set_protocolversion(const char* value);
  void set_protocolversion(const char* value, size_t size);
  ::std::string* mutable_protocolversion();
  ::std::string* release_protocolversion();
  void set_allocated_protocolversion(::std::string* protocolversion);

  // string releaseDate = 8 [(.nanopb) = {
  void clear_releasedate();
  static const int kReleaseDateFieldNumber = 8;
  const ::std::string& releasedate() const;
  void set_releasedate(const ::std::string& value);
  #if LANG_CXX11
  void set_releasedate(::std::string&& value);
  #endif
  void set_releasedate(const char* value);
  void set_releasedate(const char* value, size_t size);
  ::std::string* mutable_releasedate();
  ::std::string* release_releasedate();
  void set_allocated_releasedate(::std::string* releasedate);

  // string protocolDate = 9 [(.nanopb) = {
  void clear_protocoldate();
  static const int kProtocolDateFieldNumber = 9;
  const ::std::string& protocoldate() const;
  void set_protocoldate(const ::std::string& value);
  #if LANG_CXX11
  void set_protocoldate(::std::string&& value);
  #endif
  void set_protocoldate(const char* value);
  void set_protocoldate(const char* value, size_t size);
  ::std::string* mutable_protocoldate();
  ::std::string* release_protocoldate();
  void set_allocated_protocoldate(::std::string* protocoldate);

  // string timeZone = 14 [(.nanopb) = {
  void clear_timezone();
  static const int kTimeZoneFieldNumber = 14;
  const ::std::string& timezone() const;
  void set_timezone(const ::std::string& value);
  #if LANG_CXX11
  void set_timezone(::std::string&& value);
  #endif
  void set_timezone(const char* value);
  void set_timezone(const char* value, size_t size);
  ::std::string* mutable_timezone();
  ::std::string* release_timezone();
  void set_allocated_timezone(::std::string* timezone);

  // .blox_test.SysInfo.Platform platform = 3 [(.brewblox.field) = {
  void clear_platform();
  static const int kPlatformFieldNumber = 3;
  ::blox_test::SysInfo::Platform platform() const;
  void set_platform(::blox_test::SysInfo::Platform value);

  // uint32 ip = 10 [(.nanopb) = {
  void clear_ip();
  static const int kIpFieldNumber = 10;
  ::google::protobuf::uint32 ip() const;
  void set_ip(::google::protobuf::uint32 value);

  // uint32 uptime = 11 [(.nanopb) = {
  void clear_uptime();
  static const int kUptimeFieldNumber = 11;
  ::google::protobuf::uint32 uptime() const;
  void set_uptime(::google::protobuf::uint32 value);

  // uint32 updatesPerSecond = 12 [(.nanopb) = {
  void clear_updatespersecond();
  static const int kUpdatesPerSecondFieldNumber = 12;
  ::google::protobuf::uint32 updatespersecond() const;
  void set_updatespersecond(::google::protobuf::uint32 value);

  // uint32 systemTime = 13 [(.nanopb) = {
  void clear_systemtime();
  static const int kSystemTimeFieldNumber = 13;
  ::google::protobuf::uint32 systemtime() const;
  void set_systemtime(::google::protobuf::uint32 value);

  // .blox_test.SysInfo.TemperatureUnit tempUnit = 15;
  void clear_tempunit();
  static const int kTempUnitFieldNumber = 15;
  ::blox_test::SysInfo::TemperatureUnit tempunit() const;
  void set_tempunit(::blox_test::SysInfo::TemperatureUnit value);

  // uint32 displayBrightness = 16 [(.nanopb) = {
  void clear_displaybrightness();
  static const int kDisplayBrightnessFieldNumber = 16;
  ::google::protobuf::uint32 displaybrightness() const;
  void set_displaybrightness(::google::protobuf::uint32 value);

  // bool command = 90 [(.nanopb) = {
  void clear_command();
  static const int kCommandFieldNumber = 90;
  bool command() const;
  void set_command(bool value);

  // @@protoc_insertion_point(class_scope:blox_test.SysInfo.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr deviceid_;
  ::google::protobuf::internal::ArenaStringPtr version_;
  ::google::protobuf::internal::ArenaStringPtr protocolversion_;
  ::google::protobuf::internal::ArenaStringPtr releasedate_;
  ::google::protobuf::internal::ArenaStringPtr protocoldate_;
  ::google::protobuf::internal::ArenaStringPtr timezone_;
  int platform_;
  ::google::protobuf::uint32 ip_;
  ::google::protobuf::uint32 uptime_;
  ::google::protobuf::uint32 updatespersecond_;
  ::google::protobuf::uint32 systemtime_;
  int tempunit_;
  ::google::protobuf::uint32 displaybrightness_;
  bool command_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SysInfo_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// bytes deviceId = 1 [(.nanopb) = {
inline void Block::clear_deviceid() {
  deviceid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::deviceid() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.deviceId)
  return deviceid_.GetNoArena();
}
inline void Block::set_deviceid(const ::std::string& value) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.deviceId)
}
#if LANG_CXX11
inline void Block::set_deviceid(::std::string&& value) {
  
  deviceid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.deviceId)
}
#endif
inline void Block::set_deviceid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.deviceId)
}
inline void Block::set_deviceid(const void* value, size_t size) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.deviceId)
}
inline ::std::string* Block::mutable_deviceid() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.deviceId)
  return deviceid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_deviceid() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.deviceId)
  
  return deviceid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_deviceid(::std::string* deviceid) {
  if (deviceid != NULL) {
    
  } else {
    
  }
  deviceid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), deviceid);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.deviceId)
}

// string version = 2 [(.nanopb) = {
inline void Block::clear_version() {
  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::version() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.version)
  return version_.GetNoArena();
}
inline void Block::set_version(const ::std::string& value) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.version)
}
#if LANG_CXX11
inline void Block::set_version(::std::string&& value) {
  
  version_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.version)
}
#endif
inline void Block::set_version(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.version)
}
inline void Block::set_version(const char* value, size_t size) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.version)
}
inline ::std::string* Block::mutable_version() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.version)
  return version_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_version() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.version)
  
  return version_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_version(::std::string* version) {
  if (version != NULL) {
    
  } else {
    
  }
  version_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), version);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.version)
}

// .blox_test.SysInfo.Platform platform = 3 [(.brewblox.field) = {
inline void Block::clear_platform() {
  platform_ = 0;
}
inline ::blox_test::SysInfo::Platform Block::platform() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.platform)
  return static_cast< ::blox_test::SysInfo::Platform >(platform_);
}
inline void Block::set_platform(::blox_test::SysInfo::Platform value) {
  
  platform_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.platform)
}

// string protocolVersion = 7 [(.nanopb) = {
inline void Block::clear_protocolversion() {
  protocolversion_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::protocolversion() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.protocolVersion)
  return protocolversion_.GetNoArena();
}
inline void Block::set_protocolversion(const ::std::string& value) {
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.protocolVersion)
}
#if LANG_CXX11
inline void Block::set_protocolversion(::std::string&& value) {
  
  protocolversion_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.protocolVersion)
}
#endif
inline void Block::set_protocolversion(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.protocolVersion)
}
inline void Block::set_protocolversion(const char* value, size_t size) {
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.protocolVersion)
}
inline ::std::string* Block::mutable_protocolversion() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.protocolVersion)
  return protocolversion_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_protocolversion() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.protocolVersion)
  
  return protocolversion_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_protocolversion(::std::string* protocolversion) {
  if (protocolversion != NULL) {
    
  } else {
    
  }
  protocolversion_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), protocolversion);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.protocolVersion)
}

// string releaseDate = 8 [(.nanopb) = {
inline void Block::clear_releasedate() {
  releasedate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::releasedate() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.releaseDate)
  return releasedate_.GetNoArena();
}
inline void Block::set_releasedate(const ::std::string& value) {
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.releaseDate)
}
#if LANG_CXX11
inline void Block::set_releasedate(::std::string&& value) {
  
  releasedate_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.releaseDate)
}
#endif
inline void Block::set_releasedate(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.releaseDate)
}
inline void Block::set_releasedate(const char* value, size_t size) {
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.releaseDate)
}
inline ::std::string* Block::mutable_releasedate() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.releaseDate)
  return releasedate_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_releasedate() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.releaseDate)
  
  return releasedate_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_releasedate(::std::string* releasedate) {
  if (releasedate != NULL) {
    
  } else {
    
  }
  releasedate_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), releasedate);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.releaseDate)
}

// string protocolDate = 9 [(.nanopb) = {
inline void Block::clear_protocoldate() {
  protocoldate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::protocoldate() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.protocolDate)
  return protocoldate_.GetNoArena();
}
inline void Block::set_protocoldate(const ::std::string& value) {
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.protocolDate)
}
#if LANG_CXX11
inline void Block::set_protocoldate(::std::string&& value) {
  
  protocoldate_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.protocolDate)
}
#endif
inline void Block::set_protocoldate(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.protocolDate)
}
inline void Block::set_protocoldate(const char* value, size_t size) {
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.protocolDate)
}
inline ::std::string* Block::mutable_protocoldate() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.protocolDate)
  return protocoldate_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_protocoldate() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.protocolDate)
  
  return protocoldate_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_protocoldate(::std::string* protocoldate) {
  if (protocoldate != NULL) {
    
  } else {
    
  }
  protocoldate_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), protocoldate);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.protocolDate)
}

// uint32 ip = 10 [(.nanopb) = {
inline void Block::clear_ip() {
  ip_ = 0u;
}
inline ::google::protobuf::uint32 Block::ip() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.ip)
  return ip_;
}
inline void Block::set_ip(::google::protobuf::uint32 value) {
  
  ip_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.ip)
}

// uint32 uptime = 11 [(.nanopb) = {
inline void Block::clear_uptime() {
  uptime_ = 0u;
}
inline ::google::protobuf::uint32 Block::uptime() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.uptime)
  return uptime_;
}
inline void Block::set_uptime(::google::protobuf::uint32 value) {
  
  uptime_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.uptime)
}

// uint32 updatesPerSecond = 12 [(.nanopb) = {
inline void Block::clear_updatespersecond() {
  updatespersecond_ = 0u;
}
inline ::google::protobuf::uint32 Block::updatespersecond() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.updatesPerSecond)
  return updatespersecond_;
}
inline void Block::set_updatespersecond(::google::protobuf::uint32 value) {
  
  updatespersecond_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.updatesPerSecond)
}

// uint32 systemTime = 13 [(.nanopb) = {
inline void Block::clear_systemtime() {
  systemtime_ = 0u;
}
inline ::google::protobuf::uint32 Block::systemtime() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.systemTime)
  return systemtime_;
}
inline void Block::set_systemtime(::google::protobuf::uint32 value) {
  
  systemtime_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.systemTime)
}

// string timeZone = 14 [(.nanopb) = {
inline void Block::clear_timezone() {
  timezone_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::timezone() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.timeZone)
  return timezone_.GetNoArena();
}
inline void Block::set_timezone(const ::std::string& value) {
  
  timezone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.timeZone)
}
#if LANG_CXX11
inline void Block::set_timezone(::std::string&& value) {
  
  timezone_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.SysInfo.Block.timeZone)
}
#endif
inline void Block::set_timezone(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  timezone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.SysInfo.Block.timeZone)
}
inline void Block::set_timezone(const char* value, size_t size) {
  
  timezone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.SysInfo.Block.timeZone)
}
inline ::std::string* Block::mutable_timezone() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.SysInfo.Block.timeZone)
  return timezone_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_timezone() {
  // @@protoc_insertion_point(field_release:blox_test.SysInfo.Block.timeZone)
  
  return timezone_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_timezone(::std::string* timezone) {
  if (timezone != NULL) {
    
  } else {
    
  }
  timezone_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), timezone);
  // @@protoc_insertion_point(field_set_allocated:blox_test.SysInfo.Block.timeZone)
}

// .blox_test.SysInfo.TemperatureUnit tempUnit = 15;
inline void Block::clear_tempunit() {
  tempunit_ = 0;
}
inline ::blox_test::SysInfo::TemperatureUnit Block::tempunit() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.tempUnit)
  return static_cast< ::blox_test::SysInfo::TemperatureUnit >(tempunit_);
}
inline void Block::set_tempunit(::blox_test::SysInfo::TemperatureUnit value) {
  
  tempunit_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.tempUnit)
}

// uint32 displayBrightness = 16 [(.nanopb) = {
inline void Block::clear_displaybrightness() {
  displaybrightness_ = 0u;
}
inline ::google::protobuf::uint32 Block::displaybrightness() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.displayBrightness)
  return displaybrightness_;
}
inline void Block::set_displaybrightness(::google::protobuf::uint32 value) {
  
  displaybrightness_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.displayBrightness)
}

// bool command = 90 [(.nanopb) = {
inline void Block::clear_command() {
  command_ = false;
}
inline bool Block::command() const {
  // @@protoc_insertion_point(field_get:blox_test.SysInfo.Block.command)
  return command_;
}
inline void Block::set_command(bool value) {
  
  command_ = value;
  // @@protoc_insertion_point(field_set:blox_test.SysInfo.Block.command)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace SysInfo
}  // namespace blox_test

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox_test::SysInfo::Platform> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::SysInfo::Platform>() {
  return ::blox_test::SysInfo::Platform_descriptor();
}
template <> struct is_proto_enum< ::blox_test::SysInfo::TemperatureUnit> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::SysInfo::TemperatureUnit>() {
  return ::blox_test::SysInfo::TemperatureUnit_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_SysInfo_5ftest_2eproto
