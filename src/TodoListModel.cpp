// TodoListModel.cpp
#include "TodoListModel.h"

TodoListModel::TodoListModel(QObject *parent) : QAbstractListModel(parent)
{
}

int TodoListModel::rowCount(const QModelIndex &) const
{
    return static_cast<int>(m_items.size());
}

QVariant TodoListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(m_items.size()))
        return {};

    const TodoItem &item = m_items[index.row()];
    switch (role)
    {
    case ContentsRole:
        return item.contents;
    case DoneRole:
        return item.done;
    default:
        return {};
    }
}

QHash<int, QByteArray> TodoListModel::roleNames() const
{
    return {
        {ContentsRole, "contents"},
        {DoneRole, "done"},
    };
}

void TodoListModel::addItem(const QString &text)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.push_back({text, false});
    endInsertRows();
}

void TodoListModel::toggleDone(int index)
{
    if (index >= 0 && index < static_cast<int>(m_items.size()))
    {
        m_items[index].done = !m_items[index].done;
        emit dataChanged(this->index(index), this->index(index));
    }
}
