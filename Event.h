// Event.h

#ifndef _EVENT_h
#define _EVENT_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Node.h"
#include "List.h"
#include "EventListener.h"

class Event : public Node
{
  friend class MicroTasksClass;

  private:
    List oClients;
    static List oEvents;

    volatile int triggered;

  protected:
    void Trigger() {
      triggered = 1;
    }

  public:
    Event() : oClients(), triggered(0) {
      oEvents.Add(this);
    }
    ~Event() {
      oEvents.Remove(this);
    }

    void Register(EventListener *oListener);
    void Deregister(EventListener *oListener);
    bool IsTriggered() {
      return triggered ? true : false;
    }
};

#endif

