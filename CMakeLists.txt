# Điều kiện phiên bản nhỏ nhất của CMake

cmake_minimum_required(VERSION 2.8.12)
 
# Tên project

project (SnakeGame)
 
# Thêm thư mục chứa các file header (.h)

include_directories(include)
 
# Thêm một tập các file source

file(GLOB SOURCES "src/*.cpp" "include/*.cpp")
 
#
# Thư viện bao gồm những source nào.
# Loại thư viện là STATIC (tĩnh)
# Tên thư viện có thể khác tên *project*

#add_library(greetings_enjavi STATIC ${SOURCES})

# tao file run

add_executable(snakegame ${SOURCES})