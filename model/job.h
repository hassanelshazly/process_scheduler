#ifndef JOB_H
#define JOB_H

#include <QAbstractTableModel>
#include <QHash>

class JobModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum JobRoles {
        LabelRole = Qt::UserRole + 1,
        StartTimeRole,
        DurationRole
    };

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
};

#endif // JOB_H
