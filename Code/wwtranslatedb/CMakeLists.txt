set (wwtranslatedb_headers
        stringtwiddler.h
        tdbcategories.h
        tdbcategory.h
        translatedb.h
        translatedbids.h
        translateobj.h)

set (wwtranslatedb_sources
        stringtwiddler.cpp
        tdbcategory.cpp
        translatedb.cpp
        translateobj.cpp)

add_library(wwtranslatedb STATIC ${wwtranslatedb_sources} ${wwtranslatedb_headers})
set_target_properties(wwtranslatedb PROPERTIES LINKER_LANGUAGE CXX)