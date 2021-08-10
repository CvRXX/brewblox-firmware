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
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_SysInfo_5ftest_2eproto
namespace blox {
class SysInfo;
class SysInfoDefaultTypeInternal;
extern SysInfoDefaultTypeInternal _SysInfo_default_instance_;
class Trace;
class TraceDefaultTypeInternal;
extern TraceDefaultTypeInternal _Trace_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::SysInfo* Arena::CreateMaybeMessage<::blox::SysInfo>(Arena*);
template<> ::blox::Trace* Arena::CreateMaybeMessage<::blox::Trace>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

enum Trace_Action {
  Trace_Action_NONE = 0,
  Trace_Action_READ_OBJECT = 1,
  Trace_Action_WRITE_OBJECT = 2,
  Trace_Action_CREATE_OBJECT = 3,
  Trace_Action_DELETE_OBJECT = 4,
  Trace_Action_LIST_ACTIVE_OBJECTS = 5,
  Trace_Action_READ_STORED_OBJECT = 6,
  Trace_Action_LIST_STORED_OBJECTS = 7,
  Trace_Action_CLEAR_OBJECTS = 8,
  Trace_Action_REBOOT = 9,
  Trace_Action_FACTORY_RESET = 10,
  Trace_Action_LIST_COMPATIBLE_OBJECTS = 11,
  Trace_Action_DISCOVER_NEW_OBJECTS = 12,
  Trace_Action_CONSTRUCT_OBJECT = 20,
  Trace_Action_DESTRUCT_OBJECT = 21,
  Trace_Action_STREAM_FROM_OBJECT = 22,
  Trace_Action_STREAM_TO_OBJECT = 23,
  Trace_Action_UPDATE_OBJECT = 24,
  Trace_Action_PERSIST_OBJECT = 25,
  Trace_Action_LOAD_STORED_OBJECT = 26,
  Trace_Action_UPDATE_OBJECTS = 27,
  Trace_Action_UPDATE_CONNECTIONS = 28,
  Trace_Action_UPDATE_DISPLAY = 101,
  Trace_Action_SYSTEM_TASKS = 102,
  Trace_Action_MANAGE_CONNECTIVITY = 103,
  Trace_Action_MDNS_START = 104,
  Trace_Action_MDNS_PROCESS = 105,
  Trace_Action_HTTP_START = 106,
  Trace_Action_HTTP_STOP = 107,
  Trace_Action_HTTP_RESPONSE = 108,
  Trace_Action_WIFI_CONNECT = 109,
  Trace_Action_FIRMWARE_UPDATE_STARTED = 110,
  Trace_Action_Trace_Action_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Trace_Action_Trace_Action_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Trace_Action_IsValid(int value);
const Trace_Action Trace_Action_Action_MIN = Trace_Action_NONE;
const Trace_Action Trace_Action_Action_MAX = Trace_Action_FIRMWARE_UPDATE_STARTED;
const int Trace_Action_Action_ARRAYSIZE = Trace_Action_Action_MAX + 1;

const ::google::protobuf::EnumDescriptor* Trace_Action_descriptor();
inline const ::std::string& Trace_Action_Name(Trace_Action value) {
  return ::google::protobuf::internal::NameOfEnum(
    Trace_Action_descriptor(), value);
}
inline bool Trace_Action_Parse(
    const ::std::string& name, Trace_Action* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Trace_Action>(
    Trace_Action_descriptor(), name, value);
}
enum SysInfo_Platform {
  SysInfo_Platform_PLATFORM_UNKNOWN = 0,
  SysInfo_Platform_PLATFORM_GCC = 3,
  SysInfo_Platform_PLATFORM_PHOTON = 6,
  SysInfo_Platform_PLATFORM_P1 = 8,
  SysInfo_Platform_SysInfo_Platform_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SysInfo_Platform_SysInfo_Platform_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SysInfo_Platform_IsValid(int value);
const SysInfo_Platform SysInfo_Platform_Platform_MIN = SysInfo_Platform_PLATFORM_UNKNOWN;
const SysInfo_Platform SysInfo_Platform_Platform_MAX = SysInfo_Platform_PLATFORM_P1;
const int SysInfo_Platform_Platform_ARRAYSIZE = SysInfo_Platform_Platform_MAX + 1;

const ::google::protobuf::EnumDescriptor* SysInfo_Platform_descriptor();
inline const ::std::string& SysInfo_Platform_Name(SysInfo_Platform value) {
  return ::google::protobuf::internal::NameOfEnum(
    SysInfo_Platform_descriptor(), value);
}
inline bool SysInfo_Platform_Parse(
    const ::std::string& name, SysInfo_Platform* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SysInfo_Platform>(
    SysInfo_Platform_descriptor(), name, value);
}
enum SysInfo_SysInfoCommand {
  SysInfo_SysInfoCommand_SYS_CMD_NONE = 0,
  SysInfo_SysInfoCommand_SYS_CMD_TRACE_READ = 1,
  SysInfo_SysInfoCommand_SYS_CMD_TRACE_RESUME = 2,
  SysInfo_SysInfoCommand_SYS_CMD_TRACE_READ_RESUME = 3,
  SysInfo_SysInfoCommand_SysInfo_SysInfoCommand_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SysInfo_SysInfoCommand_SysInfo_SysInfoCommand_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SysInfo_SysInfoCommand_IsValid(int value);
const SysInfo_SysInfoCommand SysInfo_SysInfoCommand_SysInfoCommand_MIN = SysInfo_SysInfoCommand_SYS_CMD_NONE;
const SysInfo_SysInfoCommand SysInfo_SysInfoCommand_SysInfoCommand_MAX = SysInfo_SysInfoCommand_SYS_CMD_TRACE_READ_RESUME;
const int SysInfo_SysInfoCommand_SysInfoCommand_ARRAYSIZE = SysInfo_SysInfoCommand_SysInfoCommand_MAX + 1;

const ::google::protobuf::EnumDescriptor* SysInfo_SysInfoCommand_descriptor();
inline const ::std::string& SysInfo_SysInfoCommand_Name(SysInfo_SysInfoCommand value) {
  return ::google::protobuf::internal::NameOfEnum(
    SysInfo_SysInfoCommand_descriptor(), value);
}
inline bool SysInfo_SysInfoCommand_Parse(
    const ::std::string& name, SysInfo_SysInfoCommand* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SysInfo_SysInfoCommand>(
    SysInfo_SysInfoCommand_descriptor(), name, value);
}
// ===================================================================

class Trace : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Trace) */ {
 public:
  Trace();
  virtual ~Trace();

