#ifndef SHARKDB_NODE_REPLICA_MAN_H
#define SHARKDB_NODE_REPLICA_MAN_H

#include "common.h"
#include <map>
#include "replica.h"

SHARKDB_NODE_NS_BEGIN

class ReplicaMan {

private:
    std::map<uint64_t, Replica*> fragmentIdMap;
    std::map<uint64_t, Replica*> replicaIdMap;

};

SHARKDB_NODE_NS_END

#endif//SHARKDB_NODE_REPLICA_MAN_H
