# CMakeList.txt : CMake project for EmbeddableArchitecture, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (EAT "EATest.cpp")
target_link_libraries (EAT EA)

# TODO: Add tests and install targets if needed.
