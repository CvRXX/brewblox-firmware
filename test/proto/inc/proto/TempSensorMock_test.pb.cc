// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorMock_test.proto

#include "TempSensorMock_test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_TempSensorMock_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_TempSensorMock_5ftest_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Fluctuation;
}  // namespace protobuf_TempSensorMock_5ftest_2eproto
namespace blox_test {
namespace TempSensorMock {
class FluctuationDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Fluctuation>
      _instance;
} _Fluctuation_default_instance_;
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace TempSensorMock
}  // namespace blox_test
namespace protobuf_TempSensorMock_5ftest_2eproto {
static void InitDefaultsFluctuation() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::TempSensorMock::_Fluctuation_default_instance_;
    new (ptr) ::blox_test::TempSensorMock::Fluctuation();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::TempSensorMock::Fluctuation::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Fluctuation =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsFluctuation}, {}};

static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::TempSensorMock::_Block_default_instance_;
    new (ptr) ::blox_test::TempSensorMock::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::TempSensorMock::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_TempSensorMock_5ftest_2eproto::scc_info_Fluctuation.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Fluctuation.base);
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Fluctuation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Fluctuation, amplitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Fluctuation, period_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, connected_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, setting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, fluctuations_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::TempSensorMock::Block, strippedfields_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::TempSensorMock::Fluctuation)},
  { 7, -1, sizeof(::blox_test::TempSensorMock::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::TempSensorMock::_Fluctuation_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::TempSensorMock::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "TempSensorMock_test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\031TempSensorMock_test.proto\022\030blox_test.T"
      "empSensorMock\032\023brewblox_test.proto\032\021nano"
      "pb_test.proto\"^\n\013Fluctuation\022+\n\tamplitud"
      "e\030\001 \001(\021B\030\212\265\030\0020\001\212\265\030\002\010\006\212\265\030\003\020\200 \222\?\0028 \022\"\n\006per"
      "iod\030\002 \001(\rB\022\212\265\030\002\010\003\212\265\030\003\020\350\007\222\?\0028 \"\354\001\n\005Block\022"
      "-\n\005value\030\001 \001(\021B\036\212\265\030\0020\001\212\265\030\002\010\001\212\265\030\003\020\200 \212\265\030\002("
      "\001\222\?\0028 \022\031\n\tconnected\030\003 \001(\010B\006\212\265\030\0020\001\022#\n\007set"
      "ting\030\004 \001(\021B\022\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \022;\n\014fluctu"
      "ations\030\005 \003(\0132%.blox_test.TempSensorMock."
      "Fluctuation\022(\n\016strippedFields\030c \003(\rB\020\212\265\030"
      "\002(\001\222\?\0028\020\222\?\002\020\001:\r\212\265\030\003\030\255\002\212\265\030\002H\002b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 436);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "TempSensorMock_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_TempSensorMock_5ftest_2eproto
namespace blox_test {
namespace TempSensorMock {

// ===================================================================

void Fluctuation::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Fluctuation::kAmplitudeFieldNumber;
const int Fluctuation::kPeriodFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Fluctuation::Fluctuation()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_TempSensorMock_5ftest_2eproto::scc_info_Fluctuation.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.TempSensorMock.Fluctuation)
}
Fluctuation::Fluctuation(const Fluctuation& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&amplitude_, &from.amplitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&period_) -
    reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
  // @@protoc_insertion_point(copy_constructor:blox_test.TempSensorMock.Fluctuation)
}

void Fluctuation::SharedCtor() {
  ::memset(&amplitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&period_) -
      reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
}

Fluctuation::~Fluctuation() {
  // @@protoc_insertion_point(destructor:blox_test.TempSensorMock.Fluctuation)
  SharedDtor();
}

void Fluctuation::SharedDtor() {
}

void Fluctuation::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Fluctuation::descriptor() {
  ::protobuf_TempSensorMock_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorMock_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Fluctuation& Fluctuation::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_TempSensorMock_5ftest_2eproto::scc_info_Fluctuation.base);
  return *internal_default_instance();
}


void Fluctuation::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.TempSensorMock.Fluctuation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&amplitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&period_) -
      reinterpret_cast<char*>(&amplitude_)) + sizeof(period_));
  _internal_metadata_.Clear();
}

bool Fluctuation::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.TempSensorMock.Fluctuation)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // sint32 amplitude = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &amplitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 period = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &period_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:blox_test.TempSensorMock.Fluctuation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.TempSensorMock.Fluctuation)
  return false;
#undef DO_
}

void Fluctuation::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.TempSensorMock.Fluctuation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 amplitude = 1 [(.nanopb) = {
  if (this->amplitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->amplitude(), output);
  }

  // uint32 period = 2 [(.nanopb) = {
  if (this->period() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->period(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.TempSensorMock.Fluctuation)
}

::google::protobuf::uint8* Fluctuation::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.TempSensorMock.Fluctuation)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 amplitude = 1 [(.nanopb) = {
  if (this->amplitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->amplitude(), target);
  }

  // uint32 period = 2 [(.nanopb) = {
  if (this->period() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->period(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.TempSensorMock.Fluctuation)
  return target;
}

size_t Fluctuation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.TempSensorMock.Fluctuation)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // sint32 amplitude = 1 [(.nanopb) = {
  if (this->amplitude() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->amplitude());
  }

  // uint32 period = 2 [(.nanopb) = {
  if (this->period() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->period());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Fluctuation::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.TempSensorMock.Fluctuation)
  GOOGLE_DCHECK_NE(&from, this);
  const Fluctuation* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Fluctuation>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.TempSensorMock.Fluctuation)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.TempSensorMock.Fluctuation)
    MergeFrom(*source);
  }
}

