#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "model.h"
#include <algorithm>
#include <iostream>


class Scheduler
{
public:
    Scheduler();

    Scheduler& add_job(const Job &j);
    QList<Job> sjf_nonpreemptive();
    QList<Job> sjf_preemptive();
    QList<Job> priority_preemptive();
    QList<Job> priority_nonpreemptive();
    double average_waiting_time(const QList<Job>& jobs);

private:

    QList<Job> schedule_preemptive(std::function<bool(Job&, Job&)> comp_func);
    QList<Job> schedule_nonpreemptive(std::function<bool(Job&, Job&)> comp_func);

    QList<Job> wait_queue;

    static constexpr auto comp_arrival_func = [](Job &p1, Job &p2) {
        if(p1.arrival_time() == p2.arrival_time())
            return p1.duration() < p2.duration();
        return p1.arrival_time() < p2.arrival_time();
    };

    static constexpr auto comp_durtion_func = [](Job &p1, Job &p2) {
        if(p1.duration() == p2.duration())
            return p1.arrival_time() > p2.arrival_time();
        return p1.duration() > p2.duration();
    };

    static constexpr auto comp_priority_func = [](Job &p1, Job &p2) {
        if(p1.priority() == p2.priority())
            return p1.arrival_time() > p2.arrival_time();
        return p1.priority() > p2.priority();
    };

};

#endif // SCHEDULER_H
