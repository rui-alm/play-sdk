set(CMAKE_SYSTEM_NAME PS4)
set(TOOLCHAIN /opt/OpenOrbis/PS4Toolchain)
set(LIBS -lc -lkernel -lc++)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_FLAGS -fuse-ld=lld)
set(CMAKE_CXX_FLAGS -fuse-ld=lld)
set(EXTRAFLAGS -Wno-format -Wno-error=unused-command-line-argument)
set(LLVM_ENABLE_LLD TRUE)
set(CLANG_DEFAULT_LINKER lld)

include_directories(BEFORE SYSTEM ${TOOLCHAIN} ${TOOLCHAIN}/include ${TOOLCHAIN}/include/c++/v1)
add_compile_options(-D__PS4__ -mavx --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -c ${EXTRAFLAGS})
link_directories(BEFORE SYSTEM ${TOOLCHAIN}/lib)
add_link_options(-Wl,-melf_x86_64 -Wl,-pie -Wl,--script=${TOOLCHAIN}/link.x -Wl,--eh-frame-hdr ${LIBS})

# -fuse-ld=ld.lld
# set(TOOLCHAIN armgcc)

set(PS4 TRUE)

MESSAGE(STATUS "ps4.cmake loaded")
