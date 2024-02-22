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
#ifndef HAVE_INT128BUILTIN
#define HAVE_INT128BUILTIN
#endif
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
#ifdef HAVE_INT128BUILTIN
#undef HAVE_INT128BUILTIN
#endif
//#if defined(_MSC_VER)
//#include <intrin.h>
//#endif
#include <stdint.h>
typedef struct uint128_t {
    uint64_t hi;
    uint64_t lo;
};
#endif
#endif // !defined(HAVEuint128_t)

#ifndef HAVE_UINT128BUILTIN
#define HAVE_UINT128BUILTIN
#endif
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
#ifdef HAVE_UINT128BUILTIN
#undef HAVE_UINT128BUILTIN
#endif
//#if defined(_MSC_VER)
//#include <intrin.h>
//#endif
#include <stdint.h>
typedef struct int128_t {
	int64_t hi;
	int64_t lo;
};
#endif
#endif // !defined(HAVEint128_t)

#endif // ifdef __STDINT128__
