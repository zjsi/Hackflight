/*
   ladybug.hpp : Ladybug Flight Controller implementation of Hackflight Board routines

   Uses EM7180 SENtral Sensor Hub in master mode mode

   Copyright (c) 2018 Simon D. Levy

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

#include <Wire.h>
#include "boards/arduino/sentral.hpp"
#include "motors/brushed.hpp"

namespace hf {

    class Ladybug : public SentralBoard {

        private:

            BrushedMotor motors[4] = { BrushedMotor(13), BrushedMotor(A2), BrushedMotor(3), BrushedMotor(11) };

        protected:

            void writeMotor(uint8_t index, float value)
            {
                motors[index].write(value);
            }

        public:

            // Support prototype version where LED is on pin A1
            Ladybug(uint8_t ledPin = A4) 
                : SentralBoard(ledPin)
            {
                // Start I^2C
                Wire.begin();

                // Hang a bit before starting up the EM7180
                delay(100);

                SentralBoard::begin();

                // Initialize the motors
                for (int k=0; k<4; ++k) {
                    motors[k].init();
                }

                // Hang a bit more
                delay(100);
            }

    }; // class Ladybug

} // namespace hf
