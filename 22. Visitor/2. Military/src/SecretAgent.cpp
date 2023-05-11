#include "SecretAgent.h"

#include "GeneralStaff.h"
#include "MilitaryObject.h"

void SecretAgent::visitGeneralStaff(GeneralStaff& object) 
{
    std::cout << "Secret Agent is collecting classified papers from General Staff.\n";
}

void SecretAgent::visitMilitaryBase(MilitaryBase& object) 
{
    std::cout << "Secret Agent is gathering intelligence from Military Base.\n";
}