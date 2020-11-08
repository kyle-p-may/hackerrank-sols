cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(HackerrankSolutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories("/home/kylemay/Documents/career/hackerrank-sols/")
file(GLOB_RECURSE test_files "../*_test.cpp")
file(GLOB_RECURSE main_files "../*_main.cpp")

enable_testing()

foreach(test_file ${test_files})
    
    get_filename_component(test_name ${test_file} NAME_WE)
    string(REPLACE "_test.cpp" "" test_name ${test_name})

    add_executable(${test_name}_unit.out ${test_file})

    add_test(
        NAME ${test_name}
        COMMAND ${test_name}_unit.out
    )

endforeach(test_file ${test_files})

foreach(test_file ${main_files})
    
    get_filename_component(test_name ${test_file} NAME_WE)
    string(REPLACE "_main.cpp" "" test_name ${test_name})

    add_executable(${test_name}.out ${test_file})

    add_test(
        NAME ${test_name}
        COMMAND ${test_name}.out
    )

endforeach(test_file ${test_files})
