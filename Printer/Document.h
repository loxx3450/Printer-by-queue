#pragma once

#include "Employee.h"

class Document
{
private:
    std::string name;
    int data;
    std::string message;

    Employee employee;

public:
    Document() :
        name{"no_name"},
        data{0},
        message{"no_text"},
        employee{}
    {}

    Document(std::string name, int data, std::string message, const Employee& employee) :
        name{ name },
        data{ data },
        message{ message },
        employee{ employee }
    {}

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

    void setMessage(std::string message)
    {
        this->message = message;
    }

    std::string getMessage() const
    {
        return this->message;
    }

    int getEmployee() const
    {
        return this->employee.getStatus();
    }

    Employee* getEmployee()
    {
        return &this->employee;
    }

    friend std::ostream& operator<<(std::ostream& out, const Document& obj)
    {
        out << "Name of the document is " << obj.name << " by " << obj.data << " date.\n" << "Text inside: " << obj.message << "\nEmployee: " << obj.employee.getTitle() << "\n";

        return out;
    }
};
