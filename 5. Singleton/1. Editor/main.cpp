#include <iostream>

#include "Editor.h"

int main() 
{
    Editor* editor = Editor::getInstance();

    std::string filename = "sample.txt";

    // Write
    std::string content1 = "Hello, World!\n";

    editor->openForWrite(filename);
    editor->writeFile(content1);

    // Read
    editor->openForRead(filename);
    std::string content2 = editor->getContent();
    std::cout << "Content of 'sample.txt':\n" << content2;

    return 0;
}