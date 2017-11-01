BRPC_PATH = ../brpc
include $(BRPC_PATH)/config.mk

CC = gcc
CXX = g++
CFLAGS = -W -Wall -ggdb -fPIC
CXXFLAGS += $(CPPFLAGS) -std=c++0x -DNDEBUG -O2 -D__const__= -pipe -ggdb -W -Wall -Wno-unused-parameter -fPIC -fno-omit-frame-pointer

INCPATH = -I$(HDRS)
LIBPATH = $(LIBS)

LDFLAGS = $(STATIC_LINKINGS)
SYS_LDFLAGS = $(DYNAMIC_LINKINGS)