  Trace(const Trace& from);

  inline Trace& operator=(const Trace& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Trace(Trace&& from) noexcept
    : Trace() {
    *this = ::std::move(from);
  }

  inline Trace& operator=(Trace&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Trace& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Trace* internal_default_instance() {
    return reinterpret_cast<const Trace*>(
               &_Trace_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Trace* other);
  friend void swap(Trace& a, Trace& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Trace* New() const final {
    return CreateMaybeMessage<Trace>(NULL);
  }

  Trace* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Trace>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Trace& from);
  void MergeFrom(const Trace& from);
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
  void InternalSwap(Trace* other);
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

  typedef Trace_Action Action;
  static const Action NONE =
    Trace_Action_NONE;
  static const Action READ_OBJECT =
    Trace_Action_READ_OBJECT;
  static const Action WRITE_OBJECT =
    Trace_Action_WRITE_OBJECT;
  static const Action CREATE_OBJECT =
    Trace_Action_CREATE_OBJECT;
  static const Action DELETE_OBJECT =
    Trace_Action_DELETE_OBJECT;
  static const Action LIST_ACTIVE_OBJECTS =
    Trace_Action_LIST_ACTIVE_OBJECTS;
  static const Action READ_STORED_OBJECT =
    Trace_Action_READ_STORED_OBJECT;
  static const Action LIST_STORED_OBJECTS =
    Trace_Action_LIST_STORED_OBJECTS;
  static const Action CLEAR_OBJECTS =
    Trace_Action_CLEAR_OBJECTS;
  static const Action REBOOT =
    Trace_Action_REBOOT;
  static const Action FACTORY_RESET =
    Trace_Action_FACTORY_RESET;
  static const Action LIST_COMPATIBLE_OBJECTS =
    Trace_Action_LIST_COMPATIBLE_OBJECTS;
  static const Action DISCOVER_NEW_OBJECTS =
    Trace_Action_DISCOVER_NEW_OBJECTS;
  static const Action CONSTRUCT_OBJECT =
    Trace_Action_CONSTRUCT_OBJECT;
  static const Action DESTRUCT_OBJECT =
    Trace_Action_DESTRUCT_OBJECT;
  static const Action STREAM_FROM_OBJECT =
    Trace_Action_STREAM_FROM_OBJECT;
  static const Action STREAM_TO_OBJECT =
    Trace_Action_STREAM_TO_OBJECT;
  static const Action UPDATE_OBJECT =
    Trace_Action_UPDATE_OBJECT;
  static const Action PERSIST_OBJECT =
    Trace_Action_PERSIST_OBJECT;
  static const Action LOAD_STORED_OBJECT =
    Trace_Action_LOAD_STORED_OBJECT;
  static const Action UPDATE_OBJECTS =
    Trace_Action_UPDATE_OBJECTS;
  static const Action UPDATE_CONNECTIONS =
    Trace_Action_UPDATE_CONNECTIONS;
  static const Action UPDATE_DISPLAY =
    Trace_Action_UPDATE_DISPLAY;
  static const Action SYSTEM_TASKS =
    Trace_Action_SYSTEM_TASKS;
  static const Action MANAGE_CONNECTIVITY =
    Trace_Action_MANAGE_CONNECTIVITY;
  static const Action MDNS_START =
    Trace_Action_MDNS_START;
  static const Action MDNS_PROCESS =
    Trace_Action_MDNS_PROCESS;
  static const Action HTTP_START =
    Trace_Action_HTTP_START;
  static const Action HTTP_STOP =
    Trace_Action_HTTP_STOP;
  static const Action HTTP_RESPONSE =
    Trace_Action_HTTP_RESPONSE;
  static const Action WIFI_CONNECT =
    Trace_Action_WIFI_CONNECT;
  static const Action FIRMWARE_UPDATE_STARTED =
    Trace_Action_FIRMWARE_UPDATE_STARTED;
  static inline bool Action_IsValid(int value) {
    return Trace_Action_IsValid(value);
  }
  static const Action Action_MIN =
    Trace_Action_Action_MIN;
  static const Action Action_MAX =
    Trace_Action_Action_MAX;
  static const int Action_ARRAYSIZE =
    Trace_Action_Action_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Action_descriptor() {
    return Trace_Action_descriptor();
  }
  static inline const ::std::string& Action_Name(Action value) {
    return Trace_Action_Name(value);
  }
  static inline bool Action_Parse(const ::std::string& name,
      Action* value) {
    return Trace_Action_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // .blox.Trace.Action action = 1;
  void clear_action();
  static const int kActionFieldNumber = 1;
  ::blox::Trace_Action action() const;
  void set_action(::blox::Trace_Action value);

  // uint32 id = 2 [(.nanopb_test) = {
  void clear_id();
  static const int kIdFieldNumber = 2;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // uint32 type = 3 [(.nanopb_test) = {
  void clear_type();
  static const int kTypeFieldNumber = 3;
  ::google::protobuf::uint32 type() const;
  void set_type(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.Trace)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int action_;
  ::google::protobuf::uint32 id_;
  ::google::protobuf::uint32 type_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SysInfo_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SysInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.SysInfo) */ {
 public:
  SysInfo();
  virtual ~SysInfo();

  SysInfo(const SysInfo& from);

  inline SysInfo& operator=(const SysInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SysInfo(SysInfo&& from) noexcept
    : SysInfo() {
    *this = ::std::move(from);
  }

  inline SysInfo& operator=(SysInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SysInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SysInfo* internal_default_instance() {
    return reinterpret_cast<const SysInfo*>(
               &_SysInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SysInfo* other);
  friend void swap(SysInfo& a, SysInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SysInfo* New() const final {
    return CreateMaybeMessage<SysInfo>(NULL);
  }

  SysInfo* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SysInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SysInfo& from);
  void MergeFrom(const SysInfo& from);
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
  void InternalSwap(SysInfo* other);
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

  typedef SysInfo_Platform Platform;
  static const Platform PLATFORM_UNKNOWN =
    SysInfo_Platform_PLATFORM_UNKNOWN;
  static const Platform PLATFORM_GCC =
    SysInfo_Platform_PLATFORM_GCC;
  static const Platform PLATFORM_PHOTON =
    SysInfo_Platform_PLATFORM_PHOTON;
  static const Platform PLATFORM_P1 =
    SysInfo_Platform_PLATFORM_P1;
  static inline bool Platform_IsValid(int value) {
    return SysInfo_Platform_IsValid(value);
  }
  static const Platform Platform_MIN =
    SysInfo_Platform_Platform_MIN;
  static const Platform Platform_MAX =
    SysInfo_Platform_Platform_MAX;
  static const int Platform_ARRAYSIZE =
    SysInfo_Platform_Platform_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Platform_descriptor() {
    return SysInfo_Platform_descriptor();
  }
  static inline const ::std::string& Platform_Name(Platform value) {
    return SysInfo_Platform_Name(value);
  }
  static inline bool Platform_Parse(const ::std::string& name,
      Platform* value) {
    return SysInfo_Platform_Parse(name, value);
  }

  typedef SysInfo_SysInfoCommand SysInfoCommand;
  static const SysInfoCommand SYS_CMD_NONE =
    SysInfo_SysInfoCommand_SYS_CMD_NONE;
  static const SysInfoCommand SYS_CMD_TRACE_READ =
    SysInfo_SysInfoCommand_SYS_CMD_TRACE_READ;
  static const SysInfoCommand SYS_CMD_TRACE_RESUME =
    SysInfo_SysInfoCommand_SYS_CMD_TRACE_RESUME;
  static const SysInfoCommand SYS_CMD_TRACE_READ_RESUME =
    SysInfo_SysInfoCommand_SYS_CMD_TRACE_READ_RESUME;
  static inline bool SysInfoCommand_IsValid(int value) {
    return SysInfo_SysInfoCommand_IsValid(value);
  }
  static const SysInfoCommand SysInfoCommand_MIN =
    SysInfo_SysInfoCommand_SysInfoCommand_MIN;
  static const SysInfoCommand SysInfoCommand_MAX =
    SysInfo_SysInfoCommand_SysInfoCommand_MAX;
  static const int SysInfoCommand_ARRAYSIZE =
    SysInfo_SysInfoCommand_SysInfoCommand_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  SysInfoCommand_descriptor() {
    return SysInfo_SysInfoCommand_descriptor();
  }
  static inline const ::std::string& SysInfoCommand_Name(SysInfoCommand value) {
    return SysInfo_SysInfoCommand_Name(value);
  }
  static inline bool SysInfoCommand_Parse(const ::std::string& name,
      SysInfoCommand* value) {
    return SysInfo_SysInfoCommand_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // repeated .blox.Trace trace = 11 [(.nanopb_test) = {
  int trace_size() const;
  void clear_trace();
  static const int kTraceFieldNumber = 11;
  ::blox::Trace* mutable_trace(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::Trace >*
      mutable_trace();
  const ::blox::Trace& trace(int index) const;
  ::blox::Trace* add_trace();
  const ::google::protobuf::RepeatedPtrField< ::blox::Trace >&
      trace() const;

  // bytes deviceId = 1 [(.nanopb_test) = {
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

  // string version = 2 [(.nanopb_test) = {
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

  // string protocolVersion = 7 [(.nanopb_test) = {
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

  // string releaseDate = 8 [(.nanopb_test) = {
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

  // string protocolDate = 9 [(.nanopb_test) = {
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

  // .blox.SysInfo.Platform platform = 3 [(.brewblox_test) = {
  void clear_platform();
  static const int kPlatformFieldNumber = 3;
  ::blox::SysInfo_Platform platform() const;
  void set_platform(::blox::SysInfo_Platform value);

  // .blox.SysInfo.SysInfoCommand command = 10;
  void clear_command();
  static const int kCommandFieldNumber = 10;
  ::blox::SysInfo_SysInfoCommand command() const;
  void set_command(::blox::SysInfo_SysInfoCommand value);

  // @@protoc_insertion_point(class_scope:blox.SysInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::Trace > trace_;
  ::google::protobuf::internal::ArenaStringPtr deviceid_;
  ::google::protobuf::internal::ArenaStringPtr version_;
  ::google::protobuf::internal::ArenaStringPtr protocolversion_;
  ::google::protobuf::internal::ArenaStringPtr releasedate_;
  ::google::protobuf::internal::ArenaStringPtr protocoldate_;
  int platform_;
  int command_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_SysInfo_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Trace

// .blox.Trace.Action action = 1;
inline void Trace::clear_action() {
  action_ = 0;
}
inline ::blox::Trace_Action Trace::action() const {
  // @@protoc_insertion_point(field_get:blox.Trace.action)
  return static_cast< ::blox::Trace_Action >(action_);
}
inline void Trace::set_action(::blox::Trace_Action value) {
  
  action_ = value;
  // @@protoc_insertion_point(field_set:blox.Trace.action)
}

// uint32 id = 2 [(.nanopb_test) = {
inline void Trace::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 Trace::id() const {
  // @@protoc_insertion_point(field_get:blox.Trace.id)
  return id_;
}
inline void Trace::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox.Trace.id)
}

// uint32 type = 3 [(.nanopb_test) = {
inline void Trace::clear_type() {
  type_ = 0u;
}
inline ::google::protobuf::uint32 Trace::type() const {
  // @@protoc_insertion_point(field_get:blox.Trace.type)
  return type_;
}
inline void Trace::set_type(::google::protobuf::uint32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:blox.Trace.type)
}

// -------------------------------------------------------------------

// SysInfo

// bytes deviceId = 1 [(.nanopb_test) = {
inline void SysInfo::clear_deviceid() {
  deviceid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SysInfo::deviceid() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.deviceId)
  return deviceid_.GetNoArena();
}
inline void SysInfo::set_deviceid(const ::std::string& value) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox.SysInfo.deviceId)
}
#if LANG_CXX11
inline void SysInfo::set_deviceid(::std::string&& value) {
  
  deviceid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox.SysInfo.deviceId)
}
#endif
inline void SysInfo::set_deviceid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox.SysInfo.deviceId)
}
inline void SysInfo::set_deviceid(const void* value, size_t size) {
  
  deviceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox.SysInfo.deviceId)
}
inline ::std::string* SysInfo::mutable_deviceid() {
  
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.deviceId)
  return deviceid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SysInfo::release_deviceid() {
  // @@protoc_insertion_point(field_release:blox.SysInfo.deviceId)
  
  return deviceid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SysInfo::set_allocated_deviceid(::std::string* deviceid) {
  if (deviceid != NULL) {
    
  } else {
    
  }
  deviceid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), deviceid);
  // @@protoc_insertion_point(field_set_allocated:blox.SysInfo.deviceId)
}

// string version = 2 [(.nanopb_test) = {
inline void SysInfo::clear_version() {
  version_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SysInfo::version() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.version)
  return version_.GetNoArena();
}
inline void SysInfo::set_version(const ::std::string& value) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox.SysInfo.version)
}
#if LANG_CXX11
inline void SysInfo::set_version(::std::string&& value) {
  
  version_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox.SysInfo.version)
}
#endif
inline void SysInfo::set_version(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox.SysInfo.version)
}
inline void SysInfo::set_version(const char* value, size_t size) {
  
  version_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox.SysInfo.version)
}
inline ::std::string* SysInfo::mutable_version() {
  
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.version)
  return version_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SysInfo::release_version() {
  // @@protoc_insertion_point(field_release:blox.SysInfo.version)
  
  return version_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SysInfo::set_allocated_version(::std::string* version) {
  if (version != NULL) {
    
  } else {
    
  }
  version_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), version);
  // @@protoc_insertion_point(field_set_allocated:blox.SysInfo.version)
}

