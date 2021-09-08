// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DigitalActuator_test.proto

#include "DigitalActuator_test.pb.h"

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
constexpr DigitalActuator::DigitalActuator(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : strippedfields_()
  , _strippedfields_cached_byte_size_(0)
  , constrainedby_(nullptr)
  , hwdevice_(0u)
  , channel_(0u)
  , state_(0)

  , invert_(false)
  , desiredstate_(0)
{}
struct DigitalActuatorDefaultTypeInternal {
  constexpr DigitalActuatorDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DigitalActuatorDefaultTypeInternal() {}
  union {
    DigitalActuator _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DigitalActuatorDefaultTypeInternal _DigitalActuator_default_instance_;
}  // namespace blox
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_DigitalActuator_5ftest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_DigitalActuator_5ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_DigitalActuator_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_DigitalActuator_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, hwdevice_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, channel_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, state_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, invert_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, constrainedby_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, desiredstate_),
  PROTOBUF_FIELD_OFFSET(::blox::DigitalActuator, strippedfields_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::DigitalActuator)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_DigitalActuator_default_instance_),
};

const char descriptor_table_protodef_DigitalActuator_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032DigitalActuator_test.proto\022\004blox\032\023brew"
  "blox_test.proto\032\021nanopb_test.proto\032\035Digi"
  "talConstraints_test.proto\032\022IoArray_test."
  "proto\"\253\002\n\017DigitalActuator\022#\n\010hwDevice\030\001 "
  "\001(\rB\021\212\265\030\002\030\n\212\265\030\002@\001\222\?\0028\020\022\026\n\007channel\030\002 \001(\rB"
  "\005\222\?\0028\010\022/\n\005state\030\003 \001(\0162\022.blox.DigitalStat"
  "eB\014\212\265\030\0020\001\212\265\030\002(\001\022\016\n\006invert\030\004 \001(\010\022/\n\rconst"
  "rainedBy\030\005 \001(\0132\030.blox.DigitalConstraints"
  "\0220\n\014desiredState\030\006 \001(\0162\022.blox.DigitalSta"
  "teB\006\212\265\030\0020\001\022(\n\016strippedFields\030c \003(\rB\020\212\265\030\002"
  "(\001\222\?\0028\020\222\?\002\020\001:\r\212\265\030\003\030\276\002\212\265\030\002H\006b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_DigitalActuator_5ftest_2eproto_deps[4] = {
  &::descriptor_table_DigitalConstraints_5ftest_2eproto,
  &::descriptor_table_IoArray_5ftest_2eproto,
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_DigitalActuator_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_DigitalActuator_5ftest_2eproto = {
  false, false, 435, descriptor_table_protodef_DigitalActuator_5ftest_2eproto, "DigitalActuator_test.proto", 
  &descriptor_table_DigitalActuator_5ftest_2eproto_once, descriptor_table_DigitalActuator_5ftest_2eproto_deps, 4, 1,
  schemas, file_default_instances, TableStruct_DigitalActuator_5ftest_2eproto::offsets,
  file_level_metadata_DigitalActuator_5ftest_2eproto, file_level_enum_descriptors_DigitalActuator_5ftest_2eproto, file_level_service_descriptors_DigitalActuator_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_DigitalActuator_5ftest_2eproto_getter() {
  return &descriptor_table_DigitalActuator_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_DigitalActuator_5ftest_2eproto(&descriptor_table_DigitalActuator_5ftest_2eproto);
namespace blox {

// ===================================================================

class DigitalActuator::_Internal {
 public:
  static const ::blox::DigitalConstraints& constrainedby(const DigitalActuator* msg);
};

const ::blox::DigitalConstraints&
DigitalActuator::_Internal::constrainedby(const DigitalActuator* msg) {
  return *msg->constrainedby_;
}
void DigitalActuator::clear_constrainedby() {
  if (GetArenaForAllocation() == nullptr && constrainedby_ != nullptr) {
    delete constrainedby_;
  }
  constrainedby_ = nullptr;
}
DigitalActuator::DigitalActuator(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  strippedfields_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.DigitalActuator)
}
DigitalActuator::DigitalActuator(const DigitalActuator& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_constrainedby()) {
    constrainedby_ = new ::blox::DigitalConstraints(*from.constrainedby_);
  } else {
    constrainedby_ = nullptr;
  }
  ::memcpy(&hwdevice_, &from.hwdevice_,
    static_cast<size_t>(reinterpret_cast<char*>(&desiredstate_) -
    reinterpret_cast<char*>(&hwdevice_)) + sizeof(desiredstate_));
  // @@protoc_insertion_point(copy_constructor:blox.DigitalActuator)
}

inline void DigitalActuator::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&constrainedby_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&desiredstate_) -
    reinterpret_cast<char*>(&constrainedby_)) + sizeof(desiredstate_));
}

DigitalActuator::~DigitalActuator() {
  // @@protoc_insertion_point(destructor:blox.DigitalActuator)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void DigitalActuator::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete constrainedby_;
}

