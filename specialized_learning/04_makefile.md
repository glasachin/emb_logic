# Make File

```makefile
target: dependencies
<tab> `commands` to make target
```

## Phony Targets
A phony target is one that isn't really the name of a file. It will only have a list of commands and no dependencies. 

```
clean:
    rm -rf *.o
```

## Macros
with this we can avoid repeating text entries.

```
NAME=[text string]
e.g. CC=g++
```

### Special Macros

**@**

`@` evaluates to the name of the current target.

e.g.

```
prog1:$(objs)
    $(cxx) -o $@ $(objs)

the above is equivalent to 

prog1:$(objs)
    $(cxx) -o prog1 $(objs)
```


## example of make file if files are in different folders

```makefile
# Compiler & flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -MMD -MP

# Project structure
SRC_DIR := src
INC_DIR := include
OBJ_DIR := build
BIN_DIR := bin

# Target executable
TARGET := $(BIN_DIR)/my_app

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directories if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include dependencies
-include $(DEPS)

.PHONY: all clean
```


