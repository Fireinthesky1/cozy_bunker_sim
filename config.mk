#  Main config.mk file for Mouse Engine
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

# Tools
CC         = gcc

# Output directories
BUILD_DIR  = build
BIN_DIR    = bin
PLUGIN_DIR = plugins # output .so files from modules are called plugins.

# Output files
HOST_TARGET = $(BIN_DIR)/mouse_engine

# Compiler flags
CFLAGS  = -Wall -Wextra -g -Iinclude

# Position Independent Code
PICFLAGS = -fPIC

# Linker options
LDFLAGS =

# Dynamic Linking Library
# X11 core
# X Window System extensions
HOST_LIBS = -ldl -lX11 -lXext

PLUGIN_LDFLAGS = -shared
