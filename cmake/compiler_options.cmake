########################
#   Compiler options   #
########################

SET (CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -pg")

SET (CMAKE_CXX_STANDARD 14)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)
SET (CMAKE_CXX_EXTENSIONS OFF)
MESSAGE(STATUS "C++ Standard selected: c++${CMAKE_CXX_STANDARD}")

SET (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg -Wall -D_REENTRANT -DDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native -DNDEBUG")

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release." FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# Platform specific
IF (APPLE)
    MESSAGE (STATUS "Apple system detected")
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-inconsistent-missing-override")
    SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Accelerate")
ENDIF(APPLE)

if(CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE (STATUS "GCC compiler detected")
    # This one allow to detect libblas.so.3gf on Debian/Ubuntu
    SET (CMAKE_SYSTEM_NAME "Linux")
    SET (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfpmath=sse -fomit-frame-pointer -pipe")
    IF (WARNINGS_EFF_CXX)
        SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")
    ENDIF (WARNINGS_EFF_CXX)
ENDIF ()
