#ifndef SHARKDB_NODE_ROCKSDB_ENGINE_H
#define SHARKDB_NODE_ROCKSDB_ENGINE_H
#include <rocksdb/db.h>
#include "common.h"
#include "storage_engine.h"

SHARKDB_NODE_NS_BEGIN

class RocksDBEngine : public StorageEngine {
 public:
  static RocksDBEngine* Open(const std::string& path);
  virtual ~RocksDBEngine();

  virtual std::string Get(const std::string& key);
  virtual bool Put(const std::string& key, const std::string& value);
  virtual bool Delete(const std::string& key);

 private:
  RocksDBEngine();
  rocksdb::DB* db_;
};

SHARKDB_NODE_NS_END

#endif//SHARKDB_NODE_ROCKSDB_ENGINE_H



