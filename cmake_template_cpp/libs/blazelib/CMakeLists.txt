add_library(blazelib SHARED src/blaze.cpp)
target_include_directories(blazelib
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)
