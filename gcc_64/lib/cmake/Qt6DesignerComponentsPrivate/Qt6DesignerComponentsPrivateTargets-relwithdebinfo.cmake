#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::DesignerComponentsPrivate" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::DesignerComponentsPrivate APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::DesignerComponentsPrivate PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6DesignerComponents.so.6.2.4"
  IMPORTED_SONAME_RELWITHDEBINFO "libQt6DesignerComponents.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::DesignerComponentsPrivate )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::DesignerComponentsPrivate "${_IMPORT_PREFIX}/lib/libQt6DesignerComponents.so.6.2.4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)