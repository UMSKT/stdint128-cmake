# stdint128-cmake
standardized implementation of [u]int128_t

selects a compiler specific builtin implementation of 128bit integers or defines a struct if a builtin is not supported.

TODO: use actual intrinsics for when a builtin is not provided

##Usage

###CMakeLists.txt
```cmake
CPMAddPackage(
        NAME stdint128
        GITHUB_REPOSITORY UMSKT/stdint128
        VERSION 1.0.0
)
```

###C++
```C++

#include <stdint128>

// int128_t and uint128_t are now in the global namespace

```

###C
```C
#include <stdint128.t>

// int128_t and uint128_t have been typedef'd

```