void DigitalActuator::ArenaDtor(void* object) {
  DigitalActuator* _this = reinterpret_cast< DigitalActuator* >(object);
  (void)_this;
}
void DigitalActuator::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DigitalActuator::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void DigitalActuator::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.DigitalActuator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  strippedfields_.Clear();
  if (GetArenaForAllocation() == nullptr && constrainedby_ != nullptr) {
    delete constrainedby_;
  }
  constrainedby_ = nullptr;
  ::memset(&hwdevice_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&desiredstate_) -
      reinterpret_cast<char*>(&hwdevice_)) + sizeof(desiredstate_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DigitalActuator::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 hwDevice = 1 [(.nanopb_test) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          hwdevice_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 channel = 2 [(.nanopb_test) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          channel_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .blox.DigitalState state = 3 [(.brewblox_test) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_state(static_cast<::blox::DigitalState>(val));
        } else goto handle_unusual;
        continue;
      // bool invert = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          invert_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .blox.DigitalConstraints constrainedBy = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_constrainedby(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .blox.DigitalState desiredState = 6 [(.brewblox_test) = {
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_desiredstate(static_cast<::blox::DigitalState>(val));
        } else goto handle_unusual;
        continue;
      // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
      case 99:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_strippedfields(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24) {
          _internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* DigitalActuator::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.DigitalActuator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  if (this->_internal_hwdevice() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_hwdevice(), target);
  }

  // uint32 channel = 2 [(.nanopb_test) = {
  if (this->_internal_channel() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_channel(), target);
  }

  // .blox.DigitalState state = 3 [(.brewblox_test) = {
  if (this->_internal_state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_state(), target);
  }

  // bool invert = 4;
  if (this->_internal_invert() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(4, this->_internal_invert(), target);
  }

  // .blox.DigitalConstraints constrainedBy = 5;
  if (this->_internal_has_constrainedby()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        5, _Internal::constrainedby(this), target, stream);
  }

  // .blox.DigitalState desiredState = 6 [(.brewblox_test) = {
  if (this->_internal_desiredstate() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      6, this->_internal_desiredstate(), target);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  {
    int byte_size = _strippedfields_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          99, _internal_strippedfields(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.DigitalActuator)
  return target;
}

size_t DigitalActuator::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.DigitalActuator)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      UInt32Size(this->strippedfields_);
    if (data_size > 0) {
      total_size += 2 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _strippedfields_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // .blox.DigitalConstraints constrainedBy = 5;
  if (this->_internal_has_constrainedby()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *constrainedby_);
  }

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  if (this->_internal_hwdevice() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_hwdevice());
  }

  // uint32 channel = 2 [(.nanopb_test) = {
  if (this->_internal_channel() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_channel());
  }

  // .blox.DigitalState state = 3 [(.brewblox_test) = {
  if (this->_internal_state() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_state());
  }

  // bool invert = 4;
  if (this->_internal_invert() != 0) {
    total_size += 1 + 1;
  }

  // .blox.DigitalState desiredState = 6 [(.brewblox_test) = {
  if (this->_internal_desiredstate() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_desiredstate());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData DigitalActuator::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    DigitalActuator::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*DigitalActuator::GetClassData() const { return &_class_data_; }

void DigitalActuator::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<DigitalActuator *>(to)->MergeFrom(
      static_cast<const DigitalActuator &>(from));
}


void DigitalActuator::MergeFrom(const DigitalActuator& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.DigitalActuator)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  strippedfields_.MergeFrom(from.strippedfields_);
  if (from._internal_has_constrainedby()) {
    _internal_mutable_constrainedby()->::blox::DigitalConstraints::MergeFrom(from._internal_constrainedby());
  }
  if (from._internal_hwdevice() != 0) {
    _internal_set_hwdevice(from._internal_hwdevice());
  }
  if (from._internal_channel() != 0) {
    _internal_set_channel(from._internal_channel());
  }
  if (from._internal_state() != 0) {
    _internal_set_state(from._internal_state());
  }
  if (from._internal_invert() != 0) {
    _internal_set_invert(from._internal_invert());
  }
  if (from._internal_desiredstate() != 0) {
    _internal_set_desiredstate(from._internal_desiredstate());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void DigitalActuator::CopyFrom(const DigitalActuator& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.DigitalActuator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DigitalActuator::IsInitialized() const {
  return true;
}

void DigitalActuator::InternalSwap(DigitalActuator* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  strippedfields_.InternalSwap(&other->strippedfields_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(DigitalActuator, desiredstate_)
      + sizeof(DigitalActuator::desiredstate_)
      - PROTOBUF_FIELD_OFFSET(DigitalActuator, constrainedby_)>(
          reinterpret_cast<char*>(&constrainedby_),
          reinterpret_cast<char*>(&other->constrainedby_));
}

::PROTOBUF_NAMESPACE_ID::Metadata DigitalActuator::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_DigitalActuator_5ftest_2eproto_getter, &descriptor_table_DigitalActuator_5ftest_2eproto_once,
      file_level_metadata_DigitalActuator_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox::DigitalActuator* Arena::CreateMaybeMessage< ::blox::DigitalActuator >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::DigitalActuator >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
