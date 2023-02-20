#pragma once

#include "QueueItem.h"

template<class T, int step = 3>
class Queue
{
private:
    int count;
    QueueItem<T>** arr;
    int capacity;
    int priorityCount;
    int* prs;

    void resetPrs()
    {
        for (int i{}; i < this->priorityCount; ++i)
            this->prs[i] = -1;
    }

    bool isNotAllocated() const
    {
        return this->arr == nullptr;
    }

    bool isFool() const
    {
        return this->count == this->capacity;
    }

    void reallocateMemory()
    {
        if (this->arr == nullptr)
        {
            this->arr = new QueueItem<T>*[step] {};
            this->capacity = step;

            return;
        }

        this->capacity = this->count + step;

        QueueItem<T>** temp = new QueueItem<T>*[this->capacity];

        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] this->arr;
        this->arr = temp;
    }

    void clearMemory()
    {
        if (this->arr != nullptr)
        {
            for (int i{}; i < this->count; ++i)
            {
                if (this->arr[i] != nullptr)
                    delete this->arr[i];
            }

            delete[] this->arr;
        }

        if (this->prs != nullptr)
            delete[] this->prs;

        this->arr = nullptr;
        this->prs = nullptr;
    }

    int findTargetPriority()
    {
        int targetPriority = -1;
        for (int i{ this->priorityCount - 1 }; i >= 0; --i)
        {
            if (this->prs[i] != -1)
            {
                targetPriority = i;
                break;
            }
        }

        return targetPriority;
    }

    void updatePrs(int targetIndex, int targetPriority)
    {
        for (int i{}; i < this->priorityCount; ++i)
        {
            if (this->prs[i] > targetIndex)
                --this->prs[i];
        }

        this->prs[targetPriority] = -1;

        for (int i{ targetIndex }; i < this->count; ++i)
        {
            if ((this->arr[i])->getPriority() == targetPriority)
            {
                this->prs[targetPriority] = i;

                return;
            }
        }
    }

public:
    Queue(int priorityCount = 3) :
        count{ 0 },
        arr{ nullptr },
        capacity{ 0 },
        priorityCount{ priorityCount },
        prs{ new int[priorityCount] }
    {
        this->resetPrs();
    }

    Queue(const Queue<T>& obj) :
        count{ obj.count },
        arr{ new QueueItem<T>*[obj.capacity] },
        capacity{ obj.capacity },
        priorityCount{ obj.priorityCount },
        prs{ new int[priorityCount] }
    {
        for (int i{}; i < obj.count; ++i)
        {
            this->arr[i] = new QueueItem<T>{ *(obj.arr[i]) };

            // this->arr[i] = new QueueItem<T>{ obj.arr[i]->getValue(), obj.arr[i]->getPriority() };
        }

        for (int i{}; i < priorityCount; ++i)
            prs[i] = obj.prs[i];
    }

    Queue& operator=(const Queue<T>& obj)
    {
        if (this == &obj)
            return *this;

        this->clearMemory();

        this->count = obj.count;
        this->arr = new QueueItem<T>*[obj.capacity];
        this->capacity = obj.capacity;
        this->priorityCount = obj.priorityCount;
        this->prs = new int[obj.priorityCount];

        for (int i{}; i < obj.count; ++i)
        {
            this->arr[i] = new QueueItem<T>{ *(obj.arr[i]) };
        }

        for (int i{}; i < this->priorityCount; ++i)
            this->prs[i] = obj.prs[i];

        return *this;
    }

    Queue(Queue<T>&& obj) :
        count{ obj.count },
        arr{ obj.arr },
        capacity{ obj.capacity },
        priorityCount{ obj.priorityCount },
        prs{ obj.prs }
    {
        obj.arr = nullptr;
        obj.prs = nullptr;
    }

    Queue& operator=(Queue<T>&& obj)
    {
        this->clearMemory();

        this->count = obj.count;
        this->arr = obj.arr;
        this->capacity = obj.capacity;
        this->priorityCount = obj.priorityCount;
        this->prs = obj.prs;

        obj.arr = nullptr;
        obj.prs = nullptr;

        return *this;
    }

    void enqueue(const T& val, int priority)
    {
        // TODO: check priority range

        if (this->isNotAllocated() || this->isFool())
            this->reallocateMemory();

        this->arr[this->count] = new QueueItem<T>{ val, priority };

        if (this->prs[priority] == -1)
            this->prs[priority] = this->count;

        ++this->count;
    }

    T* dequeue()
    {
        if (!isEmpty())
        {
            int targetPriority = this->findTargetPriority();

            int targetIndex = this->prs[targetPriority];

            T val = (this->arr[targetIndex])->getValue();

            delete this->arr[targetIndex];
            this->arr[targetIndex] = nullptr;

            for (int i{ targetIndex }; i < this->count - 1; ++i)
                this->arr[i] = this->arr[i + 1];

            --this->count;

            this->updatePrs(targetIndex, targetPriority);

            return new T{ val };
        }

        return new T{};
    }

    bool isEmpty() const
    {
        return this->count == 0;
    }

    int getCount() const
    {
        return this->count;
    }

    int getCapacity() const
    {
        return this->capacity;
    }

    void show() const
    {
        std::cout << "prs: ";
        for (int i{}; i < this->priorityCount; ++i)
            std::cout << this->prs[i] << ' ';
        std::cout << '\n';

        std::cout << "capacity = " << this->capacity << '\n';
        std::cout << "count = " << this->count << '\n';
        std::cout << "arr: ";
        for (int i{}; i < this->count; ++i)
            std::cout << *(this->arr[i]) << ' ';
        std::cout << "\n\n";
    }

    ~Queue()
    {
        this->clearMemory();
    }
};