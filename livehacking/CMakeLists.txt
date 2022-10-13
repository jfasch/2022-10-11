ADD_EXECUTABLE(overview overview.cpp)
TARGET_LINK_LIBRARIES(overview Threads::Threads)

ADD_EXECUTABLE(rule-of-5 rule-of-5.cpp)
ADD_EXECUTABLE(explicit explicit.cpp)

ADD_EXECUTABLE(structured-binding structured-binding.cpp)

ADD_EXECUTABLE(structured-binding-vs-tie structured-binding-vs-tie.cpp)

ADD_EXECUTABLE(auto auto.cpp)

ADD_EXECUTABLE(initializer-list initializer-list.cpp)
ADD_EXECUTABLE(enum enum.cpp)
ADD_EXECUTABLE(const-rvalue-ref const-rvalue-ref.cpp)
ADD_EXECUTABLE(rvalue-ref rvalue-ref.cpp)
ADD_EXECUTABLE(lambda lambda.cpp)
ADD_EXECUTABLE(lambda-this lambda-this.cpp)
ADD_EXECUTABLE(thread-detach thread-detach.cpp)
ADD_EXECUTABLE(thread-race thread-race.cpp)

ADD_SUBDIRECTORY(smart-ptr)

