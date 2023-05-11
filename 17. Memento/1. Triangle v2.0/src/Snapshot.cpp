#include "Snapshot.h"

#include "Triangle.h"


Snapshot::Snapshot(Triangle* obligator, int a, int b, int c)
    : obligator(obligator), a(a), b(b), c(c) {}

void Snapshot::restore() {
    obligator->update(a, b, c);
}

bool Snapshot::isEmpty()
{
    return obligator == nullptr;
}