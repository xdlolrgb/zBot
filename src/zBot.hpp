#ifndef _zbot_hpp
#define _zbot_hpp
#include "replay.hpp"
#include <Geode/cocos/cocoa/CCGeometry.h>

enum zState {
    NONE, RECORD, PLAYBACK
};

enum zError {
    ERROR_NONE,
    KEY_NOT_FOUND_ERROR,
    KEY_INVALID_ERROR,
    CURL_FAILED_ERROR,
    INVALID_HWID_ERROR,
    UNKNOWN_ERROR,
    KEY_LINKED_DIFFERENT_COMPUTER_ERROR
};

class zBot {
public:
    zState state = NONE;
    zError error = ERROR_NONE;

    int frame;
    float runningTotal;
    
    bool disableRender = false;
    bool gameLoaded = false;
    bool ignoreBypass = false;
    bool justLoaded = false;
    bool ignoreInput = false;
    bool playing = false;
    bool practice = false;

    cocos2d::CCPoint previousPosition;

    double speed = 1;

    Replay* currentReplay;

    static auto* get() {
        static zBot* instance = new zBot();
        return instance;
    }
};

#endif