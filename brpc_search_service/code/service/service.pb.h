// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: service.proto

#ifndef PROTOBUF_service_2eproto__INCLUDED
#define PROTOBUF_service_2eproto__INCLUDED

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
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace NLP {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_service_2eproto();
void protobuf_AssignDesc_service_2eproto();
void protobuf_ShutdownFile_service_2eproto();

class SearchRequest;
class SearchResItem;
class SearchResponse;
class SearchHotRequest;
class SearchHotResponse;

// ===================================================================

class SearchRequest : public ::google::protobuf::Message {
 public:
  SearchRequest();
  virtual ~SearchRequest();

  SearchRequest(const SearchRequest& from);

  inline SearchRequest& operator=(const SearchRequest& from) {
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
  static const SearchRequest& default_instance();

  void Swap(SearchRequest* other);

  // implements Message ----------------------------------------------

  SearchRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchRequest& from);
  void MergeFrom(const SearchRequest& from);
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

  // required string query = 1;
  inline bool has_query() const;
  inline void clear_query();
  static const int kQueryFieldNumber = 1;
  inline const ::std::string& query() const;
  inline void set_query(const ::std::string& value);
  inline void set_query(const char* value);
  inline void set_query(const char* value, size_t size);
  inline ::std::string* mutable_query();
  inline ::std::string* release_query();
  inline void set_allocated_query(::std::string* query);

  // @@protoc_insertion_point(class_scope:NLP.SearchRequest)
 private:
  inline void set_has_query();
  inline void clear_has_query();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* query_;
  friend void  protobuf_AddDesc_service_2eproto();
  friend void protobuf_AssignDesc_service_2eproto();
  friend void protobuf_ShutdownFile_service_2eproto();

  void InitAsDefaultInstance();
  static SearchRequest* default_instance_;
};
// -------------------------------------------------------------------

class SearchResItem : public ::google::protobuf::Message {
 public:
  SearchResItem();
  virtual ~SearchResItem();

  SearchResItem(const SearchResItem& from);

  inline SearchResItem& operator=(const SearchResItem& from) {
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
  static const SearchResItem& default_instance();

  void Swap(SearchResItem* other);

  // implements Message ----------------------------------------------

  SearchResItem* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchResItem& from);
  void MergeFrom(const SearchResItem& from);
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

  // required int32 DocId = 1;
  inline bool has_docid() const;
  inline void clear_docid();
  static const int kDocIdFieldNumber = 1;
  inline ::google::protobuf::int32 docid() const;
  inline void set_docid(::google::protobuf::int32 value);

  // required float score = 2;
  inline bool has_score() const;
  inline void clear_score();
  static const int kScoreFieldNumber = 2;
  inline float score() const;
  inline void set_score(float value);

  // required string title = 3;
  inline bool has_title() const;
  inline void clear_title();
  static const int kTitleFieldNumber = 3;
  inline const ::std::string& title() const;
  inline void set_title(const ::std::string& value);
  inline void set_title(const char* value);
  inline void set_title(const char* value, size_t size);
  inline ::std::string* mutable_title();
  inline ::std::string* release_title();
  inline void set_allocated_title(::std::string* title);

  // required string content = 4;
  inline bool has_content() const;
  inline void clear_content();
  static const int kContentFieldNumber = 4;
  inline const ::std::string& content() const;
  inline void set_content(const ::std::string& value);
  inline void set_content(const char* value);
  inline void set_content(const char* value, size_t size);
  inline ::std::string* mutable_content();
  inline ::std::string* release_content();
  inline void set_allocated_content(::std::string* content);

  // required string url = 5;
  inline bool has_url() const;
  inline void clear_url();
  static const int kUrlFieldNumber = 5;
  inline const ::std::string& url() const;
  inline void set_url(const ::std::string& value);
  inline void set_url(const char* value);
  inline void set_url(const char* value, size_t size);
  inline ::std::string* mutable_url();
  inline ::std::string* release_url();
  inline void set_allocated_url(::std::string* url);

  // @@protoc_insertion_point(class_scope:NLP.SearchResItem)
 private:
  inline void set_has_docid();
  inline void clear_has_docid();
  inline void set_has_score();
  inline void clear_has_score();
  inline void set_has_title();
  inline void clear_has_title();
  inline void set_has_content();
  inline void clear_has_content();
  inline void set_has_url();
  inline void clear_has_url();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 docid_;
  float score_;
  ::std::string* title_;
  ::std::string* content_;
  ::std::string* url_;
  friend void  protobuf_AddDesc_service_2eproto();
  friend void protobuf_AssignDesc_service_2eproto();
  friend void protobuf_ShutdownFile_service_2eproto();

  void InitAsDefaultInstance();
  static SearchResItem* default_instance_;
};
// -------------------------------------------------------------------

class SearchResponse : public ::google::protobuf::Message {
 public:
  SearchResponse();
  virtual ~SearchResponse();

  SearchResponse(const SearchResponse& from);

  inline SearchResponse& operator=(const SearchResponse& from) {
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
  static const SearchResponse& default_instance();

  void Swap(SearchResponse* other);

  // implements Message ----------------------------------------------

  SearchResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchResponse& from);
  void MergeFrom(const SearchResponse& from);
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

  // repeated .NLP.SearchResItem result = 1;
  inline int result_size() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline const ::NLP::SearchResItem& result(int index) const;
  inline ::NLP::SearchResItem* mutable_result(int index);
  inline ::NLP::SearchResItem* add_result();
  inline const ::google::protobuf::RepeatedPtrField< ::NLP::SearchResItem >&
      result() const;
  inline ::google::protobuf::RepeatedPtrField< ::NLP::SearchResItem >*
      mutable_result();

  // @@protoc_insertion_point(class_scope:NLP.SearchResponse)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::NLP::SearchResItem > result_;
  friend void  protobuf_AddDesc_service_2eproto();
  friend void protobuf_AssignDesc_service_2eproto();
  friend void protobuf_ShutdownFile_service_2eproto();

  void InitAsDefaultInstance();
  static SearchResponse* default_instance_;
};
// -------------------------------------------------------------------

class SearchHotRequest : public ::google::protobuf::Message {
 public:
  SearchHotRequest();
  virtual ~SearchHotRequest();

  SearchHotRequest(const SearchHotRequest& from);

  inline SearchHotRequest& operator=(const SearchHotRequest& from) {
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
  static const SearchHotRequest& default_instance();

  void Swap(SearchHotRequest* other);

  // implements Message ----------------------------------------------

  SearchHotRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchHotRequest& from);
  void MergeFrom(const SearchHotRequest& from);
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

  // @@protoc_insertion_point(class_scope:NLP.SearchHotRequest)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_service_2eproto();
  friend void protobuf_AssignDesc_service_2eproto();
  friend void protobuf_ShutdownFile_service_2eproto();

  void InitAsDefaultInstance();
  static SearchHotRequest* default_instance_;
};
// -------------------------------------------------------------------

class SearchHotResponse : public ::google::protobuf::Message {
 public:
  SearchHotResponse();
  virtual ~SearchHotResponse();

  SearchHotResponse(const SearchHotResponse& from);

  inline SearchHotResponse& operator=(const SearchHotResponse& from) {
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
  static const SearchHotResponse& default_instance();

  void Swap(SearchHotResponse* other);

  // implements Message ----------------------------------------------

  SearchHotResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchHotResponse& from);
  void MergeFrom(const SearchHotResponse& from);
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

  // repeated string result = 1;
  inline int result_size() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline const ::std::string& result(int index) const;
  inline ::std::string* mutable_result(int index);
  inline void set_result(int index, const ::std::string& value);
  inline void set_result(int index, const char* value);
  inline void set_result(int index, const char* value, size_t size);
  inline ::std::string* add_result();
  inline void add_result(const ::std::string& value);
  inline void add_result(const char* value);
  inline void add_result(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& result() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_result();

  // @@protoc_insertion_point(class_scope:NLP.SearchHotResponse)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> result_;
  friend void  protobuf_AddDesc_service_2eproto();
  friend void protobuf_AssignDesc_service_2eproto();
  friend void protobuf_ShutdownFile_service_2eproto();

  void InitAsDefaultInstance();
  static SearchHotResponse* default_instance_;
};
// ===================================================================

class SearchService_Stub;

class SearchService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline SearchService() {};
 public:
  virtual ~SearchService();

  typedef SearchService_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void query(::google::protobuf::RpcController* controller,
                       const ::NLP::SearchRequest* request,
                       ::NLP::SearchResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void hot(::google::protobuf::RpcController* controller,
                       const ::NLP::SearchHotRequest* request,
                       ::NLP::SearchHotResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SearchService);
};

class SearchService_Stub : public SearchService {
 public:
  SearchService_Stub(::google::protobuf::RpcChannel* channel);
  SearchService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~SearchService_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements SearchService ------------------------------------------

  void query(::google::protobuf::RpcController* controller,
                       const ::NLP::SearchRequest* request,
                       ::NLP::SearchResponse* response,
                       ::google::protobuf::Closure* done);
  void hot(::google::protobuf::RpcController* controller,
                       const ::NLP::SearchHotRequest* request,
                       ::NLP::SearchHotResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SearchService_Stub);
};


// ===================================================================


// ===================================================================

// SearchRequest

// required string query = 1;
inline bool SearchRequest::has_query() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SearchRequest::set_has_query() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SearchRequest::clear_has_query() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SearchRequest::clear_query() {
  if (query_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    query_->clear();
  }
  clear_has_query();
}
inline const ::std::string& SearchRequest::query() const {
  // @@protoc_insertion_point(field_get:NLP.SearchRequest.query)
  return *query_;
}
inline void SearchRequest::set_query(const ::std::string& value) {
  set_has_query();
  if (query_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    query_ = new ::std::string;
  }
  query_->assign(value);
  // @@protoc_insertion_point(field_set:NLP.SearchRequest.query)
}
inline void SearchRequest::set_query(const char* value) {
  set_has_query();
  if (query_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    query_ = new ::std::string;
  }
  query_->assign(value);
  // @@protoc_insertion_point(field_set_char:NLP.SearchRequest.query)
}
inline void SearchRequest::set_query(const char* value, size_t size) {
  set_has_query();
  if (query_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    query_ = new ::std::string;
  }
  query_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NLP.SearchRequest.query)
}
inline ::std::string* SearchRequest::mutable_query() {
  set_has_query();
  if (query_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    query_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:NLP.SearchRequest.query)
  return query_;
}
inline ::std::string* SearchRequest::release_query() {
  clear_has_query();
  if (query_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = query_;
    query_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SearchRequest::set_allocated_query(::std::string* query) {
  if (query_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete query_;
  }
  if (query) {
    set_has_query();
    query_ = query;
  } else {
    clear_has_query();
    query_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:NLP.SearchRequest.query)
}

// -------------------------------------------------------------------

// SearchResItem

// required int32 DocId = 1;
inline bool SearchResItem::has_docid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SearchResItem::set_has_docid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SearchResItem::clear_has_docid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SearchResItem::clear_docid() {
  docid_ = 0;
  clear_has_docid();
}
inline ::google::protobuf::int32 SearchResItem::docid() const {
  // @@protoc_insertion_point(field_get:NLP.SearchResItem.DocId)
  return docid_;
}
inline void SearchResItem::set_docid(::google::protobuf::int32 value) {
  set_has_docid();
  docid_ = value;
  // @@protoc_insertion_point(field_set:NLP.SearchResItem.DocId)
}

// required float score = 2;
inline bool SearchResItem::has_score() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SearchResItem::set_has_score() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SearchResItem::clear_has_score() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SearchResItem::clear_score() {
  score_ = 0;
  clear_has_score();
}
inline float SearchResItem::score() const {
  // @@protoc_insertion_point(field_get:NLP.SearchResItem.score)
  return score_;
}
inline void SearchResItem::set_score(float value) {
  set_has_score();
  score_ = value;
  // @@protoc_insertion_point(field_set:NLP.SearchResItem.score)
}

// required string title = 3;
inline bool SearchResItem::has_title() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SearchResItem::set_has_title() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SearchResItem::clear_has_title() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SearchResItem::clear_title() {
  if (title_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    title_->clear();
  }
  clear_has_title();
}
inline const ::std::string& SearchResItem::title() const {
  // @@protoc_insertion_point(field_get:NLP.SearchResItem.title)
  return *title_;
}
inline void SearchResItem::set_title(const ::std::string& value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    title_ = new ::std::string;
  }
  title_->assign(value);
  // @@protoc_insertion_point(field_set:NLP.SearchResItem.title)
}
inline void SearchResItem::set_title(const char* value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    title_ = new ::std::string;
  }
  title_->assign(value);
  // @@protoc_insertion_point(field_set_char:NLP.SearchResItem.title)
}
inline void SearchResItem::set_title(const char* value, size_t size) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    title_ = new ::std::string;
  }
  title_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NLP.SearchResItem.title)
}
inline ::std::string* SearchResItem::mutable_title() {
  set_has_title();
  if (title_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    title_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:NLP.SearchResItem.title)
  return title_;
}
inline ::std::string* SearchResItem::release_title() {
  clear_has_title();
  if (title_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = title_;
    title_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SearchResItem::set_allocated_title(::std::string* title) {
  if (title_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete title_;
  }
  if (title) {
    set_has_title();
    title_ = title;
  } else {
    clear_has_title();
    title_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:NLP.SearchResItem.title)
}

// required string content = 4;
inline bool SearchResItem::has_content() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SearchResItem::set_has_content() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SearchResItem::clear_has_content() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SearchResItem::clear_content() {
  if (content_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    content_->clear();
  }
  clear_has_content();
}
inline const ::std::string& SearchResItem::content() const {
  // @@protoc_insertion_point(field_get:NLP.SearchResItem.content)
  return *content_;
}
inline void SearchResItem::set_content(const ::std::string& value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    content_ = new ::std::string;
  }
  content_->assign(value);
  // @@protoc_insertion_point(field_set:NLP.SearchResItem.content)
}
inline void SearchResItem::set_content(const char* value) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    content_ = new ::std::string;
  }
  content_->assign(value);
  // @@protoc_insertion_point(field_set_char:NLP.SearchResItem.content)
}
inline void SearchResItem::set_content(const char* value, size_t size) {
  set_has_content();
  if (content_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    content_ = new ::std::string;
  }
  content_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NLP.SearchResItem.content)
}
inline ::std::string* SearchResItem::mutable_content() {
  set_has_content();
  if (content_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    content_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:NLP.SearchResItem.content)
  return content_;
}
inline ::std::string* SearchResItem::release_content() {
  clear_has_content();
  if (content_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = content_;
    content_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SearchResItem::set_allocated_content(::std::string* content) {
  if (content_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete content_;
  }
  if (content) {
    set_has_content();
    content_ = content;
  } else {
    clear_has_content();
    content_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:NLP.SearchResItem.content)
}

// required string url = 5;
inline bool SearchResItem::has_url() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SearchResItem::set_has_url() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SearchResItem::clear_has_url() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SearchResItem::clear_url() {
  if (url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    url_->clear();
  }
  clear_has_url();
}
inline const ::std::string& SearchResItem::url() const {
  // @@protoc_insertion_point(field_get:NLP.SearchResItem.url)
  return *url_;
}
inline void SearchResItem::set_url(const ::std::string& value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    url_ = new ::std::string;
  }
  url_->assign(value);
  // @@protoc_insertion_point(field_set:NLP.SearchResItem.url)
}
inline void SearchResItem::set_url(const char* value) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    url_ = new ::std::string;
  }
  url_->assign(value);
  // @@protoc_insertion_point(field_set_char:NLP.SearchResItem.url)
}
inline void SearchResItem::set_url(const char* value, size_t size) {
  set_has_url();
  if (url_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    url_ = new ::std::string;
  }
  url_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NLP.SearchResItem.url)
}
inline ::std::string* SearchResItem::mutable_url() {
  set_has_url();
  if (url_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    url_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:NLP.SearchResItem.url)
  return url_;
}
inline ::std::string* SearchResItem::release_url() {
  clear_has_url();
  if (url_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = url_;
    url_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SearchResItem::set_allocated_url(::std::string* url) {
  if (url_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete url_;
  }
  if (url) {
    set_has_url();
    url_ = url;
  } else {
    clear_has_url();
    url_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:NLP.SearchResItem.url)
}

// -------------------------------------------------------------------

// SearchResponse

// repeated .NLP.SearchResItem result = 1;
inline int SearchResponse::result_size() const {
  return result_.size();
}
inline void SearchResponse::clear_result() {
  result_.Clear();
}
inline const ::NLP::SearchResItem& SearchResponse::result(int index) const {
  // @@protoc_insertion_point(field_get:NLP.SearchResponse.result)
  return result_.Get(index);
}
inline ::NLP::SearchResItem* SearchResponse::mutable_result(int index) {
  // @@protoc_insertion_point(field_mutable:NLP.SearchResponse.result)
  return result_.Mutable(index);
}
inline ::NLP::SearchResItem* SearchResponse::add_result() {
  // @@protoc_insertion_point(field_add:NLP.SearchResponse.result)
  return result_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::NLP::SearchResItem >&
SearchResponse::result() const {
  // @@protoc_insertion_point(field_list:NLP.SearchResponse.result)
  return result_;
}
inline ::google::protobuf::RepeatedPtrField< ::NLP::SearchResItem >*
SearchResponse::mutable_result() {
  // @@protoc_insertion_point(field_mutable_list:NLP.SearchResponse.result)
  return &result_;
}

// -------------------------------------------------------------------

// SearchHotRequest

// -------------------------------------------------------------------

// SearchHotResponse

// repeated string result = 1;
inline int SearchHotResponse::result_size() const {
  return result_.size();
}
inline void SearchHotResponse::clear_result() {
  result_.Clear();
}
inline const ::std::string& SearchHotResponse::result(int index) const {
  // @@protoc_insertion_point(field_get:NLP.SearchHotResponse.result)
  return result_.Get(index);
}
inline ::std::string* SearchHotResponse::mutable_result(int index) {
  // @@protoc_insertion_point(field_mutable:NLP.SearchHotResponse.result)
  return result_.Mutable(index);
}
inline void SearchHotResponse::set_result(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:NLP.SearchHotResponse.result)
  result_.Mutable(index)->assign(value);
}
inline void SearchHotResponse::set_result(int index, const char* value) {
  result_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:NLP.SearchHotResponse.result)
}
inline void SearchHotResponse::set_result(int index, const char* value, size_t size) {
  result_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:NLP.SearchHotResponse.result)
}
inline ::std::string* SearchHotResponse::add_result() {
  return result_.Add();
}
inline void SearchHotResponse::add_result(const ::std::string& value) {
  result_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:NLP.SearchHotResponse.result)
}
inline void SearchHotResponse::add_result(const char* value) {
  result_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:NLP.SearchHotResponse.result)
}
inline void SearchHotResponse::add_result(const char* value, size_t size) {
  result_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:NLP.SearchHotResponse.result)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
SearchHotResponse::result() const {
  // @@protoc_insertion_point(field_list:NLP.SearchHotResponse.result)
  return result_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
SearchHotResponse::mutable_result() {
  // @@protoc_insertion_point(field_mutable_list:NLP.SearchHotResponse.result)
  return &result_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace NLP

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_service_2eproto__INCLUDED
