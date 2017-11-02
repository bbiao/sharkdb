#include "rocksdb_engine.h"

SHARKDB_NODE_NS_BEGIN

RocksDBEngine::RocksDBEngine() : db_(NULL) {

}

RocksDBEngine* RocksDBEngine::Open(const std::string& path) {
  RocksDBEngine* db_engine = new RocksDBEngine;
  rocksdb::Options options;
  options.create_if_missing = true;
  rocksdb::DB::Open(options, path, &db_engine->db_);

  return db_engine;
}

RocksDBEngine::~RocksDBEngine() {

}
  
std::string RocksDBEngine::Get(const std::string& key) {
  std::string value;
  rocksdb::ReadOptions read_options;
  this->db_->Get(read_options, key, &value);
  return value;
}

bool RocksDBEngine::Put(const std::string& key, const std::string& value) {
  rocksdb::WriteOptions write_options;
  this->db_->Put(write_options, key, value);
  return true;
}


bool RocksDBEngine::Delete(const std::string& key) {
  return true;
}

SHARKDB_NODE_NS_END
