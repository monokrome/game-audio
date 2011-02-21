cmake_minimum_required(VERSION 2.8)

include("builders/cmake/RequireOutOfSource.cmake")

project(GAMEAUDIO)

SET(GAMEAUDIO_SOURCE_FILES 
	src/audio.cxx
	src/audiosample.cxx
	src/samplecache.cxx
)

SET(GAMEAUDIO_HEADER_FILES
	src/audiosample.cxx
	src/samplecache.cxx
)

SOURCE_GROUP(Sources "${GAMEAUDIO_SOURCE_FILES}")
SOURCE_GROUP(Headers "${GAMEAUDIO_HEADER_FILES}")

ADD_LIBRARY(gameaudio ${GAMEAUDIO_SOURCE_FILES})

# Find required libraries, and then link them to our project
FIND_LIBRARY(OPENAL_LIBRARY openal REQUIRED)

SET(GAMEAUDIO_LIBRARIES ${GAMEAUDIO_LIBRARIES} ${OPENAL_LIBRARY})
TARGET_LINK_LIBRARIES(gameaudio ${GAMEAUDIO_LIBRARIES})
