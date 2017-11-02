include base.mk

INCPATH += -I. -I./include

SOURCES = $(wildcard src/*.cc)
OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))

LIB = libcommon.a
TEST_BINARY = common_test

all : $(LIB) $(TEST_BINARY)

clean : test_clean
	rm -f $(LIB) $(OBJECTS)

%.o: %.cc
	$(CXX) $(INCPATH) -c $< -o $@

$(LIB) : $(OBJECTS)
	ar cr $@ $^

TEST_INCPATH = $(INCPATH) -I$(GTEST_PATH)/googletest/include
TEST_LIBPATH = $(LIBPATH) -L$(GTEST_PATH)/googlemock/gtest
TEST_LDFLAGS = $(LDFLAGS) -lgtest
TEST_SOURCES = $(wildcard test/*.cc)
TEST_OBJECTS = $(patsubst %.cc, %.o, $(TEST_SOURCES))

test/%.o : test/%.cc 
	$(CXX) $(TEST_INCPATH) -c $< -o $@

$(TEST_BINARY) : $(TEST_OBJECTS)
	$(CXX) $(TEST_LIBPATH) -Xlinker "-(" $^ -Wl,-Bstatic $(TEST_LDFLAGS) -Wl,-Bdynamic -Xlinker "-)" $(SYS_LDFLAGS) -o $@

test_clean :
	rm -f $(TEST_BINARY) $(TEST_OBJECTS)

.PHONY: all clean test_clean
