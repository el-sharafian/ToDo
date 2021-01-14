#include "../include/task.hpp"
#include "../include/table.hpp"
#include "../include/start.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int findId(vector<task> &tasks, unsigned int a)
{
    for (auto i = 0; i <= tasks.size(); i++)
    {
        if (tasks[i].getId() == a)
        {
            return i;
        }
    }
    throw out_of_range("ID was not found!!");
}
/*void menu(vector<task> tasks)
{
  string c;
  string e="exit";
  while(c != e)
    {
      cout << "Please enter the command : "<<endl;
      cout << ">";
      fflush(stdin);
      getline(cin,c,'\n');
        
        if(c=="add")
        {
            add(tasks);
        }
        else if(c=="complete")
        {
            complete(tasks);
        }
         else if(c=="delete")
        {
            delet(tasks);
        }
        else if(c=="list_todo")
        {
            listTodo(tasks);
        }
        else if(c=="list_complete")
        {
           listComplete(tasks);
        }
        else if((c.substr(0,4)) =="edit")
        {
            try
            {
             unsigned int i;
             stringstream geek(c.substr(5,4)); 
             int x = 0; 
             geek >> x;
             i=findId(tasks,x);
             edit(tasks,i);
            }
            catch(out_of_range & e)
            {
              cerr << e.what() << '\n';
            } 
        }
    }
}*/

int findLongest(vector<task> &tasks)
{
    int index = tasks.size();
    int max = 0;
    for (auto i = 0; i < index; i++)
    {
        if (max < (tasks[i].getTask()).length())
        {
            max = (tasks[i].getTask()).length();
        }
    }
    return max;
}

void addT(vector<task> &tasks, string taskN, unsigned int Pi, char fav)
{
    task t;

    t.setTask(taskN);
    try
    {
        t.setPriority(Pi);
    }
    catch (invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        t.setFavorite(fav);
    }
    catch (invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    t.setId();

    tasks.push_back(t);

    /* int index;
    index=tasks.size();
    cout<<"\n>your task has been successfully added to the list "<<endl;
    cout<<"Task information : "<<endl;
    cout<<tasks[index-1].getTask()<<"\t\t";
    cout<<tasks[index-1].getPriority()<<"\t\t";
    cout<<tasks[index-1].getFavorite()<<"\t\t";
    cout<<tasks[index-1].getId()<<endl;
    index++;*/
}

/*void delet(vector<task> &tasks)
{
    unsigned int I,d;
    cout<<"Enter Task ID : ";
    cin>>I;
    try
    {
      d=findId(tasks,I);
      cout<<">Found!"<<tasks[d].getTask()<<endl;
      char c;
      cout<<"delete (y/n) : ";
      cin>>c;
      if(c=='y')
       {
         tasks.erase(tasks.begin()+(d));
         cout<<">Task "<<std::quoted(tasks[d].getTask())<<" deleted."<<endl;
       }
     else if (c=='n')
      {
         cout<<"Task was not deleted"<<endl;
      }
        
    }
    catch(out_of_range & e)
    {
      cerr << e.what() << '\n';
    }

}
 void complete(vector<task>&tasks)
 {
   unsigned int I,h;
   bool a;
   cout<<"Enter task id : ";
   cin>>I;
   try
   {
     h=findId(tasks,I);
     cout<<">Found!"<<tasks[h].getTask()<<endl;
     char c;
     cout<<"complete(y/n) : ";
     cin>>c;
     if(c=='y')
      {
        tasks[h].setCheck(true);
        
        cout<<"Task "<<std::quoted(tasks[h].getTask())<<" completed."<<endl;
      }
     else if (c=='n')
     {
       cout<<"Task was not completed !"<<endl;
     }   
    }
   catch(out_of_range & e)
   {
       std::cerr << e.what() << '\n';
   }
 }
 void listTodo(vector<task>&tasks)
 {
    int index;
    index=tasks.size();
    cout<<" Task"<<setw(findLongest(tasks)+5)<<"P"<<setw(findLongest(tasks)+5)<<"F"<<setw(findLongest(tasks)+5)<<"ID"<<endl;
    for(auto i=0 ; i<(findLongest(tasks)+60) ; i++)
    {
        cout<<"_";
    }
    cout<<endl;
    for(int i=0 ; i < index ; i++)
    {
        if(tasks[i].getCheck() == false)
        {
          if (tasks[i].getPriority()>tasks[i+1].getPriority())
          {
            swap(tasks[i],tasks[i+1]);
          }
         else if(tasks[i].getPriority() == tasks[i+1].getPriority())
          {
            if (tasks[i+1].getFavorite()=='y')
            {
              swap(tasks[i],tasks[i+1]);
            }
          }
          cout<<"-"<<tasks[i].getTask()<<setw(findLongest(tasks)+5)<<tasks[i].getPriority()<<setw(findLongest(tasks)+5)<<tasks[i].getFavorite()<<setw(findLongest(tasks)+5)<<tasks[i].getId()<<endl;
        }
    }
 }

 void listComplete(vector<task> &tasks)
 {
    cout<<"Task"<<setw(findLongest(tasks)+15)<<"ID"<<endl;
    for(auto i=0 ; i<(findLongest(tasks)+35) ; i++)
    {
        cout<<"_";
    }
    cout<<endl;
    int index;
    index=tasks.size();
    for(int i=0 ; i < index ; i++)
    {
        if(tasks[i].getCheck() == true)
        {
          cout<<"-"<<tasks[i].getTask()<<setw(findLongest(tasks)+15)<<tasks[i].getId()<<endl;
        }
    }
 }
 
 /*void edit(vector<task> &tasks,unsigned int i)
 {
    string c;
    int a;
    fflush(stdin);
    getline(cin,c);
    a=c.length()-3;
     
     if(c.substr(0,2)=="-n")
     {
       string name;
       name=c.substr(3,a);
       tasks[i].setTask(name);
       cout<<tasks[i].getTask()<<endl;
     }
     else if(c.substr(0,2)=="-p")
     {
       stringstream geek(c.substr(3,a)); 
       int x = 0; 
       geek >> x;
       int p;
       p=x;
       tasks[i].setPriority(p);
       cout<<tasks[i].getPriority()<<endl;
     }
     else if(c.substr(0,2)=="-f")
     {
       if(c.substr(3,a) == "y")
       char fb = 'y';
       //tasks[i].setFavorite(fb);
     }
    
 }*/