cmake_minimum_required(VERSION 2.8)
#project(Demo1)
aux_source_directory(. DIR)
add_subdirectory(math)
add_executable(main ${DIR})

#This line links main with lib MathFunctions, check ./math/CMakeLists.txt to see how to make a lib.
target_link_libraries(main MathFunctions)


#how to deploy tests with cmake
enable_testing()
add_test(test_run main 5 2)
set_tests_properties(test_run 
	PROPERTIES PASS_REGULAR_EXPRESSION "7")

macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} main ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test(5 6 "11")
do_test(10 11 "21")
	
