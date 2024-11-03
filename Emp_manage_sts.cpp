// Employee Managemant System with file handling using C++


#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class employee
{
private:
    int employee_id, salary, group_id;
    string name, address;

public:
    void menu();
    void insert();
    void display();
    void search();
    void modify();
    void deletes();
    void group();
    void search_group();
    void show_group();
};

void login()
{
    p:
    system("cls");

    char ch;
    string user,pass;

    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t <<:=====================================================================:>>";
    cout<<"\n\n\t\t\t\t\t\t .....Login Process.....";
    cout<<"\n\n\t\t\t <<:=====================================================================:>>";
    cout<<"\n\n\n Enter User_Name :)  ";
    cin>>user;
    cout<<"\n\n Enter Passwerd :) ";

    for(int i=1; i<=6; i++)
    {
        ch = getch();
        pass += ch;
        cout<<"*";
    }

    if(user == "Md_Umar" &&  pass ==  "Mdayan")
    {
        cout<<"\n\n\n \t\t\t\t.....Login Successfully......";
        cout<<"\n\n\n\t\t\t\t\t\t Loading";

        for(int i=1; i<=6; i++)
        {
            Sleep(500);
            cout<<".";
        }
    } 

    else if(user != "Md_Umar" &&  pass ==  "Mdayan")
    {
        cout<<"\n\n\n Your User Name is Wrong.....";
        getch();
        goto p;
    }

    else if(user == "Md_Umar" &&  pass !=  "Mdayan")
    {
        cout<<"\n\n\n Your User Password is Wrong.....";
        getch();
        goto p;
    }

    else
    {
        cout<<"\n\n\n User Name & Password Both are Wrong..... ";
        getch();
        exit(0);
    }


}

void employee::menu()
{
p:
    system("cls");
    int x;

    cout << "\n\n\t\t\t\t\t\t\t (: Control panel :) " << endl;
    cout << "\n\n\n 1. Insert Record : " << endl;
    cout << " 2. Display Record : " << endl;
    cout << " 3. Search Record : " << endl;
    cout << " 4. Modify Record : " << endl;
    cout << " 5. Delete Record : " << endl;
    cout << " 6. Group Record : " << endl;
    cout << " 7. Search Group : " << endl;
    cout << " 8. Show All Group : " << endl;
    cout << " 9. Exit : " << endl;
    cout << "\n\n Enter Your choice to check : ";

    cin >> x;

    switch (x)
    {
    case 1:
        insert();
        break;

    case 2:
        display();
        break;
    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deletes();
        break;

    case 6:
        group();
        break;

    case 7:
        search_group();
        break;

    case 8:
        show_group();
        break;

    case 9:
        cout << "\nYou are Exit From This Program " << endl;
        cout << "Thanks" << endl;
        exit(0);

    default:
        cout << "\n Your choice is invalid .... Please try Again....";
    }

    getch();
    goto p;
}

void employee::insert()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1;

    cout << "\n\n\t\t\t\t\t\t Insert Record : ";

    cout << "\n\n\n Employee ID : ";
    cin >> employee_id;

    cout << "\n\n\t\t Employee Name : ";
    cin >> name;

    cout << "\n\n Employee Salary : ";
    cin >> salary;

    cout << "\n\n\t\t Employee Address : ";
    cin >> address;

    cout << "\n\n Employee Group ID : ";
    cin >> group_id;

    file.open("Employee.txt", ios::out | ios::app);
    file << " " << employee_id << "                   " << name << "                    " << salary << "                     " << address << "                       " << group_id << endl;
    file.close();

    file1.open("group.txt", ios::out | ios::app);
    file1 << " " << group_id << "                " << employee_id << "                    " << salary << endl;
    file1.close();

    file.open("groupid.txt", ios::in);
    if (!file)
    {
        file1.open("groupid.txt", ios::app | ios::out);
        file1 << " " << group_id << endl;
        file1.close();
    }
    else
    {
        file >> test_id;
        while (!file.eof())
        {
            if (test_id == group_id)
                found++;
            file >> test_id;
        }
        file.close();
        if (found == 0)
        {
            file1.open("groupid.txt", ios::app | ios::out);
            file1 << " " << group_id << endl;
            file1.close();
        }
    }

    cout << "\n\n\n\t\t\t .... New Record Inserted Successfully...." << endl;
}

