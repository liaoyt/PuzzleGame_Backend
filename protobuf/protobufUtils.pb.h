// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protobufUtils.proto

#ifndef PROTOBUF_protobufUtils_2eproto__INCLUDED
#define PROTOBUF_protobufUtils_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobufUtils {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_protobufUtils_2eproto();
void protobuf_AssignDesc_protobufUtils_2eproto();
void protobuf_ShutdownFile_protobufUtils_2eproto();

class PGRequest;
class PGRequest_RankInfo;

// ===================================================================

class PGRequest_RankInfo : public ::google::protobuf::Message {
 public:
  PGRequest_RankInfo();
  virtual ~PGRequest_RankInfo();

  PGRequest_RankInfo(const PGRequest_RankInfo& from);

  inline PGRequest_RankInfo& operator=(const PGRequest_RankInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PGRequest_RankInfo& default_instance();

  void Swap(PGRequest_RankInfo* other);

  // implements Message ----------------------------------------------

  PGRequest_RankInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PGRequest_RankInfo& from);
  void MergeFrom(const PGRequest_RankInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 myRank = 1;
  inline bool has_myrank() const;
  inline void clear_myrank();
  static const int kMyRankFieldNumber = 1;
  inline ::google::protobuf::int32 myrank() const;
  inline void set_myrank(::google::protobuf::int32 value);

  // repeated string username = 2;
  inline int username_size() const;
  inline void clear_username();
  static const int kUsernameFieldNumber = 2;
  inline const ::std::string& username(int index) const;
  inline ::std::string* mutable_username(int index);
  inline void set_username(int index, const ::std::string& value);
  inline void set_username(int index, const char* value);
  inline void set_username(int index, const char* value, size_t size);
  inline ::std::string* add_username();
  inline void add_username(const ::std::string& value);
  inline void add_username(const char* value);
  inline void add_username(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& username() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_username();

  // @@protoc_insertion_point(class_scope:protobufUtils.PGRequest.RankInfo)
 private:
  inline void set_has_myrank();
  inline void clear_has_myrank();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> username_;
  ::google::protobuf::int32 myrank_;
  friend void  protobuf_AddDesc_protobufUtils_2eproto();
  friend void protobuf_AssignDesc_protobufUtils_2eproto();
  friend void protobuf_ShutdownFile_protobufUtils_2eproto();

  void InitAsDefaultInstance();
  static PGRequest_RankInfo* default_instance_;
};
// -------------------------------------------------------------------

class PGRequest : public ::google::protobuf::Message {
 public:
  PGRequest();
  virtual ~PGRequest();

  PGRequest(const PGRequest& from);

  inline PGRequest& operator=(const PGRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PGRequest& default_instance();

  void Swap(PGRequest* other);

  // implements Message ----------------------------------------------

  PGRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PGRequest& from);
  void MergeFrom(const PGRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef PGRequest_RankInfo RankInfo;

  // accessors -------------------------------------------------------

  // required int32 Code = 1;
  inline bool has_code() const;
  inline void clear_code();
  static const int kCodeFieldNumber = 1;
  inline ::google::protobuf::int32 code() const;
  inline void set_code(::google::protobuf::int32 value);

  // optional string errorInfo = 2;
  inline bool has_errorinfo() const;
  inline void clear_errorinfo();
  static const int kErrorInfoFieldNumber = 2;
  inline const ::std::string& errorinfo() const;
  inline void set_errorinfo(const ::std::string& value);
  inline void set_errorinfo(const char* value);
  inline void set_errorinfo(const char* value, size_t size);
  inline ::std::string* mutable_errorinfo();
  inline ::std::string* release_errorinfo();
  inline void set_allocated_errorinfo(::std::string* errorinfo);

  // optional string username = 3;
  inline bool has_username() const;
  inline void clear_username();
  static const int kUsernameFieldNumber = 3;
  inline const ::std::string& username() const;
  inline void set_username(const ::std::string& value);
  inline void set_username(const char* value);
  inline void set_username(const char* value, size_t size);
  inline ::std::string* mutable_username();
  inline ::std::string* release_username();
  inline void set_allocated_username(::std::string* username);

  // optional string password = 4;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 4;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // optional string score = 5;
  inline bool has_score() const;
  inline void clear_score();
  static const int kScoreFieldNumber = 5;
  inline const ::std::string& score() const;
  inline void set_score(const ::std::string& value);
  inline void set_score(const char* value);
  inline void set_score(const char* value, size_t size);
  inline ::std::string* mutable_score();
  inline ::std::string* release_score();
  inline void set_allocated_score(::std::string* score);

  // optional string picture = 6;
  inline bool has_picture() const;
  inline void clear_picture();
  static const int kPictureFieldNumber = 6;
  inline const ::std::string& picture() const;
  inline void set_picture(const ::std::string& value);
  inline void set_picture(const char* value);
  inline void set_picture(const char* value, size_t size);
  inline ::std::string* mutable_picture();
  inline ::std::string* release_picture();
  inline void set_allocated_picture(::std::string* picture);

  // optional .protobufUtils.PGRequest.RankInfo rankInfo = 7;
  inline bool has_rankinfo() const;
  inline void clear_rankinfo();
  static const int kRankInfoFieldNumber = 7;
  inline const ::protobufUtils::PGRequest_RankInfo& rankinfo() const;
  inline ::protobufUtils::PGRequest_RankInfo* mutable_rankinfo();
  inline ::protobufUtils::PGRequest_RankInfo* release_rankinfo();
  inline void set_allocated_rankinfo(::protobufUtils::PGRequest_RankInfo* rankinfo);

  // repeated string picList = 8;
  inline int piclist_size() const;
  inline void clear_piclist();
  static const int kPicListFieldNumber = 8;
  inline const ::std::string& piclist(int index) const;
  inline ::std::string* mutable_piclist(int index);
  inline void set_piclist(int index, const ::std::string& value);
  inline void set_piclist(int index, const char* value);
  inline void set_piclist(int index, const char* value, size_t size);
  inline ::std::string* add_piclist();
  inline void add_piclist(const ::std::string& value);
  inline void add_piclist(const char* value);
  inline void add_piclist(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& piclist() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_piclist();

  // @@protoc_insertion_point(class_scope:protobufUtils.PGRequest)
 private:
  inline void set_has_code();
  inline void clear_has_code();
  inline void set_has_errorinfo();
  inline void clear_has_errorinfo();
  inline void set_has_username();
  inline void clear_has_username();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_score();
  inline void clear_has_score();
  inline void set_has_picture();
  inline void clear_has_picture();
  inline void set_has_rankinfo();
  inline void clear_has_rankinfo();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* errorinfo_;
  ::std::string* username_;
  ::std::string* password_;
  ::std::string* score_;
  ::std::string* picture_;
  ::protobufUtils::PGRequest_RankInfo* rankinfo_;
  ::google::protobuf::RepeatedPtrField< ::std::string> piclist_;
  ::google::protobuf::int32 code_;
  friend void  protobuf_AddDesc_protobufUtils_2eproto();
  friend void protobuf_AssignDesc_protobufUtils_2eproto();
  friend void protobuf_ShutdownFile_protobufUtils_2eproto();

  void InitAsDefaultInstance();
  static PGRequest* default_instance_;
};
// ===================================================================


// ===================================================================

// PGRequest_RankInfo

// required int32 myRank = 1;
inline bool PGRequest_RankInfo::has_myrank() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PGRequest_RankInfo::set_has_myrank() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PGRequest_RankInfo::clear_has_myrank() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PGRequest_RankInfo::clear_myrank() {
  myrank_ = 0;
  clear_has_myrank();
}
inline ::google::protobuf::int32 PGRequest_RankInfo::myrank() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.RankInfo.myRank)
  return myrank_;
}
inline void PGRequest_RankInfo::set_myrank(::google::protobuf::int32 value) {
  set_has_myrank();
  myrank_ = value;
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.RankInfo.myRank)
}

// repeated string username = 2;
inline int PGRequest_RankInfo::username_size() const {
  return username_.size();
}
inline void PGRequest_RankInfo::clear_username() {
  username_.Clear();
}
inline const ::std::string& PGRequest_RankInfo::username(int index) const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.RankInfo.username)
  return username_.Get(index);
}
inline ::std::string* PGRequest_RankInfo::mutable_username(int index) {
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.RankInfo.username)
  return username_.Mutable(index);
}
inline void PGRequest_RankInfo::set_username(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.RankInfo.username)
  username_.Mutable(index)->assign(value);
}
inline void PGRequest_RankInfo::set_username(int index, const char* value) {
  username_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.RankInfo.username)
}
inline void PGRequest_RankInfo::set_username(int index, const char* value, size_t size) {
  username_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.RankInfo.username)
}
inline ::std::string* PGRequest_RankInfo::add_username() {
  return username_.Add();
}
inline void PGRequest_RankInfo::add_username(const ::std::string& value) {
  username_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:protobufUtils.PGRequest.RankInfo.username)
}
inline void PGRequest_RankInfo::add_username(const char* value) {
  username_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:protobufUtils.PGRequest.RankInfo.username)
}
inline void PGRequest_RankInfo::add_username(const char* value, size_t size) {
  username_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:protobufUtils.PGRequest.RankInfo.username)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
