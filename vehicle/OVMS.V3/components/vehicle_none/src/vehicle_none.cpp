/*
;    Project:       Open Vehicle Monitor System
;    Date:          14th March 2017
;
;    Changes:
;    1.0  Initial release
;
;    (C) 2011       Michael Stegen / Stegen Electronics
;    (C) 2011-2017  Mark Webb-Johnson
;    (C) 2011        Sonny Chen @ EPRO/DX
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#include "esp_log.h"
static const char *TAG = "v-none";

#include <stdio.h>
#include "vehicle_none.h"

OvmsVehicleNone::OvmsVehicleNone()
  {
  ESP_LOGI(TAG, "Generic NONE vehicle module");
  }

OvmsVehicleNone::~OvmsVehicleNone()
  {
  ESP_LOGI(TAG, "Shutdown NONE vehicle module");
  }

const std::string OvmsVehicleNone::VehicleName()
  {
  return std::string("NONE");
  }

class OvmsVehicleNoneInit
  {
  public: OvmsVehicleNoneInit();
} MyOvmsVehicleNoneInit  __attribute__ ((init_priority (9000)));

OvmsVehicleNoneInit::OvmsVehicleNoneInit()
  {
  ESP_LOGI(TAG, "Registering Vehicle: NONE (9000)");

  MyVehicleFactory.RegisterVehicle<OvmsVehicleNone>("NONE");
  }