void employee::display()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t\t\t\t Display Record : ";
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\n .....File Openning Error.....";
        getch();
        menu();
    }
    file >> employee_id >> name >> salary >> address >> group_id;
    while (!file.eof())
    {
        cout << "\n\n\n\n Employee Id : " << employee_id;
        cout << "\n\n\t\t\t Employee Name : " << name;
        cout << "\n\n Employee Salary : " << salary;
        cout << "\n\n\t\t\t Employee Address : " << address;
        cout << "\n\n Employee group_id : " << group_id;
        file >> employee_id >> name >> salary >> address >> group_id;

        cout << "\n___________________________________________________________________________________________";
    }

    file.close();
}

void employee::search()
{
    system("cls");
    fstream file;
    int employee_idd, found = 0;
    cout << "\n\n\t\t\t\t\t\t Search Record : ";
    file.open("Employee.txt", ios::in);
    if (!file)
    {
        cout << "\n\n .....File Openning Error.....";
        getch();
        menu();
    }

    cout << "\n\n Employee Id for Search : ";
    cin >> employee_idd;

    file >> employee_id >> name >> salary >> address >> group_id;
    while (!file.eof())
    {
        if (employee_idd == employee_id)
        {
            system("cls");
            cout << "\n\n\n\t\t\t\t Search Record : ";
            cout << "\n\n Employee Id : " << employee_id;
            cout << "\n\n\t\t\t Employee Name : " << name;
            cout << "\n\n Employee Salary : " << salary;
            cout << "\n\n\t\t\t Employee Address : " << address;
            cout << "\n\n Employee group_id : " << group_id;
            found++;
        }
        file >> employee_id >> name >> salary >> address >> group_id;

        cout << "\n___________________________________________________________________________________________";
    }

    file.close();
    if (found == 0)
    {
        cout << "\n\n ......Employe Id Can not found......";
    }
}

void employee::modify()
{
    system("cls");
    int salary1, test_id, found = 0;
    string name1, address1;
    fstream file, file1, file2, file3;
    cout << "\n\n\t\t\t\t Modify Record";
    file.open("Employee.txt", ios::in);
    file1.open("group.txt", ios::in);
    if (!file || !file1)
    {
        cout << "\n\n .....File Opening Error.....";
        getch();
        menu();
    }
    cout << "\n\n Employee Id For Modify : ";
    cin >> test_id;
    file2.open("Employee1.txt", ios::app | ios::out);
    file >> employee_id >> name >> salary >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == employee_id)
        {
            system("cls");
            cout << "\n\n\t\t\t\t Modify Record ";
            cout << "\n\n\n Employee Name : ";
            cin >> name1;

            cout << "\n\n\t\t Employee Salary  : ";
            cin >> salary1;

            cout << "\n\n Employee Address : ";
            cin >> address1;

            file2 << " " << employee_id << "                   " << name1 << "                    " << salary1 << "                     " << address1 << "                       " << group_id << endl;
            found++;
        }

        else
        {
            file2 << " " << employee_id << "                   " << name << "                    " << salary << "                     " << address << "                       " << group_id << endl;
        }
        file >> employee_id >> name >> salary >> address >> group_id;
    }
    file.close();
    file2.close();
    remove("Employee.txt");
    rename("Employee1.txt", "Employee.txt");
    file3.open("group1.txt", ios::app | ios::out);
    file1 >> group_id >> employee_id >> salary;
    while (!file.eof())
    {
        if (test_id == employee_id)
        {
            file3 << " " << group_id << " " << employee_id << " " << salary1 << "\n";
        }

        else
        {
            file3 << " " << group_id << " " << employee_id << " " << salary << "\n";
            file1 >> group_id >> employee_id >> salary;
        }
    }
    file1.close();
    file3.close();
    remove("group.txt");
    rename("group1.txt", "group.txt");
    if (found == 0)
    {
        cout << "\n\n .....Employee ID can Not Found......";
    }
    else
    {
        cout << "\n\n\t\t\t\t .....Record Modify SuccessFully......";
    }
}

