#include "TravelAgency.h"
#include "Employee.h"
#include "Client.h"
#include "SuperUser.h"

#include <iostream>

// Agency functions 
TravelAgency::TravelAgency(string _name, string _address)
{
    name = _name;
	address = _address;
	employee_number = 0;
	client_number = 0;
    superUser_number = 0;
    travel_number = 0;
    booking_number = 0;
    payment_number = 0;
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
void TravelAgency::addSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    SuperUser superUser;
    superUser.createSuperUser(_email, _username, _password, _name, _surname, _address);
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
//

// Employee functions

void TravelAgency::addEmployee(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    Employee employee;
    employee.createEmployee(_email, _username, _password, _name, _surname, _address);
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

        // Travel functions
        void TravelAgency::pbTravel(Travel travel)
        {
            tab_travel.push_back(travel);
            travel_number++;
        }

        void TravelAgency::publishTravel(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].setIsPublishedTrue();
                }
            }
        }

        void TravelAgency::unPublishTravel(int _travel_id)
        {
            int a = 0;
            for (int i = 0; i < booking_number; i++)
            {
                if (tab_booking[i].getTravelID() == _travel_id)
                {
                    a++;
                }
            }

            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id && a == 0)
                {
                    tab_travel[i].setIsPublishedFalse();
                }
                else
                {
                    cout << "Someone has already booked this travel.." << endl;
                }
            }  
        }

        void TravelAgency::printTravel()
        {
            for (int i = 0; i < travel_number; i++)
            {
                tab_travel[i].print();
            }
        }

        void TravelAgency::updateTravel(int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].updateTravel(_destination, _place_available, _start_date, _end_date, _duration);
                }    
            }
        }

        void TravelAgency::deleteTravel(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    if (!tab_travel[i].getIsPublished())
                    {
                        tab_travel.erase(tab_travel.begin() + i);
                    }
                    else
                    {
                        cout << "Travel to " << tab_travel[i].getTitle() << " is published.." << endl;
                    }
                }
            }
            travel_number--;

            for (int i = 0; i < travel_number; i++)
            {
                tab_travel[i].setID(i);
            }
            
        }

        // Hotel functions
        void TravelAgency::addHotel(int _travel_id, int _night_number, string _address, string _name, double _price)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].addHotel(_night_number, _address, _name, _price);
                }
            }
        }

                void TravelAgency::updateHotel(int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price)
                {
                    for (int i = 0; i < travel_number; i++)
                    {
                        if (tab_travel[i].getID() == _travel_id)
                        {
                            tab_travel[i].updateHotel(_hotel_id, _night_number, _address, _name, _price);
                        }
                    }
                }

        void TravelAgency::deleteHotel(int _travel_id, int _hotel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].deleteHotel(_hotel_id);
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
void TravelAgency::addClient(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    Client client;
    client.createClient(_email, _username, _password, _name, _surname, _address);
    client.setID(client_number);
    tab_client.push_back(client);
    client_number++;
}

        void TravelAgency::printTravelForClient()
        {
            for (int i = 0; i < travel_number; i++)
            {
                tab_travel[i].printForClient();
            }
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

        // Booking functions
        void TravelAgency::addBooking(int _client_id, int _travel_id)
        {
            if (tab_travel[_travel_id].getIsPublished())
            {                   
                if (checkAvaibilityToBook(_travel_id))
                {           
                    Booking booking(_travel_id);
                    booking.setClientID(_client_id);
                    for (int i = 0; i < client_number; i++)
                    {
                        if (tab_client[i].getID() == _client_id)
                        {
                            booking.setID(tab_client[i].getBookingNumber());
                            tab_client[i].setBookingNumber(1);
                        }            
                    }
                    for (int i = 0; i < travel_number; i++)
                    {
                        if (tab_travel[i].getID() == _travel_id)
                        {
                            booking.setTravelPrice(tab_travel[i].getPrice());
                            booking.setTitle(tab_travel[i].getTitle());
                        }
                    }
                    tab_booking.push_back(booking);
                    booking_number++;
                }
                else
                {
                    for (int i = 0; i < travel_number; i++)
                    {
                        if (tab_travel[i].getID() == _travel_id)
                        {
                            cout << "No more places available for the travel to " << tab_travel[i].getTitle() << endl;
                        } 
                    }     
                } 
            }
        }
        
                
                void TravelAgency::printBooking(int _client_id)
                {
                    for (int i = 0; i < booking_number;i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id)
                        {
                            tab_booking[i].print();
                        }
                    }    
                }

                void TravelAgency::printAppliedBooking(int _client_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getIsFinished())
                        {
                            tab_booking[i].print();
                        }
                    }
                }

                bool TravelAgency::checkAvaibilityToBook(int _travel_id)
                        {
                            for (int i = 0; i < travel_number; i++)
                            {
                                if (tab_travel[i].getID() == _travel_id)
                                {   
                                    if (tab_travel[i].getPlaceAvailable() != 0)
                                    {
                                        return true;
                                    }
                                }       
                            } 
                            return false;
                        }

                void TravelAgency::applied(int _client_id, int _booking_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                        {
                            tab_booking[i].setIsFinished(true);
                        }
                    }
                }

                void TravelAgency::unapplied(int _client_id, int _booking_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                        {
                            tab_booking[i].setIsFinished(false);
                        }
                    }
                }

                // Plane functions
                void TravelAgency::addPlane(int _client_id, int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _bookind_id)
                        {
                            tab_booking[i].addPlane(_flight_id, _date, _a_to_b, _ad_time, _price);
                        }
                    }
                }

                        void TravelAgency::updatePlane(int _client_id, int _booking_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
                        {
                            for (int i = 0; i < booking_number; i++)
                            {
                                if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                                {
                                    tab_booking[i].updatePlane(_plane_id, _flight_id, _date, _a_to_b, _ad_time, _price);
                                }
                            }                            
                        }
                    
                void TravelAgency::deletePlane(int _client_id, int _booking_id, int _plane_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                        {
                            tab_booking[i].deletePlane(_plane_id);
                        }
                    }
                }

                // Train functions
                void TravelAgency::addTrain(int _client_id, int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _bookind_id)
                        {
                            tab_booking[i].addTrain(_train_number_id, _date, _a_to_b, _ad_time, _price);
                        }
                    }
                }

                        void TravelAgency::updateTrain(int _client_id, int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
                        {
                            for (int i = 0; i < booking_number; i++)
                            {
                                if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _bookind_id)
                                {
                                    tab_booking[i].updateTrain(_train_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
                                }
                                
                            }
                            
                        }

                void TravelAgency::deleteTrain(int _client_id, int _booking_id, int _train_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                        {
                            tab_booking[i].deleteTrain(_train_id);
                        }                      
                    }                  
                }

                // Payment functions
                void TravelAgency::createPayment(int _client_id, int _booking_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {   
                        // Select the booking made by the client
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                        {   
                            // In case if the client try to paid a second time (without any booking modification)
                            if (!tab_booking[i].getIsPayed())
                            {
                                double amount_paid = 0;
                                // Function to compute the amount paid
                                for (int i = 0; i < payment_number; i++)
                                {
                                    if (tab_payment[i].getClientID() == _client_id && tab_payment[i].getBookingID() == _booking_id)
                                    {
                                        amount_paid += tab_payment[i].getAmount();                             
                                    }
                                }
                                // Does the compagny refund the customer ?
                                if (amount_paid > tab_booking[i].getTotalDue())
                                {
                                    cout << "We will refund your " << amount_paid - tab_booking[i].getTotalDue() << "€ ASAP.." << endl;
                                    Payment payment(_client_id, _booking_id, tab_booking[i].getTotalDue() - amount_paid);
                                    payment.setID(tab_client[_client_id].getPaymentNumber());
                                    payment.setIsRefund(true);
                                    tab_payment.push_back(payment);
                                    payment_number++;
                                }
                                else if (amount_paid == tab_booking[i].getTotalDue())
                                {
                                    
                                    cout << "Nothing to do, you already paid " << amount_paid << "€ for the trip to " << tab_booking[i].getTitle() << ".." << endl;
                                }
                                else
                                {
                                    Payment payment(_client_id, _booking_id, tab_booking[i].getTotalDue() - amount_paid);
                                    payment.setID(tab_client[_client_id].getPaymentNumber());
                                    tab_payment.push_back(payment);
                                    payment_number++;
                                    cout << "You paid " << tab_booking[i].getTotalDue() - amount_paid << "€ to go in " << tab_booking[i].getTitle() << ".." << endl;
                                }
                                tab_booking[i].setIsPayed(true);         
                            }
                            else
                            {
                                cout << "You already paid to go in " << tab_booking[i].getTitle() << ".." << endl; 
                            }       
                        }
                    }
                }

                bool TravelAgency::checkIfIsApplied(int _client_id, int _booking_id)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id && tab_booking[i].getIsFinished())
                        {
                            return true;
                        }
                    }
                    return false;
                }

                void TravelAgency::printPayment(int _client_id)
                {
                    cout << "payment:" << endl;
                    for (int i = 0; i < payment_number; i++)
                    {
                        if (tab_payment[i].getClientID() == _client_id)
                        {
                            tab_payment[i].print();
                        }
                    }
                }

            void TravelAgency::deleteBooking(int _client_id, int _booking_id)
            {
                int money_to_refund = 0;
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getClientID() == _client_id && tab_booking[i].getID() == _booking_id)
                    {
                        for (int i = 0; i < payment_number; i++)
                        {
                            if (tab_payment[i].getClientID() == _client_id && tab_payment[i].getBookingID() == _booking_id && !tab_payment[i].getIsRefund())
                            {
                                money_to_refund += tab_payment[i].getAmount();
                                tab_payment[i].setIsRefund(true);
                            }
                        }
                        tab_booking.erase(tab_booking.begin() + i);
                    }                    
                }
                if (money_to_refund != 0)
                {
                    cout << "We will contact you soon to refund your " << money_to_refund << "€.." << endl;
                }
                booking_number--;
                for (int i = 0; i < client_number; i++)
                {
                    if (tab_client[i].getID() == _client_id)
                    {
                        tab_client[i].setBookingNumber(-1);
                    } 
                }
                int a = 0;
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getClientID() == _client_id)
                    {
                        tab_booking[i].setID(a);
                        a++;
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

// Getter

    int TravelAgency::getTravelNbr()
    {
        return travel_number;
    }

//

// Setter

    void TravelAgency::setTravelNbr(int _travel_number)
    {
        travel_number = _travel_number;
    }

//








