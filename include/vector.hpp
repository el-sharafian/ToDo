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
    void Push(std::string);
    std::string Get();
    std::vector<Task>* Assign();
};

#endif // VECTOR_H