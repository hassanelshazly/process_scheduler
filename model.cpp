#include "model.h"

Job::Job(const QString &label, const quint32 &start_time, const quint32 &duration)
    : m_label(label), m_start_time(start_time), m_duration(duration)
{
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
