#ifndef TASK_H
#define TASK_H
#include <string>
#include <vector>


class task
{
    friend std::istream &operator>>(std::istream &input, task &p);
    friend std::ostream &operator<<(std::ostream &output, const task &p);
    // friend void add(std::vector<task> &,std::string);

public:
    task();

    void setTask(std::string t);
    std::string getTask();
    void setPriority(unsigned int);
    int getPriority(void);
    void setFavorite(char);
    char getFavorite(void);
    void setId();
    int getId(void);
    void setCheck(bool);
    bool getCheck(void);

private:
    std::string TaskN;
    unsigned int id;
    unsigned int priority;
    char favorite;
    bool check = false;
    int index;
};

#endif