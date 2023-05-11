#include <iostream>

#include "src/GeneralStaff.h"
#include "src/MilitaryBase.h"

#include "src/SecretAgent.h"
#include "src/Saboteur.h"

int main()
{
    GeneralStaff generalStaff;
    MilitaryBase militaryBase;

    SecretAgent secretAgent;
    Saboteur saboteur;

    generalStaff.accept(secretAgent);
    militaryBase.accept(secretAgent);

    generalStaff.accept(saboteur);
    militaryBase.accept(saboteur);

    return 0;
}