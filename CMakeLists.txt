cmake_minimum_required (VERSION 3.28)

project (searchEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(INC_PATH ${CMAKE_SOURCE_DIR}/include)
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH ${CMAKE_SOURCE_DIR}/tests)

set(SRC ${SRC_PATH}/searchEngine.cpp ${SRC_PATH}/ConverterJSON.cpp ${SRC_PATH}/invertedIndex.cpp)
set(HDRS ${INC_PATH}/searchEngine.h ${INC_PATH}/ConverterJSON.h ${INC_PATH}/invertedIndex.h)
set(TESTS ${TEST_PATH}/testConverterJSON.h ${TEST_PATH}/testInvertedIndex.h)

include(FetchContent)

	#nlohmann json region
	option(EXAMPLE_USE_EXTERNAL_JSON "Use an external JSON library" OFF)
	set(JSON_BuildTests OFF CACHE INTERNAL "")

	FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
	FetchContent_MakeAvailable(json)
	#end region

    #google test region
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	set(gtest_disable_pthreads ON)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	#end region

file(COPY ${CMAKE_SOURCE_DIR}/resources
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/requests.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/config.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/answer.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable (searchEngine ${SRC} ${TESTS} ${HDRS})
target_include_directories(searchEngine PUBLIC ${INC_PATH} ${TEST_PATH})

	#nlohmann json region
	target_link_libraries(searchEngine PRIVATE nlohmann_json::nlohmann_json)
	#end region

	#google test region
	target_link_libraries(searchEngine PRIVATE GTest::gtest_main)
	include(GoogleTest)
	gtest_discover_tests(searchEngine)
	#end region
