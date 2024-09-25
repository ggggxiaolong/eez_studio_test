cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99) #C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17) #C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test)
find_package(SQLite3 REQUIRED)
find_package(eclipse-paho-mqtt-c REQUIRED)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(lvgl)
# 添加 lvgl 头文件到 src
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})
add_subdirectory(src/ui)
# 链接动态库
link_directories(${PROJECT_SOURCE_DIR}/libs)

add_executable(${PROJECT_NAME} main.c mouse_cursor_icon.c)

# include(${CMAKE_CURRENT_LIST_DIR}/lvgl/tests/FindLibDRM.cmake)
# include_directories(${Libdrm_INCLUDE_DIRS})

# find_package(SDL2)
# find_package(SDL2_image)
# include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} lvgl ui lvgl::thorvg ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${Libdrm_LIBRARIES} m pthread
    libsqlite3.so libpaho-mqtt3c.so)
# add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main DEPENDS main)

