cmake_minimum_required(VERSION 2.8)

include("builders/cmake/RequireOutOfSource.cmake")

project(GAMEAUDIO)

SET(GAMEAUDIO_SOURCE_FILES
	src/audiosample.cxx
	src/samplecache.cxx
	src/simplesamplecache.cxx
)

SET(GAMEAUDIO_HEADER_FILES
	src/audiosample.hpp
	src/samplecache.hpp
	src/simplesamplecache.hpp
)

# A bit of extra configuration for Visual Studio
SET (MSPROJECT_TEMPLATE_DIRECTORY "${CMAKE_SOURCE_DIR}/CMake/Visual Studio")

# Attempt to find OpenAL on this machine
FIND_PACKAGE(OpenAL)

# This creates the library that will be generated for linking to GameAudio
ADD_LIBRARY(gameaudio ${GAMEAUDIO_SOURCE_FILES} ${GAMEAUDIO_HEADER_FILES})

SET(GAMEAUDIO_LIBRARIES ${GAMEAUDIO_LIBRARIES} ${OPENAL_LIBRARY})
TARGET_LINK_LIBRARIES(gameaudio ${GAMEAUDIO_LIBRARIES})