PGRequest_RankInfo::username() const {
  // @@protoc_insertion_point(field_list:protobufUtils.PGRequest.RankInfo.username)
  return username_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
PGRequest_RankInfo::mutable_username() {
  // @@protoc_insertion_point(field_mutable_list:protobufUtils.PGRequest.RankInfo.username)
  return &username_;
}

// -------------------------------------------------------------------

// PGRequest

// required int32 Code = 1;
inline bool PGRequest::has_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PGRequest::set_has_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PGRequest::clear_has_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PGRequest::clear_code() {
  code_ = 0;
  clear_has_code();
}
inline ::google::protobuf::int32 PGRequest::code() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.Code)
  return code_;
}
inline void PGRequest::set_code(::google::protobuf::int32 value) {
  set_has_code();
  code_ = value;
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.Code)
}

// optional string errorInfo = 2;
inline bool PGRequest::has_errorinfo() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PGRequest::set_has_errorinfo() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PGRequest::clear_has_errorinfo() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PGRequest::clear_errorinfo() {
  if (errorinfo_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    errorinfo_->clear();
  }
  clear_has_errorinfo();
}
inline const ::std::string& PGRequest::errorinfo() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.errorInfo)
  return *errorinfo_;
}
inline void PGRequest::set_errorinfo(const ::std::string& value) {
  set_has_errorinfo();
  if (errorinfo_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    errorinfo_ = new ::std::string;
  }
  errorinfo_->assign(value);
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.errorInfo)
}
inline void PGRequest::set_errorinfo(const char* value) {
  set_has_errorinfo();
  if (errorinfo_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    errorinfo_ = new ::std::string;
  }
  errorinfo_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.errorInfo)
}
inline void PGRequest::set_errorinfo(const char* value, size_t size) {
  set_has_errorinfo();
  if (errorinfo_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    errorinfo_ = new ::std::string;
  }
  errorinfo_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.errorInfo)
}
inline ::std::string* PGRequest::mutable_errorinfo() {
  set_has_errorinfo();
  if (errorinfo_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    errorinfo_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.errorInfo)
  return errorinfo_;
}
inline ::std::string* PGRequest::release_errorinfo() {
  clear_has_errorinfo();
  if (errorinfo_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = errorinfo_;
    errorinfo_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void PGRequest::set_allocated_errorinfo(::std::string* errorinfo) {
  if (errorinfo_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete errorinfo_;
  }
  if (errorinfo) {
    set_has_errorinfo();
    errorinfo_ = errorinfo;
  } else {
    clear_has_errorinfo();
    errorinfo_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.errorInfo)
}

// optional string username = 3;
inline bool PGRequest::has_username() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PGRequest::set_has_username() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PGRequest::clear_has_username() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PGRequest::clear_username() {
  if (username_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    username_->clear();
  }
  clear_has_username();
}
inline const ::std::string& PGRequest::username() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.username)
  return *username_;
}
inline void PGRequest::set_username(const ::std::string& value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    username_ = new ::std::string;
  }
  username_->assign(value);
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.username)
}
inline void PGRequest::set_username(const char* value) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    username_ = new ::std::string;
  }
  username_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.username)
}
inline void PGRequest::set_username(const char* value, size_t size) {
  set_has_username();
  if (username_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    username_ = new ::std::string;
  }
  username_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.username)
}
inline ::std::string* PGRequest::mutable_username() {
  set_has_username();
  if (username_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    username_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.username)
  return username_;
}
inline ::std::string* PGRequest::release_username() {
  clear_has_username();
  if (username_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = username_;
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void PGRequest::set_allocated_username(::std::string* username) {
  if (username_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete username_;
  }
  if (username) {
    set_has_username();
    username_ = username;
  } else {
    clear_has_username();
    username_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.username)
}

// optional string password = 4;
inline bool PGRequest::has_password() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PGRequest::set_has_password() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PGRequest::clear_has_password() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PGRequest::clear_password() {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& PGRequest::password() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.password)
  return *password_;
}
inline void PGRequest::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.password)
}
inline void PGRequest::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.password)
}
inline void PGRequest::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.password)
}
inline ::std::string* PGRequest::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.password)
  return password_;
}
inline ::std::string* PGRequest::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void PGRequest::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.password)
}

