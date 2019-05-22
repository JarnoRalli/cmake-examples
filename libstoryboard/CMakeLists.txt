# Define a target and add source files to the target
set(MYLIBNAME "libstoryboard")
add_library (${MYLIBNAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/storyboard.cpp)

# Add directories to the target
# PRIVATE and PUBLIC items will populate the INCLUDE_DIRECTORIES property of target
# PUBLIC and INTERFACE items will populate the INTERFACE_INCLUDE_DIRECTORIES property of target
target_include_directories (${MYLIBNAME}
			PUBLIC 
				$<INSTALL_INTERFACE:include>
				$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
			PRIVATE
				${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Compile features for the target -> these get propagated to anyone linking against this library
target_compile_features (${MYLIBNAME} PRIVATE cxx_std_14)

# Export the target
include(GNUInstallDirs)
# Installs a target
install(TARGETS ${MYLIBNAME}
	EXPORT ${MYLIBNAME}-export
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
# Generates and installs a CMake file to import a target
install(EXPORT ${MYLIBNAME}-export
	FILE
		${MYLIBNAME}Targets.cmake
	DESTINATION
		${CMAKE_INSTALL_LIBDIR}/cmake)

