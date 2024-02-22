# This file is a part of the UMSKT Project
#
# Copyleft (C) 2019-2024 UMSKT Contributors (et.al.)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# SPDX-License-Identifier: AGPL-3.0-or-later
#
# @FileCreated by Neo on 02/19/2024
# @Maintainer Neo

cmake_minimum_required(VERSION 3.12)

project(stdint128 VERSION 1.0.1 LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindInt128.cmake)
FIND_INT128_TYPES()

add_library(stdint128 INTERFACE)

target_include_directories(stdint128
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(stdint128 INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:${INT128_FLAGS}>
    $<$<CXX_COMPILER_ID:MSVC>:${INT128_FLAGS}>
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/stdint128ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    TARGETS stdint128
    EXPORT stdint128Targets
    INCLUDES DESTINATION include
)

install(
    DIRECTORY include/
    DESTINATION include
)

install(
    EXPORT stdint128Targets
    FILE stdint128Targets.cmake
    NAMESPACE stdint128::
    DESTINATION lib/cmake/stdint128
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/stdint128ConfigVersion.cmake"
    DESTINATION lib/cmake/stdint128
)

