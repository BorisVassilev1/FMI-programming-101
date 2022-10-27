cmake_minimum_required(VERSION 3.24)
project("pusheen")

add_compile_options(-Wall -c -D_THREAD_SAFE)
add_executable(pusheen main.cpp ./draw/sdlwrapper.cpp)
set_target_properties(pusheen PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ../
	)

# find_package(NanoSVG REQUIRED)
add_subdirectory(./nanosvg)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

# execute_process(COMMAND "sdl2-config --cflags --libs" OUTPUT_VARIABLE sdl2flags)

target_link_libraries(pusheen SDL2_image SDL2_ttf)
target_link_libraries(pusheen nanosvg nanosvgrast ${SDL2_LIBRARIES})

target_link_directories(pusheen PRIVATE ./draw/)


target_include_directories(pusheen PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(pusheen PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
target_include_directories(pusheen PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
