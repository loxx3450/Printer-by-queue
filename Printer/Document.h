#pragma once

#include <iostream>

template <class T>
class Document
{
private:
    std::string name;
    int data;
    T* info;

public:
    Document() :
        name{"no_name"},
        data{0},
        info{nullptr}
    {}

    Document(std::string name, int data, const T& info) :
        name{ name },
        data{ data },
        info{ new T{info} }
    {}

    Document(const Document<T>& obj) :
        name{ obj.name },
        data{ obj.data }
    {
        if (obj.info != nullptr)
        {
            info = new T{ *obj.info };
        }
        else {
            info = nullptr;
        }
    }

    Document(Document<T>&& obj) :
        name{ obj.name },
        data{ obj.data },
        info{ obj.info }
    {
        obj.info = nullptr;
    }

    Document& operator=(const Document<T>& obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        name = obj.name;
        data = obj.data;
        delete info;
        info = new T{ *obj.info };

        return *this;
    }

    Document& operator=(Document<T>&& obj)
    {
        name = obj.name;
        data = obj.data;
        delete info;
        info = obj.info;

        obj.info = nullptr;

        return *this;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName() const
    {
        return this->name;
    }

    void setData(int val)
    {
        this->data = val;
    }

    int getData() const
    {
        return this->data;
    }

    T getInfo() const
    {
        return *this->info;
    }

    friend std::ostream& operator<<(std::ostream& out, const Document<T>& obj)
    {
        out << "Name of the document is " << obj.name << " by " << obj.data << " date.\n";

        if (obj.info != nullptr)
        {
            out << "Text inside: " << *obj.info << "\n";
        }

        return out;
    }

    ~Document()
    {
        if (this->info != nullptr)
        {
            delete this->info;
        }
    }
};
