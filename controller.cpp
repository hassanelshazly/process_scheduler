#include "controller.h"

#include <QRandomGenerator>

#include "model.h"

JobController::JobController(QObject *parent)
    : QObject(parent), m_current_time(0)
{
    m_model.addJob(Job("A", 0, 5));
    m_model.addJob(Job("B", 5, 15));
    m_model.addJob(Job("A", 15, 5));
    m_current_time = 20;
}

JobModel *JobController::model()
{
    return &m_model;
}

void JobController::addSlot()
{
    quint32 dur = qRound((QRandomGenerator::global()->generate() % 25 / (qreal)5) * 5);
    m_model.addJob(Job("C", m_current_time, dur));
    m_current_time += dur;
}
