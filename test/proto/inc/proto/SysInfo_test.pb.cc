// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SysInfo_test.proto

#include "SysInfo_test.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace blox_test {
namespace SysInfo {
PROTOBUF_CONSTEXPR Trace::Trace(
    ::_pbi::ConstantInitialized)
  : action_(0)

  , id_(0u)
  , type_(0u){}
struct TraceDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TraceDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TraceDefaultTypeInternal() {}
  union {
    Trace _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TraceDefaultTypeInternal _Trace_default_instance_;
PROTOBUF_CONSTEXPR Block::Block(
    ::_pbi::ConstantInitialized)
  : trace_()
  , deviceid_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , version_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , protocolversion_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , releasedate_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , protocoldate_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , platform_(0)

  , command_(0)
{}
struct BlockDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BlockDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace SysInfo
}  // namespace blox_test
static ::_pb::Metadata file_level_metadata_SysInfo_5ftest_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_SysInfo_5ftest_2eproto[3];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_SysInfo_5ftest_2eproto = nullptr;

const uint32_t TableStruct_SysInfo_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Trace, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Trace, action_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Trace, id_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Trace, type_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, deviceid_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, version_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, platform_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, protocolversion_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, releasedate_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, protocoldate_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, command_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SysInfo::Block, trace_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::blox_test::SysInfo::Trace)},
  { 9, -1, -1, sizeof(::blox_test::SysInfo::Block)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::blox_test::SysInfo::_Trace_default_instance_._instance,
  &::blox_test::SysInfo::_Block_default_instance_._instance,
};

