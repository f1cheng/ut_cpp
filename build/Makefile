# Where to find user code.
USER_DIR = ..

CPPFLAGS += -isystem $(USER_DIR)/src

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -DNO__UT__

TESTS = server_test

#.PHONY : all
all : $(TESTS)

clean :
	rm -f $(TESTS) gmock.a gmock_main.a *.o *.gcno *.gcda
	rm -rf $(USER_DIR)/src/*.o
	rm -rf $(USER_DIR)/src/*.gc*

# Builds a sample test.
SRCS := $(wildcard $(USER_DIR)/src/*.cpp)
#TST_SRCS := $(wildcard $(USER_DIR)/src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

.cpp:.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c 

$(TESTS) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


