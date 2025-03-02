set (binkmovie_headers
        BINKMovie.h
        subtitle.h
        subtitlemanager.h
        subtitleparser.h)

set (binkmovie_sources
        BINKMovie.cpp
        subtitle.cpp
        subtitlemanager.cpp
        subtitleparser.cpp)

add_library(binkmovie STATIC ${binkmovie_sources} ${binkmovie_headers})
set_target_properties(binkmovie PROPERTIES LINKER_LANGUAGE CXX)