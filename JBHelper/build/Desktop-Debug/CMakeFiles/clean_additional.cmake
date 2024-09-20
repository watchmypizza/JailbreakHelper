# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/JBHelper_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/JBHelper_autogen.dir/ParseCache.txt"
  "JBHelper_autogen"
  )
endif()
