cmake_minimum_required (VERSION 3.28)

project (searchEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INC_PATH ${CMAKE_SOURCE_DIR}/include)
set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
set(TEST_PATH ${CMAKE_SOURCE_DIR}/tests)

set(SRC ${SRC_PATH}/searchEngine.cpp ${SRC_PATH}/ConverterJSON.cpp ${SRC_PATH}/invertedIndex.cpp)
set(HDRS ${INC_PATH}/searchEngine.h ${INC_PATH}/ConverterJSON.h ${INC_PATH}/invertedIndex.h)
#set(TESTS ${TEST_PATH}/testConverterJSON.h ${TEST_PATH}/testInvertedIndex.h)

include(FetchContent)

	#nlohmann json region
	option(EXAMPLE_USE_EXTERNAL_JSON "Use an external JSON library" OFF)
	set(JSON_BuildTests OFF CACHE INTERNAL "")

	FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
	FetchContent_MakeAvailable(json)
	#end region

	#google test region
	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
	include(GoogleTest)
	#google test end region


file(COPY ${CMAKE_SOURCE_DIR}/resources
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/requests.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/config.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_SOURCE_DIR}/answer.json
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable (searchEngine ${SRC} ${HDRS})
target_include_directories(searchEngine PUBLIC ${INC_PATH} ${TEST_PATH})

target_link_libraries(searchEngine PRIVATE nlohmann_json::nlohmann_json PUBLIC GTest::gtest_main)


	#google test region
	gtest_discover_tests(searchEngine) 
	set_tests_properties(PROPERTIES TIMEOUT 40)
	#google test end region

