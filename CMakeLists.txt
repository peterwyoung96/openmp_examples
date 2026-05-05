cmake_minimum_required(VERSION 3.16)

project(OpenMPExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

# Common function to reduce repetition
function(add_openmp_example name file)
    add_executable(${name} ${file})

    if(OpenMP_CXX_FOUND)
        target_link_libraries(${name} PUBLIC OpenMP::OpenMP_CXX)
    endif()
endfunction()

# Add your examples
add_openmp_example(example001 src/example001_helloWorld.cpp)
add_openmp_example(example002 src/example002_parallelLoop.cpp)
add_openmp_example(example003 src/example003_reduction.cpp)
add_openmp_example(example004 src/example004_critical.cpp)
add_openmp_example(example005 src/example005_privateVar.cpp)
add_openmp_example(example006 src/example006_ordered.cpp)
add_openmp_example(example007 src/example007_timing.cpp)
add_openmp_example(example008 src/example008_particleSimulation.cpp)