#include "MilitaryBase.h"

#include "SpyVisitor.h"

void MilitaryBase::accept(SpyVisitor& visitor) {
    visitor.visitMilitaryBase(*this);
}