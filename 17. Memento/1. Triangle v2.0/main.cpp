#include <iostream>
#include <vector>

#include "src/Triangle.h"
#include "src/Snapshot.h"
#include "src/SnapshotCommand.h"

int main()
{
    std::vector<SnapshotCommand> history = {};

    Triangle triangle = { 10, 10, 10 };
    triangle.info();
    SnapshotCommand command0 = { &triangle };
    command0.backup();
    history.push_back(command0);

    triangle.doubleSides();
    triangle.info();
    SnapshotCommand command1 = { &triangle };
    command1.backup();
    history.push_back(command1);

    triangle.doubleSides();
    triangle.info();
    SnapshotCommand command2 = { &triangle };
    command2.backup();
    history.push_back(command2);

    triangle.doubleSides();
    triangle.info();
    SnapshotCommand command3 = { &triangle };
    command3.backup();
    history.push_back(command3);

    // =============================
    while (!history.empty())
    {
        SnapshotCommand command = history.back();
        history.pop_back();
        command.undo();
        triangle.info();
    }
}
