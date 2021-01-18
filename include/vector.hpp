#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#include <iostream>
#include "task.hpp"

class Vector
{
    // friend class Icon;
    friend std::ostream &operator<<(std::ostream &output, const Vector &p);

private:
    std::vector<Task> tasks;
    std::vector<Task>* temp;

public:
    Vector();
    // ~Vector();
    void push(std::string);
    std::string get();
    std::vector<Task>* assign();
};

#endif // VECTOR_H