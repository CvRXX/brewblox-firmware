// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MockPins_test.proto

#include "MockPins_test.pb.h"

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
namespace MockPins {
PROTOBUF_CONSTEXPR Block::Block(
    ::_pbi::ConstantInitialized)
  : channels_()
  , pins_(false){}
struct BlockDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BlockDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace MockPins
}  // namespace blox_test
static ::_pb::Metadata file_level_metadata_MockPins_5ftest_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_MockPins_5ftest_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_MockPins_5ftest_2eproto = nullptr;

const uint32_t TableStruct_MockPins_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::MockPins::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::MockPins::Block, channels_),
  PROTOBUF_FIELD_OFFSET(::blox_test::MockPins::Block, pins_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::blox_test::MockPins::Block)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::blox_test::MockPins::_Block_default_instance_._instance,
};

const char descriptor_table_protodef_MockPins_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023MockPins_test.proto\022\022blox_test.MockPin"
  "s\032\023brewblox_test.proto\032\021nanopb_test.prot"
  "o\032\022IoArray_test.proto\"s\n\005Block\022@\n\010channe"
  "ls\030\002 \003(\0132\034.blox_test.IoArray.IoChannelB\020"
  "\222\?\002\020\010\222\?\002x\001\212\265\030\002(\001\022\031\n\004pins\030Z \001(\010B\013\212\265\030\002H\001\222\?"
  "\002\030\003:\r\212\265\030\003\030\303\002\212\265\030\002H\n*\313\001\n\tChannelId\022\026\n\022MOCK"
  "PINS_CHAN_NONE\020\000\022\023\n\017MOCKPINS_CHAN_A\020\001\022\023\n"
  "\017MOCKPINS_CHAN_B\020\002\022\023\n\017MOCKPINS_CHAN_C\020\003\022"
  "\023\n\017MOCKPINS_CHAN_D\020\004\022\023\n\017MOCKPINS_CHAN_E\020"
  "\005\022\023\n\017MOCKPINS_CHAN_F\020\006\022\023\n\017MOCKPINS_CHAN_"
  "G\020\007\022\023\n\017MOCKPINS_CHAN_H\020\010b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_MockPins_5ftest_2eproto_deps[3] = {
  &::descriptor_table_IoArray_5ftest_2eproto,
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_MockPins_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_MockPins_5ftest_2eproto = {
    false, false, 432, descriptor_table_protodef_MockPins_5ftest_2eproto,
    "MockPins_test.proto",
    &descriptor_table_MockPins_5ftest_2eproto_once, descriptor_table_MockPins_5ftest_2eproto_deps, 3, 1,
    schemas, file_default_instances, TableStruct_MockPins_5ftest_2eproto::offsets,
    file_level_metadata_MockPins_5ftest_2eproto, file_level_enum_descriptors_MockPins_5ftest_2eproto,
    file_level_service_descriptors_MockPins_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_MockPins_5ftest_2eproto_getter() {
  return &descriptor_table_MockPins_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_MockPins_5ftest_2eproto(&descriptor_table_MockPins_5ftest_2eproto);
namespace blox_test {
namespace MockPins {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ChannelId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_MockPins_5ftest_2eproto);
  return file_level_enum_descriptors_MockPins_5ftest_2eproto[0];
}
bool ChannelId_IsValid(int value) {
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
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Block::_Internal {
 public:
};

void Block::clear_channels() {
  channels_.Clear();
}
Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  channels_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.MockPins.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  pins_ = from.pins_;
  // @@protoc_insertion_point(copy_constructor:blox_test.MockPins.Block)
}

inline void Block::SharedCtor() {
pins_ = false;
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.MockPins.Block)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.MockPins.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  pins_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_channels(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      // bool pins = 90 [(.nanopb) = {
      case 90:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 208)) {
          pins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

uint8_t* Block::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.MockPins.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_channels_size()); i < n; i++) {
    const auto& repfield = this->_internal_channels(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->_internal_pins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(90, this->_internal_pins(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.MockPins.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.MockPins.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
  total_size += 1UL * this->_internal_channels_size();
  for (const auto& msg : this->channels_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->_internal_pins() != 0) {
    total_size += 2 + 1;
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
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.MockPins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from._internal_pins() != 0) {
    _internal_set_pins(from._internal_pins());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.MockPins.Block)
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
  channels_.InternalSwap(&other->channels_);
  swap(pins_, other->pins_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_MockPins_5ftest_2eproto_getter, &descriptor_table_MockPins_5ftest_2eproto_once,
      file_level_metadata_MockPins_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace MockPins
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::MockPins::Block*
Arena::CreateMaybeMessage< ::blox_test::MockPins::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::MockPins::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
