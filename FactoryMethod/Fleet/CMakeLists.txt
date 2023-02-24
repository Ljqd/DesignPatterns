# CMakeList.txt : CMake project for DesignPattern_FactoryMethod_FeightTransportation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPattern_FactoryMethod_Fleet")

# Add source to this project's executable.

add_executable (
    DesignPattern_FactoryMethod_Fleet "main.cpp"
    "Fleet.h" "Fleet.cpp" 
    "Mercedes.h" "Mercedes.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DesignPattern_FactoryMethod_Fleet PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
