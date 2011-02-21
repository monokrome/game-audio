# Force out-of-source build
STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" BUILDING_IN_SOURCE)

IF(BUILDING_IN_SOURCE)
  MESSAGE(FATAL_ERROR "
    This project requires an out of source build. Create a separate
    build directory and run 'cmake path_to_project [options]' from there.
  ")

  IF(WIN32)
    # DELETE THOSE FILES.
  ELSE(WIN32)
    # DELETE THOSE FILES.
  ENDIF(WIN32)
ENDIF(BUILDING_IN_SOURCE)

