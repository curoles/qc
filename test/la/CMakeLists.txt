add_executable(test_vector
  ${CMAKE_CURRENT_SOURCE_DIR}/vector.cpp
)
add_test(NAME test-vector COMMAND test_vector)