// .blox.SysInfo.Platform platform = 3 [(.brewblox_test) = {
inline void SysInfo::clear_platform() {
  platform_ = 0;
}
inline ::blox::SysInfo_Platform SysInfo::platform() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.platform)
  return static_cast< ::blox::SysInfo_Platform >(platform_);
}
inline void SysInfo::set_platform(::blox::SysInfo_Platform value) {
  
  platform_ = value;
  // @@protoc_insertion_point(field_set:blox.SysInfo.platform)
}

// string protocolVersion = 7 [(.nanopb_test) = {
inline void SysInfo::clear_protocolversion() {
  protocolversion_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SysInfo::protocolversion() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.protocolVersion)
  return protocolversion_.GetNoArena();
}
inline void SysInfo::set_protocolversion(const ::std::string& value) {
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox.SysInfo.protocolVersion)
}
#if LANG_CXX11
inline void SysInfo::set_protocolversion(::std::string&& value) {
  
  protocolversion_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox.SysInfo.protocolVersion)
}
#endif
inline void SysInfo::set_protocolversion(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox.SysInfo.protocolVersion)
}
inline void SysInfo::set_protocolversion(const char* value, size_t size) {
  
  protocolversion_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox.SysInfo.protocolVersion)
}
inline ::std::string* SysInfo::mutable_protocolversion() {
  
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.protocolVersion)
  return protocolversion_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SysInfo::release_protocolversion() {
  // @@protoc_insertion_point(field_release:blox.SysInfo.protocolVersion)
  
  return protocolversion_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SysInfo::set_allocated_protocolversion(::std::string* protocolversion) {
  if (protocolversion != NULL) {
    
  } else {
    
  }
  protocolversion_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), protocolversion);
  // @@protoc_insertion_point(field_set_allocated:blox.SysInfo.protocolVersion)
}

