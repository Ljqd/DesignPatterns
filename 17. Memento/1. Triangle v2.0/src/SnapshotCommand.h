#pragma once

#include "Triangle.h"
#include "Snapshot.h"

class SnapshotCommand
{
public:
    SnapshotCommand(Triangle* obligator);

    void backup();
    void undo();

private:
    Triangle* obligator;
    Snapshot snapshot;
};