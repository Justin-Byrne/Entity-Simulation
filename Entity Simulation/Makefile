# VARIABLES
## Binary
BIN := Entity-Simulation

## Compiler
CXX := g++
CXX_FLAGS := -std=c++11

SRC_DIRS := ./include

SRCS := $(shell find $(SRC_DIRS) -name '*.hpp')

OBJS := $(patsubst %.hpp, %.o, $(SRCS))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# CONDITIONALS
ifeq ($(OS),Windows_NT)
	CLEAN := del $(OBJS) *.o && del $(BIN)
	LD_FLAG := -LC:/SFML/lib
	LIBS := -lsfml-graphics-s -lsfml-system-s -lsfml-window-s
else
	CLEAN := rm -f $(OBJS) *.o && rm -f $(BIN)
	LD_FLAG := -L/usr/local/Cellar/sfml/2.5.1_1/lib		
	LIBS := -lsfml-graphics.2.5.1 -lsfml-system.2.5.1 -lsfml-window.2.5.1
endif

# COMMANDS
## All
all: $(BIN)

## Binary
$(BIN): $(OBJS) main.cpp
	touch $@
	$(CXX) $(LD_FLAG) $(CXX_FLAGS) main.cpp $(OBJS) -o $@ $(LIBS) -march=native -v

## Objects
%.o: %.hpp
	$(CXX) -c $(CXX_FLAGS) $< -o $@

## Clean
clean:
	$(CLEAN)