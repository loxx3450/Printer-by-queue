#include <iostream>

#include "Document.h"

int main()
{
    Document a;
    Document b{ "Yehpr", 15, "Very important document", Employee{"Yehor", 2} };

    std::cout << b << "\n";

    Employee* c = new Employee{ *b.getEmployee() };

    std::cout << c->getStatus();
    std::cout << c->getTitle();

    delete c;
}