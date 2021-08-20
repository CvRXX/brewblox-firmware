// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Mutex_test.proto

#include "Mutex_test.pb.h"

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
constexpr Mutex::Mutex(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : differentactuatorwait_(0u)
  , waitremaining_(0u){}
struct MutexDefaultTypeInternal {
  constexpr MutexDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~MutexDefaultTypeInternal() {}
  union {
    Mutex _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT MutexDefaultTypeInternal _Mutex_default_instance_;
}  // namespace blox
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Mutex_5ftest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Mutex_5ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Mutex_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Mutex_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::Mutex, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::Mutex, differentactuatorwait_),
  PROTOBUF_FIELD_OFFSET(::blox::Mutex, waitremaining_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::Mutex)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_Mutex_default_instance_),
};

const char descriptor_table_protodef_Mutex_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020Mutex_test.proto\022\004blox\032\023brewblox_test."
  "proto\032\021nanopb_test.proto\"u\n\005Mutex\022,\n\025dif"
  "ferentActuatorWait\030\001 \001(\rB\r\212\265\030\002\010\003\212\265\030\003\020\350\007\022"
  "/\n\rwaitRemaining\030\002 \001(\rB\030\212\265\030\002(\001\212\265\030\002\010\003\212\265\030\003"
  "\020\350\007\222\?\0028 :\r\212\265\030\003\030\266\002\212\265\030\002H\010b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Mutex_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Mutex_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Mutex_5ftest_2eproto = {
  false, false, 191, descriptor_table_protodef_Mutex_5ftest_2eproto, "Mutex_test.proto", 
  &descriptor_table_Mutex_5ftest_2eproto_once, descriptor_table_Mutex_5ftest_2eproto_deps, 2, 1,
  schemas, file_default_instances, TableStruct_Mutex_5ftest_2eproto::offsets,
  file_level_metadata_Mutex_5ftest_2eproto, file_level_enum_descriptors_Mutex_5ftest_2eproto, file_level_service_descriptors_Mutex_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Mutex_5ftest_2eproto_getter() {
  return &descriptor_table_Mutex_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Mutex_5ftest_2eproto(&descriptor_table_Mutex_5ftest_2eproto);
namespace blox {

// ===================================================================

class Mutex::_Internal {
 public:
};

Mutex::Mutex(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.Mutex)
}
Mutex::Mutex(const Mutex& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&differentactuatorwait_, &from.differentactuatorwait_,
    static_cast<size_t>(reinterpret_cast<char*>(&waitremaining_) -
    reinterpret_cast<char*>(&differentactuatorwait_)) + sizeof(waitremaining_));
  // @@protoc_insertion_point(copy_constructor:blox.Mutex)
}

inline void Mutex::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&differentactuatorwait_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&waitremaining_) -
    reinterpret_cast<char*>(&differentactuatorwait_)) + sizeof(waitremaining_));
}

Mutex::~Mutex() {
  // @@protoc_insertion_point(destructor:blox.Mutex)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Mutex::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Mutex::ArenaDtor(void* object) {
  Mutex* _this = reinterpret_cast< Mutex* >(object);
  (void)_this;
}
void Mutex::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Mutex::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Mutex::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.Mutex)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&differentactuatorwait_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&waitremaining_) -
      reinterpret_cast<char*>(&differentactuatorwait_)) + sizeof(waitremaining_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Mutex::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 differentActuatorWait = 1 [(.brewblox_test) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          differentactuatorwait_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 waitRemaining = 2 [(.nanopb_test) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          waitremaining_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Mutex::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.Mutex)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 differentActuatorWait = 1 [(.brewblox_test) = {
  if (this->_internal_differentactuatorwait() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_differentactuatorwait(), target);
  }

  // uint32 waitRemaining = 2 [(.nanopb_test) = {
  if (this->_internal_waitremaining() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_waitremaining(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.Mutex)
  return target;
}

size_t Mutex::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.Mutex)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 differentActuatorWait = 1 [(.brewblox_test) = {
  if (this->_internal_differentactuatorwait() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_differentactuatorwait());
  }

  // uint32 waitRemaining = 2 [(.nanopb_test) = {
  if (this->_internal_waitremaining() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_waitremaining());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Mutex::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Mutex::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Mutex::GetClassData() const { return &_class_data_; }

void Mutex::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Mutex *>(to)->MergeFrom(
      static_cast<const Mutex &>(from));
}


void Mutex::MergeFrom(const Mutex& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.Mutex)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_differentactuatorwait() != 0) {
    _internal_set_differentactuatorwait(from._internal_differentactuatorwait());
  }
  if (from._internal_waitremaining() != 0) {
    _internal_set_waitremaining(from._internal_waitremaining());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Mutex::CopyFrom(const Mutex& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.Mutex)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Mutex::IsInitialized() const {
  return true;
}

void Mutex::InternalSwap(Mutex* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Mutex, waitremaining_)
      + sizeof(Mutex::waitremaining_)
      - PROTOBUF_FIELD_OFFSET(Mutex, differentactuatorwait_)>(
          reinterpret_cast<char*>(&differentactuatorwait_),
          reinterpret_cast<char*>(&other->differentactuatorwait_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Mutex::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Mutex_5ftest_2eproto_getter, &descriptor_table_Mutex_5ftest_2eproto_once,
      file_level_metadata_Mutex_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox::Mutex* Arena::CreateMaybeMessage< ::blox::Mutex >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::Mutex >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
