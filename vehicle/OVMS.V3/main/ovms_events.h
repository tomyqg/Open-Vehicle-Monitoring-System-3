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

#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <functional>
#include <map>
#include <list>
#include <esp_event.h>

typedef std::function<void(std::string,void*)> EventCallback;

class EventCallbackEntry
  {
  public:
    EventCallbackEntry(std::string caller, EventCallback callback);
    virtual ~EventCallbackEntry();

  public:
    std::string m_caller;
    EventCallback m_callback;
  };

typedef std::list<EventCallbackEntry*> EventCallbackList;
typedef std::map<std::string, EventCallbackList*> EventMap;

class OvmsEvents
  {
  public:
    OvmsEvents();
    ~OvmsEvents();

  public:
    void RegisterEvent(std::string caller, std::string event, EventCallback callback);
    void DeregisterEvent(std::string caller);
    void SignalEvent(std::string event, void* data);

  public:
    static esp_err_t ReceiveSystemEvent(void *ctx, system_event_t *event);
    void SignalSystemEvent(system_event_t *event);

  protected:
    EventMap m_map;

  public:
    bool m_trace;
  };

extern OvmsEvents MyEvents;

#endif //#ifndef __EVENT_H__
