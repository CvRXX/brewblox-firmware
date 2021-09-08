// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorMock_test.proto

#include "TempSensorMock_test.pb.h"

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
constexpr Fluctuation::Fluctuation(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : amplitude_(0)
  , period_(0u){}
struct FluctuationDefaultTypeInternal {
  constexpr FluctuationDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~FluctuationDefaultTypeInternal() {}
  union {
    Fluctuation _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT FluctuationDefaultTypeInternal _Fluctuation_default_instance_;
constexpr TempSensorMock::TempSensorMock(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : fluctuations_()
  , strippedfields_()
  , _strippedfields_cached_byte_size_(0)
  , value_(0)
  , connected_(false)
  , setting_(0){}
struct TempSensorMockDefaultTypeInternal {
  constexpr TempSensorMockDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TempSensorMockDefaultTypeInternal() {}
  union {
    TempSensorMock _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TempSensorMockDefaultTypeInternal _TempSensorMock_default_instance_;
}  // namespace blox
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_TempSensorMock_5ftest_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_TempSensorMock_5ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_TempSensorMock_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_TempSensorMock_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::Fluctuation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::Fluctuation, amplitude_),
  PROTOBUF_FIELD_OFFSET(::blox::Fluctuation, period_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, value_),
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, connected_),
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, setting_),
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, fluctuations_),
  PROTOBUF_FIELD_OFFSET(::blox::TempSensorMock, strippedfields_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::Fluctuation)},
  { 7, -1, sizeof(::blox::TempSensorMock)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_Fluctuation_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_TempSensorMock_default_instance_),
};

const char descriptor_table_protodef_TempSensorMock_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031TempSensorMock_test.proto\022\004blox\032\023brewb"
  "lox_test.proto\032\021nanopb_test.proto\"^\n\013Flu"
  "ctuation\022+\n\tamplitude\030\001 \001(\021B\030\212\265\030\0020\001\212\265\030\002\010"
  "\006\212\265\030\003\020\200 \222\?\0028 \022\"\n\006period\030\002 \001(\rB\022\212\265\030\002\010\003\212\265\030"
  "\003\020\350\007\222\?\0028 \"\341\001\n\016TempSensorMock\022-\n\005value\030\001 "
  "\001(\021B\036\212\265\030\0020\001\212\265\030\002\010\001\212\265\030\003\020\200 \212\265\030\002(\001\222\?\0028 \022\031\n\tc"
  "onnected\030\003 \001(\010B\006\212\265\030\0020\001\022#\n\007setting\030\004 \001(\021B"
  "\022\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \022\'\n\014fluctuations\030\005 \003("
  "\0132\021.blox.Fluctuation\022(\n\016strippedFields\030c"
  " \003(\rB\020\212\265\030\002(\001\222\?\0028\020\222\?\002\020\001:\r\212\265\030\003\030\255\002\212\265\030\002H\002b\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_TempSensorMock_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_TempSensorMock_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TempSensorMock_5ftest_2eproto = {
  false, false, 405, descriptor_table_protodef_TempSensorMock_5ftest_2eproto, "TempSensorMock_test.proto", 
  &descriptor_table_TempSensorMock_5ftest_2eproto_once, descriptor_table_TempSensorMock_5ftest_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_TempSensorMock_5ftest_2eproto::offsets,
  file_level_metadata_TempSensorMock_5ftest_2eproto, file_level_enum_descriptors_TempSensorMock_5ftest_2eproto, file_level_service_descriptors_TempSensorMock_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_TempSensorMock_5ftest_2eproto_getter() {
  return &descriptor_table_TempSensorMock_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_TempSensorMock_5ftest_2eproto(&descriptor_table_TempSensorMock_5ftest_2eproto);
namespace blox {

// ===================================================================

class Fluctuation::_Internal {
 public:
};

Fluctuation::Fluctuation(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.Fluctuation)
}
Fluctuation::Fluctuation(const Fluctuation& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&amplitude_, &from.amplitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&period_) -
    reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
  // @@protoc_insertion_point(copy_constructor:blox.Fluctuation)
}

inline void Fluctuation::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&amplitude_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&period_) -
    reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
}

Fluctuation::~Fluctuation() {
  // @@protoc_insertion_point(destructor:blox.Fluctuation)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Fluctuation::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Fluctuation::ArenaDtor(void* object) {
  Fluctuation* _this = reinterpret_cast< Fluctuation* >(object);
  (void)_this;
}
void Fluctuation::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Fluctuation::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Fluctuation::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.Fluctuation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&amplitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&period_) -
      reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Fluctuation::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // sint32 amplitude = 1 [(.nanopb_test) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          amplitude_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 period = 2 [(.nanopb_test) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          period_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* Fluctuation::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.Fluctuation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 amplitude = 1 [(.nanopb_test) = {
  if (this->_internal_amplitude() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(1, this->_internal_amplitude(), target);
  }

  // uint32 period = 2 [(.nanopb_test) = {
  if (this->_internal_period() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_period(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.Fluctuation)
  return target;
}

size_t Fluctuation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.Fluctuation)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // sint32 amplitude = 1 [(.nanopb_test) = {
  if (this->_internal_amplitude() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_amplitude());
  }

  // uint32 period = 2 [(.nanopb_test) = {
  if (this->_internal_period() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_period());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Fluctuation::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Fluctuation::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Fluctuation::GetClassData() const { return &_class_data_; }

void Fluctuation::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<Fluctuation *>(to)->MergeFrom(
      static_cast<const Fluctuation &>(from));
}


