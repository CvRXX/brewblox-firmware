// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Spark2Pins_test.proto

#include "Spark2Pins_test.pb.h"

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

namespace protobuf_IoArray_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_IoArray_5ftest_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_IoChannel;
}  // namespace protobuf_IoArray_5ftest_2eproto
namespace blox_test {
namespace Spark2Pins {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace Spark2Pins
}  // namespace blox_test
namespace protobuf_Spark2Pins_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::Spark2Pins::_Block_default_instance_;
    new (ptr) ::blox_test::Spark2Pins::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::Spark2Pins::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_IoArray_5ftest_2eproto::scc_info_IoChannel.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::Spark2Pins::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::Spark2Pins::Block, soundalarm_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::Spark2Pins::Block, hardware_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::Spark2Pins::Block, channels_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::Spark2Pins::Block, pins_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::Spark2Pins::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::Spark2Pins::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "Spark2Pins_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\025Spark2Pins_test.proto\022\024blox_test.Spark"
      "2Pins\032\023brewblox_test.proto\032\021nanopb_test."
      "proto\032\022IoArray_test.proto\"\201\002\n\005Block\022\022\n\ns"
      "oundAlarm\030\005 \001(\010\022>\n\010hardware\030\010 \001(\0162$.blox"
      "_test.Spark2Pins.Block.HardwareB\006\212\265\030\002(\001\022"
      "@\n\010channels\030\t \003(\0132\034.blox_test.IoArray.Io"
      "ChannelB\020\222\?\002\020\004\222\?\002x\001\212\265\030\002(\001\022\031\n\004pins\030Z \001(\010B"
      "\013\212\265\030\002H\001\222\?\002\030\003\"8\n\010Hardware\022\016\n\nHW_UNKNOWN\020\000"
      "\022\r\n\tHW_SPARK1\020\001\022\r\n\tHW_SPARK2\020\002:\r\212\265\030\003\030\300\002\212"
      "\265\030\002H\n*\205\001\n\tChannelId\022\024\n\020SPARK2_CHAN_NONE\020"
      "\000\022\027\n\023SPARK2_CHAN_BOTTOM1\020\001\022\027\n\023SPARK2_CHA"
      "N_BOTTOM2\020\002\022\027\n\023SPARK2_CHAN_BOTTOM3\020\003\022\027\n\023"
      "SPARK2_CHAN_BOTTOM0\020\004b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 509);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Spark2Pins_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
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
}  // namespace protobuf_Spark2Pins_5ftest_2eproto
namespace blox_test {
namespace Spark2Pins {
const ::google::protobuf::EnumDescriptor* Block_Hardware_descriptor() {
  protobuf_Spark2Pins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_Spark2Pins_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool Block_Hardware_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const Block_Hardware Block::HW_UNKNOWN;
const Block_Hardware Block::HW_SPARK1;
const Block_Hardware Block::HW_SPARK2;
const Block_Hardware Block::Hardware_MIN;
const Block_Hardware Block::Hardware_MAX;
const int Block::Hardware_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
const ::google::protobuf::EnumDescriptor* ChannelId_descriptor() {
  protobuf_Spark2Pins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_Spark2Pins_5ftest_2eproto::file_level_enum_descriptors[1];
}
bool ChannelId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
void Block::clear_channels() {
  channels_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kSoundAlarmFieldNumber;
const int Block::kHardwareFieldNumber;
const int Block::kChannelsFieldNumber;
const int Block::kPinsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_Spark2Pins_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.Spark2Pins.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&hardware_, &from.hardware_,
    static_cast<size_t>(reinterpret_cast<char*>(&pins_) -
    reinterpret_cast<char*>(&hardware_)) + sizeof(pins_));
  // @@protoc_insertion_point(copy_constructor:blox_test.Spark2Pins.Block)
}

void Block::SharedCtor() {
  ::memset(&hardware_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&pins_) -
      reinterpret_cast<char*>(&hardware_)) + sizeof(pins_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.Spark2Pins.Block)
  SharedDtor();
}

void Block::SharedDtor() {
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_Spark2Pins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Spark2Pins_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_Spark2Pins_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.Spark2Pins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  ::memset(&hardware_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&pins_) -
      reinterpret_cast<char*>(&hardware_)) + sizeof(pins_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.Spark2Pins.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bool soundAlarm = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &soundalarm_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.Spark2Pins.Block.Hardware hardware = 8 [(.brewblox.field) = {
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_hardware(static_cast< ::blox_test::Spark2Pins::Block_Hardware >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .blox_test.IoArray.IoChannel channels = 9 [(.nanopb) = {
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(74u /* 74 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_channels()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool pins = 90 [(.nanopb) = {
      case 90: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(208u /* 720 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &pins_)));
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
  // @@protoc_insertion_point(parse_success:blox_test.Spark2Pins.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.Spark2Pins.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.Spark2Pins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool soundAlarm = 5;
  if (this->soundalarm() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(5, this->soundalarm(), output);
  }

  // .blox_test.Spark2Pins.Block.Hardware hardware = 8 [(.brewblox.field) = {
  if (this->hardware() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      8, this->hardware(), output);
  }

  // repeated .blox_test.IoArray.IoChannel channels = 9 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9,
      this->channels(static_cast<int>(i)),
      output);
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->pins() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(90, this->pins(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.Spark2Pins.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.Spark2Pins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool soundAlarm = 5;
  if (this->soundalarm() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(5, this->soundalarm(), target);
  }

  // .blox_test.Spark2Pins.Block.Hardware hardware = 8 [(.brewblox.field) = {
  if (this->hardware() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      8, this->hardware(), target);
  }

  // repeated .blox_test.IoArray.IoChannel channels = 9 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        9, this->channels(static_cast<int>(i)), deterministic, target);
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->pins() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(90, this->pins(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.Spark2Pins.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.Spark2Pins.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .blox_test.IoArray.IoChannel channels = 9 [(.nanopb) = {
  {
    unsigned int count = static_cast<unsigned int>(this->channels_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->channels(static_cast<int>(i)));
    }
  }

  // .blox_test.Spark2Pins.Block.Hardware hardware = 8 [(.brewblox.field) = {
  if (this->hardware() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->hardware());
  }

  // bool soundAlarm = 5;
  if (this->soundalarm() != 0) {
    total_size += 1 + 1;
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->pins() != 0) {
    total_size += 2 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.Spark2Pins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.Spark2Pins.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.Spark2Pins.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.Spark2Pins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from.hardware() != 0) {
    set_hardware(from.hardware());
  }
  if (from.soundalarm() != 0) {
    set_soundalarm(from.soundalarm());
  }
  if (from.pins() != 0) {
    set_pins(from.pins());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.Spark2Pins.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.Spark2Pins.Block)
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
  CastToBase(&channels_)->InternalSwap(CastToBase(&other->channels_));
  swap(hardware_, other->hardware_);
  swap(soundalarm_, other->soundalarm_);
  swap(pins_, other->pins_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_Spark2Pins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_Spark2Pins_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Spark2Pins
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::Spark2Pins::Block* Arena::CreateMaybeMessage< ::blox_test::Spark2Pins::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::Spark2Pins::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
