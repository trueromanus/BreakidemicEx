cmake_minimum_required(VERSION 3.16)

project(Breakidemic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick LinguistTools Concurrent Qml QuickControls2 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick LinguistTools Network WebSockets Concurrent Qml QuickControls2 REQUIRED)

qt_add_executable(breakidemic
    WIN32 MACOSX_BUNDLE

    main.cpp

    qml-box2d/box2dbody.cpp
    qml-box2d/box2dbody.h
    qml-box2d/box2dcontact.cpp
    qml-box2d/box2dcontact.h
    qml-box2d/box2ddebugdraw.cpp
    qml-box2d/box2ddebugdraw.h
    qml-box2d/box2ddistancejoint.cpp
    qml-box2d/box2ddistancejoint.h
    qml-box2d/box2dfixture.cpp
    qml-box2d/box2dfixture.h
    qml-box2d/box2dfrictionjoint.cpp
    qml-box2d/box2dfrictionjoint.h
    qml-box2d/box2dgearjoint.cpp
    qml-box2d/box2dgearjoint.h
    qml-box2d/box2djoint.cpp
    qml-box2d/box2djoint.h
    qml-box2d/box2dmotorjoint.cpp
    qml-box2d/box2dmotorjoint.h
    qml-box2d/box2dmousejoint.cpp
    qml-box2d/box2dmousejoint.h
    qml-box2d/box2dplugin.cpp
    qml-box2d/box2dplugin.h
    qml-box2d/box2dprismaticjoint.cpp
    qml-box2d/box2dprismaticjoint.h
    qml-box2d/box2dpulleyjoint.cpp
    qml-box2d/box2dpulleyjoint.h
    qml-box2d/box2draycast.cpp
    qml-box2d/box2draycast.h
    qml-box2d/box2drevolutejoint.cpp
    qml-box2d/box2drevolutejoint.h
    qml-box2d/box2dropejoint.cpp
    qml-box2d/box2dropejoint.h
    qml-box2d/box2dweldjoint.cpp
    qml-box2d/box2dweldjoint.h
    qml-box2d/box2dwheeljoint.cpp
    qml-box2d/box2dwheeljoint.h
    qml-box2d/box2dworld.cpp
    qml-box2d/box2dworld.h

    Brekidemic/ballcomponent.h Brekidemic/ballcomponent.cpp
    Brekidemic/paddlecomponent.h Brekidemic/paddlecomponent.cpp
    Brekidemic/wallcomponent.h Brekidemic/wallcomponent.cpp
    Brekidemic/localstorage.h Brekidemic/localstorage.cpp

    vintage/entityitem.h vintage/entityitem.cpp
    vintage/entitymanager.h vintage/entitymanager.cpp
    vintage/scene.h vintage/scene.cpp
    vintage/playerinputcontroller.h vintage/playerinputcontroller.cpp

    qml.qrc
)

set_target_properties(breakidemic PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(breakidemic PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(breakidemic PRIVATE Qt6::Quick PUBLIC Box2D)
target_link_libraries(breakidemic PRIVATE Qt6::Concurrent)
target_link_libraries(breakidemic PRIVATE Qt6::Qml)
target_link_libraries(breakidemic PRIVATE Qt6::QuickControls2)

add_subdirectory(Box2D)
