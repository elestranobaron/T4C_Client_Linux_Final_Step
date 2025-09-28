cmake_minimum_required(VERSION 3.10)
project(T4CClient)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Platform-specific configurations
if(WIN32)
    # Windows-specific libraries (DirectX, etc.)
    # Assuming DirectX SDK is installed and paths are set
    include_directories(
        "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/DirectX8Lib/include"
        "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/Directx9SDK/Include"
        "${CMAKE_SOURCE_DIR}/SXL/include"
        "${CMAKE_SOURCE_DIR}/WTL/include"
        "${CMAKE_SOURCE_DIR}/TFCCRYPTC/include"  # Or TFCCRYPTS depending on usage
        # Add other includes as needed
    )

    # Link Windows libraries (placeholder; adjust based on actual libs)
    link_directories(
        "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/DirectX8Lib/Lib"
        "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/Directx9SDK/Lib"
        "${CMAKE_SOURCE_DIR}/SXL/lib"
        "${CMAKE_SOURCE_DIR}/TFCCRYPTC/lib"
    )
else()  # Assuming Linux/UNIX
    # Find SDL3
    find_package(SDL3 REQUIRED CONFIG)
    if(NOT SDL3_FOUND)
        message(FATAL_ERROR "SDL3 not found. Install libsdl3-dev: sudo apt install libsdl3-dev")
    endif()

    # Other Linux dependencies (e.g., MySQL, OpenSSL if needed, but client may not require all)
    find_package(Threads REQUIRED)

    # Build SXL from sources for Linux
    file(GLOB SXL_SOURCES "${CMAKE_SOURCE_DIR}/SXL/sxl/*.cpp" "${CMAKE_SOURCE_DIR}/SXL/sxl/*.c")
    add_library(sxl STATIC ${SXL_SOURCES})
    target_include_directories(sxl PUBLIC "${CMAKE_SOURCE_DIR}/SXL/include")

    # For TFCCrypt, assuming sources are in CryptMestoph and already included

    include_directories(
        ${SDL3_INCLUDE_DIRS}
        "${CMAKE_SOURCE_DIR}/SXL/include"  # Assuming SXL is cross-platform
        "${CMAKE_SOURCE_DIR}/TFCCRYPTC/include"
        # Add Linux-specific includes if needed
    )

    # No link_directories for prebuilt libs on Linux; link built targets instead
endif()

# Common include directories
include_directories(
    "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/T4C Client"
    "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/CryptMestoph"
    # Add other common includes
)

# Source files (glob recursively from client directory)
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/Client/T4C Client/*.cpp"
    "${CMAKE_SOURCE_DIR}/CLIENT168_RC14h_OK/1.68RC14h/CryptMestoph/*.cpp"
    # Add other source directories as needed
)

# Exclude build and temp directories if any
list(FILTER SOURCES EXCLUDE REGEX "${CMAKE_SOURCE_DIR}/build/.*")

# Create executable
add_executable(T4CClient ${SOURCES})

# Platform-specific linking
if(WIN32)
    target_link_libraries(T4CClient PRIVATE
        # DirectX libraries (adjust names/paths)
        dxguid
        ddraw
        dsound
        dxerr8
        # SXL, WTL, crypt libs
        sxl
        TFCCrypt
        # Other Windows libs
    )
else()
    target_link_libraries(T4CClient PRIVATE
        SDL3::SDL3
        Threads::Threads
        sxl  # Built static lib
        # Crypt libs, etc.
        # TFCCrypt - if prebuilt, or link built version if sources available
        # Add Linux-specific libs like dl, m if needed
        dl
        m
    )
endif()

# Installation
install(TARGETS T4CClient DESTINATION bin)

# Custom target for running
add_custom_target(run
    COMMAND T4CClient
    DEPENDS T4CClient
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running T4CClient"
)