const char descriptor_table_protodef_SysInfo_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022SysInfo_test.proto\022\021blox_test.SysInfo\032"
  "\023brewblox_test.proto\032\021nanopb_test.proto\""
  "\367\005\n\005Trace\022/\n\006action\030\001 \001(\0162\037.blox_test.Sy"
  "sInfo.Trace.Action\022\021\n\002id\030\002 \001(\rB\005\222\?\0028\020\022\023\n"
  "\004type\030\003 \001(\rB\005\222\?\0028\020\"\224\005\n\006Action\022\010\n\004NONE\020\000\022"
  "\017\n\013READ_OBJECT\020\001\022\020\n\014WRITE_OBJECT\020\002\022\021\n\rCR"
  "EATE_OBJECT\020\003\022\021\n\rDELETE_OBJECT\020\004\022\027\n\023LIST"
  "_ACTIVE_OBJECTS\020\005\022\026\n\022READ_STORED_OBJECT\020"
  "\006\022\027\n\023LIST_STORED_OBJECTS\020\007\022\021\n\rCLEAR_OBJE"
  "CTS\020\010\022\n\n\006REBOOT\020\t\022\021\n\rFACTORY_RESET\020\n\022\033\n\027"
  "LIST_COMPATIBLE_OBJECTS\020\013\022\030\n\024DISCOVER_NE"
  "W_OBJECTS\020\014\022\024\n\020CONSTRUCT_OBJECT\020\024\022\023\n\017DES"
  "TRUCT_OBJECT\020\025\022\026\n\022STREAM_FROM_OBJECT\020\026\022\024"
  "\n\020STREAM_TO_OBJECT\020\027\022\021\n\rUPDATE_OBJECT\020\030\022"
  "\022\n\016PERSIST_OBJECT\020\031\022\026\n\022LOAD_STORED_OBJEC"
  "T\020\032\022\022\n\016UPDATE_OBJECTS\020\033\022\026\n\022UPDATE_CONNEC"
  "TIONS\020\034\022\022\n\016UPDATE_DISPLAY\020e\022\020\n\014SYSTEM_TA"
  "SKS\020f\022\027\n\023MANAGE_CONNECTIVITY\020g\022\016\n\nMDNS_S"
  "TART\020h\022\020\n\014MDNS_PROCESS\020i\022\016\n\nHTTP_START\020j"
  "\022\r\n\tHTTP_STOP\020k\022\021\n\rHTTP_RESPONSE\020l\022\020\n\014WI"
  "FI_CONNECT\020m\022\033\n\027FIRMWARE_UPDATE_STARTED\020"
  "n\"\330\002\n\005Block\022#\n\010deviceId\030\001 \001(\014B\021\212\265\030\002(\001\222\?\002"
  "\010\014\212\265\030\0028\001\022\034\n\007version\030\002 \001(\tB\013\212\265\030\002(\001\222\?\002\010\014\0225"
  "\n\010platform\030\003 \001(\0162\033.blox_test.SysInfo.Pla"
  "tformB\006\212\265\030\002(\001\022$\n\017protocolVersion\030\007 \001(\tB\013"
  "\212\265\030\002(\001\222\?\002\010\014\022 \n\013releaseDate\030\010 \001(\tB\013\212\265\030\002(\001"
  "\222\?\002\010\014\022!\n\014protocolDate\030\t \001(\tB\013\212\265\030\002(\001\222\?\002\010\014"
  "\022+\n\007command\030\n \001(\0162\032.blox_test.SysInfo.Co"
  "mmand\0224\n\005trace\030\013 \003(\0132\030.blox_test.SysInfo"
  ".TraceB\013\212\265\030\002(\001\222\?\002\020\n:\007\212\265\030\003\030\200\002*X\n\010Platform"
  "\022\024\n\020PLATFORM_UNKNOWN\020\000\022\020\n\014PLATFORM_GCC\020\003"
  "\022\023\n\017PLATFORM_PHOTON\020\006\022\017\n\013PLATFORM_P1\020\010*l"
  "\n\007Command\022\020\n\014SYS_CMD_NONE\020\000\022\026\n\022SYS_CMD_T"
  "RACE_READ\020\001\022\030\n\024SYS_CMD_TRACE_RESUME\020\002\022\035\n"
  "\031SYS_CMD_TRACE_READ_RESUME\020\003b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_SysInfo_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_SysInfo_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_SysInfo_5ftest_2eproto = {
    false, false, 1396, descriptor_table_protodef_SysInfo_5ftest_2eproto,
    "SysInfo_test.proto",
    &descriptor_table_SysInfo_5ftest_2eproto_once, descriptor_table_SysInfo_5ftest_2eproto_deps, 2, 2,
    schemas, file_default_instances, TableStruct_SysInfo_5ftest_2eproto::offsets,
    file_level_metadata_SysInfo_5ftest_2eproto, file_level_enum_descriptors_SysInfo_5ftest_2eproto,
    file_level_service_descriptors_SysInfo_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_SysInfo_5ftest_2eproto_getter() {
  return &descriptor_table_SysInfo_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_SysInfo_5ftest_2eproto(&descriptor_table_SysInfo_5ftest_2eproto);
namespace blox_test {
namespace SysInfo {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Trace_Action_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_SysInfo_5ftest_2eproto);
  return file_level_enum_descriptors_SysInfo_5ftest_2eproto[0];
}
bool Trace_Action_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Trace_Action Trace::NONE;
constexpr Trace_Action Trace::READ_OBJECT;
constexpr Trace_Action Trace::WRITE_OBJECT;
constexpr Trace_Action Trace::CREATE_OBJECT;
constexpr Trace_Action Trace::DELETE_OBJECT;
constexpr Trace_Action Trace::LIST_ACTIVE_OBJECTS;
constexpr Trace_Action Trace::READ_STORED_OBJECT;
constexpr Trace_Action Trace::LIST_STORED_OBJECTS;
constexpr Trace_Action Trace::CLEAR_OBJECTS;
constexpr Trace_Action Trace::REBOOT;
constexpr Trace_Action Trace::FACTORY_RESET;
constexpr Trace_Action Trace::LIST_COMPATIBLE_OBJECTS;
constexpr Trace_Action Trace::DISCOVER_NEW_OBJECTS;
constexpr Trace_Action Trace::CONSTRUCT_OBJECT;
constexpr Trace_Action Trace::DESTRUCT_OBJECT;
constexpr Trace_Action Trace::STREAM_FROM_OBJECT;
constexpr Trace_Action Trace::STREAM_TO_OBJECT;
constexpr Trace_Action Trace::UPDATE_OBJECT;
constexpr Trace_Action Trace::PERSIST_OBJECT;
constexpr Trace_Action Trace::LOAD_STORED_OBJECT;
constexpr Trace_Action Trace::UPDATE_OBJECTS;
constexpr Trace_Action Trace::UPDATE_CONNECTIONS;
constexpr Trace_Action Trace::UPDATE_DISPLAY;
constexpr Trace_Action Trace::SYSTEM_TASKS;
constexpr Trace_Action Trace::MANAGE_CONNECTIVITY;
constexpr Trace_Action Trace::MDNS_START;
constexpr Trace_Action Trace::MDNS_PROCESS;
constexpr Trace_Action Trace::HTTP_START;
constexpr Trace_Action Trace::HTTP_STOP;
constexpr Trace_Action Trace::HTTP_RESPONSE;
constexpr Trace_Action Trace::WIFI_CONNECT;
constexpr Trace_Action Trace::FIRMWARE_UPDATE_STARTED;
constexpr Trace_Action Trace::Action_MIN;
constexpr Trace_Action Trace::Action_MAX;
constexpr int Trace::Action_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Platform_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_SysInfo_5ftest_2eproto);
  return file_level_enum_descriptors_SysInfo_5ftest_2eproto[1];
}
bool Platform_IsValid(int value) {
  switch (value) {
    case 0:
    case 3:
    case 6:
    case 8:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Command_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_SysInfo_5ftest_2eproto);
  return file_level_enum_descriptors_SysInfo_5ftest_2eproto[2];
}
bool Command_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Trace::_Internal {
 public:
};

