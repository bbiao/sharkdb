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

private:
    std::string table_name;
    uint64_t fragment_id;
    uint64_t replica_id;
};

}
}
