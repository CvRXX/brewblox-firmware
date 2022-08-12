// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DisplaySettings_test.proto

#include "DisplaySettings_test.pb.h"

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

namespace protobuf_DisplaySettings_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_DisplaySettings_5ftest_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Widget;
}  // namespace protobuf_DisplaySettings_5ftest_2eproto
namespace blox_test {
namespace DisplaySettings {
class WidgetDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Widget>
      _instance;
  ::google::protobuf::uint32 tempsensor_;
  ::google::protobuf::uint32 setpointsensorpair_;
  ::google::protobuf::uint32 actuatoranalog_;
  ::google::protobuf::uint32 pid_;
} _Widget_default_instance_;
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace DisplaySettings
}  // namespace blox_test
namespace protobuf_DisplaySettings_5ftest_2eproto {
static void InitDefaultsWidget() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::DisplaySettings::_Widget_default_instance_;
    new (ptr) ::blox_test::DisplaySettings::Widget();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::DisplaySettings::Widget::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Widget =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsWidget}, {}};

static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::DisplaySettings::_Block_default_instance_;
    new (ptr) ::blox_test::DisplaySettings::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::DisplaySettings::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_DisplaySettings_5ftest_2eproto::scc_info_Widget.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Widget.base);
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, _internal_metadata_),
  ~0u,  // no _extensions_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, pos_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, color_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, name_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, tempsensor_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, setpointsensorpair_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, actuatoranalog_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, pid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, WidgetType_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Block, widgets_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Block, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::DisplaySettings::Block, brightness_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::DisplaySettings::Widget)},
  { 13, -1, sizeof(::blox_test::DisplaySettings::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::DisplaySettings::_Widget_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::DisplaySettings::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "DisplaySettings_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\032DisplaySettings_test.proto\022\031blox_test."
      "DisplaySettings\032\023brewblox_test.proto\032\021na"
      "nopb_test.proto\"\362\001\n\006Widget\022\022\n\003pos\030\001 \001(\rB"
      "\005\222\?\0028\010\022\037\n\005color\030\002 \001(\014B\020\222\?\002\010\003\222\?\002x\001\212\265\030\0028\001\022"
      "\023\n\004name\030\003 \001(\tB\005\222\?\002\010\020\022!\n\ntempSensor\030\n \001(\r"
      "B\013\212\265\030\002\030\002\222\?\0028\020H\000\022)\n\022setpointSensorPair\030\013 "
      "\001(\rB\013\212\265\030\002\030\004\222\?\0028\020H\000\022%\n\016actuatorAnalog\030\014 \001"
      "(\rB\013\212\265\030\002\030\005\222\?\0028\020H\000\022\033\n\003pid\030\016 \001(\rB\014\212\265\030\003\030\260\002\222"
      "\?\0028\020H\000B\014\n\nWidgetType\"\201\001\n\005Block\0229\n\007widget"
      "s\030\001 \003(\0132!.blox_test.DisplaySettings.Widg"
      "etB\005\222\?\002\020\006\022\023\n\004name\030\002 \001(\tB\005\222\?\002\010(\022\037\n\nbright"
      "ness\030Z \001(\010B\013\212\265\030\002H\001\222\?\002\030\003:\007\212\265\030\003\030\272\002b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 480);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DisplaySettings_test.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_DisplaySettings_5ftest_2eproto
namespace blox_test {
namespace DisplaySettings {

// ===================================================================

void Widget::InitAsDefaultInstance() {
  ::blox_test::DisplaySettings::_Widget_default_instance_.tempsensor_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.setpointsensorpair_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.actuatoranalog_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.pid_ = 0u;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Widget::kPosFieldNumber;
const int Widget::kColorFieldNumber;
const int Widget::kNameFieldNumber;
const int Widget::kTempSensorFieldNumber;
const int Widget::kSetpointSensorPairFieldNumber;
const int Widget::kActuatorAnalogFieldNumber;
const int Widget::kPidFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Widget::Widget()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_DisplaySettings_5ftest_2eproto::scc_info_Widget.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.DisplaySettings.Widget)
}
Widget::Widget(const Widget& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  color_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.color().size() > 0) {
    color_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.color_);
  }
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  pos_ = from.pos_;
  clear_has_WidgetType();
  switch (from.WidgetType_case()) {
    case kTempSensor: {
      set_tempsensor(from.tempsensor());
      break;
    }
    case kSetpointSensorPair: {
      set_setpointsensorpair(from.setpointsensorpair());
      break;
    }
    case kActuatorAnalog: {
      set_actuatoranalog(from.actuatoranalog());
      break;
    }
    case kPid: {
      set_pid(from.pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:blox_test.DisplaySettings.Widget)
}

void Widget::SharedCtor() {
  color_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  pos_ = 0u;
  clear_has_WidgetType();
}

Widget::~Widget() {
  // @@protoc_insertion_point(destructor:blox_test.DisplaySettings.Widget)
  SharedDtor();
}

void Widget::SharedDtor() {
  color_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (has_WidgetType()) {
    clear_WidgetType();
  }
}

void Widget::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Widget::descriptor() {
  ::protobuf_DisplaySettings_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DisplaySettings_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Widget& Widget::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_DisplaySettings_5ftest_2eproto::scc_info_Widget.base);
  return *internal_default_instance();
}


void Widget::clear_WidgetType() {
// @@protoc_insertion_point(one_of_clear_start:blox_test.DisplaySettings.Widget)
  switch (WidgetType_case()) {
    case kTempSensor: {
      // No need to clear
      break;
    }
    case kSetpointSensorPair: {
      // No need to clear
      break;
    }
    case kActuatorAnalog: {
      // No need to clear
      break;
    }
    case kPid: {
      // No need to clear
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = WIDGETTYPE_NOT_SET;
}


void Widget::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.DisplaySettings.Widget)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  color_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  pos_ = 0u;
  clear_WidgetType();
  _internal_metadata_.Clear();
}

bool Widget::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.DisplaySettings.Widget)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 pos = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &pos_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes color = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_color()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string name = 3 [(.nanopb) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "blox_test.DisplaySettings.Widget.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 tempSensor = 10 [(.nanopb) = {
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(80u /* 80 & 0xFF */)) {
          clear_WidgetType();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &WidgetType_.tempsensor_)));
          set_has_tempsensor();
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 setpointSensorPair = 11 [(.nanopb) = {
      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(88u /* 88 & 0xFF */)) {
          clear_WidgetType();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &WidgetType_.setpointsensorpair_)));
          set_has_setpointsensorpair();
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 actuatorAnalog = 12 [(.nanopb) = {
      case 12: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(96u /* 96 & 0xFF */)) {
          clear_WidgetType();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &WidgetType_.actuatoranalog_)));
          set_has_actuatoranalog();
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 pid = 14 [(.nanopb) = {
      case 14: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(112u /* 112 & 0xFF */)) {
          clear_WidgetType();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &WidgetType_.pid_)));
          set_has_pid();
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
  // @@protoc_insertion_point(parse_success:blox_test.DisplaySettings.Widget)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.DisplaySettings.Widget)
  return false;
