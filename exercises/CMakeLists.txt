ADD_EXECUTABLE(
  exercises-suite

  dummy.cpp
  thread.cpp
)
TARGET_LINK_LIBRARIES(exercises-suite gtest_main)
