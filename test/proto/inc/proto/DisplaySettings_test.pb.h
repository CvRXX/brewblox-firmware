// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DisplaySettings_test.proto

#ifndef PROTOBUF_INCLUDED_DisplaySettings_5ftest_2eproto
#define PROTOBUF_INCLUDED_DisplaySettings_5ftest_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_DisplaySettings_5ftest_2eproto 

namespace protobuf_DisplaySettings_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_DisplaySettings_5ftest_2eproto
namespace blox_test {
namespace DisplaySettings {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class Widget;
class WidgetDefaultTypeInternal;
extern WidgetDefaultTypeInternal _Widget_default_instance_;
}  // namespace DisplaySettings
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::DisplaySettings::Block* Arena::CreateMaybeMessage<::blox_test::DisplaySettings::Block>(Arena*);
template<> ::blox_test::DisplaySettings::Widget* Arena::CreateMaybeMessage<::blox_test::DisplaySettings::Widget>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace DisplaySettings {

// ===================================================================

class Widget : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.DisplaySettings.Widget) */ {
 public:
  Widget();
  virtual ~Widget();

  Widget(const Widget& from);

  inline Widget& operator=(const Widget& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Widget(Widget&& from) noexcept
    : Widget() {
    *this = ::std::move(from);
  }

  inline Widget& operator=(Widget&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Widget& default_instance();

  enum WidgetTypeCase {
    kTempSensor = 10,
    kSetpointSensorPair = 11,
    kActuatorAnalog = 12,
    kPid = 14,
    WIDGETTYPE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Widget* internal_default_instance() {
    return reinterpret_cast<const Widget*>(
               &_Widget_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Widget* other);
  friend void swap(Widget& a, Widget& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Widget* New() const final {
    return CreateMaybeMessage<Widget>(NULL);
  }

  Widget* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Widget>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Widget& from);
  void MergeFrom(const Widget& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Widget* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes color = 2 [(.nanopb) = {
  void clear_color();
  static const int kColorFieldNumber = 2;
  const ::std::string& color() const;
  void set_color(const ::std::string& value);
  #if LANG_CXX11
  void set_color(::std::string&& value);
  #endif
  void set_color(const char* value);
  void set_color(const void* value, size_t size);
  ::std::string* mutable_color();
  ::std::string* release_color();
  void set_allocated_color(::std::string* color);

  // string name = 3 [(.nanopb) = {
  void clear_name();
  static const int kNameFieldNumber = 3;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // uint32 pos = 1 [(.nanopb) = {
  void clear_pos();
  static const int kPosFieldNumber = 1;
  ::google::protobuf::uint32 pos() const;
  void set_pos(::google::protobuf::uint32 value);

  // uint32 tempSensor = 10 [(.nanopb) = {
  private:
  bool has_tempsensor() const;
  public:
  void clear_tempsensor();
  static const int kTempSensorFieldNumber = 10;
  ::google::protobuf::uint32 tempsensor() const;
  void set_tempsensor(::google::protobuf::uint32 value);

  // uint32 setpointSensorPair = 11 [(.nanopb) = {
  private:
  bool has_setpointsensorpair() const;
  public:
  void clear_setpointsensorpair();
  static const int kSetpointSensorPairFieldNumber = 11;
  ::google::protobuf::uint32 setpointsensorpair() const;
  void set_setpointsensorpair(::google::protobuf::uint32 value);

  // uint32 actuatorAnalog = 12 [(.nanopb) = {
  private:
  bool has_actuatoranalog() const;
  public:
  void clear_actuatoranalog();
  static const int kActuatorAnalogFieldNumber = 12;
  ::google::protobuf::uint32 actuatoranalog() const;
  void set_actuatoranalog(::google::protobuf::uint32 value);

  // uint32 pid = 14 [(.nanopb) = {
  private:
  bool has_pid() const;
  public:
  void clear_pid();
  static const int kPidFieldNumber = 14;
  ::google::protobuf::uint32 pid() const;
  void set_pid(::google::protobuf::uint32 value);

  void clear_WidgetType();
  WidgetTypeCase WidgetType_case() const;
  // @@protoc_insertion_point(class_scope:blox_test.DisplaySettings.Widget)
 private:
  void set_has_tempsensor();
  void set_has_setpointsensorpair();
  void set_has_actuatoranalog();
  void set_has_pid();

  inline bool has_WidgetType() const;
  inline void clear_has_WidgetType();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr color_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint32 pos_;
  union WidgetTypeUnion {
    WidgetTypeUnion() {}
    ::google::protobuf::uint32 tempsensor_;
    ::google::protobuf::uint32 setpointsensorpair_;
    ::google::protobuf::uint32 actuatoranalog_;
    ::google::protobuf::uint32 pid_;
  } WidgetType_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_DisplaySettings_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.DisplaySettings.Block) */ {
 public:
  Block();
  virtual ~Block();

  Block(const Block& from);

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(Block&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Block& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Block* other);
  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Block* New() const final {
    return CreateMaybeMessage<Block>(NULL);
  }

  Block* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Block* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
  int widgets_size() const;
  void clear_widgets();
  static const int kWidgetsFieldNumber = 1;
  ::blox_test::DisplaySettings::Widget* mutable_widgets(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::DisplaySettings::Widget >*
      mutable_widgets();
  const ::blox_test::DisplaySettings::Widget& widgets(int index) const;
  ::blox_test::DisplaySettings::Widget* add_widgets();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::DisplaySettings::Widget >&
      widgets() const;

  // string name = 2 [(.nanopb) = {
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // bool brightness = 90 [(.nanopb) = {
  void clear_brightness();
  static const int kBrightnessFieldNumber = 90;
  bool brightness() const;
  void set_brightness(bool value);

  // bool timeZone = 91 [(.nanopb) = {
  void clear_timezone();
  static const int kTimeZoneFieldNumber = 91;
  bool timezone() const;
  void set_timezone(bool value);

  // bool tempUnit = 92 [(.nanopb) = {
  void clear_tempunit();
  static const int kTempUnitFieldNumber = 92;
  bool tempunit() const;
  void set_tempunit(bool value);

  // @@protoc_insertion_point(class_scope:blox_test.DisplaySettings.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::DisplaySettings::Widget > widgets_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  bool brightness_;
  bool timezone_;
  bool tempunit_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_DisplaySettings_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Widget

// uint32 pos = 1 [(.nanopb) = {
inline void Widget::clear_pos() {
  pos_ = 0u;
}
inline ::google::protobuf::uint32 Widget::pos() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.pos)
  return pos_;
}
inline void Widget::set_pos(::google::protobuf::uint32 value) {
  
  pos_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.pos)
}

// bytes color = 2 [(.nanopb) = {
inline void Widget::clear_color() {
  color_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Widget::color() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.color)
  return color_.GetNoArena();
}
inline void Widget::set_color(const ::std::string& value) {
  
  color_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.color)
}
#if LANG_CXX11
inline void Widget::set_color(::std::string&& value) {
  
  color_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.DisplaySettings.Widget.color)
}
#endif
inline void Widget::set_color(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  color_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.DisplaySettings.Widget.color)
}
inline void Widget::set_color(const void* value, size_t size) {
  
  color_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.DisplaySettings.Widget.color)
}
inline ::std::string* Widget::mutable_color() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.DisplaySettings.Widget.color)
  return color_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Widget::release_color() {
  // @@protoc_insertion_point(field_release:blox_test.DisplaySettings.Widget.color)
  
  return color_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Widget::set_allocated_color(::std::string* color) {
  if (color != NULL) {
    
  } else {
    
  }
  color_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), color);
  // @@protoc_insertion_point(field_set_allocated:blox_test.DisplaySettings.Widget.color)
}

