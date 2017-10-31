#include <cstdint>
#include <string>

namespace sharkdb {
namespace node {

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

    void Destroy();

private:
    std::string table_name;
    uint64_t fragment_id;
    uint64_t replica_id;
    std::string path;
};

}
}
