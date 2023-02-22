#pragma once
#include "Queue.h"
#include "Employee.h"
#include "Document.h"

template <class T>
class Printer
{
private:
	std::string name;
	Queue<Document<T>> q;

public:
	Printer() :
		name{ "no_name" },
		q{}
	{}

	Printer(std::string name, int count) :
		name{ name },
		q{ Queue<Document<T>>{count} }
	{}

	void addDocument(const Document<T>& document, const Employee& employee)
	{
		q.enqueue(document, (int)employee);

		std::cout << "We added document from " << document.getName() << "(" << employee.getTitle() << ")" << " by " << document.getData() << "\n\n";
	}

	Document<T>* getDocument()
	{
		return q.dequeue();
	}

	std::string getName() const
	{
		return this->name;
	}

	int getCount() const
	{
		return q.getCount();
	}

	void show() const
	{
		q.show();
	}
};

