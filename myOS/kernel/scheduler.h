#ifndef SCHEDULER_H
#define SCHEDULER_H

struct Task {
    int pid;
    int weight;
    int vruntime;
    int work;
};

void scheduler_init();
void scheduler_run();

#endif
