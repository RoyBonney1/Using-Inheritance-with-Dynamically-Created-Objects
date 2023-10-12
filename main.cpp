//Roy Ebo Bonney
// 10/11/2023
//This program will find higtest paid average manager and average pay of all managers
#include "employee.h"
#include "employee.cpp"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Manager: public Employee
{   
    private:
        double bonus;

    public:
        double calcPay() const;
        Manager(string theName, double theWage, double theHours, double extra);


};

double Manager::calcPay() const
{
    return (bonus + (wage * hours));
}

Manager::Manager(std::string theName, double theWage, double theHours, double extra):Employee(theName, theWage, theHours)
{
    bonus = extra;
}

int main()
{
    int num;
    //this will determine size of the array
    cout << "Enter number of managers: ";
    cin >> num;
    cout << endl;
    
    const int NUM_OF_MANAGERS = num;
    //array of pointers to manager objects
    Manager* manager_collection[NUM_OF_MANAGERS];

    //loop to take information for each manager
    for (int i = 0; i < NUM_OF_MANAGERS; i++)
    {
        string name;
        double wage;
        double hours;
        double bonus;

        cin.ignore(1, '\n');
        cout << "Enter manager " << i << " name: ";
        getline(cin, name);
        
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;        

        manager_collection[i] = new Manager(name, wage, hours, bonus);
        cout << endl;
    }

    double total = 0;
    int highest_index = 0;

    //loop to find the combined pay of all managers
    for (int i = 0; i < NUM_OF_MANAGERS; i++)
    {
        total += manager_collection[i]->calcPay();
    }

    //loop to find the array index of highest paid manager
    for (int i = 1; i < NUM_OF_MANAGERS; i++)
    {
        if ((manager_collection[i]->calcPay()) > (manager_collection[highest_index]->calcPay()))
        {
            highest_index = i;
        }
    }

    double average = total / NUM_OF_MANAGERS;
    cout << fixed << setprecision(2);
    cout << "Highest paid manager is " << manager_collection[highest_index]->getName() << " who is paid $" << manager_collection[highest_index]->calcPay() << endl;
    cout << "Average pay is $" << average << endl;



    //releasing dynamically allocated memory
    for (int i = 0; i < NUM_OF_MANAGERS; i++)
    {
        delete manager_collection[i];
    }

    return 0;
}
