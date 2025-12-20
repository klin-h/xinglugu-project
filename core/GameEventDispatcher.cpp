#include "GameEventDispatcher.h"
#include <algorithm>

GameEventDispatcher& GameEventDispatcher::instance() {
    static GameEventDispatcher dispatcher;
    return dispatcher;
}

void GameEventDispatcher::post(const GameEvent& event) {
    auto it = listeners_.find(event.type);
    if (it == listeners_.end()) {
        return;
    }

    // 拷贝一份，避免回调中修改订阅列表导致迭代失效
    auto listenersCopy = it->second;
    for (const auto& entry : listenersCopy) {
        const auto& cb = entry.second;
        if (cb) {
            cb(event);
        }
    }
}

int GameEventDispatcher::subscribe(GameEventType type, const Callback& cb) {
    int handleId = nextHandleId_++;
    listeners_[type].push_back({handleId, cb});
    return handleId;
}

void GameEventDispatcher::unsubscribe(GameEventType type, int handleId) {
    auto it = listeners_.find(type);
    if (it == listeners_.end()) {
        return;
    }

    auto& vec = it->second;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [handleId](const auto& entry) {
        return entry.first == handleId;
    }), vec.end());
}
