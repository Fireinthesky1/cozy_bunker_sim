#  Makefile for Mouse Engine Host
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

# Source directories
CORE_DIR           = host/core
PLATFORM_DIR       = host/platform

# Source files
HOST_CORE_SRCS = \
	$(CORE_DIR)/main.c \
	$(CORE_DIR)/mouse_time.c \
	$(CORE_DIR)/mouse_window.c

# HOST_PLATFORM_SRCS = \
# 	$(CORE_DIR)/platform.c \
# 	$(CORE_DIR)/linux_platform.c \
# 	$(CORE_DIR)/linux_window.c

HOST_SRCS = \
	$(HOST_CORE_SRCS) \
	$(HOST_PLATFORM_SRCS)

# Object files
HOST_OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(HOST_SRCS))

# Build host executable

# Rule for building the host.
$(HOST_TARGET): $(HOST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(HOST_OBJS) -o $@ $(LDFLAGS) $(HOST_LIBS)

# Compile c sources
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CLFAGS) -c $< -o $@
