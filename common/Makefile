include ../base.mk

INCPATH += -I. -I./include

SOURCES = $(wildcard src/*.cc)
OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))

LIB = libcommon.a

all : $(LIB)

$(LIB) : $(OBJECTS)
	ar cr $@ $^

.cc.o:
	$(CXX) $(INCPATH) -c $< -o $@


