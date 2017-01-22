cmake_minimum_required(VERSION 2.9)
project(Arm)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB CXX_FILES "src/Arm.cpp")
add_executable(Arm ${CXX_FILES})

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Arm ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

install(TARGETS Arm RUNTIME DESTINATION bin)

