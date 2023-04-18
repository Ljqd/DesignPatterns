#include "FileReader.h"

FileReader::FileReader(const std::string& path) : file(path) {
    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << path << std::endl;
        throw std::runtime_error("File open failed");
    }
    readNextLine();
}

FileReader::~FileReader() {
    if (file.is_open()) {
        file.close();
    }
}

std::string FileReader::next() {
    std::string current_line = line;
    readNextLine();
    return current_line;
}

bool FileReader::isEoF() const {
    return file.eof();
}

void FileReader::readNextLine() {
    if (!std::getline(file, line)) {
        file.setstate(std::ios_base::eofbit);
    }
}