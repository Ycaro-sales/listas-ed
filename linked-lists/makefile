#
# Name of the project
PROJ_NAME=lista
SRC = questoes

# .c files
CC = gcc
SRC_DIR = .
BUILD_DIR = build
EXEC_DIR = bin

# Get all .c files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Generate corresponding object file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Generate corresponding executable file names
EXEC_FILES = $(patsubst $(SRC_DIR)/%.c, $(EXEC_DIR)/%, $(SRC_FILES))

# Compiler flags
CFLAGS = -Wall -g

# Default target
all: $(EXEC_FILES)

# Rule for generating object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for generating executables
$(EXEC_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) $(CFLAGS) $< -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR)/* $(EXEC_DIR)/*
