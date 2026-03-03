#include "print.h"

#define MAX_TASKS 3
#define DEFAULT_WEIGHT 1024

enum TaskState {
    TASK_READY,
    TASK_RUNNING,
    TASK_FINISHED
};

struct Task {
    const char* name;
    int remaining_work;
    int weight;
    unsigned long vruntime;
    TaskState state;
};

Task tasks[MAX_TASKS] = {
    {"Task-1", 5, 1024, 0, TASK_READY},
    {"Task-2", 5, 2048, 0, TASK_READY},
    {"Task-3", 5, 512,  0, TASK_READY}
};


// Pick task with minimum vruntime
Task* pick_next_task() {
    Task* best = 0;

    for(int i = 0; i < MAX_TASKS; i++) {
        if(tasks[i].state == TASK_READY) {
            if(best == 0 || tasks[i].vruntime < best->vruntime)
                best = &tasks[i];
        }
    }
    return best;
}


extern "C" void scheduler_task()
{
    print("\n=== CFS Scheduler Started ===\n");

    Task* current = 0;

    while(true)
    {
        Task* next = pick_next_task();
        if(next == 0) break;

        // Visible context switch
        if(current && current != next) {
            print("Context Switch: ");
            print(current->name);
            print(" -> ");
            print(next->name);
            print("\n");
        }

        if(!current)
        {
            print("Starting with ");
            print(next->name);
            print("\n");
        }

        current = next;
        current->state = TASK_RUNNING;

        // Simulate 1 time slice
        current->remaining_work--;
        current->vruntime += (DEFAULT_WEIGHT / current->weight);

        if(current->remaining_work <= 0)
        {
            current->state = TASK_FINISHED;
            print(current->name);
            print(" Finished\n");
        }
        else
        {
            current->state = TASK_READY;
        }
    }

    print("=== All Tasks Completed ===\n");
}