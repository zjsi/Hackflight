/*
   omnibusf3.cpp : Board class for Omnibus F3

   Copyright (C) 2018 Simon D. Levy 

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <MPU6000.h>
#include "stm32fboard.h"

// Cleanflight includes
extern "C" {

#include "platform.h"
#include "drivers/system.h"
#include "drivers/timer.h"
#include "drivers/time.h"
#include "drivers/pwm_output.h"
#include "drivers/serial.h"
#include "drivers/serial_uart.h"
#include "drivers/serial_usb_vcp.h"
#include "io/serial.h"
#include "target.h"
#include "stm32f30x.h"

} // extern "C"

class OmnibusF3 : public Stm32FBoard {

    private:

        MPU6000 * _imu;

        // For incoming sensor messages
        serialPort_t * _serial2;

        void initMotors(void);
        void initUsb(void);
        void initImu(void);

    protected:

        // SoftwareQuaternionBoard class overrides
        virtual bool     imuRead(void) override;

        // RealBoard class overrides
        virtual uint8_t  serialTelemetryAvailable(void) override;
        virtual uint8_t  serialTelemetryRead(void) override;
        virtual void     serialTelemetryWrite(uint8_t c) override;

    public:

        OmnibusF3(void);

}; // class OmnibusF3
