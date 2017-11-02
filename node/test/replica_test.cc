#include <gtest/gtest.h>
#include "replica.h"

namespace sharkdb {
namespace node {
namespace test {

class ReplicaTest : public testing::Test {

};

TEST_F(ReplicaTest, StaticCreate) {
    ReplicaOptions replica_options;
    Replica* replica = Replica::Create(replica_options);
    ASSERT_TRUE(replica != NULL);
    replica->Destroy();
}

}
}
}