// string releaseDate = 8 [(.nanopb_test) = {
inline void SysInfo::clear_releasedate() {
  releasedate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SysInfo::releasedate() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.releaseDate)
  return releasedate_.GetNoArena();
}
inline void SysInfo::set_releasedate(const ::std::string& value) {
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox.SysInfo.releaseDate)
}
#if LANG_CXX11
inline void SysInfo::set_releasedate(::std::string&& value) {
  
  releasedate_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox.SysInfo.releaseDate)
}
#endif
inline void SysInfo::set_releasedate(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox.SysInfo.releaseDate)
}
inline void SysInfo::set_releasedate(const char* value, size_t size) {
  
  releasedate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox.SysInfo.releaseDate)
}
inline ::std::string* SysInfo::mutable_releasedate() {
  
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.releaseDate)
  return releasedate_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SysInfo::release_releasedate() {
  // @@protoc_insertion_point(field_release:blox.SysInfo.releaseDate)
  
  return releasedate_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SysInfo::set_allocated_releasedate(::std::string* releasedate) {
  if (releasedate != NULL) {
    
  } else {
    
  }
  releasedate_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), releasedate);
  // @@protoc_insertion_point(field_set_allocated:blox.SysInfo.releaseDate)
}

// string protocolDate = 9 [(.nanopb_test) = {
inline void SysInfo::clear_protocoldate() {
  protocoldate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SysInfo::protocoldate() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.protocolDate)
  return protocoldate_.GetNoArena();
}
inline void SysInfo::set_protocoldate(const ::std::string& value) {
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox.SysInfo.protocolDate)
}
#if LANG_CXX11
inline void SysInfo::set_protocoldate(::std::string&& value) {
  
  protocoldate_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox.SysInfo.protocolDate)
}
#endif
inline void SysInfo::set_protocoldate(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox.SysInfo.protocolDate)
}
inline void SysInfo::set_protocoldate(const char* value, size_t size) {
  
  protocoldate_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox.SysInfo.protocolDate)
}
inline ::std::string* SysInfo::mutable_protocoldate() {
  
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.protocolDate)
  return protocoldate_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SysInfo::release_protocoldate() {
  // @@protoc_insertion_point(field_release:blox.SysInfo.protocolDate)
  
  return protocoldate_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SysInfo::set_allocated_protocoldate(::std::string* protocoldate) {
  if (protocoldate != NULL) {
    
  } else {
    
  }
  protocoldate_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), protocoldate);
  // @@protoc_insertion_point(field_set_allocated:blox.SysInfo.protocolDate)
}

