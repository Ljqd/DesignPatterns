#include "Editor.h"

Editor* Editor::editor = nullptr;

Editor::Editor()
{}

// Singleton
Editor* Editor::getInstance()
{
    if (editor == nullptr) {
        editor = new Editor();
    }
    return editor;
}

void Editor::openForRead(const std::string& filename)
{
    close();

    iFile.open(filename);
    if (!iFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for reading." << std::endl;
        return;
    }
}

void Editor::openForWrite(const std::string& filename)
{
    close();

    oFile.open(filename, std::ios_base::app);
    if (!oFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for writing." << std::endl;
        return;
    }
}

void Editor::close()
{
    if (iFile.is_open())
        iFile.close();

    if (oFile.is_open())
        oFile.close();
}

std::string Editor::readLine() 
{
    std::string line;
    if (std::getline(iFile, line))
        return line + '\n';
    return "";
}

std::string Editor::getContent()
{
    std::string content;
    std::string line;
    while (std::getline(iFile, line)) {
        content += line + "\n";
    }
    return content;
}

void Editor::writeFile(const std::string& content)
{
    oFile << content;
}