Trace::Trace(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.SysInfo.Trace)
}
Trace::Trace(const Trace& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&action_, &from.action_,
    static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&action_)) + sizeof(type_));
  // @@protoc_insertion_point(copy_constructor:blox_test.SysInfo.Trace)
}

inline void Trace::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&action_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&action_)) + sizeof(type_));
}

Trace::~Trace() {
  // @@protoc_insertion_point(destructor:blox_test.SysInfo.Trace)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Trace::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Trace::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Trace::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.SysInfo.Trace)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&action_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&type_) -
      reinterpret_cast<char*>(&action_)) + sizeof(type_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Trace::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .blox_test.SysInfo.Trace.Action action = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_action(static_cast<::blox_test::SysInfo::Trace_Action>(val));
        } else
          goto handle_unusual;
        continue;
      // uint32 id = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 type = 3 [(.nanopb) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          type_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Trace::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.SysInfo.Trace)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .blox_test.SysInfo.Trace.Action action = 1;
  if (this->_internal_action() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_action(), target);
  }

  // uint32 id = 2 [(.nanopb) = {
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_id(), target);
  }

  // uint32 type = 3 [(.nanopb) = {
  if (this->_internal_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.SysInfo.Trace)
  return target;
}

size_t Trace::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.SysInfo.Trace)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .blox_test.SysInfo.Trace.Action action = 1;
  if (this->_internal_action() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_action());
  }

  // uint32 id = 2 [(.nanopb) = {
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_id());
  }

  // uint32 type = 3 [(.nanopb) = {
  if (this->_internal_type() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_type());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Trace::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Trace::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Trace::GetClassData() const { return &_class_data_; }

void Trace::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Trace *>(to)->MergeFrom(
      static_cast<const Trace &>(from));
}


