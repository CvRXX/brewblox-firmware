// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OneWireBus_test.proto

#include "OneWireBus_test.pb.h"

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
namespace OneWireBus {
PROTOBUF_CONSTEXPR Command::Command(
    ::_pbi::ConstantInitialized)
  : opcode_(0u)
  , data_(0u){}
struct CommandDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CommandDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~CommandDefaultTypeInternal() {}
  union {
    Command _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CommandDefaultTypeInternal _Command_default_instance_;
PROTOBUF_CONSTEXPR Block::Block(
    ::_pbi::ConstantInitialized)
  : address_()
  , command_(nullptr){}
struct BlockDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BlockDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace OneWireBus
}  // namespace blox_test
static ::_pb::Metadata file_level_metadata_OneWireBus_5ftest_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_OneWireBus_5ftest_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_OneWireBus_5ftest_2eproto = nullptr;

const uint32_t TableStruct_OneWireBus_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Command, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Command, opcode_),
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Command, data_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Block, command_),
  PROTOBUF_FIELD_OFFSET(::blox_test::OneWireBus::Block, address_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::blox_test::OneWireBus::Command)},
  { 8, -1, -1, sizeof(::blox_test::OneWireBus::Block)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::blox_test::OneWireBus::_Command_default_instance_._instance,
  &::blox_test::OneWireBus::_Block_default_instance_._instance,
};

const char descriptor_table_protodef_OneWireBus_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025OneWireBus_test.proto\022\024blox_test.OneWi"
  "reBus\032\023brewblox_test.proto\032\021nanopb_test."
  "proto\"5\n\007Command\022\025\n\006opcode\030\001 \001(\rB\005\222\?\0028\010\022"
  "\023\n\004data\030\002 \001(\rB\005\222\?\0028\010\"_\n\005Block\022.\n\007command"
  "\030\001 \001(\0132\035.blox_test.OneWireBus.Command\022\035\n"
  "\007address\030\002 \003(\006B\014\212\265\030\002 \001\212\265\030\002(\001:\007\212\265\030\003\030\202\002b\006p"
  "roto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_OneWireBus_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_OneWireBus_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_OneWireBus_5ftest_2eproto = {
    false, false, 245, descriptor_table_protodef_OneWireBus_5ftest_2eproto,
    "OneWireBus_test.proto",
    &descriptor_table_OneWireBus_5ftest_2eproto_once, descriptor_table_OneWireBus_5ftest_2eproto_deps, 2, 2,
    schemas, file_default_instances, TableStruct_OneWireBus_5ftest_2eproto::offsets,
    file_level_metadata_OneWireBus_5ftest_2eproto, file_level_enum_descriptors_OneWireBus_5ftest_2eproto,
    file_level_service_descriptors_OneWireBus_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_OneWireBus_5ftest_2eproto_getter() {
  return &descriptor_table_OneWireBus_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_OneWireBus_5ftest_2eproto(&descriptor_table_OneWireBus_5ftest_2eproto);
namespace blox_test {
namespace OneWireBus {

// ===================================================================

class Command::_Internal {
 public:
};

Command::Command(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.OneWireBus.Command)
}
Command::Command(const Command& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&opcode_, &from.opcode_,
    static_cast<size_t>(reinterpret_cast<char*>(&data_) -
    reinterpret_cast<char*>(&opcode_)) + sizeof(data_));
  // @@protoc_insertion_point(copy_constructor:blox_test.OneWireBus.Command)
}

inline void Command::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&opcode_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&data_) -
    reinterpret_cast<char*>(&opcode_)) + sizeof(data_));
}

Command::~Command() {
  // @@protoc_insertion_point(destructor:blox_test.OneWireBus.Command)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Command::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Command::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Command::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.OneWireBus.Command)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&opcode_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&data_) -
      reinterpret_cast<char*>(&opcode_)) + sizeof(data_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Command::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 opcode = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          opcode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 data = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          data_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

uint8_t* Command::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.OneWireBus.Command)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 opcode = 1 [(.nanopb) = {
  if (this->_internal_opcode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_opcode(), target);
  }

  // uint32 data = 2 [(.nanopb) = {
  if (this->_internal_data() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.OneWireBus.Command)
  return target;
}

