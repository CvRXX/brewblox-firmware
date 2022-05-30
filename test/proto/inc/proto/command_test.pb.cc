// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: command_test.proto

#include "command_test.pb.h"

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

namespace command {
PROTOBUF_CONSTEXPR Payload::Payload(
    ::_pbi::ConstantInitialized)
  : content_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , blockid_(0u)
  , blocktype_(0)

  , subtype_(0u){}
struct PayloadDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PayloadDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PayloadDefaultTypeInternal() {}
  union {
    Payload _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PayloadDefaultTypeInternal _Payload_default_instance_;
PROTOBUF_CONSTEXPR Request::Request(
    ::_pbi::ConstantInitialized)
  : payload_(nullptr)
  , msgid_(0u)
  , opcode_(0)
{}
struct RequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~RequestDefaultTypeInternal() {}
  union {
    Request _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RequestDefaultTypeInternal _Request_default_instance_;
PROTOBUF_CONSTEXPR Response::Response(
    ::_pbi::ConstantInitialized)
  : payload_()
  , msgid_(0u)
  , error_(0)
{}
struct ResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResponseDefaultTypeInternal() {}
  union {
    Response _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResponseDefaultTypeInternal _Response_default_instance_;
}  // namespace command
static ::_pb::Metadata file_level_metadata_command_5ftest_2eproto[3];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_command_5ftest_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_command_5ftest_2eproto = nullptr;

const uint32_t TableStruct_command_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::command::Payload, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::command::Payload, blockid_),
  PROTOBUF_FIELD_OFFSET(::command::Payload, blocktype_),
  PROTOBUF_FIELD_OFFSET(::command::Payload, subtype_),
  PROTOBUF_FIELD_OFFSET(::command::Payload, content_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::command::Request, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::command::Request, msgid_),
  PROTOBUF_FIELD_OFFSET(::command::Request, opcode_),
  PROTOBUF_FIELD_OFFSET(::command::Request, payload_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::command::Response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::command::Response, msgid_),
  PROTOBUF_FIELD_OFFSET(::command::Response, error_),
  PROTOBUF_FIELD_OFFSET(::command::Response, payload_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::command::Payload)},
  { 10, -1, -1, sizeof(::command::Request)},
  { 19, -1, -1, sizeof(::command::Response)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::command::_Payload_default_instance_._instance,
  &::command::_Request_default_instance_._instance,
  &::command::_Response_default_instance_._instance,
};

const char descriptor_table_protodef_command_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022command_test.proto\022\007command\032\023brewblox_"
  "test.proto\032\021nanopb_test.proto\"r\n\007Payload"
  "\022\026\n\007blockId\030\001 \001(\rB\005\222\?\0028\020\022&\n\tblockType\030\002 "
  "\001(\0162\023.brewblox.BlockType\022\026\n\007subtype\030\003 \001("
  "\rB\005\222\?\0028\020\022\017\n\007content\030\004 \001(\t\"\\\n\007Request\022\r\n\005"
  "msgId\030\001 \001(\r\022\037\n\006opcode\030\002 \001(\0162\017.command.Op"
  "code\022!\n\007payload\030\003 \001(\0132\020.command.Payload\""
  "_\n\010Response\022\r\n\005msgId\030\001 \001(\r\022!\n\005error\030\002 \001("
  "\0162\022.command.ErrorCode\022!\n\007payload\030\003 \003(\0132\020"
  ".command.Payload*\212\002\n\006Opcode\022\010\n\004NONE\020\000\022\013\n"
  "\007VERSION\020\001\022\016\n\nBLOCK_READ\020\n\022\022\n\016BLOCK_READ"
  "_ALL\020\013\022\017\n\013BLOCK_WRITE\020\014\022\020\n\014BLOCK_CREATE\020"
  "\r\022\020\n\014BLOCK_DELETE\020\016\022\022\n\016BLOCK_DISCOVER\020\017\022"
  "\020\n\014STORAGE_READ\020\024\022\024\n\020STORAGE_READ_ALL\020\025\022"
  "\n\n\006REBOOT\020\036\022\020\n\014CLEAR_BLOCKS\020\037\022\016\n\nCLEAR_W"
  "IFI\020 \022\021\n\rFACTORY_RESET\020!\022\023\n\017FIRMWARE_UPD"
  "ATE\020(*\355\005\n\tErrorCode\022\006\n\002OK\020\000\022\021\n\rUNKNOWN_E"
  "RROR\020\001\022\022\n\016INVALID_OPCODE\020\002\022\025\n\021INSUFFICIE"
  "NT_HEAP\020\004\022\030\n\024INSUFFICIENT_STORAGE\020\005\022\021\n\rN"
  "ETWORK_ERROR\020\n\022\026\n\022NETWORK_READ_ERROR\020\013\022\032"
  "\n\026NETWORK_DECODING_ERROR\020\014\022\027\n\023NETWORK_WR"
  "ITE_ERROR\020\r\022\032\n\026NETWORK_ENCODING_ERROR\020\016\022"
  "\021\n\rSTORAGE_ERROR\020\024\022\026\n\022STORAGE_READ_ERROR"
  "\020\025\022\032\n\026STORAGE_DECODING_ERROR\020\026\022\025\n\021STORAG"
  "E_CRC_ERROR\020\027\022\027\n\023STORAGE_WRITE_ERROR\020\030\022\032"
  "\n\026STORAGE_ENCODING_ERROR\020\031\022\026\n\022BLOCK_NOT_"
  "WRITABLE\020\036\022\026\n\022BLOCK_NOT_READABLE\020\037\022\027\n\023BL"
  "OCK_NOT_CREATABLE\020 \022\027\n\023BLOCK_NOT_DELETAB"
  "LE\020!\022\021\n\rINVALID_BLOCK\020(\022\024\n\020INVALID_BLOCK"
  "_ID\020)\022\026\n\022INVALID_BLOCK_TYPE\020*\022\031\n\025INVALID"
  "_BLOCK_SUBTYPE\020+\022\031\n\025INVALID_BLOCK_CONTEN"
  "T\020,\022\030\n\024INVALID_STORED_BLOCK\0202\022\033\n\027INVALID"
  "_STORED_BLOCK_ID\0203\022\035\n\031INVALID_STORED_BLO"
  "CK_TYPE\0204\022 \n\034INVALID_STORED_BLOCK_SUBTYP"
  "E\0205\022 \n\034INVALID_STORED_BLOCK_CONTENT\0206b\006p"
  "roto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_command_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_command_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_command_5ftest_2eproto = {
    false, false, 1405, descriptor_table_protodef_command_5ftest_2eproto,
    "command_test.proto",
    &descriptor_table_command_5ftest_2eproto_once, descriptor_table_command_5ftest_2eproto_deps, 2, 3,
    schemas, file_default_instances, TableStruct_command_5ftest_2eproto::offsets,
    file_level_metadata_command_5ftest_2eproto, file_level_enum_descriptors_command_5ftest_2eproto,
    file_level_service_descriptors_command_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_command_5ftest_2eproto_getter() {
  return &descriptor_table_command_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_command_5ftest_2eproto(&descriptor_table_command_5ftest_2eproto);
namespace command {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Opcode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_command_5ftest_2eproto);
  return file_level_enum_descriptors_command_5ftest_2eproto[0];
}
bool Opcode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 20:
    case 21:
    case 30:
    case 31:
    case 32:
    case 33:
    case 40:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ErrorCode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_command_5ftest_2eproto);
  return file_level_enum_descriptors_command_5ftest_2eproto[1];
}
bool ErrorCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 30:
    case 31:
    case 32:
    case 33:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Payload::_Internal {
 public:
};

