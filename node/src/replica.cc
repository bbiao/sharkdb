#include "replica.h"

namespace sharkdb {
namespace node {

Replica::Replica() : table_name(), fragment_id(UINT64_MAX), replica_id(UINT64_MAX) {

}

Replica* Replica::Create(const ReplicaOptions& replica_options) {
    Replica* replica = new Replica;
    return replica;
}

Replica::~Replica() {

}

void Replica::Destroy() {
    //TODO
    
    delete this;
}

}
}
