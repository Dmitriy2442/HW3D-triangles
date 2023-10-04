cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(HW3D-triangles)			# Название проекта

set(SOURCE_EXE figures.cpp)		# Установка переменной со списком исходников для исполняемого файла

#set(SOURCE_LIB foo.cpp)			# Тоже самое, но для библиотеки

#add_library(foo STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main)		# Линковка программы с библиотекой