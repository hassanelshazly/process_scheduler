#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "model.h"

class JobController : public QObject
{
    Q_OBJECT
public:
    JobController(QObject *parent = 0);

    JobModel *model();

public slots:
    void addSlot();
private:
    JobModel m_model;
    quint32 m_current_time;
};

#endif // CONTROLLER_H
