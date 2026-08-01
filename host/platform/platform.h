//  Platform Abstraction Layer Header.
//    This file is responsible for platform detection.
//  Copyright (C) <2026>  <James Hicks>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#ifndef PLATFORM
#define PLATFORM

// Detect the linux platform and include the linux platform header.
#ifdef __linux__
#define LINUX_PLATFORM
#include "linux_platform.h"
#endif

#endif
