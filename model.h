#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QStringList>

class Job
{
public:
    Job(const QString &label, const quint32 &start_time, const quint32 &duration);

    QString label() const;
    quint32 start_time() const;
    quint32 duration() const;

private:
    QString m_label;
    quint32 m_start_time;
    quint32 m_duration;
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
