set(NAME firmware)
add_executable(${NAME} main.cpp)

target_link_libraries(
	${NAME}
	PRIVATE raspicam)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${NAME} DESTINATION ${DEPLOY_PREFIX})
