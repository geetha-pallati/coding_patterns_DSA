# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Binary names
BINS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%)

# Default target
all: $(BIN_DIR) $(BINS)

# Create bin directory if not exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile each .c into bin/
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# Clean binaries
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean

