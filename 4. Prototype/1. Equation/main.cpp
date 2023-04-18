#include <iostream>

#include "src/Workspace.h"


int main()
{
    Workspace workspace = {};

    // workspace.test_manually();
    // workspace.test_file("./data/input01.txt");
    // workspace.test_file("./data/input02.txt");
    // workspace.test_file("./data/input03.txt");
    workspace.test_clone();
}
