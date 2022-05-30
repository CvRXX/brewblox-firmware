// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SetpointProfile_test.proto

#include "SetpointProfile_test.pb.h"

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
namespace SetpointProfile {
PROTOBUF_CONSTEXPR Point::Point(
    ::_pbi::ConstantInitialized)
  : time_(0u)
  , _oneof_case_{}{}
struct PointDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PointDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PointDefaultTypeInternal() {}
  union {
    Point _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PointDefaultTypeInternal _Point_default_instance_;
PROTOBUF_CONSTEXPR Block::Block(
    ::_pbi::ConstantInitialized)
  : points_()
  , enabled_(false)
  , targetid_(0u)
  , driventargetid_(0u)
  , start_(0u){}
struct BlockDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BlockDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace SetpointProfile
}  // namespace blox_test
static ::_pb::Metadata file_level_metadata_SetpointProfile_5ftest_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_SetpointProfile_5ftest_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_SetpointProfile_5ftest_2eproto = nullptr;

const uint32_t TableStruct_SetpointProfile_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Point, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Point, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Point, time_),
  ::_pbi::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Point, temperature_oneof_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, points_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, enabled_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, targetid_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, driventargetid_),
  PROTOBUF_FIELD_OFFSET(::blox_test::SetpointProfile::Block, start_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::blox_test::SetpointProfile::Point)},
  { 9, -1, -1, sizeof(::blox_test::SetpointProfile::Block)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::blox_test::SetpointProfile::_Point_default_instance_._instance,
  &::blox_test::SetpointProfile::_Block_default_instance_._instance,
};

const char descriptor_table_protodef_SetpointProfile_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032SetpointProfile_test.proto\022\031blox_test."
  "SetpointProfile\032\023brewblox_test.proto\032\021na"
  "nopb_test.proto\"U\n\005Point\022\014\n\004time\030\001 \001(\r\022)"
  "\n\013temperature\030\002 \001(\005B\022\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 H"
  "\000B\023\n\021temperature_oneof\"\272\001\n\005Block\0220\n\006poin"
  "ts\030\001 \003(\0132 .blox_test.SetpointProfile.Poi"
  "nt\022\017\n\007enabled\030\003 \001(\010\022\036\n\010targetId\030\004 \001(\rB\014\212"
  "\265\030\003\030\257\002\222\?\0028\020\0220\n\016drivenTargetId\030\005 \001(\rB\030\212\265\030"
  "\003\030\257\002\212\265\030\002@\001\222\?\0028\020\212\265\030\002(\001\022\r\n\005start\030\006 \001(\r:\r\212\265"
  "\030\003\030\267\002\212\265\030\002H\017b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_SetpointProfile_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::_pbi::once_flag descriptor_table_SetpointProfile_5ftest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_SetpointProfile_5ftest_2eproto = {
    false, false, 379, descriptor_table_protodef_SetpointProfile_5ftest_2eproto,
    "SetpointProfile_test.proto",
    &descriptor_table_SetpointProfile_5ftest_2eproto_once, descriptor_table_SetpointProfile_5ftest_2eproto_deps, 2, 2,
    schemas, file_default_instances, TableStruct_SetpointProfile_5ftest_2eproto::offsets,
    file_level_metadata_SetpointProfile_5ftest_2eproto, file_level_enum_descriptors_SetpointProfile_5ftest_2eproto,
    file_level_service_descriptors_SetpointProfile_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_SetpointProfile_5ftest_2eproto_getter() {
  return &descriptor_table_SetpointProfile_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_SetpointProfile_5ftest_2eproto(&descriptor_table_SetpointProfile_5ftest_2eproto);
namespace blox_test {
namespace SetpointProfile {

// ===================================================================

class Point::_Internal {
 public:
};

Point::Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.SetpointProfile.Point)
}
Point::Point(const Point& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  time_ = from.time_;
  clear_has_temperature_oneof();
  switch (from.temperature_oneof_case()) {
    case kTemperature: {
      _internal_set_temperature(from._internal_temperature());
      break;
    }
    case TEMPERATURE_ONEOF_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:blox_test.SetpointProfile.Point)
}

inline void Point::SharedCtor() {
time_ = 0u;
clear_has_temperature_oneof();
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:blox_test.SetpointProfile.Point)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Point::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_temperature_oneof()) {
    clear_temperature_oneof();
  }
}

void Point::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Point::clear_temperature_oneof() {
// @@protoc_insertion_point(one_of_clear_start:blox_test.SetpointProfile.Point)
  switch (temperature_oneof_case()) {
    case kTemperature: {
      // No need to clear
      break;
    }
    case TEMPERATURE_ONEOF_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = TEMPERATURE_ONEOF_NOT_SET;
}


void Point::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.SetpointProfile.Point)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  time_ = 0u;
  clear_temperature_oneof();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Point::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 temperature = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _internal_set_temperature(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
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

uint8_t* Point::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.SetpointProfile.Point)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 time = 1;
  if (this->_internal_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_time(), target);
  }

  // int32 temperature = 2 [(.nanopb) = {
  if (_internal_has_temperature()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_temperature(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.SetpointProfile.Point)
  return target;
}

