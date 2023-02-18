add_executable(tridiagonal_test tridiagonal_test.cpp)
target_link_libraries(tridiagonal_test SLAE gtest)

add_executable(csr_test csr_test.cpp)
target_link_libraries(csr_test SLAE gtest)

# add_test(NAME tridiagonal_test COMMAND tridiagonal_test)