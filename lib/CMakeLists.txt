add_subdirectory(main)
add_subdirectory(common)

set(
  THIRD_PARTY_DEPENDENCIES
  absl::base
  absl::log
  absl::check
  yyjson
)

add_library(
  FFVI
  STATIC
  ${ALL_OBJECT_FILES}
)

target_link_libraries(
  FFVI
  ${THIRD_PARTY_DEPENDENCIES}
)

target_include_directories(
  FFVI
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