void Trace::MergeFrom(const Trace& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.SysInfo.Trace)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_action() != 0) {
    _internal_set_action(from._internal_action());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_type() != 0) {
    _internal_set_type(from._internal_type());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Trace::CopyFrom(const Trace& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.SysInfo.Trace)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Trace::IsInitialized() const {
  return true;
}

void Trace::InternalSwap(Trace* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Trace, type_)
      + sizeof(Trace::type_)
      - PROTOBUF_FIELD_OFFSET(Trace, action_)>(
          reinterpret_cast<char*>(&action_),
          reinterpret_cast<char*>(&other->action_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Trace::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_SysInfo_5ftest_2eproto_getter, &descriptor_table_SysInfo_5ftest_2eproto_once,
      file_level_metadata_SysInfo_5ftest_2eproto[0]);
}

// ===================================================================

class Block::_Internal {
 public:
};

Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  trace_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.SysInfo.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      trace_(from.trace_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  deviceid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    deviceid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_deviceid().empty()) {
    deviceid_.Set(from._internal_deviceid(), 
      GetArenaForAllocation());
  }
  version_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    version_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_version().empty()) {
    version_.Set(from._internal_version(), 
      GetArenaForAllocation());
  }
  protocolversion_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    protocolversion_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_protocolversion().empty()) {
    protocolversion_.Set(from._internal_protocolversion(), 
      GetArenaForAllocation());
  }
  releasedate_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    releasedate_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_releasedate().empty()) {
    releasedate_.Set(from._internal_releasedate(), 
      GetArenaForAllocation());
  }
  protocoldate_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    protocoldate_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_protocoldate().empty()) {
    protocoldate_.Set(from._internal_protocoldate(), 
      GetArenaForAllocation());
  }
  ::memcpy(&platform_, &from.platform_,
    static_cast<size_t>(reinterpret_cast<char*>(&command_) -
    reinterpret_cast<char*>(&platform_)) + sizeof(command_));
  // @@protoc_insertion_point(copy_constructor:blox_test.SysInfo.Block)
}

