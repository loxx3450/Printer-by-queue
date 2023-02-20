#pragma once

#include <iostream>

class Employee
{
private:
	std::string job_title;
	int status;

public:
	Employee() :
		job_title{"no_title"},
		status{0}
	{}

	Employee(std::string title, int val) :
		job_title{title},
		status{val}
	{}

	operator int() const
	{
		return this->status;
	}

	void setTitle(std::string title)
	{
		this->job_title = title;
	}

	std::string getTitle() const
	{
		return this->job_title;
	}

	void setStatus(int val)
	{
		this->status = val;
	}

	int getStatus() const
	{
		return this->status;
	}

};

