#pragma once

#include "Event.h"

// Events class: AppTick, AppUpdate, AppRender,

namespace Engine {
    class ENG_API EventAppTick : public Event {

    };

    class ENG_API EventAppUpdate : public Event {

    };

    class ENG_API EventAppRender : public Event {

    };
}