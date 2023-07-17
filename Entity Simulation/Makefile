# VARIABLES
## Binary
BIN := Entity-Simulation
SFML_V := 2.6.0

## Compiler
CXX := g++
CXX_FLAGS := -std=c++11

SRC_DIRS := ./include

# LD_FLAG :=

SRCS := $(shell find $(SRC_DIRS) -name '*.hpp')

OBJS := $(patsubst %.hpp, %.o, $(SRCS))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)

# CONDITIONALS
ifeq ($(OS),Windows_NT)
	CLEAN := del $(OBJ_DIR) *.o && del $(BIN)
	LIBS := -lsfml-graphics -lsfml-systems -lsfml-window
else
	CLEAN := rm -f $(OBJS) *.o && rm -f $(BIN)
	LIBS := -lsfml-graphics.${SFML_V} -lsfml-system.${SFML_V} -lsfml-window.${SFML_V}
endif

# COMMANDS
## All
all: $(BIN)

## Binary
$(BIN): $(OBJS) main.cpp
	touch $@
	$(CXX) $(CXX_FLAGS) main.cpp $(OBJS) -o $@ $(LIBS) -march=native -v $(LD_FLAG)

## Objects
%.o: %.hpp
	$(CXX) -c $(CXX_FLAGS) $< -o $@

## Clean
clean:
	$(CLEAN)