// string name = 3 [(.nanopb) = {
inline void Widget::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Widget::name() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.name)
  return name_.GetNoArena();
}
inline void Widget::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.name)
}
#if LANG_CXX11
inline void Widget::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.DisplaySettings.Widget.name)
}
#endif
inline void Widget::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.DisplaySettings.Widget.name)
}
inline void Widget::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.DisplaySettings.Widget.name)
}
inline ::std::string* Widget::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.DisplaySettings.Widget.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Widget::release_name() {
  // @@protoc_insertion_point(field_release:blox_test.DisplaySettings.Widget.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Widget::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:blox_test.DisplaySettings.Widget.name)
}

// uint32 tempSensor = 10 [(.nanopb) = {
inline bool Widget::has_tempsensor() const {
  return WidgetType_case() == kTempSensor;
}
inline void Widget::set_has_tempsensor() {
  _oneof_case_[0] = kTempSensor;
}
inline void Widget::clear_tempsensor() {
  if (has_tempsensor()) {
    WidgetType_.tempsensor_ = 0u;
    clear_has_WidgetType();
  }
}
inline ::google::protobuf::uint32 Widget::tempsensor() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.tempSensor)
  if (has_tempsensor()) {
    return WidgetType_.tempsensor_;
  }
  return 0u;
}
inline void Widget::set_tempsensor(::google::protobuf::uint32 value) {
  if (!has_tempsensor()) {
    clear_WidgetType();
    set_has_tempsensor();
  }
  WidgetType_.tempsensor_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.tempSensor)
}

// uint32 setpointSensorPair = 11 [(.nanopb) = {
inline bool Widget::has_setpointsensorpair() const {
  return WidgetType_case() == kSetpointSensorPair;
}
inline void Widget::set_has_setpointsensorpair() {
  _oneof_case_[0] = kSetpointSensorPair;
}
inline void Widget::clear_setpointsensorpair() {
  if (has_setpointsensorpair()) {
    WidgetType_.setpointsensorpair_ = 0u;
    clear_has_WidgetType();
  }
}
inline ::google::protobuf::uint32 Widget::setpointsensorpair() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.setpointSensorPair)
  if (has_setpointsensorpair()) {
    return WidgetType_.setpointsensorpair_;
  }
  return 0u;
}
inline void Widget::set_setpointsensorpair(::google::protobuf::uint32 value) {
  if (!has_setpointsensorpair()) {
    clear_WidgetType();
    set_has_setpointsensorpair();
  }
  WidgetType_.setpointsensorpair_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.setpointSensorPair)
}

