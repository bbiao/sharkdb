#ifndef SHARKDB_NODE_STORAGE_ENGINE_H
#define SHARKDB_NODE_STORAGE_ENGINE_H

#include "common.h"

SHARKDB_NODE_NS_BEGIN

class StorageEngine {
 public:
  virtual std::string Get(const std::string& key) = 0;
  virtual bool Put(const std::string& key, const std::string& value) = 0;
  virtual bool Delete(const std::string& key) = 0;
};

SHARKDB_NODE_NS_END

#endif//SHARKDB_NODE_STORAGE_ENGINE_H
