#include <iostream>

#include "src/Triangle.h"
#include "src/Caretaker.h"
#include "src/PublicSnapshot.h"
#include "src/SecureSnapshot.h"

void testNested(Triangle* triangle, Caretaker<Triangle::NestedSnapshot>* caretaker);
void testPublic(Triangle* triangle, Caretaker<PublicSnapshot>* caretaker);
void testSecure(Triangle* triangle, Caretaker<SecureSnapshot>* caretaker);

int main()
{
    Triangle useNested = { 10, 10, 10 };
    Triangle usePublic = { 15, 10, 10 };
    Triangle useSecure = { 20, 10, 10 };

    Caretaker<Triangle::NestedSnapshot> nestedCaretaker = { &useNested };
    Caretaker<PublicSnapshot> publicCaretaker = { &usePublic };
    Caretaker<SecureSnapshot> secureCaretaker = { &useSecure };

    testNested(&useNested, &nestedCaretaker);
    testPublic(&usePublic, &publicCaretaker);
    testSecure(&useSecure, &secureCaretaker);
}


void testNested(Triangle* triangle, Caretaker<Triangle::NestedSnapshot>* caretaker)
{
    std::cout << "Demonstration 'Nested':" << std::endl;
    std::cout << "\tBegin modification and saving: " << std::endl;

    // iteration #0
    triangle->info();
    auto snapshot0 = triangle->getNestedSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot0);

    triangle->setA(15);

    // iteration #1
    triangle->info();
    auto snapshot1 = triangle->getNestedSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot1);

    triangle->setB(17);

    // iteration #2
    triangle->info();
    auto snapshot2 = triangle->getNestedSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot2);

    triangle->setC(19);

    // iteration #3
    triangle->info();
    auto snapshot3 = triangle->getNestedSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot3);

    std::cout << "\n\tBegin restoring: " << std::endl;

    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();

    std::cout << "------------------------------" << std::endl;
}


void testPublic(Triangle* triangle, Caretaker<PublicSnapshot>* caretaker)
{
    std::cout << "Demonstration 'Public':" << std::endl;
    std::cout << "\tBegin modification and saving: " << std::endl;

    // iteration #0
    triangle->info();
    auto snapshot0 = triangle->getPublicSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot0);

    triangle->setA(15);

    // iteration #1
    triangle->info();
    auto snapshot1 = triangle->getPublicSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot1);

    triangle->setB(17);

    // iteration #2
    triangle->info();
    auto snapshot2 = triangle->getPublicSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot2);

    triangle->setC(19);

    // iteration #3
    triangle->info();
    auto snapshot3 = triangle->getPublicSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot3);

    std::cout << "\n\tBegin restoring: " << std::endl;

    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();

    std::cout << "------------------------------" << std::endl;
}

void testSecure(Triangle* triangle, Caretaker<SecureSnapshot>* caretaker)
{
    std::cout << "Demonstration 'Secure':" << std::endl;
    std::cout << "\tBegin modification and saving: " << std::endl;

    // iteration #0
    triangle->info();
    auto snapshot0 = triangle->getSecureSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot0);

    triangle->setA(15);

    // iteration #1
    triangle->info();
    auto snapshot1 = triangle->getSecureSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot1);

    triangle->setB(17);

    // iteration #2
    triangle->info();
    auto snapshot2 = triangle->getSecureSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot2);

    triangle->setC(19);

    // iteration #3
    triangle->info();
    auto snapshot3 = triangle->getSecureSnapshot(); // CHECK Caretaker.h :: save() for comment
    caretaker->save(snapshot3);

    std::cout << "\n\tBegin restoring: " << std::endl;

    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();
    caretaker->undo();
    triangle->info();

    std::cout << "------------------------------" << std::endl;
}