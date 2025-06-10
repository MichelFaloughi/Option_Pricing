# --- Makefile for Your C++ Project ---
# This Makefile automates the build process for a multi-file C++ project.
# It supports separate compilation of object files and linking them into an executable.

# --- Configuration Variables ---
# You can adjust these based on your compiler, C++ standard, and desired output.

CXX = clang++                                   # The C++ compiler to use (e.g., g++, clang++)
# CXX = g++                                     # Uncomment this if you prefer g++

# C++ standard and general compiler flags.
# -std=c++14: Use C++14 standard.
# -Wall -Wextra: Enable extensive warnings.
# -g: Include debugging information (useful for gdb, lldb).
CXXFLAGS = -std=c++14 -Wall -Wextra -g

# Directories for source files, header files, and build output.
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Name of the final executable.
TARGET = $(BUILD_DIR)/main

# List of all source files (.cpp) in your project.
# The wildcard function finds all .cpp files in the SRC_DIR.
# If you have specific files, you can list them explicitly too:
# SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/BinomialTree.cpp $(SRC_DIR)/StockTree.cpp $(SRC_DIR)/trial.cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (.o) will be created in the BUILD_DIR.
# For each src/file.cpp, create a build/file.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# --- Phony Targets ---
# Phony targets are not actual files, but commands to be executed.
.PHONY: all clean run debug

# --- Default Target ---
# The 'all' target is the default when you just type 'make'.
# It builds the main executable.
all: $(TARGET)

# --- Rule to Build the Executable ---
# The main executable depends on all object files.
# The compiler/linker links all object files into the target.
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR) # <--- THIS LINE MUST START WITH A TAB
	$(CXX) $(OBJS) -o $(TARGET) # <--- THIS LINE MUST START WITH A TAB

# --- Rule to Compile Source Files into Object Files ---
# This is a pattern rule: for any %.o in the BUILD_DIR, it depends on its corresponding %.cpp in SRC_DIR.
# -I$(INCLUDE_DIR): Tells the compiler to search the 'include' directory for header files.
# -c: Compile only, do not link.
# $<: Automatic variable for the first prerequisite (the .cpp file).
# $@: Automatic variable for the target (the .o file).
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D) # <--- THIS LINE MUST START WITH A TAB
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@ # <--- THIS LINE MUST START WITH A TAB

# --- Rule to Run the Executable ---
# Depends on the target being built first.
run: $(TARGET)
	./$(TARGET) # <--- THIS LINE MUST START WITH A TAB

# --- Rule to Clean Compiled Files ---
# Removes the entire build directory.
clean:
	@echo "Cleaning build directory..." # <--- THIS LINE MUST START WITH A TAB
	@rm -rf $(BUILD_DIR) # <--- THIS LINE MUST START WITH A TAB
	@echo "Clean complete." # <--- THIS LINE MUST START WITH A TAB

# --- Debug Target ---
# Optional: A target to start a debugger with your executable.
# Requires lldb or gdb to be installed.
debug: $(TARGET)
	lldb ./$(TARGET) # <--- THIS LINE MUST START WITH A TAB (Or 'gdb ./$(TARGET)')
