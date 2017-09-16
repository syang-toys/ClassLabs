cmake_minimum_required(VERSION 3.7)
project(RobotLight)

set(CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/libs")

set(SOURCE_FILES main.cpp view/MapRender.cpp view/MapRender.h controller/Controller.cpp controller/Controller.h
        model/Robot.cpp model/Robot.h model/Light.cpp model/Light.h model/Map.cpp model/Map.h view/MapView.cpp view/MapView.h
        utils/utils.cpp utils/utils.h utils/GameBuilder.cpp utils/GameBuilder.h controller/Rule.cpp controller/Rule.h
        controller/GameAdapter.cpp controller/GameAdapter.h controller/Command.h controller/Command.cpp model/Subject.h
        model/Observer.h utils/Record.cpp utils/Record.h utils/Timer.h utils/Timer.cpp utils/Rank.h utils/Rank.cpp controller/IController.h)
add_executable(RobotLight ${SOURCE_FILES})