size_t Point::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.SetpointProfile.Point)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 time = 1;
  if (this->_internal_time() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_time());
  }

  switch (temperature_oneof_case()) {
    // int32 temperature = 2 [(.nanopb) = {
    case kTemperature: {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_temperature());
      break;
    }
    case TEMPERATURE_ONEOF_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Point::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Point::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Point::GetClassData() const { return &_class_data_; }

void Point::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Point *>(to)->MergeFrom(
      static_cast<const Point &>(from));
}


void Point::MergeFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.SetpointProfile.Point)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_time() != 0) {
    _internal_set_time(from._internal_time());
  }
  switch (from.temperature_oneof_case()) {
    case kTemperature: {
      _internal_set_temperature(from._internal_temperature());
      break;
    }
    case TEMPERATURE_ONEOF_NOT_SET: {
      break;
    }
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Point::CopyFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.SetpointProfile.Point)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Point::IsInitialized() const {
  return true;
}

void Point::InternalSwap(Point* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(time_, other->time_);
  swap(temperature_oneof_, other->temperature_oneof_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Point::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_SetpointProfile_5ftest_2eproto_getter, &descriptor_table_SetpointProfile_5ftest_2eproto_once,
      file_level_metadata_SetpointProfile_5ftest_2eproto[0]);
}

// ===================================================================

class Block::_Internal {
 public:
};

Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  points_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:blox_test.SetpointProfile.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      points_(from.points_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&enabled_, &from.enabled_,
    static_cast<size_t>(reinterpret_cast<char*>(&start_) -
    reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
  // @@protoc_insertion_point(copy_constructor:blox_test.SetpointProfile.Block)
}

inline void Block::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&enabled_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&start_) -
    reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.SetpointProfile.Block)
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
// @@protoc_insertion_point(message_clear_start:blox_test.SetpointProfile.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  points_.Clear();
  ::memset(&enabled_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&start_) -
      reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .blox_test.SetpointProfile.Point points = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_points(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      // bool enabled = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          enabled_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 targetId = 4 [(.nanopb) = {
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          targetid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 drivenTargetId = 5 [(.nanopb) = {
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          driventargetid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 start = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          start_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.SetpointProfile.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.SetpointProfile.Point points = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_points_size()); i < n; i++) {
    const auto& repfield = this->_internal_points(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  // bool enabled = 3;
  if (this->_internal_enabled() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(3, this->_internal_enabled(), target);
  }

  // uint32 targetId = 4 [(.nanopb) = {
  if (this->_internal_targetid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_targetid(), target);
  }

  // uint32 drivenTargetId = 5 [(.nanopb) = {
  if (this->_internal_driventargetid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(5, this->_internal_driventargetid(), target);
  }

  // uint32 start = 6;
  if (this->_internal_start() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(6, this->_internal_start(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.SetpointProfile.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.SetpointProfile.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.SetpointProfile.Point points = 1;
  total_size += 1UL * this->_internal_points_size();
  for (const auto& msg : this->points_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bool enabled = 3;
  if (this->_internal_enabled() != 0) {
    total_size += 1 + 1;
  }

  // uint32 targetId = 4 [(.nanopb) = {
  if (this->_internal_targetid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_targetid());
  }

  // uint32 drivenTargetId = 5 [(.nanopb) = {
  if (this->_internal_driventargetid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_driventargetid());
  }

  // uint32 start = 6;
  if (this->_internal_start() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_start());
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
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.SetpointProfile.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  points_.MergeFrom(from.points_);
  if (from._internal_enabled() != 0) {
    _internal_set_enabled(from._internal_enabled());
  }
  if (from._internal_targetid() != 0) {
    _internal_set_targetid(from._internal_targetid());
  }
  if (from._internal_driventargetid() != 0) {
    _internal_set_driventargetid(from._internal_driventargetid());
  }
  if (from._internal_start() != 0) {
    _internal_set_start(from._internal_start());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.SetpointProfile.Block)
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
  points_.InternalSwap(&other->points_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, start_)
      + sizeof(Block::start_)
      - PROTOBUF_FIELD_OFFSET(Block, enabled_)>(
          reinterpret_cast<char*>(&enabled_),
          reinterpret_cast<char*>(&other->enabled_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_SetpointProfile_5ftest_2eproto_getter, &descriptor_table_SetpointProfile_5ftest_2eproto_once,
      file_level_metadata_SetpointProfile_5ftest_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace SetpointProfile
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::SetpointProfile::Point*
Arena::CreateMaybeMessage< ::blox_test::SetpointProfile::Point >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::SetpointProfile::Point >(arena);
}
template<> PROTOBUF_NOINLINE ::blox_test::SetpointProfile::Block*
Arena::CreateMaybeMessage< ::blox_test::SetpointProfile::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::SetpointProfile::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
