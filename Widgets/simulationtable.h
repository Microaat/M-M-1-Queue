#ifndef SIMULATIONTABLE_H
#define SIMULATIONTABLE_H

#include <QObject>
#include <QAbstractItemModel>

class SimulationTable : public QAbstractItemModel {
public:
    SimulationTable(QObject *parent = nullptr);
    virtual ~SimulationTable();

    // QAbstractItemModel interface
    /*QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;*/
};

#endif // SIMULATIONTABLE_H
