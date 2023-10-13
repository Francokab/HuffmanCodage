cmake_minimum_required(VERSION 3.12)
project(HuffmanCodage VERSION 0.1.0 LANGUAGES C CXX)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#set(CMAKE_CXX_STANDARD 17)

# Specify the source and include directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEXT_DIR ${CMAKE_SOURCE_DIR}/text)

# Add all source files from the "src" directory to the project
file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)

# Add all header files from the "include" directory to the project
file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.h)

file(GLOB TEXT_FILES ${TEXT_DIR}/*.txt)

file(COPY ${TEXT_FILES} DESTINATION text)

# Add the executable target and include directories
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Copy the "text" folder to the build directory
#configure_file(${TEXT_FILES} ${CMAKE_BINARY_DIR} COPYONLY)
