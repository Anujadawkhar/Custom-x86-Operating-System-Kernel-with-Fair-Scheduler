#include "print.h"

extern "C" void scheduler_task();

extern "C" void kernel_main()
{
    clear_screen();   // IMPORTANT FIRST

    print("Kernel Started\n");
    print("Scheduler Init\n");

    scheduler_task();

    while(1);
}




