set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_compile_options(
	"-Wall"
	"-Wextra"
	"-Wconversion"
	"-Werror"
)

SET(GCC_COVERAGE_COMPILE_FLAGS "-unresolved-symbols=ignore-all")
SET(GCC_COVERAGE_LINK_FLAGS    "-unresolved-symbols=ignore-all")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

add_subdirectory(firmware)
