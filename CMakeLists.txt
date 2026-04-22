cmake_minimum_required(VERSION 3.10)
project(problem_102_code CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(code main.cpp)
# Place the executable in project root so OJ can find it
set_target_properties(code PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
