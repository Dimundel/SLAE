add_executable(tridiagonal_test tridiagonal_test.cpp)
target_link_libraries(tridiagonal_test SLAE gtest)

add_executable(csr_test csr_test.cpp)
target_link_libraries(csr_test SLAE gtest)

add_executable(dense_test dense_test.cpp)
target_link_libraries(dense_test SLAE gtest)

add_executable(vector_operations_test vector_operations_test.cpp)
target_link_libraries(vector_operations_test SLAE gtest)