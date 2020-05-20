#include "TravelAgency.h"

#include <iostream>

// Agency functions 
TravelAgency::TravelAgency(string initializer_name, string initializer_address)
{
    name = initializer_name;
	address = initializer_address;
	employee_number = 0;
	client_number = 0;
    superUser_number = 0;
    bankrupt_flag = 0;
    addSuperUser("superuser@etravel.com", "admin", "password", "name", "surname", "Address");
}

        void TravelAgency::showAgencyDetails()
        {
            cout << "Name: ------------------- " << name << endl;
            cout << "Address: ---------------- " << address << endl;    
            cout << "Number of employee: ----- " << employee_number << endl;
            cout << "Number of client: ------- " << client_number << endl;
            cout << "Number of SuperUser: ---- " << superUser_number << endl;
        }

        void TravelAgency::bankrupt()
        {
            bankrupt_flag = 1;
            int client_number_to_remove = client_number;
            int employee_number_to_remove = employee_number;

            for (int i = 0; i < client_number_to_remove; i++)
            {
                removeClient(client_number - 1);
            }
    
            for (int i = 0; i < employee_number_to_remove; i++)
            {
                removeEmployee(employee_number - 1);
            }

            this->~TravelAgency();
        }

TravelAgency::~TravelAgency()
{
    cout << "Travel agency succesfully deleted." << endl;
}

// SuperUser functions
void TravelAgency::addSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    SuperUser superUser;
    superUser.createSuperUser(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    superUser.setSUID(superUser_number);
    tab_superUser.push_back(superUser);
    superUser_number++;
}

        void TravelAgency::printSuperUser()
        {
            tab_superUser[0].printSuperUser();
        }

        void TravelAgency::superUserLogin(string email, string password)
        {
            bool find_someone = false;
            if (tab_superUser[0].getEmail() == email && tab_superUser[0].getPassword() == password)
            {
                tab_superUser[0].login();
                find_someone = true;        
            }        
        
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        SuperUser TravelAgency::returnSuperUser()
        {
            return tab_superUser[0];
        }
        
        void TravelAgency::setSuperUser(SuperUser tempSuperUser)
        {
            tab_superUser[0] = tempSuperUser;
        }


// Employee functions

void TravelAgency::addEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    Employee employee;
    employee.createEmployee(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    employee.setID(employee_number);
    tab_employee.push_back(employee);
    employee_number++;
}

        void TravelAgency::printEmployee()
        {
            for (int i = 0; i < employee_number; i++)
            {
                tab_employee[i].printEmployee();
            }
        }

        void TravelAgency::employeeLogin(string email, string password)
        {
            bool find_someone = false;
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].getEmail() == email && tab_employee[i].getPassword() == password)
                {
                    tab_employee[i].login();
                    find_someone = true;        
                }        
            }
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        Employee TravelAgency::returnEmployee()
        {
            int a;
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].isLogin())
                {
                    a = i;
                }
            } 
            return tab_employee[a];
        }

        void TravelAgency::setEmployee(Employee tempEmployee)
        {
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].getID() == tempEmployee.getID() && tab_employee[i].isLogin())
                {
                    tab_employee[i] = tempEmployee;
                } 
            }
        }

void TravelAgency::removeEmployee(int id)
{
    for (int i = 0; i < employee_number; i++)
    {
        if(tab_employee[i].getID() == id)
        {
            tab_employee.erase(tab_employee.begin() + i);
        }
    }
    employee_number--;    
    
    for (int i = id; i < employee_number; i++)
    {
        tab_employee[i].setID(i);
    }
}


// Client functions
void TravelAgency::addClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    Client client;
    client.createClient(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    client.setID(client_number);
    tab_client.push_back(client);
    client_number++;
}

        void TravelAgency::printClient()
        {   
            for (int i = 0; i < client_number; i++)
            {
            tab_client[i].printClient();
            }
        }

        void TravelAgency::clientLogin(string email, string password)
        {
            bool find_someone = false;
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].getEmail() == email && tab_client[i].getPassword() == password)
                {
                    tab_client[i].login();
                    find_someone = true;
                }
            }
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        Client TravelAgency::returnClient()
        {
            int a;
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].isLogin())
                {
                    a = i;
                }
            }
            return tab_client[a];
        }

        void TravelAgency::setClient(Client tempClient)
        {
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].getID() == tempClient.getID())
                {
                    tab_client[i] = tempClient;
                }
            }
        }
        

void TravelAgency::removeClient(int id)
{

    for (int i = 0; i < client_number; i++)
    {
        if(tab_client[i].getID() == id)
        {
            tab_client.erase(tab_client.begin() + i);
        }
    } 
    client_number--;

    for (int i = id; i < client_number; i++)
    {
        tab_client[i].setID(i);
    }
}










