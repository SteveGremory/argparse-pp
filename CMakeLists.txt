cmake_minimum_required(VERSION 3.22)
project(argparse-pp)

set(CMAKE_CXX_STANDARD 20)

add_library(ArgParsePP 
    lib/argparse.cc
    lib/lexer/lexer.cc
)
target_include_directories(ArgParsePP PUBLIC
    lib/
)

add_executable(Main bin/main.cc)
target_include_directories(Main PUBLIC bin/)
target_link_libraries(Main PRIVATE ArgParsePP)
