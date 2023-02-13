add_executable(tridiagonal_test tridiagonal_test.cpp)

target_link_libraries(tridiagonal_test SLAE gtest)

target_include_directories(tridiagonal_test PUBLIC SLAE)

add_test(NAME tridiagonal_gtest COMMAND tridiagonal_test)