#ifndef SHARKDB_NODE_REPLICA_H
#define SHARKDB_NODE_REPLICA_H
#include "common.h"
#include "storage_engine.h"

SHARKDB_NODE_NS_BEGIN

struct ReplicaOptions {

};

class Replica {
 public:
  Replica();
  virtual ~Replica();

  static Replica* Create(const ReplicaOptions&);

  const std::string& table_name() {
    return table_name_;
  }

  uint64_t fragment_id() const {
    return fragment_id_;
  }

  uint64_t replica_id() const {
    return replica_id_;
  }

  const std::string& path() {
    return path_;
  }

  void Open();

  void Destroy();

 private:
  std::string table_name_;
  uint64_t fragment_id_;
  uint64_t replica_id_;
  std::string path_;

  StorageEngine* engine_;
};

SHARKDB_NODE_NS_END
#endif//SHARKDB_NODE_REPLICA_H
