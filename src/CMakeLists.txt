include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/thirdy_party  
)

enable_testing()

add_library(dimmerlib
  Dimmer.cpp
)