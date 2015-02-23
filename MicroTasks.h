// MicroTasks.h

#ifndef _MICROTASKS_h
#define _MICROTASKS_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Task.h"
#include "List.h"

/**
 * Gives the number of items in a static array
 *
 * @param a the array to return the number of items in
 */
#define ARRAY_ITEMS(a) (sizeof(a) / sizeof(a[0]))

class MicroTasksClass
{
  private:
    List oTasks;

  protected:
    void WakeTask(Task *oTask, WakeReason eReason);

  public:
    MicroTasksClass();

    void init();
    void update();

    void startTask(Task *oTask);
    void stopTask(Task *oTask);

    static unsigned long WaitForEvent;
    static unsigned long WaitForMessage;
    static unsigned long WaitForMask;

    static unsigned long Infinate;
};

extern MicroTasksClass MicroTasks;

#endif

