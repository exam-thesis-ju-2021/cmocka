# Install script for directory: C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xpkgconfigx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/cmocka.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cmocka" TYPE FILE FILES
    "C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/cmocka-config.cmake"
    "C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/cmocka-config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/include/cmake_install.cmake")
  include("C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/src/cmake_install.cmake")
  include("C:/Users/Warcaith/Documents/workspace/thesis/cmocka/out/build/x64-Debug/_deps/cmocka-build/doc/cmake_install.cmake")

endif()

