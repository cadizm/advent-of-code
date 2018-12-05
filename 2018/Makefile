GTEST_DIR = /googletest

CXX = g++
CPPFLAGS += -I$(GTEST_DIR)/googletest/include
CXXFLAGS += -g -Wall -Wextra -pthread -pipe -O2 -std=c++11

LDFLAGS += -L$(GTEST_DIR)/build/lib
LDLIBS += -lgtest -lgtest_main -lpthread -lm

SRC = $(wildcard *.cc)
OBJ = $(addsuffix .o, $(basename $(SRC)))
TARGETS = $(basename $(SRC))

all: $(TARGETS)

%.o: %.cc

clean:
	@rm -f $(TARGETS) $(OBJ)

lint:
	@cpplint.py $(wildcard *.h) $(SRC)

.PHONY: all clean lint
