# The name of our project is "DGtal". CMakeLists files in this
# project can refer to the root source directory of the project as
# ${DGTAL_SOURCE_DIR} and to the root binary directory of the
# project as ${DGTAL_BINARY_DIR}.

# -----------------------------------------------------------------------------
# Project definition
# -----------------------------------------------------------------------------
cmake_minimum_required (VERSION 2.4) 
project (DGtal)

message( "-------------------------------------------------------------------------------" )
message( "DGtal: see AUTHORS file" )
message( "       You may specify the following options:" )
message( "         - CMAKE_BUILD_TYPE = Debug|Release: choose configuration.")
message( "         - CMAKE_INSTALL_PREFIX = <path>: the place to install ImaGene (/usr/local).")
message( "       with the syntax (for instance)")  
message( "         cmake -DCMAKE_BUILD_TYPE:STRING=Debug")
message( "-------------------------------------------------------------------------------" )

message("Source DIR is ${PROJECT_SOURCE_DIR}")
message("Binary DIR is ${PROJECT_BINARY_DIR}")

set(INSTALL_DOC_PATH ${CMAKE_INSTALL_PREFIX}/doc/${CMAKE_PROJECT_NAME} )


# -----------------------------------------------------------------------------
# Display some information
# -----------------------------------------------------------------------------
message( STATUS "Libs extension is '${SUFFIXLIB}'. Bins extension is '${SUFFIXBIN}'." )
message(STATUS "Installation prefix directory is " ${CMAKE_INSTALL_PREFIX})
message(STATUS "Host system is " ${CMAKE_HOST_SYSTEM} " with processor " ${CMAKE_HOST_SYSTEM_PROCESSOR})
message(STATUS "Target system is " ${CMAKE_SYSTEM} " with processor " ${CMAKE_SYSTEM_PROCESSOR})

# -----------------------------------------------------------------------------
# Check packages
# -----------------------------------------------------------------------------
# Look for modules
set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
list( APPEND CMAKE_MODULE_PATH . )


# nead file 'doxy.config.in' for documentation
include(doc/doxygen.cmake)
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
INCLUDE("${CMAKE_MODULE_PATH}/TargetDoxygenDoc.cmake" OPTIONAL)

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/TargetUninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/TargetUninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/TargetUninstall.cmake")

# -----------------------------------------------------------------------------
# Check Dependencies
# -----------------------------------------------------------------------------
FIND_PACKAGE(Boost)


# -----------------------------------------------------------------------------
# Defines some variables
# -----------------------------------------------------------------------------
set ( LIBDGTAL_NAME "DGtal${SUFFIXLIB}" )

# -----------------------------------------------------------------------------
# Parsing cmake options
# -----------------------------------------------------------------------------

OPTION(BUILD_SHARED_LIBS "Build shared libraries." ON)

OPTION(BUILD_TESTS "Build tests." ON)
if (BUILD_TESTS)
  ENABLE_TESTING()
  add_subdirectory (tests)
endif (BUILD_TESTS)


#------------------------------------------------------------------------------
# Add subdirectories
#------------------------------------------------------------------------------
add_subdirectory (src)

#------------------------------------------------------------------------------
# Prepare installations concerning global scope.
#------------------------------------------------------------------------------
if (CMAKE_MAJOR_VERSION EQUAL 2)
   if (CMAKE_MINOR_VERSION GREATER 5)
      install(DIRECTORY include/ DESTINATION include 
      			FILES_MATCHING PATTERN "*.*h")
   else (CMAKE_MINOR_VERSION GREATER 5)
      install(DIRECTORY include/ DESTINATION include 
      			PATTERN "*.*h")
   endif (CMAKE_MINOR_VERSION GREATER 5)
endif (CMAKE_MAJOR_VERSION EQUAL 2)

#------------------------------------------------------------------------------
# Configuration of the Config.h
#------------------------------------------------------------------------------
SET(${DGtal_VERSION} "0.1")
CONFIGURE_FILE( "${PROJECT_SOURCE_DIR}/include/DGtal/base/Config.h.in" "${PROJECT_SOURCE_DIR}/include/DGtal/base/Config.h" IMMEDIATE @ONLY)


#------------------------------------------------------------------------------
# Some directories and files should also be cleaned when invoking 'make clean'
#------------------------------------------------------------------------------
ADD_CUSTOM_TARGET(distclean
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/TargetDistclean.cmake")

