cmake_minimum_required(VERSION 3.19)
project("PDLondon")

# C++ 20 and up is required in order to include the playdate headers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

# As this is part of the repo, we can't demonstrate this aptly, but for a full
# project, you will want to include this project in order to use the build
# system, which might looks something like this:
#
add_subdirectory(playdate-cpp)

# Now we can declare our application
add_playdate_application(PDLondon)

target_include_directories(PDLondon
PUBLIC
include
sdk/include
)

# Add its sources
target_sources(PDLondon
PUBLIC
sdk/src/model/actor/actor.cpp
sdk/src/playdate/pd_display.cpp
sdk/include/playdate/system/pd_graphics.h
sdk/src/playdate/system/pd_graphics.cpp
sdk/src/playdate/graphics/pd_bitmap_table.cpp
sdk/include/playdate/system/pd_system.h
sdk/src/playdate/system/pd_system.cpp
src/main.cpp
src/assets/walls/wall.cpp
src/model/game_model.cpp
src/model/main_model.cpp
src/controller/game_controller.cpp
src/controller/input_controller.cpp
src/controller/main_controller.cpp
src/playdate/view/main_view_playdate.cpp
src/view/main_view.cpp
src/view/game_view.cpp
sdk/include/test/controller/test_menu_controller.h
sdk/src/test/controller/test_menu_controller.cpp
sdk/include/test/model/test.h
sdk/include/test/model/actor_test.h
sdk/src/test/model/test.cpp
sdk/src/test/model/actor_test.cpp
sdk/include/test/view/test_menu_view.h
sdk/src/test/view/test_menu_view.cpp
sdk/include/test/model/test_state.h
sdk/include/system/file_system.h
sdk/include/playdate/system/pd_file_system.h
sdk/src/playdate/system/pd_file_system.cpp
sdk/include/test/graphics/font_test.h
sdk/src/test/playdate/graphics/pd_font_test.cpp
sdk/include/test/graphics/framebuffer_test.h
sdk/src/test/graphics/framebuffer_test.cpp
sdk/include/test/graphics/text_test.h
sdk/src/test/playdate/graphics/text_test.cpp
sdk/include/playdate/system/logger.h
sdk/include/graphics/text/line_splitter.h
sdk/src/graphics/text/line_splitter.cpp
sdk/include/test/graphics/text/line_splitter_test.h
sdk/src/test/graphics/line_splitter_test.cpp
)

# Link against the pdcpp_core library, and you're good to go!
target_link_libraries(PDLondon pdcpp_core)

# Compiler options
if(MSVC)
  target_compile_options(PDLondon PRIVATE /W4 /WX)
else()
  target_compile_options(PDLondon
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Werror
  -Wno-non-virtual-dtor
  -Wdelete-non-virtual-dtor)
endif()
