ADD_EXECUTABLE(hello hello.cpp)

ADD_EXECUTABLE(overview overview.cpp)
TARGET_LINK_LIBRARIES(overview Threads::Threads)