// optional string score = 5;
inline bool PGRequest::has_score() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PGRequest::set_has_score() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PGRequest::clear_has_score() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PGRequest::clear_score() {
  if (score_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    score_->clear();
  }
  clear_has_score();
}
inline const ::std::string& PGRequest::score() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.score)
  return *score_;
}
inline void PGRequest::set_score(const ::std::string& value) {
  set_has_score();
  if (score_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    score_ = new ::std::string;
  }
  score_->assign(value);
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.score)
}
inline void PGRequest::set_score(const char* value) {
  set_has_score();
  if (score_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    score_ = new ::std::string;
  }
  score_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.score)
}
inline void PGRequest::set_score(const char* value, size_t size) {
  set_has_score();
  if (score_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    score_ = new ::std::string;
  }
  score_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.score)
}
inline ::std::string* PGRequest::mutable_score() {
  set_has_score();
  if (score_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    score_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.score)
  return score_;
}
inline ::std::string* PGRequest::release_score() {
  clear_has_score();
  if (score_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = score_;
    score_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void PGRequest::set_allocated_score(::std::string* score) {
  if (score_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete score_;
  }
  if (score) {
    set_has_score();
    score_ = score;
  } else {
    clear_has_score();
    score_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.score)
}

// optional string picture = 6;
inline bool PGRequest::has_picture() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PGRequest::set_has_picture() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PGRequest::clear_has_picture() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PGRequest::clear_picture() {
  if (picture_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    picture_->clear();
  }
  clear_has_picture();
}
inline const ::std::string& PGRequest::picture() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.picture)
  return *picture_;
}
inline void PGRequest::set_picture(const ::std::string& value) {
  set_has_picture();
  if (picture_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    picture_ = new ::std::string;
  }
  picture_->assign(value);
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.picture)
}
inline void PGRequest::set_picture(const char* value) {
  set_has_picture();
  if (picture_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    picture_ = new ::std::string;
  }
  picture_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.picture)
}
inline void PGRequest::set_picture(const char* value, size_t size) {
  set_has_picture();
  if (picture_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    picture_ = new ::std::string;
  }
  picture_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.picture)
}
inline ::std::string* PGRequest::mutable_picture() {
  set_has_picture();
  if (picture_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    picture_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.picture)
  return picture_;
}
inline ::std::string* PGRequest::release_picture() {
  clear_has_picture();
  if (picture_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = picture_;
    picture_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void PGRequest::set_allocated_picture(::std::string* picture) {
  if (picture_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete picture_;
  }
  if (picture) {
    set_has_picture();
    picture_ = picture;
  } else {
    clear_has_picture();
    picture_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.picture)
}

// optional .protobufUtils.PGRequest.RankInfo rankInfo = 7;
inline bool PGRequest::has_rankinfo() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PGRequest::set_has_rankinfo() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PGRequest::clear_has_rankinfo() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PGRequest::clear_rankinfo() {
  if (rankinfo_ != NULL) rankinfo_->::protobufUtils::PGRequest_RankInfo::Clear();
  clear_has_rankinfo();
}
inline const ::protobufUtils::PGRequest_RankInfo& PGRequest::rankinfo() const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.rankInfo)
  return rankinfo_ != NULL ? *rankinfo_ : *default_instance_->rankinfo_;
}
inline ::protobufUtils::PGRequest_RankInfo* PGRequest::mutable_rankinfo() {
  set_has_rankinfo();
  if (rankinfo_ == NULL) rankinfo_ = new ::protobufUtils::PGRequest_RankInfo;
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.rankInfo)
  return rankinfo_;
}
inline ::protobufUtils::PGRequest_RankInfo* PGRequest::release_rankinfo() {
  clear_has_rankinfo();
  ::protobufUtils::PGRequest_RankInfo* temp = rankinfo_;
  rankinfo_ = NULL;
  return temp;
}
inline void PGRequest::set_allocated_rankinfo(::protobufUtils::PGRequest_RankInfo* rankinfo) {
  delete rankinfo_;
  rankinfo_ = rankinfo;
  if (rankinfo) {
    set_has_rankinfo();
  } else {
    clear_has_rankinfo();
  }
  // @@protoc_insertion_point(field_set_allocated:protobufUtils.PGRequest.rankInfo)
}

