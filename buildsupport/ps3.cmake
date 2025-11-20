if (CMAKE_HOST_WIN32)
        set (SUFFIX .exe)
else()
        set (SUFFIX "")
endif()

set(CMAKE_SYSTEM_NAME PS3)
set(CMAKE_SYSTEM_PROCESSOR powerpc)
set(TOOLCHAIN_PREFIX powerpc64-ps3-elf-)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

find_program(CROSS_GCC_PATH ${TOOLCHAIN_PREFIX}gcc${SUFFIX} NO_CACHE)
get_filename_component(TOOLCHAIN ${CROSS_GCC_PATH} PATH)

set(CMAKE_C_COMPILER ${TOOLCHAIN}/${TOOLCHAIN_PREFIX}gcc${SUFFIX})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/${TOOLCHAIN_PREFIX}g++${SUFFIX})
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})

set(CMAKE_OBJCOPY ${TOOLCHAIN}/${TOOLCHAIN_PREFIX}objcopy${SUFFIX} CACHE INTERNAL "objcopy tool")
set(CMAKE_STRIP ${TOOLCHAIN}/${TOOLCHAIN_PREFIX}strip${SUFFIX} CACHE INTERNAL "strip tool")
set(CMAKE_SIZE_UTIL ${TOOLCHAIN}/${TOOLCHAIN_PREFIX}size${SUFFIX} CACHE INTERNAL "size tool")

set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# include_directories(AFTER SYSTEM ${TOOLCHAIN}/../include)
add_compile_options(-mcpu=cell -mhard-float -fmodulo-sched -ffunction-sections -fdata-sections -fno-strict-aliasing)
# add_link_options(-lnet)

# set(TOOLCHAIN armgcc)

set(PS3 TRUE)

MESSAGE(STATUS "ps3.cmake loaded")
