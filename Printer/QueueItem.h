#pragma once

#include <iostream>

template<class T>
class QueueItem
{
private:
    static const int DEFAULT_PRIORITY = 0;

    T val;
    int priority;

public:
    QueueItem() :
        val{ T{} },
        priority{ QueueItem<T>::DEFAULT_PRIORITY }
    {}

    QueueItem(T val, int priority) :
        val{ val },
        priority{ priority }
    {}

    int getPriority() const
    {
        return this->priority;
    }

    const T& getValue() const
    {
        return this->val;
    }

    friend std::ostream& operator<<(std::ostream& out, const QueueItem<T>& obj)
    {
        out << obj.val << '(' << obj.priority << ") ";

        return out;
    }
};