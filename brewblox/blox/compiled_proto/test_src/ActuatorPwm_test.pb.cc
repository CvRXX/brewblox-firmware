// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActuatorPwm_test.proto

#include "ActuatorPwm_test.pb.h"

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

namespace protobuf_Constraints_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_Constraints_5ftest_2eproto ::google::protobuf::internal::SCCInfo<1> scc_info_AnalogConstraints;
}  // namespace protobuf_Constraints_5ftest_2eproto
namespace blox_test {
namespace ActuatorPwm {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace ActuatorPwm
}  // namespace blox_test
namespace protobuf_ActuatorPwm_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::ActuatorPwm::_Block_default_instance_;
    new (ptr) ::blox_test::ActuatorPwm::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::ActuatorPwm::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_Constraints_5ftest_2eproto::scc_info_AnalogConstraints.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, actuatorid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, period_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, setting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, constrainedby_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, drivenactuatorid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, enabled_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, desiredsetting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::ActuatorPwm::Block, strippedfields_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::ActuatorPwm::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::ActuatorPwm::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "ActuatorPwm_test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\026ActuatorPwm_test.proto\022\025blox_test.Actu"
      "atorPwm\032\023brewblox_test.proto\032\021nanopb_tes"
      "t.proto\032\026Constraints_test.proto\"\213\003\n\005Bloc"
      "k\022\037\n\nactuatorId\030\001 \001(\rB\013\212\265\030\002\030\006\222\?\0028\020\022\035\n\006pe"
      "riod\030\003 \001(\rB\r\212\265\030\002\010\003\212\265\030\003\020\350\007\022)\n\007setting\030\004 \001"
      "(\021B\030\212\265\030\0020\001\212\265\030\002(\001\212\265\030\003\020\200 \222\?\0028 \022\'\n\005value\030\005 "
      "\001(\021B\030\212\265\030\0020\001\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\022\?\n\rconstra"
      "inedBy\030\006 \001(\0132(.blox_test.Constraints.Ana"
      "logConstraints\0221\n\020drivenActuatorId\030\007 \001(\r"
      "B\027\212\265\030\002\030\006\212\265\030\002@\001\222\?\0028\020\212\265\030\002(\001\022\017\n\007enabled\030\010 \001"
      "(\010\022*\n\016desiredSetting\030\t \001(\021B\022\212\265\030\0020\001\212\265\030\003\020\200"
      " \222\?\0028 \022(\n\016strippedFields\030c \003(\rB\020\212\265\030\002(\001\222\?"
      "\0028\020\222\?\002\020\002:\023\212\265\030\003\030\263\002\212\265\030\002H\001\212\265\030\002H\005b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 517);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ActuatorPwm_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
  ::protobuf_Constraints_5ftest_2eproto::AddDescriptors();
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
}  // namespace protobuf_ActuatorPwm_5ftest_2eproto
namespace blox_test {
namespace ActuatorPwm {

// ===================================================================

void Block::InitAsDefaultInstance() {
  ::blox_test::ActuatorPwm::_Block_default_instance_._instance.get_mutable()->constrainedby_ = const_cast< ::blox_test::Constraints::AnalogConstraints*>(
      ::blox_test::Constraints::AnalogConstraints::internal_default_instance());
}
void Block::clear_constrainedby() {
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kActuatorIdFieldNumber;
const int Block::kPeriodFieldNumber;
const int Block::kSettingFieldNumber;
const int Block::kValueFieldNumber;
const int Block::kConstrainedByFieldNumber;
const int Block::kDrivenActuatorIdFieldNumber;
const int Block::kEnabledFieldNumber;
const int Block::kDesiredSettingFieldNumber;
const int Block::kStrippedFieldsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_ActuatorPwm_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.ActuatorPwm.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_constrainedby()) {
    constrainedby_ = new ::blox_test::Constraints::AnalogConstraints(*from.constrainedby_);
  } else {
    constrainedby_ = NULL;
  }
  ::memcpy(&actuatorid_, &from.actuatorid_,
    static_cast<size_t>(reinterpret_cast<char*>(&desiredsetting_) -
    reinterpret_cast<char*>(&actuatorid_)) + sizeof(desiredsetting_));
  // @@protoc_insertion_point(copy_constructor:blox_test.ActuatorPwm.Block)
}

void Block::SharedCtor() {
  ::memset(&constrainedby_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&desiredsetting_) -
      reinterpret_cast<char*>(&constrainedby_)) + sizeof(desiredsetting_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.ActuatorPwm.Block)
  SharedDtor();
}

