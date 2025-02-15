// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MockPins_test.proto

#include "MockPins_test.pb.h"

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
namespace MockPins {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace MockPins
}  // namespace blox_test
namespace protobuf_MockPins_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::MockPins::_Block_default_instance_;
    new (ptr) ::blox_test::MockPins::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::MockPins::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_IoArray_5ftest_2eproto::scc_info_IoChannel.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::MockPins::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::MockPins::Block, channels_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::MockPins::Block, pins_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::MockPins::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::MockPins::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "MockPins_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\023MockPins_test.proto\022\022blox_test.MockPin"
      "s\032\023brewblox_test.proto\032\021nanopb_test.prot"
      "o\032\022IoArray_test.proto\"s\n\005Block\022@\n\010channe"
      "ls\030\002 \003(\0132\034.blox_test.IoArray.IoChannelB\020"
      "\222\?\002\020\010\222\?\002x\001\212\265\030\002(\001\022\031\n\004pins\030Z \001(\010B\013\212\265\030\002H\001\222\?"
      "\002\030\003:\r\212\265\030\003\030\303\002\212\265\030\002H\n*\313\001\n\tChannelId\022\026\n\022MOCK"
      "PINS_CHAN_NONE\020\000\022\023\n\017MOCKPINS_CHAN_A\020\001\022\023\n"
      "\017MOCKPINS_CHAN_B\020\002\022\023\n\017MOCKPINS_CHAN_C\020\003\022"
      "\023\n\017MOCKPINS_CHAN_D\020\004\022\023\n\017MOCKPINS_CHAN_E\020"
      "\005\022\023\n\017MOCKPINS_CHAN_F\020\006\022\023\n\017MOCKPINS_CHAN_"
      "G\020\007\022\023\n\017MOCKPINS_CHAN_H\020\010b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 432);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MockPins_test.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_MockPins_5ftest_2eproto
namespace blox_test {
namespace MockPins {
const ::google::protobuf::EnumDescriptor* ChannelId_descriptor() {
  protobuf_MockPins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_MockPins_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool ChannelId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
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
const int Block::kChannelsFieldNumber;
const int Block::kPinsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_MockPins_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.MockPins.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  pins_ = from.pins_;
  // @@protoc_insertion_point(copy_constructor:blox_test.MockPins.Block)
}

void Block::SharedCtor() {
  pins_ = false;
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.MockPins.Block)
  SharedDtor();
}

void Block::SharedDtor() {
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_MockPins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MockPins_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_MockPins_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.MockPins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  pins_ = false;
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.MockPins.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
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
  // @@protoc_insertion_point(parse_success:blox_test.MockPins.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.MockPins.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.MockPins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2,
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
  // @@protoc_insertion_point(serialize_end:blox_test.MockPins.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.MockPins.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->channels(static_cast<int>(i)), deterministic, target);
  }

  // bool pins = 90 [(.nanopb) = {
  if (this->pins() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(90, this->pins(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.MockPins.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.MockPins.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .blox_test.IoArray.IoChannel channels = 2 [(.nanopb) = {
  {
    unsigned int count = static_cast<unsigned int>(this->channels_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->channels(static_cast<int>(i)));
    }
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
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.MockPins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.MockPins.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.MockPins.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.MockPins.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from.pins() != 0) {
    set_pins(from.pins());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.MockPins.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.MockPins.Block)
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
  swap(pins_, other->pins_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_MockPins_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MockPins_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace MockPins
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::MockPins::Block* Arena::CreateMaybeMessage< ::blox_test::MockPins::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::MockPins::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
