// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Spark3Pins_test.proto

#include "Spark3Pins_test.pb.h"

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
namespace Spark3Pins {
PROTOBUF_CONSTEXPR Block::Block(
    ::_pbi::ConstantInitialized)
  : channels_()
  , voltage5_(0u)
  , voltage12_(0u)
  , enableiosupply5v_(false)
  , enableiosupply12v_(false)
  , soundalarm_(false)
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
}  // namespace Spark3Pins
}  // namespace blox_test
static ::_pb::Metadata file_level_metadata_Spark3Pins_5ftest_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_Spark3Pins_5ftest_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Spark3Pins_5ftest_2eproto = nullptr;

const uint32_t TableStruct_Spark3Pins_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, enableiosupply5v_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, enableiosupply12v_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, soundalarm_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, voltage5_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, voltage12_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, channels_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Spark3Pins::Block, pins_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::blox_test::Spark3Pins::Block)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::blox_test::Spark3Pins::_Block_default_instance_._instance,
};

const char descriptor_table_protodef_Spark3Pins_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025Spark3Pins_test.proto\022\024blox_test.Spark"
  "3Pins\032\023brewblox_test.proto\032\021nanopb_test."
  "proto\032\022IoArray_test.proto\"\211\002\n\005Block\022\030\n\020e"
  "nableIoSupply5V\030\002 \001(\010\022\031\n\021enableIoSupply1"
  "2V\030\003 \001(\010\022\022\n\nsoundAlarm\030\005 \001(\010\022$\n\010voltage5"
  "\030\006 \001(\rB\022\212\265\030\002(\001\222\?\0028\020\212\265\030\003\020\232\003\022%\n\tvoltage12\030"
  "\007 \001(\rB\022\212\265\030\002(\001\222\?\0028\020\212\265\030\003\020\225\001\022@\n\010channels\030\010 "
  "\003(\0132\034.blox_test.IoArray.IoChannelB\020\222\?\002\020\005"
  "\222\?\002x\001\212\265\030\002(\001\022\031\n\004pins\030Z \001(\010B\013\212\265\030\002H\001\222\?\002\030\003:\r"
  "\212\265\030\003\030\277\002\212\265\030\002H\n*\222\001\n\tChannelId\022\021\n\rSPARK3_NO"
  "_PIN\020\000\022\024\n\020SPARK3_CHAN_TOP1\020\001\022\024\n\020SPARK3_C"
  "HAN_TOP2\020\002\022\024\n\020SPARK3_CHAN_TOP3\020\003\022\027\n\023SPAR"
  "K3_CHAN_BOTTOM1\020\004\022\027\n\023SPARK3_CHAN_BOTTOM2"
  "\020\005b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_Spark3Pins_5ftest_2eproto_deps[3] = {
  &::descriptor_table_IoArray_5ftest_2eproto,
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_Spark3Pins_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Spark3Pins_5ftest_2eproto = {
    false, false, 530, descriptor_table_protodef_Spark3Pins_5ftest_2eproto,
    "Spark3Pins_test.proto",
    &descriptor_table_Spark3Pins_5ftest_2eproto_once, descriptor_table_Spark3Pins_5ftest_2eproto_deps, 3, 1,
    schemas, file_default_instances, TableStruct_Spark3Pins_5ftest_2eproto::offsets,
    file_level_metadata_Spark3Pins_5ftest_2eproto, file_level_enum_descriptors_Spark3Pins_5ftest_2eproto,
    file_level_service_descriptors_Spark3Pins_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Spark3Pins_5ftest_2eproto_getter() {
  return &descriptor_table_Spark3Pins_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Spark3Pins_5ftest_2eproto(&descriptor_table_Spark3Pins_5ftest_2eproto);
namespace blox_test {
namespace Spark3Pins {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ChannelId_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Spark3Pins_5ftest_2eproto);
  return file_level_enum_descriptors_Spark3Pins_5ftest_2eproto[0];
}
bool ChannelId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
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
  // @@protoc_insertion_point(arena_constructor:blox_test.Spark3Pins.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&voltage5_, &from.voltage5_,
    static_cast<size_t>(reinterpret_cast<char*>(&pins_) -
    reinterpret_cast<char*>(&voltage5_)) + sizeof(pins_));
  // @@protoc_insertion_point(copy_constructor:blox_test.Spark3Pins.Block)
}

