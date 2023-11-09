cmake_minimum_required(VERSION 3.14)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(HW3D-triangles)			# Название проекта

# The beginning of first google test part ------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# The end of google test part (for now) ---------------------------------------------------------------------

set(SOURCE_EXE main.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB figures.cpp intersection.cpp)			# Тоже самое, но для библиотеки

add_library(geom STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main geom)		# Линковка программы с библиотекой

# Google test part ------------------------------------------------------------------------------------------

enable_testing()

add_executable(
	3D_operations_test
	3D_operations_test.cpp
	figures.cpp
	geometric_operations.cpp
	intersection.cpp
)
target_link_libraries(
	3D_operations_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(3D_operations_test)