inline void Block::SharedCtor() {
deviceid_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  deviceid_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
version_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  version_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
protocolversion_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  protocolversion_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
releasedate_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  releasedate_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
protocoldate_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  protocoldate_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&platform_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&command_) -
    reinterpret_cast<char*>(&platform_)) + sizeof(command_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.SysInfo.Block)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  deviceid_.Destroy();
  version_.Destroy();
  protocolversion_.Destroy();
  releasedate_.Destroy();
  protocoldate_.Destroy();
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.SysInfo.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  trace_.Clear();
  deviceid_.ClearToEmpty();
  version_.ClearToEmpty();
  protocolversion_.ClearToEmpty();
  releasedate_.ClearToEmpty();
  protocoldate_.ClearToEmpty();
  ::memset(&platform_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&command_) -
      reinterpret_cast<char*>(&platform_)) + sizeof(command_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes deviceId = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_deviceid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string version = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_version();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "blox_test.SysInfo.Block.version"));
        } else
          goto handle_unusual;
        continue;
      // .blox_test.SysInfo.Platform platform = 3 [(.brewblox.field) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_platform(static_cast<::blox_test::SysInfo::Platform>(val));
        } else
          goto handle_unusual;
        continue;
      // string protocolVersion = 7 [(.nanopb) = {
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
          auto str = _internal_mutable_protocolversion();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "blox_test.SysInfo.Block.protocolVersion"));
        } else
          goto handle_unusual;
        continue;
      // string releaseDate = 8 [(.nanopb) = {
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 66)) {
          auto str = _internal_mutable_releasedate();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "blox_test.SysInfo.Block.releaseDate"));
        } else
          goto handle_unusual;
        continue;
      // string protocolDate = 9 [(.nanopb) = {
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 74)) {
          auto str = _internal_mutable_protocoldate();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "blox_test.SysInfo.Block.protocolDate"));
        } else
          goto handle_unusual;
        continue;
      // .blox_test.SysInfo.Command command = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 80)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_command(static_cast<::blox_test::SysInfo::Command>(val));
        } else
          goto handle_unusual;
        continue;
      // repeated .blox_test.SysInfo.Trace trace = 11 [(.nanopb) = {
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 90)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_trace(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<90>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Block::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.SysInfo.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes deviceId = 1 [(.nanopb) = {
  if (!this->_internal_deviceid().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_deviceid(), target);
  }

  // string version = 2 [(.nanopb) = {
  if (!this->_internal_version().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_version().data(), static_cast<int>(this->_internal_version().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.SysInfo.Block.version");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_version(), target);
  }

  // .blox_test.SysInfo.Platform platform = 3 [(.brewblox.field) = {
  if (this->_internal_platform() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      3, this->_internal_platform(), target);
  }

  // string protocolVersion = 7 [(.nanopb) = {
  if (!this->_internal_protocolversion().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_protocolversion().data(), static_cast<int>(this->_internal_protocolversion().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.SysInfo.Block.protocolVersion");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_protocolversion(), target);
  }

  // string releaseDate = 8 [(.nanopb) = {
  if (!this->_internal_releasedate().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_releasedate().data(), static_cast<int>(this->_internal_releasedate().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.SysInfo.Block.releaseDate");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_releasedate(), target);
  }

  // string protocolDate = 9 [(.nanopb) = {
  if (!this->_internal_protocoldate().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_protocoldate().data(), static_cast<int>(this->_internal_protocoldate().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.SysInfo.Block.protocolDate");
    target = stream->WriteStringMaybeAliased(
        9, this->_internal_protocoldate(), target);
  }

  // .blox_test.SysInfo.Command command = 10;
  if (this->_internal_command() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      10, this->_internal_command(), target);
  }

  // repeated .blox_test.SysInfo.Trace trace = 11 [(.nanopb) = {
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_trace_size()); i < n; i++) {
    const auto& repfield = this->_internal_trace(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(11, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.SysInfo.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.SysInfo.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.SysInfo.Trace trace = 11 [(.nanopb) = {
  total_size += 1UL * this->_internal_trace_size();
  for (const auto& msg : this->trace_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bytes deviceId = 1 [(.nanopb) = {
  if (!this->_internal_deviceid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_deviceid());
  }

  // string version = 2 [(.nanopb) = {
  if (!this->_internal_version().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_version());
  }

  // string protocolVersion = 7 [(.nanopb) = {
  if (!this->_internal_protocolversion().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_protocolversion());
  }

  // string releaseDate = 8 [(.nanopb) = {
  if (!this->_internal_releasedate().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_releasedate());
  }

  // string protocolDate = 9 [(.nanopb) = {
  if (!this->_internal_protocoldate().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_protocoldate());
  }

  // .blox_test.SysInfo.Platform platform = 3 [(.brewblox.field) = {
  if (this->_internal_platform() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_platform());
  }

  // .blox_test.SysInfo.Command command = 10;
  if (this->_internal_command() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_command());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Block::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Block::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Block::GetClassData() const { return &_class_data_; }

void Block::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Block *>(to)->MergeFrom(
      static_cast<const Block &>(from));
}


void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.SysInfo.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  trace_.MergeFrom(from.trace_);
  if (!from._internal_deviceid().empty()) {
    _internal_set_deviceid(from._internal_deviceid());
  }
  if (!from._internal_version().empty()) {
    _internal_set_version(from._internal_version());
  }
  if (!from._internal_protocolversion().empty()) {
    _internal_set_protocolversion(from._internal_protocolversion());
  }
  if (!from._internal_releasedate().empty()) {
    _internal_set_releasedate(from._internal_releasedate());
  }
  if (!from._internal_protocoldate().empty()) {
    _internal_set_protocoldate(from._internal_protocoldate());
  }
  if (from._internal_platform() != 0) {
    _internal_set_platform(from._internal_platform());
  }
  if (from._internal_command() != 0) {
    _internal_set_command(from._internal_command());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.SysInfo.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  trace_.InternalSwap(&other->trace_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &deviceid_, lhs_arena,
      &other->deviceid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &version_, lhs_arena,
      &other->version_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &protocolversion_, lhs_arena,
      &other->protocolversion_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &releasedate_, lhs_arena,
      &other->releasedate_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &protocoldate_, lhs_arena,
      &other->protocoldate_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, command_)
      + sizeof(Block::command_)
      - PROTOBUF_FIELD_OFFSET(Block, platform_)>(
          reinterpret_cast<char*>(&platform_),
          reinterpret_cast<char*>(&other->platform_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_SysInfo_5ftest_2eproto_getter, &descriptor_table_SysInfo_5ftest_2eproto_once,
      file_level_metadata_SysInfo_5ftest_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace SysInfo
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::SysInfo::Trace*
Arena::CreateMaybeMessage< ::blox_test::SysInfo::Trace >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::SysInfo::Trace >(arena);
}
template<> PROTOBUF_NOINLINE ::blox_test::SysInfo::Block*
Arena::CreateMaybeMessage< ::blox_test::SysInfo::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::SysInfo::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
