cmake_minimum_required(VERSION 3.24)
project(ComputerRoom_Reservation_System)

set(CMAKE_CXX_STANDARD 17)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} Identity.h Student.h Teacher.h Manager.h globalFile.h)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()