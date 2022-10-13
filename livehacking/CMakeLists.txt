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
ADD_EXECUTABLE(perfect-forwarding perfect-forwarding.cpp)
ADD_EXECUTABLE(lambda lambda.cpp)
ADD_EXECUTABLE(lambda-this lambda-this.cpp)
ADD_EXECUTABLE(static-inline static-inline.cpp)
# ADD_EXECUTABLE(constexpr-infinite constexpr-infinite.cpp)

ADD_SUBDIRECTORY(smart-ptr)
ADD_SUBDIRECTORY(threads)

