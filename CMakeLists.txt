cmake_minimum_required(VERSION 3.17)
project(Battle)

set(CMAKE_CXX_STANDARD 17)

#打开QT的MOC功能，UI文件处理功能和RCC
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#设置路径
set(Qt5Widgets_DIR /opt/Qt5.9.9/5.9.9/gcc_64/lib/cmake/Qt5Widgets)
#找QT库
find_package(Qt5Widgets REQUIRED NO_DEFAULT_PATH)
#找thread库 thread不是c的标准库
find_package(Threads REQUIRED)

add_subdirectory(cache)
add_subdirectory(rpc)
add_subdirectory(util)

add_executable(Battle main.cpp qts/view/Login.cpp qts/view/Login.h qts/DivUI.cpp qts/DivUI.h qts/center/Start.cpp qts/center/Start.h qts/view/Hall.cpp qts/view/Hall.h qts/view/Edit.cpp qts/view/Edit.h qts/view/Package.cpp qts/view/Package.h qts/view/Ready.cpp qts/view/Ready.h qts/view/Lobby.cpp qts/view/Lobby.h qts/view/Load.cpp qts/view/Load.h qts/view/Play.cpp qts/view/Play.h rpc/view/UserLogin.cpp rpc/view/UserLogin.h)

#添加非标准库
target_link_libraries(Battle pthread)
#添加项目中使用到的库 自定或引用
#注意多级目录情况下，使用add library与target link library时
#不要使用外部需要link的库，不然会出现not found情况
#目录的层数最好区别开来一级XX二级XX_XX三级XX_XX_XX，link下以名称来区分，存在同名问题
#link一串中的先后顺序，也会出现not define的情况
#循环引用问题，一定要注意
#其中需要额外说明的是外部link库与循环引用问题可以在局部地方再细节link，但因为有顺序问题，可能会出现其他错误，还是老老实实在add executable中写一下比较好，可以只写有问题的文件
target_link_libraries(Battle Qt5::Widgets CACHE RPC UTIL)
