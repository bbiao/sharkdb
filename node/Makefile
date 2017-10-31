ifndef BRPC_DIR
	BRPC_DIR = ../brpc
endif
include $(BRPC_DIR)/config.mk

ifndef GFLAGS_DIR
	GFLAGS_DIR = ../gflags
endif

ifndef ROCKSDB_DIR
	ROCKSDB_DIR = ../rocksdb
endif

ifndef GTEST_DIR
	GTEST_DIR = ../googletest
endif

CC = gcc
CXX = g++
CFLAGS = -W -Wall -ggdb -fPIC
CXXFLAGS += $(CPPFLAGS) -std=c++0x -DNDEBUG -O2 -D__const__= -pipe -ggdb -W -Wall -Wno-unused-parameter -fPIC -fno-omit-frame-pointer
INCPATH = -I./include -I$(GFLAGS_DIR)/include -I$(ROCKSDB_DIR)/include -I$(BRPC_DIR)/output/include
LIBPATH = -L/usr/lib/x86_64-linux-gnu -L./ -L$(GFLAGS_DIR)/lib -L$(ROCKSDB_DIR) -L$(BRPC_DIR)/output/lib
LDFLAGS = -lgflags -lrocksdb -lbrpc
SOURCES = src/node.cc src/replica.cc
OBJECTS = $(SOURCES:.cc=.o)
#OBJECTS = $(patsubst %.cc,bm_%.o,$(SOURCES))

TEST_INCPATH = $(INCPATH) -I$(GTEST_DIR)/googletest/include  
TEST_LIBPATH = $(LIBPATH) -L$(GTEST_DIR)/googlemock/gtest 
TEST_LDFLAGS = $(LDFLAGS) -lgtest

LIB = libnode.a

BINARY = node

all : $(LIB) $(BINARY)

src/main.o : src/main.cc
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

$(BINARY) : src/main.o $(OBJECTS)
	$(CXX) $(LIBPATH) -Xlinker "-(" $^ -Wl,-Bstatic $(STATIC_LINKINGS) $(LDFLAGS) -Wl,-Bdynamic -Xlinker "-)" $(DYNAMIC_LINKINGS) -o $@

#$(CXX) $(CXXFLAGS) $(INCPATH) $(LIBPATH) $< $(LDFLAGS) -lnode -o $@

$(LIB) : $(OBJECTS)
	ar -cr $@ $^

.cc.o :
	$(CXX) $(CXXFLAGS) $(INCPATH) -c $< -o $@

clean : clean_test
	rm -rf $(LIB) $(OBJECTS) $(BINARY)

test : node_test
	@./schema_test

clean_test :
	rm -rf node_test

node_test : test/node_test.cc $(LIB)
	$(CXX) $(CXXFLAGS) $(INCPATH) $(LIBPATH) $< $(LDFLAGS) -o $@

.PHONY : all clean test
