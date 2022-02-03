// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DisplaySettings_test.proto

#include "DisplaySettings_test.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_DisplaySettings_5ftest_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Widget_DisplaySettings_5ftest_2eproto;
namespace blox_test {
namespace DisplaySettings {
class WidgetDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Widget> _instance;
  ::PROTOBUF_NAMESPACE_ID::uint32 tempsensor_;
  ::PROTOBUF_NAMESPACE_ID::uint32 setpointsensorpair_;
  ::PROTOBUF_NAMESPACE_ID::uint32 actuatoranalog_;
  ::PROTOBUF_NAMESPACE_ID::uint32 pid_;
} _Widget_default_instance_;
class BlockDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Block> _instance;
} _Block_default_instance_;
}  // namespace DisplaySettings
}  // namespace blox_test
static void InitDefaultsscc_info_Block_DisplaySettings_5ftest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::DisplaySettings::_Block_default_instance_;
    new (ptr) ::blox_test::DisplaySettings::Block();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::DisplaySettings::Block::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Block_DisplaySettings_5ftest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Block_DisplaySettings_5ftest_2eproto}, {
      &scc_info_Widget_DisplaySettings_5ftest_2eproto.base,}};

static void InitDefaultsscc_info_Widget_DisplaySettings_5ftest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::DisplaySettings::_Widget_default_instance_;
    new (ptr) ::blox_test::DisplaySettings::Widget();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::DisplaySettings::Widget::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Widget_DisplaySettings_5ftest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Widget_DisplaySettings_5ftest_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_DisplaySettings_5ftest_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_DisplaySettings_5ftest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_DisplaySettings_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_DisplaySettings_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, pos_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, color_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, name_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, tempsensor_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, setpointsensorpair_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, actuatoranalog_),
  offsetof(::blox_test::DisplaySettings::WidgetDefaultTypeInternal, pid_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Widget, WidgetType_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, widgets_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, name_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, tempunit_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, brightness_),
  PROTOBUF_FIELD_OFFSET(::blox_test::DisplaySettings::Block, timezone_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::DisplaySettings::Widget)},
  { 13, -1, sizeof(::blox_test::DisplaySettings::Block)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox_test::DisplaySettings::_Widget_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox_test::DisplaySettings::_Block_default_instance_),
};

const char descriptor_table_protodef_DisplaySettings_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032DisplaySettings_test.proto\022\031blox_test."
  "DisplaySettings\032\023brewblox_test.proto\032\021na"
  "nopb_test.proto\"\362\001\n\006Widget\022\022\n\003pos\030\001 \001(\rB"
  "\005\222\?\0028\010\022\037\n\005color\030\002 \001(\014B\020\222\?\002\010\003\222\?\002x\001\212\265\030\0028\001\022"
  "\023\n\004name\030\003 \001(\tB\005\222\?\002\010\020\022!\n\ntempSensor\030\n \001(\r"
  "B\013\212\265\030\002\030\002\222\?\0028\020H\000\022)\n\022setpointSensorPair\030\013 "
  "\001(\rB\013\212\265\030\002\030\004\222\?\0028\020H\000\022%\n\016actuatorAnalog\030\014 \001"
  "(\rB\013\212\265\030\002\030\005\222\?\0028\020H\000\022\033\n\003pid\030\016 \001(\rB\014\212\265\030\003\030\260\002\222"
  "\?\0028\020H\000B\014\n\nWidgetType\"\322\001\n\005Block\0229\n\007widget"
  "s\030\001 \003(\0132!.blox_test.DisplaySettings.Widg"
  "etB\005\222\?\002\020\006\022\023\n\004name\030\002 \001(\tB\005\222\?\002\010(\022<\n\010tempUn"
  "it\030\003 \001(\0162*.blox_test.DisplaySettings.Tem"
  "peratureUnit\022\031\n\nbrightness\030\004 \001(\rB\005\222\?\0028\010\022"
  "\027\n\010timeZone\030\005 \001(\tB\005\222\?\002\010 :\007\212\265\030\003\030\272\002*8\n\017Tem"
  "peratureUnit\022\020\n\014TEMP_CELSIUS\020\000\022\023\n\017TEMP_F"
  "AHRENHEIT\020\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_DisplaySettings_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_DisplaySettings_5ftest_2eproto_sccs[2] = {
  &scc_info_Block_DisplaySettings_5ftest_2eproto.base,
  &scc_info_Widget_DisplaySettings_5ftest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_DisplaySettings_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_DisplaySettings_5ftest_2eproto = {
  false, false, descriptor_table_protodef_DisplaySettings_5ftest_2eproto, "DisplaySettings_test.proto", 619,
  &descriptor_table_DisplaySettings_5ftest_2eproto_once, descriptor_table_DisplaySettings_5ftest_2eproto_sccs, descriptor_table_DisplaySettings_5ftest_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_DisplaySettings_5ftest_2eproto::offsets,
  file_level_metadata_DisplaySettings_5ftest_2eproto, 2, file_level_enum_descriptors_DisplaySettings_5ftest_2eproto, file_level_service_descriptors_DisplaySettings_5ftest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_DisplaySettings_5ftest_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_DisplaySettings_5ftest_2eproto)), true);
