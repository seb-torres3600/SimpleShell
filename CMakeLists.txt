cmake_minimum_required(VERSION 3.10)
project(MyShell C)

set(CMAKE_C_STANDARD 11)

set(EXECUTABLES
    main.c
    src/readline.c
    src/splitline.c 
    src/executeline.c
    src/builtin.c
    src/launchline.c
    src/helpers.c
)

# Add the executable
add_executable(my_shell ${EXECUTABLES})

# Include directory for header files
target_include_directories(my_shell PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
