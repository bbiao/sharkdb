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
  return "";
}

bool RocksDBEngine::Put(const std::string& key, const std::string& value) {
  return true;
}


bool RocksDBEngine::Delete(const std::string& key) {
  return true;
}

SHARKDB_NODE_NS_END