void Block::SharedDtor() {
  if (this != internal_default_instance()) delete constrainedby_;
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_ActuatorPwm_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ActuatorPwm_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_ActuatorPwm_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.ActuatorPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  strippedfields_.Clear();
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
  ::memset(&actuatorid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&desiredsetting_) -
      reinterpret_cast<char*>(&actuatorid_)) + sizeof(desiredsetting_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.ActuatorPwm.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 actuatorId = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &actuatorid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 period = 3 [(.brewblox.field) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &period_)));
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

      // sint32 value = 5 [(.nanopb) = {
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &value_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.Constraints.AnalogConstraints constrainedBy = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_constrainedby()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 drivenActuatorId = 7 [(.nanopb) = {
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &drivenactuatorid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool enabled = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &enabled_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 desiredSetting = 9 [(.nanopb) = {
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(72u /* 72 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &desiredsetting_)));
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
  // @@protoc_insertion_point(parse_success:blox_test.ActuatorPwm.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.ActuatorPwm.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.ActuatorPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 actuatorId = 1 [(.nanopb) = {
  if (this->actuatorid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->actuatorid(), output);
  }

  // uint32 period = 3 [(.brewblox.field) = {
  if (this->period() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->period(), output);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(4, this->setting(), output);
  }

  // sint32 value = 5 [(.nanopb) = {
  if (this->value() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(5, this->value(), output);
  }

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 6;
  if (this->has_constrainedby()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6, this->_internal_constrainedby(), output);
  }

  // uint32 drivenActuatorId = 7 [(.nanopb) = {
  if (this->drivenactuatorid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->drivenactuatorid(), output);
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->enabled(), output);
  }

  // sint32 desiredSetting = 9 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(9, this->desiredsetting(), output);
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
  // @@protoc_insertion_point(serialize_end:blox_test.ActuatorPwm.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.ActuatorPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 actuatorId = 1 [(.nanopb) = {
  if (this->actuatorid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->actuatorid(), target);
  }

  // uint32 period = 3 [(.brewblox.field) = {
  if (this->period() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->period(), target);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(4, this->setting(), target);
  }

  // sint32 value = 5 [(.nanopb) = {
  if (this->value() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(5, this->value(), target);
  }

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 6;
  if (this->has_constrainedby()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        6, this->_internal_constrainedby(), deterministic, target);
  }

  // uint32 drivenActuatorId = 7 [(.nanopb) = {
  if (this->drivenactuatorid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->drivenactuatorid(), target);
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->enabled(), target);
  }

  // sint32 desiredSetting = 9 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(9, this->desiredsetting(), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.ActuatorPwm.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.ActuatorPwm.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
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

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 6;
  if (this->has_constrainedby()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *constrainedby_);
  }

  // uint32 actuatorId = 1 [(.nanopb) = {
  if (this->actuatorid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->actuatorid());
  }

  // uint32 period = 3 [(.brewblox.field) = {
  if (this->period() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->period());
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->setting());
  }

  // sint32 value = 5 [(.nanopb) = {
  if (this->value() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->value());
  }

  // uint32 drivenActuatorId = 7 [(.nanopb) = {
  if (this->drivenactuatorid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->drivenactuatorid());
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    total_size += 1 + 1;
  }

  // sint32 desiredSetting = 9 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->desiredsetting());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.ActuatorPwm.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.ActuatorPwm.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.ActuatorPwm.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.ActuatorPwm.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  strippedfields_.MergeFrom(from.strippedfields_);
  if (from.has_constrainedby()) {
    mutable_constrainedby()->::blox_test::Constraints::AnalogConstraints::MergeFrom(from.constrainedby());
  }
  if (from.actuatorid() != 0) {
    set_actuatorid(from.actuatorid());
  }
  if (from.period() != 0) {
    set_period(from.period());
  }
  if (from.setting() != 0) {
    set_setting(from.setting());
  }
  if (from.value() != 0) {
    set_value(from.value());
  }
  if (from.drivenactuatorid() != 0) {
    set_drivenactuatorid(from.drivenactuatorid());
  }
  if (from.enabled() != 0) {
    set_enabled(from.enabled());
  }
  if (from.desiredsetting() != 0) {
    set_desiredsetting(from.desiredsetting());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.ActuatorPwm.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.ActuatorPwm.Block)
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
  strippedfields_.InternalSwap(&other->strippedfields_);
  swap(constrainedby_, other->constrainedby_);
  swap(actuatorid_, other->actuatorid_);
  swap(period_, other->period_);
  swap(setting_, other->setting_);
  swap(value_, other->value_);
  swap(drivenactuatorid_, other->drivenactuatorid_);
  swap(enabled_, other->enabled_);
  swap(desiredsetting_, other->desiredsetting_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_ActuatorPwm_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ActuatorPwm_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ActuatorPwm
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::ActuatorPwm::Block* Arena::CreateMaybeMessage< ::blox_test::ActuatorPwm::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::ActuatorPwm::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
