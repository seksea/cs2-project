cmake_minimum_required(VERSION 3.22)
project(cs2-project)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC
        # source
        "src/*.c" ,
        "src/*.cpp" ,
        "src/**/*.c" ,
        "src/**/*.cpp" ,
        "src/*.cpp"

        # dependencies
        "dependencies/*.c" ,
        "dependencies/*.cpp" ,
        "dependencies/**/*.c" ,
        "dependencies/**/*.cpp" ,
        "dependencies/*.cpp"
        )

add_library(${PROJECT_NAME} MODULE ${SRC})
find_library(SPDLOG_LIBRARY spdlog.lib PATHS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog")
target_link_libraries(${PROJECT_NAME} "d3d11.lib" "dxgi.lib" "${SPDLOG_LIBRARY}")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")