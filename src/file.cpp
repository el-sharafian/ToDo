#include "../include/File.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

File::File()
{
}
File::File(fstream &ff, string fname)
{
    ff.open(fname, ios::binary | ios::out);
    ff.close();
    ff.open(fname, ios::binary | ios::in | ios::app);
}
File::~File()
{
}
void File::isOpen(fstream &output)
{
    if (!output.is_open())
    {
        cerr << "can not open!!!" << endl;
        exit(1);
    }
}
void File::close(fstream output)
{
    output.close();
}
void File::writeToFile(fstream &output, Task &s)
{
    output.write(reinterpret_cast<const char *>(&s), sizeof(s));
}
string File::readFromFile(fstream &output, Task &s)
{
    output.seekg(0, ios::beg);
    output.read(reinterpret_cast<char *>(&s), sizeof(s));
    return s.TaskName;
}