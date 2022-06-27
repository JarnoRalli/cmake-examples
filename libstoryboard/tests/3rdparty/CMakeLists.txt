# Here we use FetchContent in order to download and build 3rd party
# Dependencies. FetchContent downloads source code of a 3rd party
# library immediately, and exposes the contents (e.g. targets)
# so that these can be used in commands like:
# - file()
# - target_link_libraries()

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

FetchContent_MakeAvailable(googletest)