#undef DO_
}

void Widget::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.DisplaySettings.Widget)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 pos = 1 [(.nanopb) = {
  if (this->pos() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->pos(), output);
  }

  // bytes color = 2 [(.nanopb) = {
  if (this->color().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->color(), output);
  }

  // string name = 3 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Widget.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->name(), output);
  }

  // uint32 tempSensor = 10 [(.nanopb) = {
  if (has_tempsensor()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->tempsensor(), output);
  }

  // uint32 setpointSensorPair = 11 [(.nanopb) = {
  if (has_setpointsensorpair()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->setpointsensorpair(), output);
  }

  // uint32 actuatorAnalog = 12 [(.nanopb) = {
  if (has_actuatoranalog()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->actuatoranalog(), output);
  }

  // uint32 pid = 14 [(.nanopb) = {
  if (has_pid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(14, this->pid(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.DisplaySettings.Widget)
}

::google::protobuf::uint8* Widget::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.DisplaySettings.Widget)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 pos = 1 [(.nanopb) = {
  if (this->pos() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->pos(), target);
  }

  // bytes color = 2 [(.nanopb) = {
  if (this->color().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->color(), target);
  }

  // string name = 3 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Widget.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->name(), target);
  }

  // uint32 tempSensor = 10 [(.nanopb) = {
  if (has_tempsensor()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->tempsensor(), target);
  }

  // uint32 setpointSensorPair = 11 [(.nanopb) = {
  if (has_setpointsensorpair()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->setpointsensorpair(), target);
  }

  // uint32 actuatorAnalog = 12 [(.nanopb) = {
  if (has_actuatoranalog()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->actuatoranalog(), target);
  }

  // uint32 pid = 14 [(.nanopb) = {
  if (has_pid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(14, this->pid(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.DisplaySettings.Widget)
  return target;
}

size_t Widget::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.DisplaySettings.Widget)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // bytes color = 2 [(.nanopb) = {
  if (this->color().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->color());
  }

  // string name = 3 [(.nanopb) = {
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // uint32 pos = 1 [(.nanopb) = {
  if (this->pos() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->pos());
  }

  switch (WidgetType_case()) {
    // uint32 tempSensor = 10 [(.nanopb) = {
    case kTempSensor: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->tempsensor());
      break;
    }
    // uint32 setpointSensorPair = 11 [(.nanopb) = {
    case kSetpointSensorPair: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->setpointsensorpair());
      break;
    }
    // uint32 actuatorAnalog = 12 [(.nanopb) = {
    case kActuatorAnalog: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->actuatoranalog());
      break;
    }
    // uint32 pid = 14 [(.nanopb) = {
    case kPid: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Widget::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.DisplaySettings.Widget)
  GOOGLE_DCHECK_NE(&from, this);
  const Widget* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Widget>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.DisplaySettings.Widget)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.DisplaySettings.Widget)
    MergeFrom(*source);
  }
}

