cmake_minimum_required(VERSION 3.12)
project(MySFMLApp)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(
    sfml-app 
    main.cpp
    Utils/VectorUtils.cpp
    )

target_link_libraries(
    sfml-app 
    sfml-graphics 
    sfml-window 
    sfml-system
    )