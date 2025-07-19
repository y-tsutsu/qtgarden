#pragma once

#include <QAbstractListModel>
#include <vector>

struct TodoItem
{
    QString contents;
    bool done;
};

class TodoListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool filterUndoneOnly READ filterUndoneOnly WRITE setFilterUndoneOnly NOTIFY filterUndoneOnlyChanged)

public:
    enum Roles
    {
        ContentsRole = Qt::UserRole + 1,
        DoneRole
    };
    Q_ENUM(Roles)

    explicit TodoListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool filterUndoneOnly() const;
    void setFilterUndoneOnly(bool value);

    Q_INVOKABLE void addItem(const QString &text);
    Q_INVOKABLE void removeItem(int index);
    Q_INVOKABLE void toggleDone(int index);

signals:
    void filterUndoneOnlyChanged();

private:
    std::vector<TodoItem> m_items;
    bool m_filterUndoneOnly = false;

    int visibleIndexToRealIndex(int visibleIndex) const;
};
