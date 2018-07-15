#####################################################
#           CMAKE ROOT PROJECT FILE                 #
#####################################################

CMAKE_MINIMUM_REQUIRED(VERSION 3.1 FATAL_ERROR)
CMAKE_POLICY (SET CMP0015 NEW)

PROJECT(dotProductTest LANGUAGES C CXX)

#####################
#   Safety checks   #
#####################

SET(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

############################################
#   Additional cmake modules and macros    #
############################################

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
INCLUDE(GetGitRevisionDescription)

git_describe(VERSION --tags)

INCLUDE(options REQUIRED)
INCLUDE(compiler_options REQUIRED)
INCLUDE(install_options REQUIRED)


#################################
#       External libraries      #
#################################

SET(BUILD_SHARED_LIBS OFF)
SET(INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin/${CMAKE_INSTALL_SUFFIX})
SET(INSTALL_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/${CMAKE_INSTALL_SUFFIX})

FIND_PACKAGE(gtest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIR})

FIND_PACKAGE(benchmark REQUIRED)
INCLUDE_DIRECTORIES(${BENCHMARK_INCLUDE_DIR})

# Set LDFLAGS: this is not in the default path...
LINK_DIRECTORIES(/usr/local/lib)

MESSAGE(STATUS "Using CXXFLAGS: ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "Using CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
MESSAGE(STATUS "Using CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")

#########################################
#   Upper level includes and subdir     #
#########################################

SET(SUBMODULES src apps)
INCLUDE_DIRECTORIES(${SUBMODULES})
FOREACH(MODULE ${SUBMODULES})
    ADD_SUBDIRECTORY(${MODULE})
ENDFOREACH(MODULE)

######################
#   Enable testing   #
######################

IF(BUILD_UNIT_TESTS)
    ENABLE_TESTING(true)
    INCLUDE_DIRECTORIES(tests)
    ADD_SUBDIRECTORY(tests)
ENDIF()