Payload::Payload(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:command.Payload)
}
Payload::Payload(const Payload& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  content_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    content_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_content().empty()) {
    content_.Set(from._internal_content(), 
      GetArenaForAllocation());
  }
  ::memcpy(&blockid_, &from.blockid_,
    static_cast<size_t>(reinterpret_cast<char*>(&subtype_) -
    reinterpret_cast<char*>(&blockid_)) + sizeof(subtype_));
  // @@protoc_insertion_point(copy_constructor:command.Payload)
}

inline void Payload::SharedCtor() {
content_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  content_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&blockid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&subtype_) -
    reinterpret_cast<char*>(&blockid_)) + sizeof(subtype_));
}

Payload::~Payload() {
  // @@protoc_insertion_point(destructor:command.Payload)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Payload::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  content_.Destroy();
}

void Payload::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Payload::Clear() {
// @@protoc_insertion_point(message_clear_start:command.Payload)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  content_.ClearToEmpty();
  ::memset(&blockid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&subtype_) -
      reinterpret_cast<char*>(&blockid_)) + sizeof(subtype_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Payload::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 blockId = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          blockid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .brewblox.BlockType blockType = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_blocktype(static_cast<::brewblox::BlockType>(val));
        } else
          goto handle_unusual;
        continue;
      // uint32 subtype = 3 [(.nanopb) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          subtype_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string content = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_content();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "command.Payload.content"));
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

