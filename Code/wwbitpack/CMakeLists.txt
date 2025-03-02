set (wwbitpack_headers
        BitPacker.h
        bitpackids.h
        bitstream.h
        encoderlist.h
        encodertypeentry.h)

set (wwbitpack_sources
        BitPacker.cpp
        bitstream.cpp
        encoderlist.cpp
        encodertypeentry.cpp)

add_library(wwbitpack STATIC ${wwbitpack_sources} ${wwbitpack_headers})
set_target_properties(wwbitpack PROPERTIES LINKER_LANGUAGE CXX)