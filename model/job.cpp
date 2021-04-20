#include <model/job.h>


int JobModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 12;
}

QVariant JobModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index)
    if (role == LabelRole)
        return "A";
    else if (role == StartTimeRole)
        return 0;
    else if (role == DurationRole)
        return 10;

    return QVariant();
}

bool JobModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index)
    Q_UNUSED(value)
    Q_UNUSED(role)
    return false;
}

Qt::ItemFlags JobModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> JobModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[LabelRole] = "label";
    roles[StartTimeRole] = "startTime";
    roles[DurationRole] = "duration";
    return roles;
}
