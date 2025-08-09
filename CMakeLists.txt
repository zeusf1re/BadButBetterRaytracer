cmake_minimum_required(VERSION 3.15)
project(BetterButBadRaytraiser)

# Настройка стандартов C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск SFML
find_package(SFML COMPONENTS Graphics Window System REQUIRED)

# Исходные файлы
file(GLOB SOURCES "src/*.cpp")

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

# Подключение SFML
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System
)

# Копирование ресурсов (опционально)
if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
endif()
