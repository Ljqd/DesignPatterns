#include "SnapshotCommand.h"

#include "Triangle.h"


SnapshotCommand::SnapshotCommand(Triangle* obligator)
    : obligator(obligator), snapshot(nullptr, 0, 0, 0) {}

void SnapshotCommand::backup()
{
    snapshot = obligator->getSnapshot();
}

void SnapshotCommand::undo()
{
    if (!snapshot.isEmpty())
        snapshot.restore();
}