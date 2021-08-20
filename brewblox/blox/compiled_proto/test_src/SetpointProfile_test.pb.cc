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
namespace blox {
constexpr Point::Point(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : time_(0u)
  , _oneof_case_{}{}
struct PointDefaultTypeInternal {
  constexpr PointDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PointDefaultTypeInternal() {}
  union {
    Point _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PointDefaultTypeInternal _Point_default_instance_;
constexpr SetpointProfile::SetpointProfile(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : points_()
  , enabled_(false)
  , targetid_(0u)
  , driventargetid_(0u)
  , start_(0u){}
struct SetpointProfileDefaultTypeInternal {
  constexpr SetpointProfileDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~SetpointProfileDefaultTypeInternal() {}
  union {
    SetpointProfile _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT SetpointProfileDefaultTypeInternal _SetpointProfile_default_instance_;
}  // namespace blox
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_SetpointProfile_5ftest_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_SetpointProfile_5ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_SetpointProfile_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_SetpointProfile_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::Point, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::blox::Point, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::Point, time_),
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::blox::Point, temperature_oneof_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, points_),
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, enabled_),
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, targetid_),
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, driventargetid_),
  PROTOBUF_FIELD_OFFSET(::blox::SetpointProfile, start_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::Point)},
  { 8, -1, sizeof(::blox::SetpointProfile)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_Point_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_SetpointProfile_default_instance_),
};

const char descriptor_table_protodef_SetpointProfile_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032SetpointProfile_test.proto\022\004blox\032\023brew"
  "blox_test.proto\032\021nanopb_test.proto\"U\n\005Po"
  "int\022\014\n\004time\030\001 \001(\r\022)\n\013temperature\030\002 \001(\005B\022"
  "\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 H\000B\023\n\021temperature_oneo"
  "f\"\251\001\n\017SetpointProfile\022\033\n\006points\030\001 \003(\0132\013."
  "blox.Point\022\017\n\007enabled\030\003 \001(\010\022\036\n\010targetId\030"
  "\004 \001(\rB\014\212\265\030\003\030\257\002\222\?\0028\020\0220\n\016drivenTargetId\030\005 "
  "\001(\rB\030\212\265\030\003\030\257\002\212\265\030\002@\001\222\?\0028\020\212\265\030\002(\001\022\r\n\005start\030\006"
  " \001(\r:\007\212\265\030\003\030\267\002b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_SetpointProfile_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_SetpointProfile_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_SetpointProfile_5ftest_2eproto = {
  false, false, 341, descriptor_table_protodef_SetpointProfile_5ftest_2eproto, "SetpointProfile_test.proto", 
  &descriptor_table_SetpointProfile_5ftest_2eproto_once, descriptor_table_SetpointProfile_5ftest_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_SetpointProfile_5ftest_2eproto::offsets,
  file_level_metadata_SetpointProfile_5ftest_2eproto, file_level_enum_descriptors_SetpointProfile_5ftest_2eproto, file_level_service_descriptors_SetpointProfile_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_SetpointProfile_5ftest_2eproto_getter() {
  return &descriptor_table_SetpointProfile_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_SetpointProfile_5ftest_2eproto(&descriptor_table_SetpointProfile_5ftest_2eproto);
namespace blox {

// ===================================================================

class Point::_Internal {
 public:
};

Point::Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.Point)
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
  // @@protoc_insertion_point(copy_constructor:blox.Point)
}

inline void Point::SharedCtor() {
time_ = 0u;
clear_has_temperature_oneof();
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:blox.Point)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Point::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has_temperature_oneof()) {
    clear_temperature_oneof();
  }
}

void Point::ArenaDtor(void* object) {
  Point* _this = reinterpret_cast< Point* >(object);
  (void)_this;
}
void Point::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Point::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Point::clear_temperature_oneof() {
// @@protoc_insertion_point(one_of_clear_start:blox.Point)
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
// @@protoc_insertion_point(message_clear_start:blox.Point)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  time_ = 0u;
  clear_temperature_oneof();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Point::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 temperature = 2 [(.nanopb_test) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _internal_set_temperature(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Point::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.Point)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 time = 1;
  if (this->_internal_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_time(), target);
  }

  // int32 temperature = 2 [(.nanopb_test) = {
  if (_internal_has_temperature()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_temperature(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.Point)
  return target;
}

size_t Point::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.Point)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 time = 1;
  if (this->_internal_time() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_time());
  }

  switch (temperature_oneof_case()) {
    // int32 temperature = 2 [(.nanopb_test) = {
    case kTemperature: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_temperature());
      break;
    }
    case TEMPERATURE_ONEOF_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Point::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Point::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Point::GetClassData() const { return &_class_data_; }

