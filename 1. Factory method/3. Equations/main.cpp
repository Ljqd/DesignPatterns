#include <iostream>

#include "src/Workspace.h"


int main()
{
    Workspace workspace = {};

    workspace.test_manually();
    workspace.test_file("nothing");
}