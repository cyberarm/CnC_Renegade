//
// Created by cyberarm on 2/28/25.
//

#pragma once

#include <SDL3/SDL.h>
#include <cstdio>
#include <cstdlib>

#define COMMANDO_ENGINE_VERSION "0.1.0"

inline float cmdo_resolution_scale = 1.0F;
inline Uint16 cmdo_frame_rate_target = 512;
// Calculate delay needed to achieve frame rate target in nanoseconds
inline Uint64 cmdo_update_interval_ns = static_cast<Uint64>((1.0 / cmdo_frame_rate_target) * 1000 * 1000000);
