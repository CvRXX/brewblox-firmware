// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DigitalActuator_test.proto

#include "DigitalActuator_test.pb.h"

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
namespace blox_test {
namespace DigitalActuator {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace DigitalActuator
}  // namespace blox_test
namespace protobuf_DigitalActuator_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::DigitalActuator::_Block_default_instance_;
    new (ptr) ::blox_test::DigitalActuator::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::DigitalActuator::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_Constraints_5ftest_2eproto::scc_info_DigitalConstraints.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, hwdevice_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, channel_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, state_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, invert_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, constrainedby_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, desiredstate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, transitiondurationpreset_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, transitiondurationsetting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, transitiondurationvalue_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DigitalActuator::Block, claimedby_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::DigitalActuator::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::DigitalActuator::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "DigitalActuator_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\032DigitalActuator_test.proto\022\031blox_test."
      "DigitalActuator\032\023brewblox_test.proto\032\021na"
      "nopb_test.proto\032\026Constraints_test.proto\032"
      "\022IoArray_test.proto\"\200\004\n\005Block\022\035\n\010hwDevic"
      "e\030\001 \001(\rB\013\212\265\030\002\030\n\222\?\0028\020\022\026\n\007channel\030\002 \001(\rB\005\222"
      "\?\0028\010\022<\n\005state\030\003 \001(\0162\037.blox_test.IoArray."
      "DigitalStateB\014\212\265\030\0020\001\212\265\030\002(\001\022\016\n\006invert\030\004 \001"
      "(\010\022@\n\rconstrainedBy\030\005 \001(\0132).blox_test.Co"
      "nstraints.DigitalConstraints\022=\n\014desiredS"
      "tate\030\006 \001(\0162\037.blox_test.IoArray.DigitalSt"
      "ateB\006\212\265\030\0020\001\022M\n\030transitionDurationPreset\030"
      "\007 \001(\0162+.blox_test.IoArray.TransitionDura"
      "tionPreset\0220\n\031transitionDurationSetting\030"
      "\010 \001(\rB\r\212\265\030\002\010\003\212\265\030\003\020\350\007\0224\n\027transitionDurati"
      "onValue\030\t \001(\rB\023\212\265\030\002\010\003\212\265\030\003\020\350\007\212\265\030\002(\001\022%\n\tcl"
      "aimedBy\030\n \001(\rB\022\212\265\030\003\030\377\001\212\265\030\002(\001\222\?\0028\020:\023\212\265\030\003\030"
      "\276\002\212\265\030\002H\006\212\265\030\002H\020b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 662);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DigitalActuator_test.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_DigitalActuator_5ftest_2eproto
namespace blox_test {
namespace DigitalActuator {

// ===================================================================

void Block::InitAsDefaultInstance() {
  ::blox_test::DigitalActuator::_Block_default_instance_._instance.get_mutable()->constrainedby_ = const_cast< ::blox_test::Constraints::DigitalConstraints*>(
      ::blox_test::Constraints::DigitalConstraints::internal_default_instance());
}
void Block::clear_constrainedby() {
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kHwDeviceFieldNumber;
const int Block::kChannelFieldNumber;
const int Block::kStateFieldNumber;
const int Block::kInvertFieldNumber;
const int Block::kConstrainedByFieldNumber;
const int Block::kDesiredStateFieldNumber;
const int Block::kTransitionDurationPresetFieldNumber;
const int Block::kTransitionDurationSettingFieldNumber;
const int Block::kTransitionDurationValueFieldNumber;
const int Block::kClaimedByFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_DigitalActuator_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.DigitalActuator.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_constrainedby()) {
    constrainedby_ = new ::blox_test::Constraints::DigitalConstraints(*from.constrainedby_);
  } else {
    constrainedby_ = NULL;
  }
  ::memcpy(&hwdevice_, &from.hwdevice_,
    static_cast<size_t>(reinterpret_cast<char*>(&claimedby_) -
    reinterpret_cast<char*>(&hwdevice_)) + sizeof(claimedby_));
  // @@protoc_insertion_point(copy_constructor:blox_test.DigitalActuator.Block)
}

void Block::SharedCtor() {
  ::memset(&constrainedby_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&claimedby_) -
      reinterpret_cast<char*>(&constrainedby_)) + sizeof(claimedby_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.DigitalActuator.Block)
  SharedDtor();
}

void Block::SharedDtor() {
  if (this != internal_default_instance()) delete constrainedby_;
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_DigitalActuator_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DigitalActuator_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_DigitalActuator_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.DigitalActuator.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
  ::memset(&hwdevice_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&claimedby_) -
      reinterpret_cast<char*>(&hwdevice_)) + sizeof(claimedby_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.DigitalActuator.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 hwDevice = 1 [(.nanopb) = {
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

      // uint32 channel = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &channel_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.IoArray.DigitalState state = 3 [(.brewblox.field) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_state(static_cast< ::blox_test::IoArray::DigitalState >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool invert = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &invert_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.Constraints.DigitalConstraints constrainedBy = 5;
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

      // .blox_test.IoArray.DigitalState desiredState = 6 [(.brewblox.field) = {
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_desiredstate(static_cast< ::blox_test::IoArray::DigitalState >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.IoArray.TransitionDurationPreset transitionDurationPreset = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_transitiondurationpreset(static_cast< ::blox_test::IoArray::TransitionDurationPreset >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 transitionDurationSetting = 8 [(.brewblox.field) = {
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &transitiondurationsetting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 transitionDurationValue = 9 [(.brewblox.field) = {
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(72u /* 72 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &transitiondurationvalue_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 claimedBy = 10 [(.nanopb) = {
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(80u /* 80 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &claimedby_)));
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
  // @@protoc_insertion_point(parse_success:blox_test.DigitalActuator.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.DigitalActuator.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.DigitalActuator.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->hwdevice(), output);
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->channel(), output);
  }

  // .blox_test.IoArray.DigitalState state = 3 [(.brewblox.field) = {
  if (this->state() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->state(), output);
  }

  // bool invert = 4;
  if (this->invert() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4, this->invert(), output);
  }

  // .blox_test.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->_internal_constrainedby(), output);
  }

  // .blox_test.IoArray.DigitalState desiredState = 6 [(.brewblox.field) = {
  if (this->desiredstate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->desiredstate(), output);
  }

  // .blox_test.IoArray.TransitionDurationPreset transitionDurationPreset = 7;
  if (this->transitiondurationpreset() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      7, this->transitiondurationpreset(), output);
  }

  // uint32 transitionDurationSetting = 8 [(.brewblox.field) = {
  if (this->transitiondurationsetting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(8, this->transitiondurationsetting(), output);
  }

  // uint32 transitionDurationValue = 9 [(.brewblox.field) = {
  if (this->transitiondurationvalue() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->transitiondurationvalue(), output);
  }

  // uint32 claimedBy = 10 [(.nanopb) = {
  if (this->claimedby() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->claimedby(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.DigitalActuator.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.DigitalActuator.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->hwdevice(), target);
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->channel(), target);
  }

  // .blox_test.IoArray.DigitalState state = 3 [(.brewblox.field) = {
  if (this->state() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->state(), target);
  }

  // bool invert = 4;
  if (this->invert() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4, this->invert(), target);
  }

  // .blox_test.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->_internal_constrainedby(), deterministic, target);
  }

  // .blox_test.IoArray.DigitalState desiredState = 6 [(.brewblox.field) = {
  if (this->desiredstate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->desiredstate(), target);
  }

  // .blox_test.IoArray.TransitionDurationPreset transitionDurationPreset = 7;
  if (this->transitiondurationpreset() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      7, this->transitiondurationpreset(), target);
  }

  // uint32 transitionDurationSetting = 8 [(.brewblox.field) = {
  if (this->transitiondurationsetting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(8, this->transitiondurationsetting(), target);
  }

  // uint32 transitionDurationValue = 9 [(.brewblox.field) = {
  if (this->transitiondurationvalue() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(9, this->transitiondurationvalue(), target);
  }

  // uint32 claimedBy = 10 [(.nanopb) = {
  if (this->claimedby() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->claimedby(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.DigitalActuator.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.DigitalActuator.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .blox_test.Constraints.DigitalConstraints constrainedBy = 5;
  if (this->has_constrainedby()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *constrainedby_);
  }

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->hwdevice());
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->channel());
  }

  // .blox_test.IoArray.DigitalState state = 3 [(.brewblox.field) = {
  if (this->state() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->state());
  }

  // bool invert = 4;
  if (this->invert() != 0) {
    total_size += 1 + 1;
  }

  // .blox_test.IoArray.DigitalState desiredState = 6 [(.brewblox.field) = {
  if (this->desiredstate() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->desiredstate());
  }

  // .blox_test.IoArray.TransitionDurationPreset transitionDurationPreset = 7;
  if (this->transitiondurationpreset() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->transitiondurationpreset());
  }

  // uint32 transitionDurationSetting = 8 [(.brewblox.field) = {
  if (this->transitiondurationsetting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->transitiondurationsetting());
  }

  // uint32 transitionDurationValue = 9 [(.brewblox.field) = {
  if (this->transitiondurationvalue() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->transitiondurationvalue());
  }

  // uint32 claimedBy = 10 [(.nanopb) = {
  if (this->claimedby() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->claimedby());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.DigitalActuator.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.DigitalActuator.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.DigitalActuator.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.DigitalActuator.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_constrainedby()) {
    mutable_constrainedby()->::blox_test::Constraints::DigitalConstraints::MergeFrom(from.constrainedby());
  }
  if (from.hwdevice() != 0) {
    set_hwdevice(from.hwdevice());
  }
  if (from.channel() != 0) {
    set_channel(from.channel());
  }
  if (from.state() != 0) {
    set_state(from.state());
  }
  if (from.invert() != 0) {
    set_invert(from.invert());
  }
  if (from.desiredstate() != 0) {
    set_desiredstate(from.desiredstate());
  }
  if (from.transitiondurationpreset() != 0) {
    set_transitiondurationpreset(from.transitiondurationpreset());
  }
  if (from.transitiondurationsetting() != 0) {
    set_transitiondurationsetting(from.transitiondurationsetting());
  }
  if (from.transitiondurationvalue() != 0) {
    set_transitiondurationvalue(from.transitiondurationvalue());
  }
  if (from.claimedby() != 0) {
    set_claimedby(from.claimedby());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.DigitalActuator.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.DigitalActuator.Block)
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
  swap(constrainedby_, other->constrainedby_);
  swap(hwdevice_, other->hwdevice_);
  swap(channel_, other->channel_);
  swap(state_, other->state_);
  swap(invert_, other->invert_);
  swap(desiredstate_, other->desiredstate_);
  swap(transitiondurationpreset_, other->transitiondurationpreset_);
  swap(transitiondurationsetting_, other->transitiondurationsetting_);
  swap(transitiondurationvalue_, other->transitiondurationvalue_);
  swap(claimedby_, other->claimedby_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_DigitalActuator_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DigitalActuator_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace DigitalActuator
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::DigitalActuator::Block* Arena::CreateMaybeMessage< ::blox_test::DigitalActuator::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::DigitalActuator::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
