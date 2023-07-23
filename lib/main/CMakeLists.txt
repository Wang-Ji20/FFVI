add_library(
  main
  OBJECT
  ffvi.cc
)

set(
  ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:main>
  PARENT_SCOPE
)