void employee::deletes()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1, file2, file3;
    cout << "\n\n\t\t\t\t Delete Record : ";
    file.open("Employee.txt", ios::in);
    file1.open("group.txt", ios::in);
    if (!file || !file1)
    {
        cout << "\n\n .....File Opening Error.....";
        getch();
        menu();
    }
    cout << "\n\n Empolyee ID For Delete : ";
    cin >> test_id;
    file2.open("employee1.txt", ios::app | ios::out);
    file >> employee_id >> name >> salary >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == employee_id)
        {
            cout << "\n\n\t .....Record Deleted SuccessFully.....";
            found++;
        }

        else
        {
            file2 << " " << employee_id << "                   " << name << "                    " << salary << "                     " << address << "                       " << group_id << endl;
        }
        file >> employee_id >> name >> salary >> address >> group_id;
    }
    file.close();
    file2.close();
    remove("Employee.txt");
    rename("Employee1.txt", "Employee.txt");

    file3.open("group1.txt", ios::app | ios::out);

    file1 >> group_id >> employee_id >> salary;
    while (!file.eof())
    {
        if (test_id != employee_id)
        {
            file3 << " " << group_id << " " << employee_id << " " << salary << "\n";
            file1 >> group_id >> employee_id >> salary;
        }
    }
    file1.close();
    file3.close();
    remove("group.txt");
    rename("group1.txt", "group.txt");
    if (found == 0)
    {
        cout << "\n\n .....Employee ID Can not Found.....";
    }
}

void employee::group()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t\t Group Record : ";
    file.open("group.txt", ios::in);
    if (!file)
    {
        cout << ".....File Opening Error.....";
        getch();
        menu();
    }
    file >> group_id >> employee_id >> salary;
    while (!file.eof())
    {
        cout << "\n\n\n\n Group ID : " << group_id;
        cout << "\n\n\t\t Employee ID : " << employee_id;
        cout << "\n\n\t\t Employee Salary : " << salary;
        file >> group_id >> employee_id >> salary;
    }

    file.close();
}

void employee::search_group()
{
    system("cls");
    int test_id, found = 0, emp_count = 0, salary_count = 0;
    fstream file;
    cout << "\n\n\t\t\t\t Search Group Record : ";
    file.open("group.txt", ios::in);
    if (!file)
    {
        cout << "\n\n .....File Opening Error.....";
        getch();
        menu();
    }
    cout << "\n\n Group ID For Search : ";
    cin >> test_id;
    system("cls");
    cout << "\n\n\t\t\t\t Search Group Record : ";
    file >> group_id >> employee_id >> salary;
    while (!file.eof())
    {
        if (test_id == group_id)
        {
            cout << "\n\n\n Group ID : " << group_id;
            cout << "\n\n\t\t\t\t Employee ID : " << employee_id;
            cout << "\n\n\n Employee Salary : " << salary;
            found++;
            emp_count++;
            salary_count = salary_count + salary;
        }
        file >> group_id >> employee_id >> salary;
    }
    file.close();
    if (found != 0)
    {
        cout << "\n\n\n Group ID : " << test_id;
        cout << "\n\n\t\t Total Employee : " << emp_count;
        cout << "\n\n\n Total Salary : " << salary_count;
    }
    else
    {
        cout << "\n\n .....Group ID Can not Found.....";
    }
}

void employee::show_group()
{
    system("cls");
    int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
    fstream file,file1;
    cout << "\n\n\t\t\t\t Show All Groups : ";
    file.open("groupid.txt", ios::in);
    if (!file)
    {
        cout << "\n\n .....File Opening Error......";
        getch();
        menu();
    }
    file>>test_id;
    while(!file.eof())
    {
        file1.open("group.txt", ios::in);
        file1>>group_id>>employee_id>>salary;
        while(!file1.eof())
        {
            if (test_id == group_id)
            {
                emp_count++;
                sal_count += salary;
                emp_total++;
                sal_total += salary;
            }
            file1 >> group_id >> employee_id >> salary;
        }
        file1.close();
        cout<<"\n\n\n\n Group ID : "<< test_id;
        cout<<"\n\n\t\t Total Employee  : "<< emp_count;
        cout<<"\n\n Total Salary : "<< sal_count;
        
        emp_count==0;
        sal_count==0;
        
        file>>test_id;
    }
    file1.close();
    cout<<"\n\n\n\n Over All Employee : "<< emp_total;
    cout<<"\n\n\t\t Over All Salary : "<< sal_total;
}

int main()
{
    employee e;

    login();
    e.menu();

    return 0;
}
