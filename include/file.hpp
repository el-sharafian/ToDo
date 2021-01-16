#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "../include/task.hpp"

class File
{
private:
    std::fstream *f;
    // std::string fname=("../src/both.txt");

public:
    File();
    File(std::fstream &, std::string);
    ~File();
    void isOpen(std::fstream &);
    void close(std::fstream);
    void writeToFile(std::fstream &, Task &t);
    std::string readFromFile(std::fstream &, Task &t);
};

#endif // File