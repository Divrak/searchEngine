cmake_minimum_required (VERSION 3.8...3.28)

project ("searchEngine" VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(INC_PATH ${CMAKE_SOURCE_DIR}/include)
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(SRC ${SRC_PATH}/searchEngine.cpp)
set(HDRS ${INC_PATH}/searchEngine.h)


	option(EXAMPLE_USE_EXTERNAL_JSON "Use an external JSON library" OFF)
	set(JSON_BuildTests OFF CACHE INTERNAL "")
	include(FetchContent)

	FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
	FetchContent_MakeAvailable(json)

add_executable (searchEngine ${SRC} ${HDRS})
target_include_directories(searchEngine PUBLIC ${INC_PATH})

	target_link_libraries(searchEngine PRIVATE nlohmann_json::nlohmann_json)