// uint32 actuatorAnalog = 12 [(.nanopb) = {
inline bool Widget::has_actuatoranalog() const {
  return WidgetType_case() == kActuatorAnalog;
}
inline void Widget::set_has_actuatoranalog() {
  _oneof_case_[0] = kActuatorAnalog;
}
inline void Widget::clear_actuatoranalog() {
  if (has_actuatoranalog()) {
    WidgetType_.actuatoranalog_ = 0u;
    clear_has_WidgetType();
  }
}
inline ::google::protobuf::uint32 Widget::actuatoranalog() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.actuatorAnalog)
  if (has_actuatoranalog()) {
    return WidgetType_.actuatoranalog_;
  }
  return 0u;
}
inline void Widget::set_actuatoranalog(::google::protobuf::uint32 value) {
  if (!has_actuatoranalog()) {
    clear_WidgetType();
    set_has_actuatoranalog();
  }
  WidgetType_.actuatoranalog_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.actuatorAnalog)
}

// uint32 pid = 14 [(.nanopb) = {
inline bool Widget::has_pid() const {
  return WidgetType_case() == kPid;
}
inline void Widget::set_has_pid() {
  _oneof_case_[0] = kPid;
}
inline void Widget::clear_pid() {
  if (has_pid()) {
    WidgetType_.pid_ = 0u;
    clear_has_WidgetType();
  }
}
inline ::google::protobuf::uint32 Widget::pid() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Widget.pid)
  if (has_pid()) {
    return WidgetType_.pid_;
  }
  return 0u;
}
inline void Widget::set_pid(::google::protobuf::uint32 value) {
  if (!has_pid()) {
    clear_WidgetType();
    set_has_pid();
  }
  WidgetType_.pid_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Widget.pid)
}

inline bool Widget::has_WidgetType() const {
  return WidgetType_case() != WIDGETTYPE_NOT_SET;
}
inline void Widget::clear_has_WidgetType() {
  _oneof_case_[0] = WIDGETTYPE_NOT_SET;
}
inline Widget::WidgetTypeCase Widget::WidgetType_case() const {
  return Widget::WidgetTypeCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// Block

// repeated .blox_test.DisplaySettings.Widget widgets = 1 [(.nanopb) = {
inline int Block::widgets_size() const {
  return widgets_.size();
}
inline void Block::clear_widgets() {
  widgets_.Clear();
}
inline ::blox_test::DisplaySettings::Widget* Block::mutable_widgets(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.DisplaySettings.Block.widgets)
  return widgets_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::DisplaySettings::Widget >*
Block::mutable_widgets() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.DisplaySettings.Block.widgets)
  return &widgets_;
}
inline const ::blox_test::DisplaySettings::Widget& Block::widgets(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Block.widgets)
  return widgets_.Get(index);
}
inline ::blox_test::DisplaySettings::Widget* Block::add_widgets() {
  // @@protoc_insertion_point(field_add:blox_test.DisplaySettings.Block.widgets)
  return widgets_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::DisplaySettings::Widget >&
Block::widgets() const {
  // @@protoc_insertion_point(field_list:blox_test.DisplaySettings.Block.widgets)
  return widgets_;
}

// string name = 2 [(.nanopb) = {
inline void Block::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::name() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Block.name)
  return name_.GetNoArena();
}
inline void Block::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Block.name)
}
#if LANG_CXX11
inline void Block::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.DisplaySettings.Block.name)
}
#endif
inline void Block::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.DisplaySettings.Block.name)
}
inline void Block::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.DisplaySettings.Block.name)
}
inline ::std::string* Block::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.DisplaySettings.Block.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_name() {
  // @@protoc_insertion_point(field_release:blox_test.DisplaySettings.Block.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:blox_test.DisplaySettings.Block.name)
}

// bool brightness = 90 [(.nanopb) = {
inline void Block::clear_brightness() {
  brightness_ = false;
}
inline bool Block::brightness() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Block.brightness)
  return brightness_;
}
inline void Block::set_brightness(bool value) {
  
  brightness_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Block.brightness)
}

// bool timeZone = 91 [(.nanopb) = {
inline void Block::clear_timezone() {
  timezone_ = false;
}
inline bool Block::timezone() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Block.timeZone)
  return timezone_;
}
inline void Block::set_timezone(bool value) {
  
  timezone_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Block.timeZone)
}

// bool tempUnit = 92 [(.nanopb) = {
inline void Block::clear_tempunit() {
  tempunit_ = false;
}
inline bool Block::tempunit() const {
  // @@protoc_insertion_point(field_get:blox_test.DisplaySettings.Block.tempUnit)
  return tempunit_;
}
inline void Block::set_tempunit(bool value) {
  
  tempunit_ = value;
  // @@protoc_insertion_point(field_set:blox_test.DisplaySettings.Block.tempUnit)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace DisplaySettings
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_DisplaySettings_5ftest_2eproto
