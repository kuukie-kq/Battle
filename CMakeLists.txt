cmake_minimum_required(VERSION 3.17)
project(Battle)

set(CMAKE_CXX_STANDARD 17)

#打开QT的MOC功能，UI文件处理功能和RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#设置路径
set(Qt5Widgets_DIR /opt/Qt5.9.9/5.9.9/gcc_64/lib/cmake/Qt5Widgets)
#找QT库
find_package(Qt5Widgets REQUIRED NO_DEFAULT_PATH)

add_subdirectory(util/json)
add_subdirectory(util/tcp)
add_subdirectory(util/udp)
add_subdirectory(util/view)
add_subdirectory(rpc)

add_executable(Battle main.cpp qts/view/Login.cpp qts/view/Login.h qts/DivUI.cpp qts/DivUI.h qts/center/Start.cpp qts/center/Start.h qts/view/Hall.cpp qts/view/Hall.h qts/view/Edit.cpp qts/view/Edit.h qts/view/Package.cpp qts/view/Package.h qts/view/Ready.cpp qts/view/Ready.h qts/view/Lobby.cpp qts/view/Lobby.h rpc/view/UserLogin.cpp rpc/view/UserLogin.h)

target_link_libraries(Battle Qt5::Widgets JSON TCP UDP RPC VIEW)
