include ../common/base.mk

INCPATH += -I. -I./include -I$(GFLAGS_PATH)/include -I$(ROCKSDB_PATH)/include -I$(BRPC_PATH)/output/include
LIBPATH += -L. -L$(GFLAGS_PATH)/lib -L$(ROCKSDB_PATH) -L$(BRPC_PATH)/output/lib
LDFLAGS += -lnode -lrocksdb -lbrpc

SOURCES = $(wildcard src/*.cc)
SOURCES := $(filter-out src/main.cc, $(SOURCES))
OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))

LIB = libnode.a
BINARY = node
TEST_BINARY = node_test

all : $(LIB) $(BINARY) $(TEST_BINARY)

clean : test_clean
	rm -f $(BINARY) $(LIB) $(OBJECTS) src/main.o

src/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

$(LIB) : $(OBJECTS)
	ar cr $@ $^

$(BINARY) : src/main.o $(LIB)
	$(CXX) $(LIBPATH) -Xlinker "-(" $< -Wl,-Bstatic $(LDFLAGS) -Wl,-Bdynamic -Xlinker "-)" $(DYNAMIC_LINKINGS) -o $@

TEST_INCPATH = $(INCPATH) -I$(GTEST_PATH)/googletest/include
TEST_LIBPATH = $(LIBPATH) -L$(GTEST_PATH)/googlemock/gtest
TEST_LDFLAGS = $(LDFLAGS) -lgtest
TEST_SOURCES = $(wildcard test/*.cc)
TEST_OBJECTS = $(patsubst %.cc, %.o, $(TEST_SOURCES))

test/%.o : test/%.cc 
	$(CXX) $(CXXFLAGS) $(TEST_INCPATH) -c $< -o $@

$(TEST_BINARY) : $(TEST_OBJECTS)
	$(CXX) $(TEST_LIBPATH) -Xlinker "-(" $^ -Wl,-Bstatic $(TEST_LDFLAGS) -Wl,-Bdynamic -Xlinker "-)" $(SYS_LDFLAGS) -o $@

test_clean :
	rm -f $(TEST_BINARY) $(TEST_OBJECTS)

#$< first
#$^ all
#$@ target
#$? file changed

.PHONY : all clean test
