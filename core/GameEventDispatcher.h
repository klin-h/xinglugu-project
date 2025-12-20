#ifndef GAME_EVENT_DISPATCHER_H
#define GAME_EVENT_DISPATCHER_H

#include "cocos2d.h"
#include <functional>
#include <unordered_map>
#include <vector>

// 事件类型定义，集中管理常用游戏事件
enum class GameEventType {
    DayPassed,
    SeasonChanged,
    InventoryChanged,
    MoneyChanged,
    FestivalStarted,
    FestivalEnded,
    FishingResult,
    MapSwitched
};

// 统一事件载荷
struct GameEvent {
    GameEventType type;
    cocos2d::ValueMap payload; // 可携带任意键值数据
};

// 轻量事件分发器，发布/订阅解耦模块依赖
class GameEventDispatcher {
public:
    using Callback = std::function<void(const GameEvent&)>;

    static GameEventDispatcher& instance();

    // 发布事件
    void post(const GameEvent& event);

    // 订阅事件，返回 handleId 用于取消订阅
    int subscribe(GameEventType type, const Callback& cb);

    // 取消订阅
    void unsubscribe(GameEventType type, int handleId);

private:
    GameEventDispatcher() = default;
    GameEventDispatcher(const GameEventDispatcher&) = delete;
    GameEventDispatcher& operator=(const GameEventDispatcher&) = delete;

    std::unordered_map<GameEventType, std::vector<std::pair<int, Callback>>> listeners_;
    int nextHandleId_ = 1;
};

#endif // GAME_EVENT_DISPATCHER_H
