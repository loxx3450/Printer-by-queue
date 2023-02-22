#include <iostream>

#include "Document.h"
#include "Employee.h"
#include "Printer.h"

int main()
{
    Document<std::string> a{ "Yehor", 20, "Heute Kozachok hort gut Musik." };

    Document<std::string> b{ "Nikita", 20, "Heute habe ich viel geschlafen." };

    Document<std::string> c{ "Polina", 20, "Heute Zhenya hat geduscht." };


    Employee Yehor{ "Admin", 2 };

    Employee Nikita{ "Student", 0 };

    Employee Polina{ "Teacher", 1 };


    Printer<std::string> printer{ "MegaPro printer", 3 };


    printer.addDocument(a, Yehor);
    printer.addDocument(b, Nikita);
    printer.addDocument(c, Polina);


    std::cout << *printer.getDocument() << "\n";
    std::cout << *printer.getDocument() << "\n";
    std::cout << *printer.getDocument() << "\n";
    std::cout << *printer.getDocument() << "\n";

    return 0;
}