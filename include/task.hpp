#ifndef TASK_H
#define TASK_H
#include <string>
#include <vector>


class Task
{
    friend std::istream &operator>>(std::istream &input, Task &p);
    friend std::ostream &operator<<(std::ostream &output, const Task &p);
    // friend void add(std::vector<task> &,std::string);

public:
    Task();
    void setPriority(unsigned int);
    int getPriority(void);
    void setFavorite(char);
    char getFavorite(void);
    void setCheck(bool);
    bool getCheck(void);
    std::string TaskName;

private:
    // std::string TaskName;
    unsigned int priority;
    char favorite;
    bool check = false;
};

#endif