// repeated string picList = 8;
inline int PGRequest::piclist_size() const {
  return piclist_.size();
}
inline void PGRequest::clear_piclist() {
  piclist_.Clear();
}
inline const ::std::string& PGRequest::piclist(int index) const {
  // @@protoc_insertion_point(field_get:protobufUtils.PGRequest.picList)
  return piclist_.Get(index);
}
inline ::std::string* PGRequest::mutable_piclist(int index) {
  // @@protoc_insertion_point(field_mutable:protobufUtils.PGRequest.picList)
  return piclist_.Mutable(index);
}
inline void PGRequest::set_piclist(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:protobufUtils.PGRequest.picList)
  piclist_.Mutable(index)->assign(value);
}
inline void PGRequest::set_piclist(int index, const char* value) {
  piclist_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:protobufUtils.PGRequest.picList)
}
inline void PGRequest::set_piclist(int index, const char* value, size_t size) {
  piclist_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobufUtils.PGRequest.picList)
}
inline ::std::string* PGRequest::add_piclist() {
  return piclist_.Add();
}
inline void PGRequest::add_piclist(const ::std::string& value) {
  piclist_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:protobufUtils.PGRequest.picList)
}
inline void PGRequest::add_piclist(const char* value) {
  piclist_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:protobufUtils.PGRequest.picList)
}
inline void PGRequest::add_piclist(const char* value, size_t size) {
  piclist_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:protobufUtils.PGRequest.picList)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
PGRequest::piclist() const {
  // @@protoc_insertion_point(field_list:protobufUtils.PGRequest.picList)
  return piclist_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
PGRequest::mutable_piclist() {
  // @@protoc_insertion_point(field_mutable_list:protobufUtils.PGRequest.picList)
  return &piclist_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protobufUtils

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_protobufUtils_2eproto__INCLUDED
