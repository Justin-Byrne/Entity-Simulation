# VARIABLES
## Binary
BIN := Entity-Simulation

## Compiler
CXX := g++
CXX_FLAGS := -std=c++11

SRC_DIRS := ./include

LD_FLAG := -L../Build/Products/Debug

SRCS := $(shell find $(SRC_DIRS) -name '*.hpp')

OBJS := $(patsubst %.hpp, %.o, $(SRCS))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# CONDITIONALS
ifeq ($(OS),Windows_NT)
	CLEAN := del $(OBJ_DIR) *.o && del $(BIN)
	LIBS := -lsfml-graphics -lsfml-systems -lsfml-window
else
	CLEAN := rm -f $(OBJS) *.o && rm -f $(BIN)
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