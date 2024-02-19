/**
 * This file is a part of the UMSKT Project
 *
 * Copyleft (C) 2019-2024 UMSKT Contributors (et.al.)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * SPDX-License-Identifier: AGPL-3.0-or-later
 *
 * @FileCreated by Neo on 02/19/2024
 * @Maintainer Neo
 */

#ifndef __STDINT128__
#define __STDINT128__

// check the results of FIND_INT128_TYPES()
#if !defined(HAVEuint128_t)
#if defined(HAVEuint128_as_u_long_long)
typedef unsigned long long uint128_t;
#elif defined(HAVE__uint128_t)
typedef __uint128_t uint128_t;
#elif defined(HAVE__uint128)
typedef __uint128 uint128_t;
#elif defined(HAVEuint128)
typedef uint128 uint128_t;
#elif defined(HAVEunsigned__int128_t)
typedef unsigned __int128_t uint128_t;
#elif defined(HAVEunsignedint128_t)
typedef unsigned int128_t uint128_t;
#elif defined(HAVEunsigned__int128)
typedef unsigned __int128 uint128_t
#elif defined(HAVEunsignedint128)
typedef unsigned int128 uint128_t;
#else
//#if defined(_MSC_VER)
//#include <intrin.h>
//#endif
#include <stdint.h>
typedef union uint128_t {
    uint8_t u8[16];
    uint16_t u16[8];
    uint32_t u32[4];
    uint64_t u64[2];
};
#endif
#endif // !defined(HAVEuint128_t)

#if !defined(HAVEint128_t)
#if defined(HAVE__int128_t)
typedef __int128_t int128_t;
#elif defined(HAVEint128_as_long_long)
typedef long long int128_t;
#elif defined(HAVE__int128)
typedef __int128 int128_t;
#elif defined(HAVEint128)
typedef int128 int128_t;
#else
//#if defined(_MSC_VER)
//#include <intrin.h>
//#endif
#include <stdint.h>
typedef union int128_t {
    int8_t i8[16];
    int16_t i16[8];
    int32_t i32[4];
    int64_t i64[2];
};
#endif
#endif // !defined(HAVEint128_t)

#endif // ifdef __STDINT128__