namespace blox_test {
namespace DisplaySettings {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* TemperatureUnit_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_DisplaySettings_5ftest_2eproto);
  return file_level_enum_descriptors_DisplaySettings_5ftest_2eproto[0];
}
bool TemperatureUnit_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Widget::InitAsDefaultInstance() {
  ::blox_test::DisplaySettings::_Widget_default_instance_.tempsensor_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.setpointsensorpair_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.actuatoranalog_ = 0u;
  ::blox_test::DisplaySettings::_Widget_default_instance_.pid_ = 0u;
}
class Widget::_Internal {
 public:
};

Widget::Widget(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:blox_test.DisplaySettings.Widget)
}
Widget::Widget(const Widget& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  color_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_color().empty()) {
    color_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_color(),
      GetArena());
  }
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  pos_ = from.pos_;
  clear_has_WidgetType();
  switch (from.WidgetType_case()) {
    case kTempSensor: {
      _internal_set_tempsensor(from._internal_tempsensor());
      break;
    }
    case kSetpointSensorPair: {
      _internal_set_setpointsensorpair(from._internal_setpointsensorpair());
      break;
    }
    case kActuatorAnalog: {
      _internal_set_actuatoranalog(from._internal_actuatoranalog());
      break;
    }
    case kPid: {
      _internal_set_pid(from._internal_pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:blox_test.DisplaySettings.Widget)
}

void Widget::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Widget_DisplaySettings_5ftest_2eproto.base);
  color_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  pos_ = 0u;
  clear_has_WidgetType();
}

Widget::~Widget() {
  // @@protoc_insertion_point(destructor:blox_test.DisplaySettings.Widget)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Widget::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  color_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (has_WidgetType()) {
    clear_WidgetType();
  }
}

void Widget::ArenaDtor(void* object) {
  Widget* _this = reinterpret_cast< Widget* >(object);
  (void)_this;
}
void Widget::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Widget::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Widget& Widget::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Widget_DisplaySettings_5ftest_2eproto.base);
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
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  color_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  pos_ = 0u;
  clear_WidgetType();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Widget::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 pos = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          pos_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes color = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_color();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string name = 3 [(.nanopb) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "blox_test.DisplaySettings.Widget.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 tempSensor = 10 [(.nanopb) = {
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          _internal_set_tempsensor(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 setpointSensorPair = 11 [(.nanopb) = {
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 88)) {
          _internal_set_setpointsensorpair(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 actuatorAnalog = 12 [(.nanopb) = {
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 96)) {
          _internal_set_actuatoranalog(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 pid = 14 [(.nanopb) = {
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 112)) {
          _internal_set_pid(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
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

::PROTOBUF_NAMESPACE_ID::uint8* Widget::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.DisplaySettings.Widget)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 pos = 1 [(.nanopb) = {
  if (this->pos() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_pos(), target);
  }

  // bytes color = 2 [(.nanopb) = {
  if (this->color().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_color(), target);
  }

  // string name = 3 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Widget.name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_name(), target);
  }

  // uint32 tempSensor = 10 [(.nanopb) = {
  if (_internal_has_tempsensor()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(10, this->_internal_tempsensor(), target);
  }

  // uint32 setpointSensorPair = 11 [(.nanopb) = {
  if (_internal_has_setpointsensorpair()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(11, this->_internal_setpointsensorpair(), target);
  }

  // uint32 actuatorAnalog = 12 [(.nanopb) = {
  if (_internal_has_actuatoranalog()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(12, this->_internal_actuatoranalog(), target);
  }

  // uint32 pid = 14 [(.nanopb) = {
  if (_internal_has_pid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(14, this->_internal_pid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.DisplaySettings.Widget)
  return target;
}

size_t Widget::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.DisplaySettings.Widget)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes color = 2 [(.nanopb) = {
  if (this->color().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_color());
  }

  // string name = 3 [(.nanopb) = {
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // uint32 pos = 1 [(.nanopb) = {
  if (this->pos() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_pos());
  }

  switch (WidgetType_case()) {
    // uint32 tempSensor = 10 [(.nanopb) = {
    case kTempSensor: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_tempsensor());
      break;
    }
    // uint32 setpointSensorPair = 11 [(.nanopb) = {
    case kSetpointSensorPair: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_setpointsensorpair());
      break;
    }
    // uint32 actuatorAnalog = 12 [(.nanopb) = {
    case kActuatorAnalog: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_actuatoranalog());
      break;
    }
    // uint32 pid = 14 [(.nanopb) = {
    case kPid: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Widget::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.DisplaySettings.Widget)
  GOOGLE_DCHECK_NE(&from, this);
  const Widget* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Widget>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.DisplaySettings.Widget)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.DisplaySettings.Widget)
    MergeFrom(*source);
  }
}

