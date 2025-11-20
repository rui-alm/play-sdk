cmake_minimum_required(VERSION 3.19)
project("PDLondon")

# C++ 20 and up is required in order to include the playdate headers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

if (PS5)
    add_compile_options(-D__PS5__ -Wno-unreachable-code-generic-assoc -Wno-format)
    set(SRC ${SRC} src/main_ps.cpp)
elseif(PS4)
    set(SRC ${SRC} src/main_ps.cpp)
elseif(PS3)
    add_compile_definitions(aligned_alloc=memalign)
    set(SRC ${SRC} src/main_ps.cpp)
elseif(PS2)
    include(buildsupport/ps2.cmake)
    set(SRC ${SRC} src/main_ps.cpp)
elseif(PDC)
    SET(SRC ${SRC}
        sdk/include/playdate/system/pd_system.h
        sdk/src/playdate/system/pd_system.cpp
        sdk/src/playdate/pd_display.cpp
        sdk/include/playdate/system/pd_graphics.h
        sdk/src/playdate/system/pd_graphics.cpp
        sdk/src/playdate/graphics/pd_bitmap_table.cpp
        # src/playdate/view/main_view_playdate.cpp
        sdk/include/playdate/system/pd_file_system.h
        sdk/src/playdate/system/pd_file_system.cpp
        # sdk/src/test/playdate/graphics/pd_font_test.cpp
        # sdk/src/test/playdate/graphics/text_test.cpp
        sdk/include/playdate/system/logger.h
        src/main.cpp
    )
    include(buildsupport/playdate.cmake)
    add_subdirectory(playdate-cpp)
endif()

# add_subdirectory(box2d-lite)
add_subdirectory(box2d)

# Now we can declare our application
if(PDC)
    add_playdate_application(PDLondon)
    target_link_libraries(box2d PRIVATE simde pdcpp_core)
    target_compile_options(box2d PRIVATE
        -Wno-error=incompatible-pointer-types
        -Wno-error=unused-variable
        -Wno-error=maybe-uninitialized
        -Wno-error=double-promotion
        -Wno-error=format)
else()
    add_executable(PDLondon)
endif()

target_include_directories(PDLondon
PUBLIC
include
sdk/include
)

set(BOX2D_LITE_SRCS
    box2d-lite/src/Arbiter.cpp
    box2d-lite/src/Body.cpp
    box2d-lite/src/Collide.cpp
    box2d-lite/src/Joint.cpp
    box2d-lite/src/World.cpp
)

# Add its sources
set(SRC
    ${SRC}
    sdk/src/model/actor/actor.cpp
    src/assets/walls/wall.cpp
    src/model/game_model.cpp
    src/model/main_model.cpp
    src/controller/game_controller.cpp
    src/controller/input_controller.cpp
    src/controller/main_controller.cpp
    src/view/main_view.cpp
    src/view/game_view.cpp
    sdk/include/model/to_string.h
    sdk/include/logger/logger.h
    sdk/include/graphics/text/line_splitter.h
    sdk/src/graphics/text/line_splitter.cpp


    # sdk/include/test/controller/test_menu_controller.h
    # sdk/src/test/controller/test_menu_controller.cpp
    # sdk/include/test/model/test.h
    # sdk/include/test/model/actor_test.h
    # sdk/src/test/model/test.cpp
    # sdk/src/test/model/actor_test.cpp
    # sdk/include/test/view/test_menu_view.h
    # sdk/src/test/view/test_menu_view.cpp
    # sdk/include/test/model/test_state.h
    # sdk/include/system/file_system.h
    # sdk/include/test/graphics/font_test.h
    # sdk/include/test/graphics/framebuffer_test.h
    # sdk/src/test/graphics/framebuffer_test.cpp
    # sdk/include/test/graphics/text_test.h
    # sdk/include/test/graphics/text/line_splitter_test.h
    # sdk/src/test/graphics/line_splitter_test.cpp
    # sdk/include/test/model/type_assertions.h
    # sdk/include/test/model/test_macros.h
    )

if(PDC)
    set(SRC ${SRC} ${PD_SRCS})
endif()

target_sources(PDLondon
PUBLIC
# ${BOX2D_LITE_SRCS}
${SRC}
)

target_include_directories(PDLondon PUBLIC
    # box2d-lite/include
    box2d/include
    # box2cpp/include
)

# Link against the pdcpp_core library, and you're good to go!
target_link_libraries(PDLondon PUBLIC
    ${LIBRARIES}
    # box2d-lite
    box2d
)

# Compiler options
if(MSVC)
  target_compile_options(PDLondon PRIVATE /W4 /WX)
else()
  add_compile_options(-Wno-format)
  target_compile_options(PDLondon
  PRIVATE
  # -mno-xgot
  -Wall
  -Wextra
  -Wpedantic
  -Werror
  -Wno-non-virtual-dtor
  -Wdelete-non-virtual-dtor)
endif()
