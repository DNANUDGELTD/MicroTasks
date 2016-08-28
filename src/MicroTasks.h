// MicroTasks.h

#ifndef _MICROTASKS_h
#define _MICROTASKS_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "MicroTasksTask.h"
#include "MicroTasksList.h"

/**
 * Gives the number of items in a static array
 *
 * @param a the array to return the number of items in
 */
#define ARRAY_ITEMS(a) (sizeof(a) / sizeof(a[0]))

namespace MicroTasks
{
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

      static uint32_t WaitForEvent;
      static uint32_t WaitForMessage;
      static uint32_t WaitForMask;

      static uint32_t Infinate;
  };
}

extern MicroTasks::MicroTasksClass MicroTasks;

#endif