#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QStringList>

class Job
{
public:
    Job();
    Job(const QString &label, const quint32 &start_time, const quint32 &duration,
        const quint32 &arrival_time, const quint32 &priority);

    QString label() const;
    void setLabel(const QString &label);

    quint32 duration() const;
    void setDuration(const quint32 &duration);

    quint32 start_time() const;
    void setStart_time(const quint32 &start_time);

    quint32 arrival_time() const;
    void setArrival_time(const quint32 &arrival_time);

    quint32 priority() const;
    void setPriority(const quint32 &priority);

    quint32 end_time() const;

    friend std::ostream &operator<<(std::ostream &os, const Job &j);

    quint32 id() const;

private:
    QString m_label;
    quint32 m_start_time;
    quint32 m_duration;
    quint32 m_arrival_time;
    quint32 m_priority;
    quint32 m_id;

    static quint32 m_global_id;
};

class JobModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum JobRoles {
        LabelRole = Qt::UserRole + 1,
        StartTimeRole,
        DurationRole
    };

    JobModel(QObject *parent = 0);

    void addJob(const Job &job);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Job> m_jobs;
};

#endif // MODEL_H
