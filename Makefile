#  Makefile for both Mouse Engine and Mouse Game.
#  Copyright (C) <2026>  <James Hicks>
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.

CC = gcc
TARGET = $(BIN_DIR)/mouse_quest

# get the sdl flags from sdl2-config
CFLAGS = -Wall -Wextra -g -Iinclude -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2

# directories
SRC_DIR   =   src
HDR_DIR   =   include
LIB_DIR   =   libs
BUILD_DIR =   build
BIN_DIR   =   bin
DEBUG_DIR =   debug

# source header and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
HDR_FILES = $(wildcard $(HDR_DIR)/*.h)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# default target
all: directories $(TARGET)
	@echo "Build successful. Here are the details:"
	@echo "======================================="
	@echo "Warnings and Errors:"
	@$(CC) $(CFLAGS) -o /dev/null $(SRC_FILES) 2>&1 | grep -E 'warning:|error:' | sed 's/^/ /'
	@echo "======================================="
	@echo "Executable Size:"
	@du -h $(TARGET)
	@echo "======================================="
	@echo "Running The program:"
	@./$(TARGET)

# debug target
debug: CFLAGS += -DDEBUG -g
debug: all
	@echo "Debug build successful. Use 'gdb --batch -tui $(TARGET)' to debug."
	@echo "Redirecting debug output to $(DEBUG_DIR)/debug.log"
	@./$(TARGET) > $(DEBUG_DIR)/debug.log 2>&1

# build rules
$(TARGET): $(OBJ_FILES)
	@echo "building $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HDR_FILES)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

directories:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR) $(LIB_DIR) $(SRC_DIR) $(DEBUG_DIR)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR) $(DEBUG_DIR)
	@echo "There is a Fire in the sky"
	@rm -f ./test_files/output/*.txt

valgrind: all
	@echo "Running valgrind on $(TARGET)"
	@valgrind --track-origins=yes ./$(TARGET)

valgrind_more: all
	@echo "Running valgrind with comprehensive options on $(TARGET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(DEBUG_DIR)/valgrind.log ./$(TARGET)

.PHONY: all clean directories
