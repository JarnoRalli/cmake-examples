project(Content)
include(FetchContent)

message(STATUS "-------------")
message(STATUS "FETCH CONTENT")
message(STATUS "-------------")

#-------------
# Google test
#-------------
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
  GIT_SHALLOW TRUE
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED )
  message(STATUS "\tFetch: Google test")
  FetchContent_Populate(googletest)
  #By default Google Test uses /Mt run-time linking which might cause problems, so we force it to use shared run-time
  set(gtest_force_shared_crt TRUE CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib." FORCE)
  message(STATUS "\t\tsource dir: ${googletest_SOURCE_DIR}")
  message(STATUS "\t\tbinary dir: ${googletest_BINARY_DIR}")
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  message(STATUS "\tFetch: done")
endif()
