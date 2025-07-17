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

    Q_INVOKABLE void addItem(const QString &text);
    Q_INVOKABLE void toggleDone(int index);
    Q_INVOKABLE void removeItem(int index);
    Q_INVOKABLE void setShowOnlyUndone(bool show);

private:
    std::vector<TodoItem> m_items;
    bool m_showOnlyUndone = false;
};