void Widget::MergeFrom(const Widget& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.DisplaySettings.Widget)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.color().size() > 0) {

    color_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.color_);
  }
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.pos() != 0) {
    set_pos(from.pos());
  }
  switch (from.WidgetType_case()) {
    case kTempSensor: {
      set_tempsensor(from.tempsensor());
      break;
    }
    case kSetpointSensorPair: {
      set_setpointsensorpair(from.setpointsensorpair());
      break;
    }
    case kActuatorAnalog: {
      set_actuatoranalog(from.actuatoranalog());
      break;
    }
    case kPid: {
      set_pid(from.pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
}

void Widget::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.DisplaySettings.Widget)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Widget::CopyFrom(const Widget& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.DisplaySettings.Widget)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Widget::IsInitialized() const {
  return true;
}

void Widget::Swap(Widget* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Widget::InternalSwap(Widget* other) {
  using std::swap;
  color_.Swap(&other->color_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(pos_, other->pos_);
  swap(WidgetType_, other->WidgetType_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Widget::GetMetadata() const {
  protobuf_DisplaySettings_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DisplaySettings_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kWidgetsFieldNumber;
const int Block::kNameFieldNumber;
const int Block::kBrightnessFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_DisplaySettings_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.DisplaySettings.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      widgets_(from.widgets_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  brightness_ = from.brightness_;
  // @@protoc_insertion_point(copy_constructor:blox_test.DisplaySettings.Block)
}

void Block::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  brightness_ = false;
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.DisplaySettings.Block)
  SharedDtor();
}

void Block::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_DisplaySettings_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DisplaySettings_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_DisplaySettings_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.DisplaySettings.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  widgets_.Clear();
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  brightness_ = false;
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.DisplaySettings.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_widgets()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string name = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "blox_test.DisplaySettings.Block.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool brightness = 90 [(.nanopb) = {
      case 90: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(208u /* 720 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &brightness_)));
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
  // @@protoc_insertion_point(parse_success:blox_test.DisplaySettings.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.DisplaySettings.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.DisplaySettings.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->widgets_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->widgets(static_cast<int>(i)),
      output);
  }

  // string name = 2 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Block.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // bool brightness = 90 [(.nanopb) = {
  if (this->brightness() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(90, this->brightness(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.DisplaySettings.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.DisplaySettings.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->widgets_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->widgets(static_cast<int>(i)), deterministic, target);
  }

  // string name = 2 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Block.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // bool brightness = 90 [(.nanopb) = {
  if (this->brightness() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(90, this->brightness(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.DisplaySettings.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.DisplaySettings.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  {
    unsigned int count = static_cast<unsigned int>(this->widgets_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->widgets(static_cast<int>(i)));
    }
  }

  // string name = 2 [(.nanopb) = {
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // bool brightness = 90 [(.nanopb) = {
  if (this->brightness() != 0) {
    total_size += 2 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.DisplaySettings.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.DisplaySettings.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.DisplaySettings.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.DisplaySettings.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  widgets_.MergeFrom(from.widgets_);
  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.brightness() != 0) {
    set_brightness(from.brightness());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.DisplaySettings.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.DisplaySettings.Block)
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
  CastToBase(&widgets_)->InternalSwap(CastToBase(&other->widgets_));
  name_.Swap(&other->name_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(brightness_, other->brightness_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_DisplaySettings_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DisplaySettings_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace DisplaySettings
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::DisplaySettings::Widget* Arena::CreateMaybeMessage< ::blox_test::DisplaySettings::Widget >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::DisplaySettings::Widget >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::DisplaySettings::Block* Arena::CreateMaybeMessage< ::blox_test::DisplaySettings::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::DisplaySettings::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
