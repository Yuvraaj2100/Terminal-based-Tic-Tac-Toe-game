SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(SRC_DIR)/*.cpp
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
	./build/debug/play
