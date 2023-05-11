#include "PublicSnapshot.h"
#include "Triangle.h"

PublicSnapshot::PublicSnapshot(Triangle* obligator, int a, int b, int c)
    : obligator(obligator), a(a), b(b), c(c) {}