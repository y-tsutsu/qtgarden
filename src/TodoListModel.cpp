#include "TodoListModel.h"

TodoListModel::TodoListModel(QObject *parent) : QAbstractListModel(parent)
{
}

int TodoListModel::rowCount(const QModelIndex &) const
{
    if (!m_showOnlyUndone)
    {
        return static_cast<int>(m_items.size());
    }

    return std::count_if(m_items.begin(), m_items.end(),
                         [](const TodoItem &item)
                         {
                             return !item.done;
                         });
}

QVariant TodoListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return {};
    }

    int realIndex = visibleIndexToRealIndex(index.row());
    if (realIndex < 0 || realIndex >= static_cast<int>(m_items.size()))
    {
        return {};
    }

    const TodoItem &item = m_items[realIndex];
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

void TodoListModel::removeItem(int index)
{
    if (index < 0 || index >= rowCount())
    {
        return;
    }

    int realIndex = visibleIndexToRealIndex(index);
    if (realIndex < 0 || realIndex >= static_cast<int>(m_items.size()))
    {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    m_items.erase(m_items.begin() + realIndex);
    endRemoveRows();
}

void TodoListModel::toggleDone(int index)
{
    if (index < 0 || index >= rowCount())
    {
        return;
    }

    int realIndex = visibleIndexToRealIndex(index);
    if (realIndex < 0 || realIndex >= static_cast<int>(m_items.size()))
    {
        return;
    }

    if (m_showOnlyUndone)
    {
        beginResetModel();
        m_items[realIndex].done = !m_items[realIndex].done;
        endResetModel();
    }
    else
    {
        m_items[realIndex].done = !m_items[realIndex].done;
        emit dataChanged(this->index(index), this->index(index));
    }
}

void TodoListModel::setShowOnlyUndone(bool show)
{
    if (m_showOnlyUndone != show)
    {
        beginResetModel();
        m_showOnlyUndone = show;
        endResetModel();
    }
}

int TodoListModel::visibleIndexToRealIndex(int visibleIndex) const
{
    if (!m_showOnlyUndone)
    {
        return visibleIndex;
    }

    int count = -1;
    for (int i = 0; i < static_cast<int>(m_items.size()); i++)
    {
        if (!m_items[i].done)
        {
            count++;
        }
        if (count == visibleIndex)
        {
            return i;
        }
    }

    return -1;
}
