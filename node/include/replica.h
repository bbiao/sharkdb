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

    const std::string& GetTableName() {
        return table_name;
    }

    uint64_t GetFragmentId() const {
        return fragment_id;
    }

    uint64_t GetReplicaId() const {
        return replica_id;
    }

    const std::string& GetPath() {
        return path;
    }

    void Open();

    void Destroy();

private:
    std::string table_name;
    uint64_t fragment_id;
    uint64_t replica_id;
    std::string path;

    StorageEngine* engine;
};

SHARKDB_NODE_NS_END
#endif//SHARKDB_NODE_REPLICA_H
