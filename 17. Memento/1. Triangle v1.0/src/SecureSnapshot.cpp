#include "SecureSnapshot.h"

#include "Triangle.h"


SecureSnapshot::SecureSnapshot(Triangle* obligator, int a, int b, int c)
    : obligator(obligator), a(a), b(b), c(c) {}

void SecureSnapshot::restore() {
    obligator->update(a, b, c);
}