void Widget::MergeFrom(const Widget& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.DisplaySettings.Widget)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.color().size() > 0) {
    _internal_set_color(from._internal_color());
  }
  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.pos() != 0) {
    _internal_set_pos(from._internal_pos());
  }
  switch (from.WidgetType_case()) {
    case kTempSensor: {
      _internal_set_tempsensor(from._internal_tempsensor());
      break;
    }
    case kSetpointSensorPair: {
      _internal_set_setpointsensorpair(from._internal_setpointsensorpair());
      break;
    }
    case kActuatorAnalog: {
      _internal_set_actuatoranalog(from._internal_actuatoranalog());
      break;
    }
    case kPid: {
      _internal_set_pid(from._internal_pid());
      break;
    }
    case WIDGETTYPE_NOT_SET: {
      break;
    }
  }
}

void Widget::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void Widget::InternalSwap(Widget* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  color_.Swap(&other->color_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(pos_, other->pos_);
  swap(WidgetType_, other->WidgetType_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata Widget::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
class Block::_Internal {
 public:
};

Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  widgets_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:blox_test.DisplaySettings.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      widgets_(from.widgets_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  timezone_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_timezone().empty()) {
    timezone_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_timezone(),
      GetArena());
  }
  ::memcpy(&tempunit_, &from.tempunit_,
    static_cast<size_t>(reinterpret_cast<char*>(&brightness_) -
    reinterpret_cast<char*>(&tempunit_)) + sizeof(brightness_));
  // @@protoc_insertion_point(copy_constructor:blox_test.DisplaySettings.Block)
}

void Block::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Block_DisplaySettings_5ftest_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timezone_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&tempunit_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&brightness_) -
      reinterpret_cast<char*>(&tempunit_)) + sizeof(brightness_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.DisplaySettings.Block)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  timezone_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Block::ArenaDtor(void* object) {
  Block* _this = reinterpret_cast< Block* >(object);
  (void)_this;
}
void Block::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Block& Block::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Block_DisplaySettings_5ftest_2eproto.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.DisplaySettings.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  widgets_.Clear();
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  timezone_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&tempunit_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&brightness_) -
      reinterpret_cast<char*>(&tempunit_)) + sizeof(brightness_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_widgets(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // string name = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "blox_test.DisplaySettings.Block.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .blox_test.DisplaySettings.TemperatureUnit tempUnit = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_tempunit(static_cast<::blox_test::DisplaySettings::TemperatureUnit>(val));
        } else goto handle_unusual;
        continue;
      // uint32 brightness = 4 [(.nanopb) = {
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          brightness_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string timeZone = 5 [(.nanopb) = {
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_timezone();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "blox_test.DisplaySettings.Block.timeZone"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
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

::PROTOBUF_NAMESPACE_ID::uint8* Block::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.DisplaySettings.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_widgets_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_widgets(i), target, stream);
  }

  // string name = 2 [(.nanopb) = {
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Block.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // .blox_test.DisplaySettings.TemperatureUnit tempUnit = 3;
  if (this->tempunit() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_tempunit(), target);
  }

  // uint32 brightness = 4 [(.nanopb) = {
  if (this->brightness() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(4, this->_internal_brightness(), target);
  }

  // string timeZone = 5 [(.nanopb) = {
  if (this->timezone().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_timezone().data(), static_cast<int>(this->_internal_timezone().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "blox_test.DisplaySettings.Block.timeZone");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_timezone(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.DisplaySettings.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.DisplaySettings.Block)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  total_size += 1UL * this->_internal_widgets_size();
  for (const auto& msg : this->widgets_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string name = 2 [(.nanopb) = {
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string timeZone = 5 [(.nanopb) = {
  if (this->timezone().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_timezone());
  }

  // .blox_test.DisplaySettings.TemperatureUnit tempUnit = 3;
  if (this->tempunit() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_tempunit());
  }

  // uint32 brightness = 4 [(.nanopb) = {
  if (this->brightness() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_brightness());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.DisplaySettings.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Block>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.DisplaySettings.Block)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.DisplaySettings.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.DisplaySettings.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  widgets_.MergeFrom(from.widgets_);
  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.timezone().size() > 0) {
    _internal_set_timezone(from._internal_timezone());
  }
  if (from.tempunit() != 0) {
    _internal_set_tempunit(from._internal_tempunit());
  }
  if (from.brightness() != 0) {
    _internal_set_brightness(from._internal_brightness());
  }
}

void Block::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
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

void Block::InternalSwap(Block* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  widgets_.InternalSwap(&other->widgets_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  timezone_.Swap(&other->timezone_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, brightness_)
      + sizeof(Block::brightness_)
      - PROTOBUF_FIELD_OFFSET(Block, tempunit_)>(
          reinterpret_cast<char*>(&tempunit_),
          reinterpret_cast<char*>(&other->tempunit_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace DisplaySettings
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::DisplaySettings::Widget* Arena::CreateMaybeMessage< ::blox_test::DisplaySettings::Widget >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::DisplaySettings::Widget >(arena);
}
template<> PROTOBUF_NOINLINE ::blox_test::DisplaySettings::Block* Arena::CreateMaybeMessage< ::blox_test::DisplaySettings::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::DisplaySettings::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
