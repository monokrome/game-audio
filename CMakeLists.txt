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

SOURCE_GROUP(Sources "${GAMEAUDIO_SOURCE_FILES}")
SOURCE_GROUP(Headers "${GAMEAUDIO_HEADER_FILES}")

ADD_LIBRARY(gameaudio ${GAMEAUDIO_SOURCE_FILES})

# Find required libraries, and then link them to our project
FIND_LIBRARY(OPENAL_LIBRARY NAMES openal PATHS "${GAMEAUDIO_SOURCE_DIR}/public/lib" OpenAL32 REQUIRED)

SET(GAMEAUDIO_LIBRARIES ${GAMEAUDIO_LIBRARIES} ${OPENAL_LIBRARY})
TARGET_LINK_LIBRARIES(gameaudio ${GAMEAUDIO_LIBRARIES})
