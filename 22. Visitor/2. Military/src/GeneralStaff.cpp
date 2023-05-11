#include "GeneralStaff.h"

#include "SpyVisitor.h"

void GeneralStaff::accept(SpyVisitor& visitor) {
    visitor.visitGeneralStaff(*this);
}