cmake_minimum_required(VERSION 3.2)
project(Castle3DEditor)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(EXECUTABLE_NAME Castle3DEditor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/main.cc
  
    ${PROJECT_SOURCE_DIR}/src/oglshader.h
    ${PROJECT_SOURCE_DIR}/src/oglshader.cc
    
    ${PROJECT_SOURCE_DIR}/src/camera.h
    ${PROJECT_SOURCE_DIR}/src/camera.cc
    
	${PROJECT_SOURCE_DIR}/src/buildcubes.h
	${PROJECT_SOURCE_DIR}/src/buildcubes.cc
	
    ${PROJECT_SOURCE_DIR}/src/ogltexture.h
	${PROJECT_SOURCE_DIR}/src/ogltexture.cc
	
	${PROJECT_SOURCE_DIR}/src/createspheremesh.h
	${PROJECT_SOURCE_DIR}/src/createspheremesh.cc

    ${PROJECT_SOURCE_DIR}/src/createconemesh.h
	${PROJECT_SOURCE_DIR}/src/createconemesh.cc

    ${PROJECT_SOURCE_DIR}/src/createcylindermesh.h
	${PROJECT_SOURCE_DIR}/src/createcylindermesh.cc)
  
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLBINDING REQUIRED)
find_package(GLM REQUIRED)
find_package(SFML 2 COMPONENTS graphics system window REQUIRED)

source_group("sources" FILES ${SOURCE_FILES})
source_group("shaders" FILES "shaders/simpleshader.frag.glsl" "shaders/simpleshader.vert.glsl")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

if(SDL2_FOUND AND OPENGL_FOUND AND GLBINDING_FOUND AND GLM_FOUND AND SFML_FOUND)
  include_directories(${PROJECT_SOURCE_DIR}/src/}
                      ${SDL2_INCLUDE_DIR} ${GLBINDING_INCLUDE_DIRS} 
                      ${GLM_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${SFML_INCLUDE_DIR})
  
  target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARY}  
                        ${GLOBJECTS_LIBRARIES} ${GLBINDING_LIBRARIES} 
                        ${OPENGL_LIBRARIES} ${SFML_LIBRARIES})
endif()
