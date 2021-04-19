#include "model.h"

quint32 Job::m_global_id = 0;

Job::Job()
    : m_label(""), m_start_time(0), m_duration(0),
      m_arrival_time(0), m_priority(0), m_id( this->m_global_id)
{
    this->m_global_id++;
}

Job::Job(const QString &label, const quint32 &start_time, const quint32 &duration,
         const quint32 &arrival_time, const quint32 &priority)
    : m_label(label), m_start_time(start_time), m_duration(duration),
      m_arrival_time(arrival_time), m_priority(priority), m_id( this->m_global_id)
{
    this->m_global_id++;
}

QString Job::label() const
{
    return m_label;
}

quint32 Job::start_time() const
{
    return m_start_time;
}

quint32 Job::duration() const
{
    return m_duration;
}

quint32 Job::arrival_time() const
{
    return m_arrival_time;
}

void Job::setArrival_time(const quint32 &arrival_time)
{
    m_arrival_time = arrival_time;
}

quint32 Job::priority() const
{
    return m_priority;
}

void Job::setPriority(const quint32 &priority)
{
    m_priority = priority;
}

quint32 Job::end_time() const
{
    return m_start_time + m_duration;
}

quint32 Job::id() const
{
    return m_id;
}

void Job::setLabel(const QString &label)
{
    m_label = label;
}

void Job::setDuration(const quint32 &duration)
{
    m_duration = duration;
}

void Job::setStart_time(const quint32 &start_time)
{
    m_start_time = start_time;
}

std::ostream &operator<<(std::ostream &os, const Job &j) {
    os << "Job Id: " << j.id() << "\n"
       << "Job name: " << j.label().toStdString() << "\n"
       << "Arrival time: " << j.arrival_time() << "\n"
       << "Start time: " << j.start_time() << "\n"
       << "Durtion: " << j.duration() << "\n";
    return os;
}

JobModel::JobModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void JobModel::addJob(const Job &job)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_jobs << job;
    endInsertRows();
}

int JobModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_jobs.count();
}

QVariant JobModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_jobs.count())
        return QVariant();

    const Job &job = m_jobs[index.row()];
    if (role == LabelRole)
        return job.label();
    else if (role == StartTimeRole)
        return job.start_time();
    else if (role == DurationRole)
        return job.duration();
    return QVariant();
}

QHash<int, QByteArray> JobModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[LabelRole] = "label";
    roles[StartTimeRole] = "start_time";
    roles[DurationRole] = "duration";
    return roles;
}
