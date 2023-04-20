#include <iostream>

#include "src/Employee.h"
#include "src/Director.h"
#include "src/Manager.h"
#include "src/Salesperson.h"

int main()
{
    Employee* director = new Director("John");

    Employee* manager1 = new Manager("Alex (meat)");
    Employee* manager2 = new Manager("Monica (milk)");
    Employee* manager3 = new Manager("Marti (candies)");

    Employee* worker11 = new Salesperson("Fred");
    Employee* worker12 = new Salesperson("Freddy");
    Employee* worker13 = new Salesperson("Fredment");

    Employee* worker21 = new Salesperson("Ben");
    Employee* worker22 = new Salesperson("Beny");
    Employee* worker23 = new Salesperson("Bony");

    Employee* worker31 = new Salesperson("Dude");
    Employee* worker32 = new Salesperson("Dudle");
    Employee* worker33 = new Salesperson("Yankee Doodle");

    manager1->addSubordinate(worker11);
    manager1->addSubordinate(worker12);
    manager1->addSubordinate(worker13);

    manager2->addSubordinate(worker21);
    manager2->addSubordinate(worker22);
    manager2->addSubordinate(worker23);

    manager3->addSubordinate(worker31);
    manager3->addSubordinate(worker32);
    manager3->addSubordinate(worker33);

    director->addSubordinate(manager1);
    director->addSubordinate(manager2);
    director->addSubordinate(manager3);

    // Finally
    director->payExpenses();
}