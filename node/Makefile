# define gtest
ifndef GTEST_DIR
	GTEST_DIR = ../googletest
endif

ifndef ROCKSDB_DIR
	ROCKSDB_DIR = ../rocksdb
endif

ifndef BRPC_DIR
	BRPC_DIR = ../brpc
endif

CC = gcc
CXX = g++
CFLAGS = -W -Wall -ggdb -fPIC
CXXFLAGS = -W -Wall -ggdb -fPIC
INCPATH = -I./include -I$(ROCKSDB_DIR)/include
LIBPATH = -L./ -L$(ROCKSDB_DIR)
LDFLAGS = -lrocksdb -lpthread
SOURCES = src/node.cc
OBJECTS = $(SOURCES:.cc=.o)
#OBJECTS = $(patsubst %.cc,bm_%.o,$(SOURCES))

TEST_INCPATH = $(INCPATH) -I$(GTEST_DIR)/googletest/include  
TEST_LIBPATH = $(LIBPATH) -L$(GTEST_DIR)/googlemock/gtest 
TEST_LDFLAGS = $(LDFLAGS) -lgtest

LIB = libnode.a

BINARY = node

all : $(LIB) $(BINARY)

$(BINARY) : src/main.cc $(LIB)
	$(CXX) $(CXXFLAGS) $(INCPATH) $(LIBPATH) $< $(LDFLAGS) -o $@

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
