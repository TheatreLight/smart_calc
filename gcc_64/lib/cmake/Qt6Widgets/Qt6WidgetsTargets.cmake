# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.19)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget Qt6::Widgets Qt6::WidgetsPrivate)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target Qt6::Widgets
add_library(Qt6::Widgets SHARED IMPORTED)

set_target_properties(Qt6::Widgets PROPERTIES
  COMPATIBLE_INTERFACE_STRING "QT_MAJOR_VERSION"
  INTERFACE_COMPILE_DEFINITIONS "QT_WIDGETS_LIB"
  INTERFACE_COMPILE_OPTIONS "-fPIC"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/QtWidgets;${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Qt6::Core;Qt6::Gui"
  INTERFACE_QT_MAJOR_VERSION "6"
  INTERFACE_SOURCES "\$<\$<BOOL:\$<TARGET_PROPERTY:QT_CONSUMES_METATYPES>>:${_IMPORT_PREFIX}/lib/metatypes/qt6widgets_relwithdebinfo_metatypes.json>"
  MODULE_PLUGIN_TYPES "styles"
  QT_DISABLED_PRIVATE_FEATURES "style_mac;style_windowsvista;style_android"
  QT_DISABLED_PUBLIC_FEATURES ""
  QT_ENABLED_PRIVATE_FEATURES "gtk3;style_fusion;style_windows;effects;widgettextcontrol"
  QT_ENABLED_PUBLIC_FEATURES "style_stylesheet;itemviews;treewidget;listwidget;tablewidget;abstractbutton;commandlinkbutton;datetimeedit;stackedwidget;textbrowser;splashscreen;splitter;label;formlayout;lcdnumber;menu;lineedit;radiobutton;spinbox;tabbar;tabwidget;combobox;fontcombobox;checkbox;pushbutton;toolbutton;toolbar;toolbox;groupbox;buttongroup;mainwindow;dockwidget;mdiarea;resizehandler;statusbar;menubar;contextmenu;progressbar;abstractslider;slider;scrollbar;dial;scrollarea;scroller;graphicsview;graphicseffect;textedit;syntaxhighlighter;rubberband;tooltip;statustip;sizegrip;calendarwidget;keysequenceedit;dialog;dialogbuttonbox;messagebox;colordialog;filedialog;fontdialog;progressdialog;inputdialog;errormessage;wizard;listview;tableview;treeview;datawidgetmapper;columnview;completer;fscompleter;undoview"
  QT_QMAKE_PRIVATE_CONFIG ""
  QT_QMAKE_PUBLIC_CONFIG ""
  QT_QMAKE_PUBLIC_QT_CONFIG ""
  _qt_config_module_name "widgets"
  _qt_module_has_headers "ON"
  _qt_module_include_name "QtWidgets"
  _qt_module_interface_name "Widgets"
)

# Create imported target Qt6::WidgetsPrivate
add_library(Qt6::WidgetsPrivate INTERFACE IMPORTED)

set_target_properties(Qt6::WidgetsPrivate PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/QtWidgets/6.2.4;${_IMPORT_PREFIX}/include/QtWidgets/6.2.4/QtWidgets"
  INTERFACE_LINK_LIBRARIES "Qt6::CorePrivate;Qt6::GuiPrivate;Qt6::Widgets"
  _qt_config_module_name "widgets_private"
)

if(CMAKE_VERSION VERSION_LESS 3.1.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.1.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/Qt6WidgetsTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# Make sure the targets which have been exported in some other
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "Qt6::Core" "Qt6::Gui" "Qt6::CorePrivate" "Qt6::GuiPrivate" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