void Fluctuation::MergeFrom(const Fluctuation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.TempSensorMock.Fluctuation)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.amplitude() != 0) {
    set_amplitude(from.amplitude());
  }
  if (from.period() != 0) {
    set_period(from.period());
  }
}

void Fluctuation::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.TempSensorMock.Fluctuation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Fluctuation::CopyFrom(const Fluctuation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.TempSensorMock.Fluctuation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Fluctuation::IsInitialized() const {
  return true;
}

void Fluctuation::Swap(Fluctuation* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Fluctuation::InternalSwap(Fluctuation* other) {
  using std::swap;
  swap(amplitude_, other->amplitude_);
  swap(period_, other->period_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Fluctuation::GetMetadata() const {
  protobuf_TempSensorMock_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorMock_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kValueFieldNumber;
const int Block::kConnectedFieldNumber;
const int Block::kSettingFieldNumber;
const int Block::kFluctuationsFieldNumber;
const int Block::kStrippedFieldsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_TempSensorMock_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.TempSensorMock.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      fluctuations_(from.fluctuations_),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&value_, &from.value_,
    static_cast<size_t>(reinterpret_cast<char*>(&setting_) -
    reinterpret_cast<char*>(&value_)) + sizeof(setting_));
  // @@protoc_insertion_point(copy_constructor:blox_test.TempSensorMock.Block)
}

void Block::SharedCtor() {
  ::memset(&value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&setting_) -
      reinterpret_cast<char*>(&value_)) + sizeof(setting_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.TempSensorMock.Block)
  SharedDtor();
}

void Block::SharedDtor() {
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_TempSensorMock_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorMock_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_TempSensorMock_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.TempSensorMock.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  fluctuations_.Clear();
  strippedfields_.Clear();
  ::memset(&value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&setting_) -
      reinterpret_cast<char*>(&value_)) + sizeof(setting_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.TempSensorMock.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // sint32 value = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &value_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool connected = 3 [(.brewblox.field) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &connected_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 setting = 4 [(.nanopb) = {
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &setting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .blox_test.TempSensorMock.Fluctuation fluctuations = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_fluctuations()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint32 strippedFields = 99 [(.nanopb) = {
      case 99: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 794 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_strippedfields())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 792 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 2, 794u, input, this->mutable_strippedfields())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:blox_test.TempSensorMock.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.TempSensorMock.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.TempSensorMock.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 value = 1 [(.nanopb) = {
  if (this->value() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->value(), output);
  }

  // bool connected = 3 [(.brewblox.field) = {
  if (this->connected() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->connected(), output);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(4, this->setting(), output);
  }

  // repeated .blox_test.TempSensorMock.Fluctuation fluctuations = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->fluctuations_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5,
      this->fluctuations(static_cast<int>(i)),
      output);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb) = {
  if (this->strippedfields_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(99, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _strippedfields_cached_byte_size_));
  }
  for (int i = 0, n = this->strippedfields_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->strippedfields(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.TempSensorMock.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.TempSensorMock.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 value = 1 [(.nanopb) = {
  if (this->value() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->value(), target);
  }

  // bool connected = 3 [(.brewblox.field) = {
  if (this->connected() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->connected(), target);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(4, this->setting(), target);
  }

  // repeated .blox_test.TempSensorMock.Fluctuation fluctuations = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->fluctuations_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->fluctuations(static_cast<int>(i)), deterministic, target);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb) = {
  if (this->strippedfields_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      99,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _strippedfields_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->strippedfields_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.TempSensorMock.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.TempSensorMock.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .blox_test.TempSensorMock.Fluctuation fluctuations = 5;
  {
    unsigned int count = static_cast<unsigned int>(this->fluctuations_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->fluctuations(static_cast<int>(i)));
    }
  }

  // repeated uint32 strippedFields = 99 [(.nanopb) = {
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt32Size(this->strippedfields_);
    if (data_size > 0) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _strippedfields_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // sint32 value = 1 [(.nanopb) = {
  if (this->value() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->value());
  }

  // bool connected = 3 [(.brewblox.field) = {
  if (this->connected() != 0) {
    total_size += 1 + 1;
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->setting());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.TempSensorMock.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.TempSensorMock.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.TempSensorMock.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.TempSensorMock.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  fluctuations_.MergeFrom(from.fluctuations_);
  strippedfields_.MergeFrom(from.strippedfields_);
  if (from.value() != 0) {
    set_value(from.value());
  }
  if (from.connected() != 0) {
    set_connected(from.connected());
  }
  if (from.setting() != 0) {
    set_setting(from.setting());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.TempSensorMock.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.TempSensorMock.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::Swap(Block* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Block::InternalSwap(Block* other) {
  using std::swap;
  CastToBase(&fluctuations_)->InternalSwap(CastToBase(&other->fluctuations_));
  strippedfields_.InternalSwap(&other->strippedfields_);
  swap(value_, other->value_);
  swap(connected_, other->connected_);
  swap(setting_, other->setting_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_TempSensorMock_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorMock_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace TempSensorMock
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::TempSensorMock::Fluctuation* Arena::CreateMaybeMessage< ::blox_test::TempSensorMock::Fluctuation >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::TempSensorMock::Fluctuation >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::TempSensorMock::Block* Arena::CreateMaybeMessage< ::blox_test::TempSensorMock::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::TempSensorMock::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
