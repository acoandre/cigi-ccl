cmake_minimum_required(VERSION 2.8)
project(tinyxml)

file(GLOB PKG_SRC "*.cpp")
file(GLOB PKG_INC "*.h*")

add_definitions(-DTINYXML_USE_STL)
add_definitions(-DTIXML_USE_STL)
add_library(tinyxml ${PKG_SRC})

install(TARGETS tinyxml
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include)