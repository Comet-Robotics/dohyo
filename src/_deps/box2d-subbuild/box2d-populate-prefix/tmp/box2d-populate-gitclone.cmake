# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt" AND EXISTS "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt" AND
  "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/evanwu03/projects/dohyo-template/src/_deps/box2d-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/erincatto/box2d.git" "box2d-src"
    WORKING_DIRECTORY "/home/evanwu03/projects/dohyo-template/src/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/erincatto/box2d.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "f0763aca7d4dfa8f1c19c2c4a9e66fa6e93ea32e" --
  WORKING_DIRECTORY "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'f0763aca7d4dfa8f1c19c2c4a9e66fa6e93ea32e'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/evanwu03/projects/dohyo-template/src/_deps/box2d-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt" "/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/evanwu03/projects/dohyo-template/src/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt'")
endif()
