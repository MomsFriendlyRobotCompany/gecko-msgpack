/**************************************************\
* The MIT License (MIT)
* Copyright (c) 2014 Kevin Walchko
* see LICENSE for full details
\**************************************************/
#pragma once

#include <stdint.h>
#include <msgpack.hpp>

enum GeckoMsgs {
    GVECTOR    = 0,  // vector: x,y,z
    GQUATERNION= 1,  // quaterion: w,x,y,z
    GWRENCH    = 2,  // wrench: force, torque
    GPOSE      = 3,  // pose: position, orientation
    GJOYSTICK  = 4,  // joystick: axes, buttons
    GTWIST     = 5,  // twist: linear, angular velocity
    GIMU       = 10, // imu
    GLIDAR     = 20, // lidar
    GIMAGE     = 12, // image
    GOCC       = 13, // occupancy grid
    GODOM      = 14  // odometry
};

/****
 * Base class for keeping track of message type
 */
class base_t {
public:
    base_t(uint8_t t): type(t) {}
    uint8_t type;
};


#include "gecko/msgpack/common.hpp"
#include "gecko/msgpack/stamped.hpp"
#include "gecko/msgpack/serialization.hpp"
