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
	}

	Document<T> getDocument()
	{
		return *q.dequeue();
	}
};

