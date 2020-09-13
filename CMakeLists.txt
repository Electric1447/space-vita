cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(spacevita)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Space Game Vita")
set(VITA_TITLEID  "SPACENX00")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl, -g -Wall -O2 -ffast-math")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wl,-q -fno-rtti -fno-exceptions -std=gnu++14 -fpermissive")

file(GLOB src_files
    "*.cpp"
	"*.c"
)

add_executable(${PROJECT_NAME}
  ${src_files}
)

target_link_libraries(${PROJECT_NAME}
	SDL2_mixer
	SDL2
	vita2d
	SceDisplay_stub
	SceCtrl_stub
	SceAudio_stub
	SceSysmodule_stub
	SceGxm_stub
	SceCommonDialog_stub
	ScePower_stub
	SceTouch_stub
	SceHid_stub
	SceAppMgr_stub
  	m
	z
	c
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
	VERSION ${VITA_VERSION}
	NAME ${VITA_APP_NAME}
)