size_t Command::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.OneWireBus.Command)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 opcode = 1 [(.nanopb) = {
  if (this->_internal_opcode() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_opcode());
  }

  // uint32 data = 2 [(.nanopb) = {
  if (this->_internal_data() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Command::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Command::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Command::GetClassData() const { return &_class_data_; }

void Command::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Command *>(to)->MergeFrom(
      static_cast<const Command &>(from));
}


void Command::MergeFrom(const Command& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.OneWireBus.Command)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_opcode() != 0) {
    _internal_set_opcode(from._internal_opcode());
  }
  if (from._internal_data() != 0) {
    _internal_set_data(from._internal_data());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Command::CopyFrom(const Command& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.OneWireBus.Command)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Command::IsInitialized() const {
  return true;
}

void Command::InternalSwap(Command* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Command, data_)
      + sizeof(Command::data_)
      - PROTOBUF_FIELD_OFFSET(Command, opcode_)>(
          reinterpret_cast<char*>(&opcode_),
          reinterpret_cast<char*>(&other->opcode_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Command::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_OneWireBus_5ftest_2eproto_getter, &descriptor_table_OneWireBus_5ftest_2eproto_once,
      file_level_metadata_OneWireBus_5ftest_2eproto[0]);
}

// ===================================================================

class Block::_Internal {
 public:
  static const ::blox_test::OneWireBus::Command& command(const Block* msg);
};

const ::blox_test::OneWireBus::Command&
Block::_Internal::command(const Block* msg) {
  return *msg->command_;
}
Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  address_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.OneWireBus.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      address_(from.address_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_command()) {
    command_ = new ::blox_test::OneWireBus::Command(*from.command_);
  } else {
    command_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:blox_test.OneWireBus.Block)
}

inline void Block::SharedCtor() {
command_ = nullptr;
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.OneWireBus.Block)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete command_;
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.OneWireBus.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  address_.Clear();
  if (GetArenaForAllocation() == nullptr && command_ != nullptr) {
    delete command_;
  }
  command_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .blox_test.OneWireBus.Command command = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_command(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated fixed64 address = 2 [(.brewblox.field) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFixed64Parser(_internal_mutable_address(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 17) {
          _internal_add_address(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<uint64_t>(ptr));
          ptr += sizeof(uint64_t);
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
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.OneWireBus.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .blox_test.OneWireBus.Command command = 1;
  if (this->_internal_has_command()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::command(this),
        _Internal::command(this).GetCachedSize(), target, stream);
  }

  // repeated fixed64 address = 2 [(.brewblox.field) = {
  if (this->_internal_address_size() > 0) {
    target = stream->WriteFixedPacked(2, _internal_address(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.OneWireBus.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.OneWireBus.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated fixed64 address = 2 [(.brewblox.field) = {
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_address_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // .blox_test.OneWireBus.Command command = 1;
  if (this->_internal_has_command()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *command_);
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
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.OneWireBus.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  address_.MergeFrom(from.address_);
  if (from._internal_has_command()) {
    _internal_mutable_command()->::blox_test::OneWireBus::Command::MergeFrom(from._internal_command());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.OneWireBus.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  address_.InternalSwap(&other->address_);
  swap(command_, other->command_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_OneWireBus_5ftest_2eproto_getter, &descriptor_table_OneWireBus_5ftest_2eproto_once,
      file_level_metadata_OneWireBus_5ftest_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace OneWireBus
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::OneWireBus::Command*
Arena::CreateMaybeMessage< ::blox_test::OneWireBus::Command >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::OneWireBus::Command >(arena);
}
template<> PROTOBUF_NOINLINE ::blox_test::OneWireBus::Block*
Arena::CreateMaybeMessage< ::blox_test::OneWireBus::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::OneWireBus::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