uint8_t* Payload::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:command.Payload)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 blockId = 1 [(.nanopb) = {
  if (this->_internal_blockid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_blockid(), target);
  }

  // .brewblox.BlockType blockType = 2;
  if (this->_internal_blocktype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_blocktype(), target);
  }

  // uint32 subtype = 3 [(.nanopb) = {
  if (this->_internal_subtype() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_subtype(), target);
  }

  // string content = 4;
  if (!this->_internal_content().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_content().data(), static_cast<int>(this->_internal_content().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "command.Payload.content");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_content(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:command.Payload)
  return target;
}

size_t Payload::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:command.Payload)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string content = 4;
  if (!this->_internal_content().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_content());
  }

  // uint32 blockId = 1 [(.nanopb) = {
  if (this->_internal_blockid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_blockid());
  }

  // .brewblox.BlockType blockType = 2;
  if (this->_internal_blocktype() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_blocktype());
  }

  // uint32 subtype = 3 [(.nanopb) = {
  if (this->_internal_subtype() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_subtype());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Payload::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Payload::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Payload::GetClassData() const { return &_class_data_; }

void Payload::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Payload *>(to)->MergeFrom(
      static_cast<const Payload &>(from));
}


void Payload::MergeFrom(const Payload& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:command.Payload)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_content().empty()) {
    _internal_set_content(from._internal_content());
  }
  if (from._internal_blockid() != 0) {
    _internal_set_blockid(from._internal_blockid());
  }
  if (from._internal_blocktype() != 0) {
    _internal_set_blocktype(from._internal_blocktype());
  }
  if (from._internal_subtype() != 0) {
    _internal_set_subtype(from._internal_subtype());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Payload::CopyFrom(const Payload& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:command.Payload)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Payload::IsInitialized() const {
  return true;
}

void Payload::InternalSwap(Payload* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &content_, lhs_arena,
      &other->content_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Payload, subtype_)
      + sizeof(Payload::subtype_)
      - PROTOBUF_FIELD_OFFSET(Payload, blockid_)>(
          reinterpret_cast<char*>(&blockid_),
          reinterpret_cast<char*>(&other->blockid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Payload::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_command_5ftest_2eproto_getter, &descriptor_table_command_5ftest_2eproto_once,
      file_level_metadata_command_5ftest_2eproto[0]);
}

// ===================================================================

class Request::_Internal {
 public:
  static const ::command::Payload& payload(const Request* msg);
};

const ::command::Payload&
Request::_Internal::payload(const Request* msg) {
  return *msg->payload_;
}
Request::Request(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:command.Request)
}
Request::Request(const Request& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_payload()) {
    payload_ = new ::command::Payload(*from.payload_);
  } else {
    payload_ = nullptr;
  }
  ::memcpy(&msgid_, &from.msgid_,
    static_cast<size_t>(reinterpret_cast<char*>(&opcode_) -
    reinterpret_cast<char*>(&msgid_)) + sizeof(opcode_));
  // @@protoc_insertion_point(copy_constructor:command.Request)
}

inline void Request::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&payload_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&opcode_) -
    reinterpret_cast<char*>(&payload_)) + sizeof(opcode_));
}

Request::~Request() {
  // @@protoc_insertion_point(destructor:command.Request)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Request::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete payload_;
}

void Request::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Request::Clear() {
// @@protoc_insertion_point(message_clear_start:command.Request)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && payload_ != nullptr) {
    delete payload_;
  }
  payload_ = nullptr;
  ::memset(&msgid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&opcode_) -
      reinterpret_cast<char*>(&msgid_)) + sizeof(opcode_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Request::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 msgId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          msgid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .command.Opcode opcode = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_opcode(static_cast<::command::Opcode>(val));
        } else
          goto handle_unusual;
        continue;
      // .command.Payload payload = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_payload(), ptr);
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

uint8_t* Request::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:command.Request)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 msgId = 1;
  if (this->_internal_msgid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_msgid(), target);
  }

  // .command.Opcode opcode = 2;
  if (this->_internal_opcode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_opcode(), target);
  }

  // .command.Payload payload = 3;
  if (this->_internal_has_payload()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::payload(this),
        _Internal::payload(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:command.Request)
  return target;
}

size_t Request::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:command.Request)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .command.Payload payload = 3;
  if (this->_internal_has_payload()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *payload_);
  }

  // uint32 msgId = 1;
  if (this->_internal_msgid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_msgid());
  }

  // .command.Opcode opcode = 2;
  if (this->_internal_opcode() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_opcode());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Request::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Request::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Request::GetClassData() const { return &_class_data_; }

