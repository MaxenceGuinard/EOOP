#include "TravelAgency.h"

#include <iostream>

TravelAgency::~TravelAgency()
{
    cout << "Travel agency succesfully deleted." << endl;
}

TravelAgency::TravelAgency(string initializer_name, string initializer_address)
{
    name = initializer_name;
	address = initializer_address;
	employee_number = 0;
	client_number = 0;
    bankrupt_flag = 0;
    addSuperUser("superUser@e.com", "admin", "password", "name0", "surname", "Address 0");
}

void TravelAgency::showAgencyDetails()
{
    cout << "Name: ------------------- " << name << endl;
    cout << "Address: ---------------- " << address << endl;    
    cout << "Number of employee: ----- " << employee_number << endl;
    cout << "Number of client: ------- " << client_number << endl;
}

void TravelAgency::addEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    Employee employee;
    employee.createEmployee(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    employee.setID(employee_number);
    tab_employee.push_back(employee);
    employee_number++;
}

void TravelAgency::removeEmployee(int id)
{
    if((bankrupt_flag == 0 && id != 0) || bankrupt_flag == 1)
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
    else
    {
        cout << "\nError: You can't remove the admin account." << endl;
    }
}

void TravelAgency::printEmployee()
{
    for (int i = 0; i < employee_number; i++)
    {
        tab_employee[i].printEmployee();
    }
}

void TravelAgency::addClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    Client client;
    client.createClient(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    client.setID(client_number);
    tab_client.push_back(client);
    client_number++;
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
        tab_client[i].setID(id);
    }
}

void TravelAgency::printClient()
{   
    for (int i = 0; i < client_number; i++)
    {
        tab_client[i].printClient();
    }
}

void TravelAgency::addSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    SuperUser superUser;
    superUser.createSuperUser(initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    superUser.setID(employee_number);
    tab_employee.push_back(superUser);
    employee_number++;
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
