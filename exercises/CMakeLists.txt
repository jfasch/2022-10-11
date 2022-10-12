ADD_EXECUTABLE(
  exercises-suite

  dummy.cpp
  thread.cpp
  bag-copy-insert-find-suite.cpp
  bag-copy-remove-suite.cpp
)
TARGET_LINK_LIBRARIES(exercises-suite gtest_main)
