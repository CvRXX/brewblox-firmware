// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MotorValve_test.proto

#include "MotorValve_test.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_protobuf_Constraints_5ftest_2eproto ::google::protobuf::internal::SCCInfo<1> scc_info_DigitalConstraints;
}  // namespace protobuf_Constraints_5ftest_2eproto
namespace blox {
namespace MotorValve {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace MotorValve
}  // namespace blox
namespace protobuf_MotorValve_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox::MotorValve::_Block_default_instance_;
    new (ptr) ::blox::MotorValve::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox::MotorValve::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_Constraints_5ftest_2eproto::scc_info_DigitalConstraints.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, hwdevice_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, startchannel_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, state_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, constrainedby_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, valvestate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, desiredstate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::MotorValve::Block, strippedfields_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::MotorValve::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox::MotorValve::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "MotorValve_test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
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
      "\n\025MotorValve_test.proto\022\017blox.MotorValve"
      "\032\023brewblox_test.proto\032\021nanopb_test.proto"
      "\032\026Constraints_test.proto\032\022IoArray_test.p"
      "roto\"\361\002\n\005Block\022#\n\010hwDevice\030\001 \001(\rB\021\212\265\030\002\030\013"
      "\212\265\030\002@\001\222\?\0028\020\022\033\n\014startChannel\030\002 \001(\rB\005\222\?\0028\010"
      "\0227\n\005state\030\003 \001(\0162\032.blox.IoArray.DigitalSt"
      "ateB\014\212\265\030\0020\001\212\265\030\002(\001\022;\n\rconstrainedBy\030\005 \001(\013"
      "2$.blox.Constraints.DigitalConstraints\022="
      "\n\nvalveState\030\006 \001(\0162\033.blox.MotorValve.Val"
      "veStateB\014\212\265\030\0020\001\212\265\030\002(\001\0228\n\014desiredState\030\007 "
      "\001(\0162\032.blox.IoArray.DigitalStateB\006\212\265\030\0020\001\022"
      "(\n\016strippedFields\030c \003(\rB\020\212\265\030\002(\001\222\?\0028\020\222\?\002\020"
      "\002:\r\212\265\030\003\030\301\002\212\265\030\002H\006*\226\001\n\nValveState\022\021\n\rVALVE"
      "_UNKNOWN\020\000\022\016\n\nVALVE_OPEN\020\001\022\020\n\014VALVE_CLOS"
      "ED\020\002\022\021\n\rVALVE_OPENING\020\003\022\021\n\rVALVE_CLOSING"
      "\020\004\022\030\n\024VALVE_HALF_OPEN_IDLE\020\005\022\023\n\017VALVE_IN"
      "IT_IDLE\020\006b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 657);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MotorValve_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
  ::protobuf_Constraints_5ftest_2eproto::AddDescriptors();
  ::protobuf_IoArray_5ftest_2eproto::AddDescriptors();
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
}  // namespace protobuf_MotorValve_5ftest_2eproto
namespace blox {
namespace MotorValve {
const ::google::protobuf::EnumDescriptor* ValveState_descriptor() {
  protobuf_MotorValve_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_MotorValve_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool ValveState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Block::InitAsDefaultInstance() {
  ::blox::MotorValve::_Block_default_instance_._instance.get_mutable()->constrainedby_ = const_cast< ::blox::Constraints::DigitalConstraints*>(
      ::blox::Constraints::DigitalConstraints::internal_default_instance());
}
void Block::clear_constrainedby() {
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kHwDeviceFieldNumber;
const int Block::kStartChannelFieldNumber;
const int Block::kStateFieldNumber;
const int Block::kConstrainedByFieldNumber;
const int Block::kValveStateFieldNumber;
const int Block::kDesiredStateFieldNumber;
const int Block::kStrippedFieldsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_MotorValve_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox.MotorValve.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_constrainedby()) {
    constrainedby_ = new ::blox::Constraints::DigitalConstraints(*from.constrainedby_);
  } else {
    constrainedby_ = NULL;
  }
  ::memcpy(&hwdevice_, &from.hwdevice_,
    static_cast<size_t>(reinterpret_cast<char*>(&desiredstate_) -
    reinterpret_cast<char*>(&hwdevice_)) + sizeof(desiredstate_));
  // @@protoc_insertion_point(copy_constructor:blox.MotorValve.Block)
}

void Block::SharedCtor() {
  ::memset(&constrainedby_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&desiredstate_) -
      reinterpret_cast<char*>(&constrainedby_)) + sizeof(desiredstate_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox.MotorValve.Block)
  SharedDtor();
}

void Block::SharedDtor() {
  if (this != internal_default_instance()) delete constrainedby_;
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_MotorValve_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MotorValve_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_MotorValve_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.MotorValve.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  strippedfields_.Clear();
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
  ::memset(&hwdevice_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&desiredstate_) -
      reinterpret_cast<char*>(&hwdevice_)) + sizeof(desiredstate_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox.MotorValve.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 hwDevice = 1 [(.nanopb_test) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &hwdevice_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 startChannel = 2 [(.nanopb_test) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &startchannel_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.IoArray.DigitalState state = 3 [(.brewblox_test) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_state(static_cast< ::blox::IoArray::DigitalState >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.Constraints.DigitalConstraints constrainedBy = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_constrainedby()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_valvestate(static_cast< ::blox::MotorValve::ValveState >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.IoArray.DigitalState desiredState = 7 [(.brewblox_test) = {
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_desiredstate(static_cast< ::blox::IoArray::DigitalState >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
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
  // @@protoc_insertion_point(parse_success:blox.MotorValve.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox.MotorValve.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox.MotorValve.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  if (this->hwdevice() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->hwdevice(), output);
  }

  // uint32 startChannel = 2 [(.nanopb_test) = {
  if (this->startchannel() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->startchannel(), output);
  }

  // .blox.IoArray.DigitalState state = 3 [(.brewblox_test) = {
  if (this->state() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->state(), output);
  }

  // .blox.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->_internal_constrainedby(), output);
  }

  // .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
  if (this->valvestate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->valvestate(), output);
  }

  // .blox.IoArray.DigitalState desiredState = 7 [(.brewblox_test) = {
  if (this->desiredstate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      7, this->desiredstate(), output);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
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
  // @@protoc_insertion_point(serialize_end:blox.MotorValve.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox.MotorValve.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  if (this->hwdevice() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->hwdevice(), target);
  }

  // uint32 startChannel = 2 [(.nanopb_test) = {
  if (this->startchannel() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->startchannel(), target);
  }

  // .blox.IoArray.DigitalState state = 3 [(.brewblox_test) = {
  if (this->state() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->state(), target);
  }

  // .blox.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->_internal_constrainedby(), deterministic, target);
  }

