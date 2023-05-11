#include "Saboteur.h"

#include "GeneralStaff.h"
#include "MilitaryObject.h"

void Saboteur::visitGeneralStaff(GeneralStaff& object)
{
    std::cout << "Saboteur is destroying classified papers in General Staff.\n";
}

void Saboteur::visitMilitaryBase(MilitaryBase& object) 
{
    std::cout << "Saboteur is sabotaging personnel and equipment in Military Base.\n";
}