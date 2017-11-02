#include "replica.h"

SHARKDB_NODE_NS_BEGIN

Replica::Replica() : table_name_(), fragment_id_(UINT64_MAX), replica_id_(UINT64_MAX) {

}

Replica* Replica::Create(const ReplicaOptions& replica_options) {
  Replica* replica = new Replica;
  return replica;
}

Replica::~Replica() {

}

void Replica::Open() {
  // check if exists

  // create on disk or load

  /// load from disk
}

void Replica::Destroy() {
  //TODO

  delete this;
}

SHARKDB_NODE_NS_END
