#
# Find VideoManagerLib library.
#
# VIDEOMANAGER_FOUND - system has found AST library
# VIDEOMANAGER_DIRS - the projects public include directory
# VIDEOMANAGER_LIBRARIES - the projects static libraries

include(ProjectEnvironment)

##################################
# Includes
##################################
find_path(VIDEOMANAGER_DIR
    NAMES VideoManager/engine.h
	PATHS ${ARTIFACTS_SEARCH_DIR}/include/
	NO_DEFAULT_PATH
	NO_CMAKE_FIND_ROOT_PATH
)

set(VIDEOMANAGER_DIRS ${VIDEOMANAGER_DIR})

##################################
# Static Libraries
##################################
find_library(VIDEOMANAGER_DEBUG
        NAMES ${CMAKE_SHARED_LIBRARY_PREFIX}VIDEOMANAGER${CMAKE_DEBUG_POSTFIX}${CMAKE_SHARED_LIBRARY_SUFFIX}
	PATHS ${TC_ARTIFACTS_SEARCH_DIR}/lib
	NO_DEFAULT_PATH
	NO_CMAKE_FIND_ROOT_PATH
)

find_library(VIDEOMANAGER_RELEASE
        NAMES ${CMAKE_SHARED_LIBRARY_PREFIX}VIDEOMANAGER${CMAKE_RELEASE_POSTFIX}${CMAKE_SHARED_LIBRARY_SUFFIX}
	PATHS ${TC_ARTIFACTS_SEARCH_DIR}/lib
	NO_DEFAULT_PATH
	NO_CMAKE_FIND_ROOT_PATH
)

set(VIDEOMANAGER_LIBRARY_DEBUG ${VIDEOMANAGER_DEBUG})
set(VIDEOMANAGER_LIBRARY_RELEASE ${VIDEOMANAGER_RELEASE})

# Setup VIDEOMANAGER_LIBRARIES based on debug and release builds
include(SelectLibraryConfigurations)
select_library_configurations(VIDEOMANAGER)

set(VIDEOMANAGER_LIBRARIES ${VIDEOMANAGER_LIBRARY})

###################################
# Setup package
###################################
include(FeatureSummary)
include(FindPackageHandleStandardArgs)
include(SelectLibraryConfigurations)


# handle the QUIETLY and REQUIRED arguments and set VIDEOMANAGER_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(VIDEOMANAGER
	DEFAULT_MSG
        VIDEOMANAGER_LIBRARIES
        VIDEOMANAGER_DIRS
)

mark_as_advanced(
    VIDEOMANAGER_DEBUG
    VIDEOMANAGER_RELEASE
    VIDEOMANAGER_DIR
)

###################################
# Library dependencies
###################################

