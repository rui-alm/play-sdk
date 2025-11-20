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
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/sdk/include
)

# Add its sources
target_sources(PDLondon
PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/sdk/src/system/playdate/pd_display.cpp
${CMAKE_CURRENT_SOURCE_DIR}/sdk/src/system/playdate/pd_graphics.cpp
${CMAKE_CURRENT_SOURCE_DIR}/sdk/src/system/playdate/pd_system.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/controllers/main_controller.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/views/main_view.cpp
${CMAKE_CURRENT_SOURCE_DIR}/sprites/one.png)

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