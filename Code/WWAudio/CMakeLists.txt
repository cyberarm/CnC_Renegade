set (wwaudio_headers
        AABTreeSoundCullClass.h
        AudibleSound.h
        AudioEvents.h
        AudioSaveLoad.h
        FilteredSound.h
        Listener.h
        LogicalListener.h
        LogicalSound.h
        PriorityVector.h
        Sound3D.h
        SoundBuffer.h
        SoundChunkIDs.h
        SoundCullObj.h
        SoundDefinition.h
        SoundPseudo3D.h
        SoundScene.h
        SoundSceneObj.h
        StaticSoundCullObj.h
        Threads.h
        Utils.h
        WWAudio.h
        listenerhandle.h
        sound2dhandle.h
        sound3dhandle.h
        soundhandle.h
        soundstreamhandle.h)

set (wwaudio_sources
        AudibleSound.cpp
        AudioEvents.cpp
        AudioSaveLoad.cpp
        FilteredSound.cpp
        Listener.cpp
        LogicalListener.cpp
        LogicalSound.cpp
        Sound3D.cpp
        SoundBuffer.cpp
        SoundPseudo3D.cpp
        SoundScene.cpp
        SoundSceneObj.cpp
        Threads.cpp
        Utils.cpp
        WWAudio.cpp
        listenerhandle.cpp
        sound2dhandle.cpp
        sound3dhandle.cpp
        soundhandle.cpp
        soundstreamhandle.cpp)

add_library(wwaudio STATIC ${wwaudio_sources} ${wwaudio_headers})
set_target_properties(wwaudio PROPERTIES LINKER_LANGUAGE CXX)