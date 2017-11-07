ifndef BRPC_PATH
BRPC_PATH = ../brpc
endif

ifndef GTEST_PATH
GTEST_PATH = ../googletest
endif

ifndef GFLAGS_PATH
GFLAGS_PATH = ../gflags
endif

ifndef ROCKSDB_PATH
ROCKSDB_PATH = ../rocksdb
endif

include $(BRPC_PATH)/config.mk

CC = gcc
CXX = g++
CFLAGS = -W -Wall -ggdb -fPIC
CXXFLAGS += $(CPPFLAGS) -std=c++0x -DNDEBUG -O2 -D__const__= -pipe -ggdb -W -Wall -Wno-unused-parameter -fPIC -fno-omit-frame-pointer

INCPATH = $(addprefix -I, $(HDRS))
LIBPATH = $(addprefix -L, $(LIBS))

LDFLAGS = $(STATIC_LINKINGS)
SYS_LDFLAGS = $(DYNAMIC_LINKINGS)
