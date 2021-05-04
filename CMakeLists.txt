cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)
project(mpi_fiddle LANGUAGES CXX VERSION 0.1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(MPI REQUIRED)

add_executable(mpi_fiddle main.cxx MPI.cxx MPI.hxx)
target_link_libraries(mpi_fiddle PRIVATE MPI::MPI_CXX)