// .blox.SysInfo.SysInfoCommand command = 10;
inline void SysInfo::clear_command() {
  command_ = 0;
}
inline ::blox::SysInfo_SysInfoCommand SysInfo::command() const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.command)
  return static_cast< ::blox::SysInfo_SysInfoCommand >(command_);
}
inline void SysInfo::set_command(::blox::SysInfo_SysInfoCommand value) {
  
  command_ = value;
  // @@protoc_insertion_point(field_set:blox.SysInfo.command)
}

// repeated .blox.Trace trace = 11 [(.nanopb_test) = {
inline int SysInfo::trace_size() const {
  return trace_.size();
}
inline void SysInfo::clear_trace() {
  trace_.Clear();
}
inline ::blox::Trace* SysInfo::mutable_trace(int index) {
  // @@protoc_insertion_point(field_mutable:blox.SysInfo.trace)
  return trace_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::Trace >*
SysInfo::mutable_trace() {
  // @@protoc_insertion_point(field_mutable_list:blox.SysInfo.trace)
  return &trace_;
}
inline const ::blox::Trace& SysInfo::trace(int index) const {
  // @@protoc_insertion_point(field_get:blox.SysInfo.trace)
  return trace_.Get(index);
}
inline ::blox::Trace* SysInfo::add_trace() {
  // @@protoc_insertion_point(field_add:blox.SysInfo.trace)
  return trace_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::Trace >&
SysInfo::trace() const {
  // @@protoc_insertion_point(field_list:blox.SysInfo.trace)
  return trace_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox::Trace_Action> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::Trace_Action>() {
  return ::blox::Trace_Action_descriptor();
}
template <> struct is_proto_enum< ::blox::SysInfo_Platform> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::SysInfo_Platform>() {
  return ::blox::SysInfo_Platform_descriptor();
}
template <> struct is_proto_enum< ::blox::SysInfo_SysInfoCommand> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::SysInfo_SysInfoCommand>() {
  return ::blox::SysInfo_SysInfoCommand_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_SysInfo_5ftest_2eproto
