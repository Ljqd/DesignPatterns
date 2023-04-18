#include "FileWriter.h"

const std::string FileWriter::pathToEmpty = "./data/solutions0.txt";
const std::string FileWriter::pathTo1 = "./data/solutions1.txt";
const std::string FileWriter::pathTo2 = "./data/solutions2.txt";
const std::string FileWriter::pathTo3 = "./data/solutions3.txt";
const std::string FileWriter::pathTo4 = "./data/solutions4.txt";
const std::string FileWriter::pathToInf = "./data/solutions_inf.txt";


void FileWriter::addEmpty(const std::string& equation)
{
    addToFile(pathToEmpty, equation, std::vector<float>{});
}

void FileWriter::addOne(const std::string& equation, const std::vector<float>& solutions)
{
    addToFile(pathTo1, equation, solutions);
}

void FileWriter::addTwo(const std::string& equation, const std::vector<float>& solutions)
{
    addToFile(pathTo2, equation, solutions);
}

void FileWriter::addThree(const std::string& equation, const std::vector<float>& solutions)
{
    addToFile(pathTo3, equation, solutions);
}

void FileWriter::addFour(const std::string& equation, const std::vector<float>& solutions)
{
    addToFile(pathTo4, equation, solutions);
}

void FileWriter::addInf(const std::string& equation, const std::vector<float>& solutions)
{
    addToFile(pathToInf, equation, solutions);
}

void FileWriter::addToFile(const std::string& path, const std::string& equation, const std::vector<float>& solutions)
{
    std::ofstream file(path, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << path << std::endl;
        throw std::runtime_error("File open failed");
    }

    file << equation << ": ";
    for (const auto& solution : solutions) file << solution << " ";
    file << '\n';

    if (file.is_open()) {
        file.close();
    }
}