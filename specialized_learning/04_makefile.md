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

## Multiple directory structure

project/
│
├── Makefile
├── src/
│   ├── main.cpp
│   ├── module1/
│   │   └── mod1.cpp
│   └── module2/
│       └── mod2.cpp
├── include/
    ├── mod1.h
    └── mod2.h


```makefile
# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Sources and objects
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) \
           $(wildcard $(SRC_DIR)/module1/*.cpp) \
           $(wildcard $(SRC_DIR)/module2/*.cpp)

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

TARGET := $(BIN_DIR)/app

# Default target
all: $(TARGET)

# Link objects into executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
```
