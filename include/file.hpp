#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include "task.hpp"
#include "vector.hpp"

class File      // saving tasks in a file
{
public:
    File();
    File(std::fstream &, std::string);
    void isOpen(std::fstream &);
    void close(std::fstream);
    void writeToFile(std::fstream &,Vector&);
    std::string readFromFile(std::fstream &,Vector&);
    ~File();

private:
    std::fstream *f;
    // std::string fname=("../src/both.txt");
};

#endif // File