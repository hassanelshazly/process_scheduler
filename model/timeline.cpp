#include "model/timeline.h"

#include <QRandomGenerator>

TimelineModel::TimelineModel(QObject *parent) :
    QAbstractListModel(parent)
{
    for (int i = 0; i < 12; i++) {
        quint32 dur = ((QRandomGenerator::global()->bounded(16) / 5) * 5) + 5;
        m_data << dur;
    }

    m_labels = { "A", "B", "A", "C", "D", "A", "E", "F", "H", "I", "J", "K" };
}

int TimelineModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

QVariant TimelineModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Vertical)
        return QVariant();

    return m_labels[section];
}

QVariant TimelineModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.row()];
    }

    return QVariant();
}

QVariant TimelineModel::labels() const
{
    return QVariant::fromValue(m_labels);
}
