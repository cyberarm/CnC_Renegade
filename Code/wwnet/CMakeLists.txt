set (wwnet_headers
        BWBalance.h
        connect.h
        fromaddress.h
        msgstat.h
        msgstatlist.h
        msgstatlistgroup.h
        netstats.h
        netutil.h
        networkobject.h
        networkobjectfactory.h
        networkobjectfactorymgr.h
        networkobjectmgr.h
        packetmgr.h
        packettype.h
        rhost.h
        singlepl.h
        wwpacket.h)

set (wwnet_sources
        BWBalance.cpp
        connect.cpp
        lan.cpp
        msgstat.cpp
        msgstatlist.cpp
        msgstatlistgroup.cpp
        netstats.cpp
        netutil.cpp
        networkobject.cpp
        networkobjectfactory.cpp
        networkobjectfactorymgr.cpp
        networkobjectmgr.cpp
        packetmgr.cpp
        rhost.cpp
        singlepl.cpp
        wwpacket.cpp)

add_library(wwnet STATIC ${wwnet_sources} ${wwnet_headers})
set_target_properties(wwnet PROPERTIES LINKER_LANGUAGE CXX)