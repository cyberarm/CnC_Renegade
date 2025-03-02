set (wwsaveload_headers
        definition.h
        definitionclassids.h
        definitionfactory.h
        definitionfactorymgr.h
        definitionmgr.h
        editable.h
        parameter.h
        parameterlist.h
        parametertypes.h
        persist.h
        persistfactory.h
        pointerremap.h
        postloadable.h
        saveload.h
        saveloadids.h
        saveloadstatus.h
        saveloadsubsystem.h
        simpledefinitionfactory.h
        simpleparameter.h
        twiddler.h
        wwsaveload.h)

set (wwsaveload_sources
        definition.cpp
        definitionfactory.cpp
        definitionfactorymgr.cpp
        definitionmgr.cpp
        parameter.cpp
        persistfactory.cpp
        pointerremap.cpp
        saveload.cpp
        saveloadstatus.cpp
        saveloadsubsystem.cpp
        twiddler.cpp
        wwsaveload.cpp)

add_library(wwsaveload STATIC ${wwsaveload_sources} ${wwsaveload_headers})
set_target_properties(wwsaveload PROPERTIES LINKER_LANGUAGE CXX)