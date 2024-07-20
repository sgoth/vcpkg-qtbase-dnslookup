cmake_minimum_required(VERSION 3.20)
project(dnsc)

set(SRC
  main.cpp
)

# LTO doesn't work with static Qt from vcpkg atm
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_executable(dnsc ${SRC})

target_link_libraries(dnsc PRIVATE
	Qt6::Core
	Qt6::Network
	resolv
)