void Fluctuation::MergeFrom(const Fluctuation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.Fluctuation)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_amplitude() != 0) {
    _internal_set_amplitude(from._internal_amplitude());
  }
  if (from._internal_period() != 0) {
    _internal_set_period(from._internal_period());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Fluctuation::CopyFrom(const Fluctuation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.Fluctuation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Fluctuation::IsInitialized() const {
  return true;
}

void Fluctuation::InternalSwap(Fluctuation* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Fluctuation, period_)
      + sizeof(Fluctuation::period_)
      - PROTOBUF_FIELD_OFFSET(Fluctuation, amplitude_)>(
          reinterpret_cast<char*>(&amplitude_),
          reinterpret_cast<char*>(&other->amplitude_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Fluctuation::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_TempSensorMock_5ftest_2eproto_getter, &descriptor_table_TempSensorMock_5ftest_2eproto_once,
      file_level_metadata_TempSensorMock_5ftest_2eproto[0]);
}

// ===================================================================

class TempSensorMock::_Internal {
 public:
};

TempSensorMock::TempSensorMock(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  fluctuations_(arena),
  strippedfields_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.TempSensorMock)
}
TempSensorMock::TempSensorMock(const TempSensorMock& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      fluctuations_(from.fluctuations_),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&value_, &from.value_,
    static_cast<size_t>(reinterpret_cast<char*>(&setting_) -
    reinterpret_cast<char*>(&value_)) + sizeof(setting_));
  // @@protoc_insertion_point(copy_constructor:blox.TempSensorMock)
}

inline void TempSensorMock::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&value_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&setting_) -
    reinterpret_cast<char*>(&value_)) + sizeof(setting_));
}

TempSensorMock::~TempSensorMock() {
  // @@protoc_insertion_point(destructor:blox.TempSensorMock)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void TempSensorMock::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void TempSensorMock::ArenaDtor(void* object) {
  TempSensorMock* _this = reinterpret_cast< TempSensorMock* >(object);
  (void)_this;
}
void TempSensorMock::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TempSensorMock::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void TempSensorMock::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.TempSensorMock)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  fluctuations_.Clear();
  strippedfields_.Clear();
  ::memset(&value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&setting_) -
      reinterpret_cast<char*>(&value_)) + sizeof(setting_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TempSensorMock::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // sint32 value = 1 [(.nanopb_test) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          value_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool connected = 3 [(.brewblox_test) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          connected_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // sint32 setting = 4 [(.nanopb_test) = {
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          setting_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .blox.Fluctuation fluctuations = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_fluctuations(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* TempSensorMock::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.TempSensorMock)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 value = 1 [(.nanopb_test) = {
  if (this->_internal_value() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(1, this->_internal_value(), target);
  }

  // bool connected = 3 [(.brewblox_test) = {
  if (this->_internal_connected() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(3, this->_internal_connected(), target);
  }

  // sint32 setting = 4 [(.nanopb_test) = {
  if (this->_internal_setting() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(4, this->_internal_setting(), target);
  }

  // repeated .blox.Fluctuation fluctuations = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_fluctuations_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_fluctuations(i), target, stream);
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
  // @@protoc_insertion_point(serialize_to_array_end:blox.TempSensorMock)
  return target;
}

size_t TempSensorMock::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.TempSensorMock)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox.Fluctuation fluctuations = 5;
  total_size += 1UL * this->_internal_fluctuations_size();
  for (const auto& msg : this->fluctuations_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

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

  // sint32 value = 1 [(.nanopb_test) = {
  if (this->_internal_value() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_value());
  }

  // bool connected = 3 [(.brewblox_test) = {
  if (this->_internal_connected() != 0) {
    total_size += 1 + 1;
  }

  // sint32 setting = 4 [(.nanopb_test) = {
  if (this->_internal_setting() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_setting());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData TempSensorMock::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    TempSensorMock::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*TempSensorMock::GetClassData() const { return &_class_data_; }

void TempSensorMock::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<TempSensorMock *>(to)->MergeFrom(
      static_cast<const TempSensorMock &>(from));
}


void TempSensorMock::MergeFrom(const TempSensorMock& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.TempSensorMock)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  fluctuations_.MergeFrom(from.fluctuations_);
  strippedfields_.MergeFrom(from.strippedfields_);
  if (from._internal_value() != 0) {
    _internal_set_value(from._internal_value());
  }
  if (from._internal_connected() != 0) {
    _internal_set_connected(from._internal_connected());
  }
  if (from._internal_setting() != 0) {
    _internal_set_setting(from._internal_setting());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void TempSensorMock::CopyFrom(const TempSensorMock& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.TempSensorMock)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TempSensorMock::IsInitialized() const {
  return true;
}

void TempSensorMock::InternalSwap(TempSensorMock* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  fluctuations_.InternalSwap(&other->fluctuations_);
  strippedfields_.InternalSwap(&other->strippedfields_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TempSensorMock, setting_)
      + sizeof(TempSensorMock::setting_)
      - PROTOBUF_FIELD_OFFSET(TempSensorMock, value_)>(
          reinterpret_cast<char*>(&value_),
          reinterpret_cast<char*>(&other->value_));
}

::PROTOBUF_NAMESPACE_ID::Metadata TempSensorMock::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_TempSensorMock_5ftest_2eproto_getter, &descriptor_table_TempSensorMock_5ftest_2eproto_once,
      file_level_metadata_TempSensorMock_5ftest_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox::Fluctuation* Arena::CreateMaybeMessage< ::blox::Fluctuation >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::Fluctuation >(arena);
}
template<> PROTOBUF_NOINLINE ::blox::TempSensorMock* Arena::CreateMaybeMessage< ::blox::TempSensorMock >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::TempSensorMock >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
