#include <iostream>
#include <fstream>

using namespace std;

class emp
{
    int empno;
    char name[20];
    char dept[10];
    float salary;
public:
    void getdata()
    {
        cout << "Enter the employee number " << endl;
        cin >> empno;

        cout << "Enter the name : " << endl;
        cin >> name;

        cout << "Enter the department of the employee : " << endl;
        cin >> dept;

        cout << "Enter the salary of the employee : " <<endl;
        cin >> salary;
    }

    void display()
    {
        cout << "Emp No : " <<empno;
        cout << endl << "Name : " << name << endl << "Department : " <<dept <<endl
             <<"Salary : " << salary <<endl;
    }

    int getempno()
    {
        return empno;
    }
};

int main()
{
    emp obj1;
    int eno;
    char ch = 'n';
    obj1.getdata();
    obj1.display();
    ifstream file1("emp.txt", ios:: in); // this file should already exist

    cout << "Enter the employee number to be searched for : " <<endl;
    cin >> eno;

    while(!file1.eof())
    {
        file1.read((char *)&obj1, sizeof(obj1));

        if(obj1.getempno()==eno)
        {
            obj1.display();
            ch = 'y';
            break;
        }
    }

    if(ch =='n')
        cout << "Record Not Found !!" << endl;
    file1.close();
}