void Request::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Request *>(to)->MergeFrom(
      static_cast<const Request &>(from));
}


void Request::MergeFrom(const Request& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:command.Request)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_payload()) {
    _internal_mutable_payload()->::command::Payload::MergeFrom(from._internal_payload());
  }
  if (from._internal_msgid() != 0) {
    _internal_set_msgid(from._internal_msgid());
  }
  if (from._internal_opcode() != 0) {
    _internal_set_opcode(from._internal_opcode());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Request::CopyFrom(const Request& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:command.Request)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Request::IsInitialized() const {
  return true;
}

void Request::InternalSwap(Request* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Request, opcode_)
      + sizeof(Request::opcode_)
      - PROTOBUF_FIELD_OFFSET(Request, payload_)>(
          reinterpret_cast<char*>(&payload_),
          reinterpret_cast<char*>(&other->payload_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Request::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_command_5ftest_2eproto_getter, &descriptor_table_command_5ftest_2eproto_once,
      file_level_metadata_command_5ftest_2eproto[1]);
}

// ===================================================================

class Response::_Internal {
 public:
};

Response::Response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  payload_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:command.Response)
}
Response::Response(const Response& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      payload_(from.payload_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&msgid_, &from.msgid_,
    static_cast<size_t>(reinterpret_cast<char*>(&error_) -
    reinterpret_cast<char*>(&msgid_)) + sizeof(error_));
  // @@protoc_insertion_point(copy_constructor:command.Response)
}

inline void Response::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&msgid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&error_) -
    reinterpret_cast<char*>(&msgid_)) + sizeof(error_));
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:command.Response)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Response::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Response::Clear() {
// @@protoc_insertion_point(message_clear_start:command.Response)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  payload_.Clear();
  ::memset(&msgid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&error_) -
      reinterpret_cast<char*>(&msgid_)) + sizeof(error_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Response::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 msgId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          msgid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .command.ErrorCode error = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_error(static_cast<::command::ErrorCode>(val));
        } else
          goto handle_unusual;
        continue;
      // repeated .command.Payload payload = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_payload(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

uint8_t* Response::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:command.Response)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 msgId = 1;
  if (this->_internal_msgid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_msgid(), target);
  }

  // .command.ErrorCode error = 2;
  if (this->_internal_error() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_error(), target);
  }

  // repeated .command.Payload payload = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_payload_size()); i < n; i++) {
    const auto& repfield = this->_internal_payload(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:command.Response)
  return target;
}

size_t Response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:command.Response)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .command.Payload payload = 3;
  total_size += 1UL * this->_internal_payload_size();
  for (const auto& msg : this->payload_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint32 msgId = 1;
  if (this->_internal_msgid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_msgid());
  }

  // .command.ErrorCode error = 2;
  if (this->_internal_error() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_error());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Response::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Response::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Response::GetClassData() const { return &_class_data_; }

void Response::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Response *>(to)->MergeFrom(
      static_cast<const Response &>(from));
}


void Response::MergeFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:command.Response)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  payload_.MergeFrom(from.payload_);
  if (from._internal_msgid() != 0) {
    _internal_set_msgid(from._internal_msgid());
  }
  if (from._internal_error() != 0) {
    _internal_set_error(from._internal_error());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Response::CopyFrom(const Response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:command.Response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {
  return true;
}

void Response::InternalSwap(Response* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  payload_.InternalSwap(&other->payload_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Response, error_)
      + sizeof(Response::error_)
      - PROTOBUF_FIELD_OFFSET(Response, msgid_)>(
          reinterpret_cast<char*>(&msgid_),
          reinterpret_cast<char*>(&other->msgid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Response::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_command_5ftest_2eproto_getter, &descriptor_table_command_5ftest_2eproto_once,
      file_level_metadata_command_5ftest_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace command
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::command::Payload*
Arena::CreateMaybeMessage< ::command::Payload >(Arena* arena) {
  return Arena::CreateMessageInternal< ::command::Payload >(arena);
}
template<> PROTOBUF_NOINLINE ::command::Request*
Arena::CreateMaybeMessage< ::command::Request >(Arena* arena) {
  return Arena::CreateMessageInternal< ::command::Request >(arena);
}
template<> PROTOBUF_NOINLINE ::command::Response*
Arena::CreateMaybeMessage< ::command::Response >(Arena* arena) {
  return Arena::CreateMessageInternal< ::command::Response >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