inline void Block::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&voltage5_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&pins_) -
    reinterpret_cast<char*>(&voltage5_)) + sizeof(pins_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.Spark3Pins.Block)
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
// @@protoc_insertion_point(message_clear_start:blox_test.Spark3Pins.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  ::memset(&voltage5_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&pins_) -
      reinterpret_cast<char*>(&voltage5_)) + sizeof(pins_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool enableIoSupply5V = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          enableiosupply5v_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool enableIoSupply12V = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          enableiosupply12v_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool soundAlarm = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          soundalarm_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 voltage5 = 6 [(.nanopb) = {
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          voltage5_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 voltage12 = 7 [(.nanopb) = {
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          voltage12_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .blox_test.IoArray.IoChannel channels = 8 [(.nanopb) = {
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 66)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_channels(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<66>(ptr));
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
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.Spark3Pins.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool enableIoSupply5V = 2;
  if (this->_internal_enableiosupply5v() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(2, this->_internal_enableiosupply5v(), target);
  }

  // bool enableIoSupply12V = 3;
  if (this->_internal_enableiosupply12v() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(3, this->_internal_enableiosupply12v(), target);
  }

  // bool soundAlarm = 5;
  if (this->_internal_soundalarm() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(5, this->_internal_soundalarm(), target);
  }

  // uint32 voltage5 = 6 [(.nanopb) = {
  if (this->_internal_voltage5() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(6, this->_internal_voltage5(), target);
  }

  // uint32 voltage12 = 7 [(.nanopb) = {
  if (this->_internal_voltage12() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(7, this->_internal_voltage12(), target);
  }

  // repeated .blox_test.IoArray.IoChannel channels = 8 [(.nanopb) = {
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_channels_size()); i < n; i++) {
    const auto& repfield = this->_internal_channels(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(8, repfield, repfield.GetCachedSize(), target, stream);
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
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.Spark3Pins.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.Spark3Pins.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.IoArray.IoChannel channels = 8 [(.nanopb) = {
  total_size += 1UL * this->_internal_channels_size();
  for (const auto& msg : this->channels_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // uint32 voltage5 = 6 [(.nanopb) = {
  if (this->_internal_voltage5() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_voltage5());
  }

  // uint32 voltage12 = 7 [(.nanopb) = {
  if (this->_internal_voltage12() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_voltage12());
  }

  // bool enableIoSupply5V = 2;
  if (this->_internal_enableiosupply5v() != 0) {
    total_size += 1 + 1;
  }

  // bool enableIoSupply12V = 3;
  if (this->_internal_enableiosupply12v() != 0) {
    total_size += 1 + 1;
  }

  // bool soundAlarm = 5;
  if (this->_internal_soundalarm() != 0) {
    total_size += 1 + 1;
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
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.Spark3Pins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from._internal_voltage5() != 0) {
    _internal_set_voltage5(from._internal_voltage5());
  }
  if (from._internal_voltage12() != 0) {
    _internal_set_voltage12(from._internal_voltage12());
  }
  if (from._internal_enableiosupply5v() != 0) {
    _internal_set_enableiosupply5v(from._internal_enableiosupply5v());
  }
  if (from._internal_enableiosupply12v() != 0) {
    _internal_set_enableiosupply12v(from._internal_enableiosupply12v());
  }
  if (from._internal_soundalarm() != 0) {
    _internal_set_soundalarm(from._internal_soundalarm());
  }
  if (from._internal_pins() != 0) {
    _internal_set_pins(from._internal_pins());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.Spark3Pins.Block)
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
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, pins_)
      + sizeof(Block::pins_)
      - PROTOBUF_FIELD_OFFSET(Block, voltage5_)>(
          reinterpret_cast<char*>(&voltage5_),
          reinterpret_cast<char*>(&other->voltage5_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Spark3Pins_5ftest_2eproto_getter, &descriptor_table_Spark3Pins_5ftest_2eproto_once,
      file_level_metadata_Spark3Pins_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Spark3Pins
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::Spark3Pins::Block*
Arena::CreateMaybeMessage< ::blox_test::Spark3Pins::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::Spark3Pins::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
