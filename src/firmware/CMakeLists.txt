set(NAME firmware)

add_executable(${NAME} main.cpp Connection.cpp Connection.hpp)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${NAME} DESTINATION ${DEPLOY_PREFIX})
