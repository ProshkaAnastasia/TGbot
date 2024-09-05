#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SOCI::soci_core" for configuration "Release"
set_property(TARGET SOCI::soci_core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_core.4.1.0.dylib"
  IMPORTED_SONAME_RELEASE "/usr/local/lib/libsoci_core.4.1.dylib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_core )
list(APPEND _cmake_import_check_files_for_SOCI::soci_core "${_IMPORT_PREFIX}/lib/libsoci_core.4.1.0.dylib" )

# Import target "SOCI::soci_core_static" for configuration "Release"
set_property(TARGET SOCI::soci_core_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_core_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_core.a"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_core_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_core_static "${_IMPORT_PREFIX}/lib/libsoci_core.a" )

# Import target "SOCI::soci_empty" for configuration "Release"
set_property(TARGET SOCI::soci_empty APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_empty PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_empty.4.1.0.dylib"
  IMPORTED_SONAME_RELEASE "/usr/local/lib/libsoci_empty.4.1.dylib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_empty )
list(APPEND _cmake_import_check_files_for_SOCI::soci_empty "${_IMPORT_PREFIX}/lib/libsoci_empty.4.1.0.dylib" )

# Import target "SOCI::soci_empty_static" for configuration "Release"
set_property(TARGET SOCI::soci_empty_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_empty_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_empty.a"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_empty_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_empty_static "${_IMPORT_PREFIX}/lib/libsoci_empty.a" )

# Import target "SOCI::soci_mysql" for configuration "Release"
set_property(TARGET SOCI::soci_mysql APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_mysql PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_mysql.4.1.0.dylib"
  IMPORTED_SONAME_RELEASE "/usr/local/lib/libsoci_mysql.4.1.dylib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_mysql )
list(APPEND _cmake_import_check_files_for_SOCI::soci_mysql "${_IMPORT_PREFIX}/lib/libsoci_mysql.4.1.0.dylib" )

# Import target "SOCI::soci_mysql_static" for configuration "Release"
set_property(TARGET SOCI::soci_mysql_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_mysql_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_mysql.a"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_mysql_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_mysql_static "${_IMPORT_PREFIX}/lib/libsoci_mysql.a" )

# Import target "SOCI::soci_sqlite3" for configuration "Release"
set_property(TARGET SOCI::soci_sqlite3 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_sqlite3 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_sqlite3.4.1.0.dylib"
  IMPORTED_SONAME_RELEASE "/usr/local/lib/libsoci_sqlite3.4.1.dylib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_sqlite3 )
list(APPEND _cmake_import_check_files_for_SOCI::soci_sqlite3 "${_IMPORT_PREFIX}/lib/libsoci_sqlite3.4.1.0.dylib" )

# Import target "SOCI::soci_sqlite3_static" for configuration "Release"
set_property(TARGET SOCI::soci_sqlite3_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SOCI::soci_sqlite3_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsoci_sqlite3.a"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_sqlite3_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_sqlite3_static "${_IMPORT_PREFIX}/lib/libsoci_sqlite3.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
