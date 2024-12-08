cmake_minimum_required(VERSION 3.10)

project(DropDash)

set(MOD_NAME DropDash CACHE STRING "The mod directory to look into")
set(OUTPUT_NAME "DropDash" CACHE STRING "The name of the built library")

set(RETRO_REVISION 3 CACHE STRING "What revision to compile for. Defaults to Origins = 3")
set(RETRO_MOD_LOADER_VER 2 CACHE STRING "Sets the mod loader version. Defaults to latest")

option(MOD_INCLUDE_EDITOR "Whether or not to include editor functions. Defaults to true" ON)

find_path(GAMEAPI
  NAMES
    C
    CPP
  PATHS
    .
    ..
  PATH_SUFFIXES
    GameAPI
    RSDKv5-GameAPI
  NO_DEFAULT_PATH
  NO_CMAKE_FIND_ROOT_PATH
)

if(GAMEAPI)
  message(STATUS "Found GameAPI for ${MOD_NAME}: ${GAMEAPI}")
else()
  message(FATAL_ERROR "GameAPI not found for ${MOD_NAME}. Did you clone the repository recursively?")
endif()

file(GLOB OBJECTS RELATIVE ${CMAKE_SOURCE_DIR} ${MOD_NAME}/Objects/*.cpp)

add_library(DropDash SHARED
    ${GAMEAPI}/CPP/GameAPI/Game.cpp
    ${MOD_NAME}/dllmain.cpp
    ${OBJECTS}
)

target_include_directories(DropDash PRIVATE
    ${MOD_NAME}/
    ${MOD_NAME}/Objects/
    ${GAMEAPI}/CPP/
)

set_target_properties(DropDash PROPERTIES OUTPUT_NAME ${OUTPUT_NAME})

target_compile_definitions(DropDash PRIVATE
	RETRO_REVISION=${RETRO_REVISION}
	RETRO_USE_MOD_LOADER=1
	RETRO_MOD_LOADER_VER=${RETRO_MOD_LOADER_VER}
	RETRO_INCLUDE_EDITOR=$<BOOL:${MOD_INCLUDE_EDITOR}>
	GAME_TYPE=0
	GAME_NO_GLOBALS=1
)

unset(MOD_NAME CACHE)
unset(OUTPUT_NAME CACHE)