void Point::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Point *>(to)->MergeFrom(
      static_cast<const Point &>(from));
}


void Point::MergeFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.Point)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
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
// @@protoc_insertion_point(class_specific_copy_from_start:blox.Point)
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
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_SetpointProfile_5ftest_2eproto_getter, &descriptor_table_SetpointProfile_5ftest_2eproto_once,
      file_level_metadata_SetpointProfile_5ftest_2eproto[0]);
}

// ===================================================================

class SetpointProfile::_Internal {
 public:
};

SetpointProfile::SetpointProfile(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  points_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.SetpointProfile)
}
SetpointProfile::SetpointProfile(const SetpointProfile& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      points_(from.points_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&enabled_, &from.enabled_,
    static_cast<size_t>(reinterpret_cast<char*>(&start_) -
    reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
  // @@protoc_insertion_point(copy_constructor:blox.SetpointProfile)
}

inline void SetpointProfile::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&enabled_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&start_) -
    reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
}

SetpointProfile::~SetpointProfile() {
  // @@protoc_insertion_point(destructor:blox.SetpointProfile)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void SetpointProfile::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void SetpointProfile::ArenaDtor(void* object) {
  SetpointProfile* _this = reinterpret_cast< SetpointProfile* >(object);
  (void)_this;
}
void SetpointProfile::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SetpointProfile::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void SetpointProfile::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.SetpointProfile)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  points_.Clear();
  ::memset(&enabled_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&start_) -
      reinterpret_cast<char*>(&enabled_)) + sizeof(start_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SetpointProfile::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .blox.Point points = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_points(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // bool enabled = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          enabled_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 targetId = 4 [(.nanopb_test) = {
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          targetid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 drivenTargetId = 5 [(.nanopb_test) = {
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          driventargetid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 start = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          start_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SetpointProfile::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.SetpointProfile)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox.Point points = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_points_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_points(i), target, stream);
  }

  // bool enabled = 3;
  if (this->_internal_enabled() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_enabled(), target);
  }

  // uint32 targetId = 4 [(.nanopb_test) = {
  if (this->_internal_targetid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_targetid(), target);
  }

  // uint32 drivenTargetId = 5 [(.nanopb_test) = {
  if (this->_internal_driventargetid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(5, this->_internal_driventargetid(), target);
  }

  // uint32 start = 6;
  if (this->_internal_start() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(6, this->_internal_start(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.SetpointProfile)
  return target;
}

size_t SetpointProfile::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.SetpointProfile)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox.Point points = 1;
  total_size += 1UL * this->_internal_points_size();
  for (const auto& msg : this->points_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bool enabled = 3;
  if (this->_internal_enabled() != 0) {
    total_size += 1 + 1;
  }

  // uint32 targetId = 4 [(.nanopb_test) = {
  if (this->_internal_targetid() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_targetid());
  }

  // uint32 drivenTargetId = 5 [(.nanopb_test) = {
  if (this->_internal_driventargetid() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_driventargetid());
  }

  // uint32 start = 6;
  if (this->_internal_start() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_start());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData SetpointProfile::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    SetpointProfile::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*SetpointProfile::GetClassData() const { return &_class_data_; }

void SetpointProfile::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<SetpointProfile *>(to)->MergeFrom(
      static_cast<const SetpointProfile &>(from));
}


void SetpointProfile::MergeFrom(const SetpointProfile& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.SetpointProfile)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
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

void SetpointProfile::CopyFrom(const SetpointProfile& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.SetpointProfile)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SetpointProfile::IsInitialized() const {
  return true;
}

void SetpointProfile::InternalSwap(SetpointProfile* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  points_.InternalSwap(&other->points_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(SetpointProfile, start_)
      + sizeof(SetpointProfile::start_)
      - PROTOBUF_FIELD_OFFSET(SetpointProfile, enabled_)>(
          reinterpret_cast<char*>(&enabled_),
          reinterpret_cast<char*>(&other->enabled_));
}

::PROTOBUF_NAMESPACE_ID::Metadata SetpointProfile::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_SetpointProfile_5ftest_2eproto_getter, &descriptor_table_SetpointProfile_5ftest_2eproto_once,
      file_level_metadata_SetpointProfile_5ftest_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox::Point* Arena::CreateMaybeMessage< ::blox::Point >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::Point >(arena);
}
template<> PROTOBUF_NOINLINE ::blox::SetpointProfile* Arena::CreateMaybeMessage< ::blox::SetpointProfile >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::SetpointProfile >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
