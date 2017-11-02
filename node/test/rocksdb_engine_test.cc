/**
 * @file rocksdb_engine_test.cc
 * @brief RocksDBEngine Test
 * @author Zhang Biao(zhangbiaozb@didichuxing.com)
 * @version 0.0.1
 * @date 2017-11-02
 */

#include <gtest/gtest.h>
#include "common.h"
#include "rocksdb_engine.h"

SHARKDB_NODE_NS_BEGIN

namespace {

const std::string kDBPath = "./test_db";

class RocksDBEngineTest : public ::testing::Test {
 public:
  virtual void SetUp() {

  }

  virtual void TearDown() {

  }
};

TEST_F(RocksDBEngineTest, OpenDB) {
  RocksDBEngine* engine = RocksDBEngine::Open("./test_db");
  ASSERT_TRUE(engine != NULL);
}

}

SHARKDB_NODE_NS_END
