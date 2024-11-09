# [[ Project ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

# Each internal library can act as a project. You can also just use a normal
# variable name for the same purpose if you wish to.

# Project name cannot contain any spaces. Use underlines instead.
project("Lib_Algorithms"

    VERSION 0.0.1

    DESCRIPTION "A simple implementation of the most used algorithms"

    LANGUAGES CXX)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Project ]]





# [[ Files ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

set(HEADER_FILES

    "${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Sort.hpp")

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Files ]]





# [[ Library ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

add_library(${PROJECT_NAME} INTERFACE)




target_sources(${PROJECT_NAME}

    PUBLIC
    ${HEADER_FILES})


target_include_directories(${PROJECT_NAME}
	
    INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")


target_link_libraries(${PROJECT_NAME}

    PRIVATE
    ${EXTERNAL_LIBRARIES_TO_LINK})

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Library ]]





# [[ Add Internal Libraries ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]

# Include any additional internal libraries that this library may rely on.

target_link_libraries(${PROJECT_NAME}

    PRIVATE)

# [[ ----------------------------------------------------------------------- ]]
# [[ ----------------------------------------------------------------------- ]]
# [[ Add Internal Libraries ]]
