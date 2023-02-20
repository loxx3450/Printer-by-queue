#include <iostream>
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include "Document.h"
#include "Employee.h"
#include "Printer.h"

int main()
{
    Document<std::string> a{"Nikita", 20, "Heute habe ich viel geschlafen."};

    Document<std::string> b{ "Yehor", 20, "Heute Kozachok hort gut Musik."};

    Document<std::string> c{ "Polina", 20, "Heute Zhenya hat geduscht."};

    Employee Yehor{ "Yehor", 2 };

    Employee Nikita{ "Nikita", 0 };

    Employee Polina{ "Polina", 1 };

    Printer<std::string> printer{ "MegaPro printer", 3 };

    printer.addDocument(a, Nikita);
    printer.addDocument(b, Yehor);
    printer.addDocument(c, Polina);

    std::cout << printer.getDocument() << "\n";
    std::cout << printer.getDocument() << "\n";
    std::cout << printer.getDocument() << "\n";
    std::cout << printer.getDocument() << "\n";

    _CrtDumpMemoryLeaks();

    return 0;
}