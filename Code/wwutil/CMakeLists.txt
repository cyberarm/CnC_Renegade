set (wwutils_headers
    mathutil.h
    miscutil.h
    stackdump.h)

set (wwutils_sources
    mathutil.cpp
    miscutil.cpp
    stackdump.cpp)

add_library(wwutils STATIC ${wwutils_sources} ${wwutils_headers})
set_target_properties(wwutils PROPERTIES LINKER_LANGUAGE CXX)