  // .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
  if (this->valvestate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->valvestate(), target);
  }

  // .blox.IoArray.DigitalState desiredState = 7 [(.brewblox_test) = {
  if (this->desiredstate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      7, this->desiredstate(), target);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
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
  // @@protoc_insertion_point(serialize_to_array_end:blox.MotorValve.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.MotorValve.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
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

  // .blox.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *constrainedby_);
  }

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  if (this->hwdevice() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->hwdevice());
  }

  // uint32 startChannel = 2 [(.nanopb_test) = {
  if (this->startchannel() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->startchannel());
  }

  // .blox.IoArray.DigitalState state = 3 [(.brewblox_test) = {
  if (this->state() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->state());
  }

  // .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
  if (this->valvestate() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->valvestate());
  }

  // .blox.IoArray.DigitalState desiredState = 7 [(.brewblox_test) = {
  if (this->desiredstate() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->desiredstate());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox.MotorValve.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox.MotorValve.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox.MotorValve.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.MotorValve.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  strippedfields_.MergeFrom(from.strippedfields_);
  if (from.has_constrainedby()) {
    mutable_constrainedby()->::blox::Constraints::DigitalConstraints::MergeFrom(from.constrainedby());
  }
  if (from.hwdevice() != 0) {
    set_hwdevice(from.hwdevice());
  }
  if (from.startchannel() != 0) {
    set_startchannel(from.startchannel());
  }
  if (from.state() != 0) {
    set_state(from.state());
  }
  if (from.valvestate() != 0) {
    set_valvestate(from.valvestate());
  }
  if (from.desiredstate() != 0) {
    set_desiredstate(from.desiredstate());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox.MotorValve.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.MotorValve.Block)
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
  swap(hwdevice_, other->hwdevice_);
  swap(startchannel_, other->startchannel_);
  swap(state_, other->state_);
  swap(valvestate_, other->valvestate_);
  swap(desiredstate_, other->desiredstate_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_MotorValve_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MotorValve_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace MotorValve
}  // namespace blox
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox::MotorValve::Block* Arena::CreateMaybeMessage< ::blox::MotorValve::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox::MotorValve::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
