#include<iostream> 
using namespace std;
class Train { 
private:
int trainNumber;   
string trainName; 
string source; 
string destination;  
int availableSeats[3];  
public: 
void setTrainDetails(int tNo, string tName, string src, string dest, int seats[3]) {
trainNumber = tNo; 
trainName = tName;
source = src; 
destination = dest;  
for (int i = 0; i < 3; i++){  
availableSeats[i] = seats[i]; 
}
}
void displayTrainDetails() {
cout << "Train No.: " << trainNumber << endl; 
cout << "Train Name: " << trainName << endl; 
cout << "Source: " << source << endl; 
cout << "Destination: " << destination << endl; 
cout << "Available Seats: " << endl;
for (int i = 0; i < 3; i++) { 
cout << "Class " << i + 1 << ": " << availableSeats[i] << endl; 
}
}
int getTrainNumber() { 
return trainNumber;
}
string getTrainName() { 
return trainName; 
}
string getSource() {
return source; 
}
string getDestination() { 
return destination;
}
int* getAvailableSeats() {
return availableSeats; 
} 
};
class Passenger { 
private: 
string name;
int age; 
6 string gender;
int ticketNumber;
int seatClass;
int seatNumber;
public: 
void setPassengerDetails(string n, int a, string g, int tNo, int sClass, int sNo) {
name = n; 
age = a; 
gender = g;
ticketNumber = tNo; 
seatClass = sClass; 
seatNumber = sNo; 
}
void displayPassengerDetails() { 
cout << "Passenger Name: " << name << endl; 
cout << "Age: " << age << endl; 
cout << "Gender: " << gender << endl;
cout << "Ticket Number: " << ticketNumber << endl; 
cout << "Seat Class: " << seatClass << endl;
cout << "Seat Number: " << seatNumber << endl;
}
};
class ReservationSystem {
private:
Train trains[3]; 
Passenger passengers[9];
int ticketCounter = 1;
public: void initializeTrains() { 
int availableSeats[3] = {50, 50, 50}; 
trains[0].setTrainDetails(101, "Rajdhani Express", "Mumbai", "Delhi", availableSeats); availableSeats[0] = 40; 
availableSeats[1] = 30;
availableSeats[2] = 20; 
trains[1].setTrainDetails(102, "Shatabdi Express", "Bangalore", "Chennai", availableSeats); 
availableSeats[0] = 60;
availableSeats[1] = 50;
availableSeats[2] = 40; 
trains[2].setTrainDetails(103, "Duronto Express", "Kolkata", "Mumbai", availableSeats);
}
void displayTrainDetails(int trainNumber) { 
for (int i = 0; i < 3; i++) {
if (trains[i].getTrainNumber() == trainNumber) {
trains[i].displayTrainDetails(); 
return; 
}
} 
cout << " Train not found" << endl;
} 
if (trains[i].getTrainNumber() == trainNumber) { 
7 trains[i].displayTrainDetails(); 
return; 
}
else { 
cout << "Train not found" << endl; return; 
}
} 
void bookTicket(int trainNumber, string name, int age, string gender, int seatClass) {
for (int i = 0; i < 3; i++) {
if (trains[i].getTrainNumber() == trainNumber) {
int* availableSeats = trains[i].getAvailableSeats(); 
if (availableSeats[seatClass - 1] > 0) {
int ticketNumber = ticketCounter++;
int seatNumber = 50 - availableSeats[seatClass - 1] + 1; 
passengers[ticketNumber - 1].setPassengerDetails(name, age, gender, ticketNumber, seatClass, seatNumber); 
availableSeats[seatClass - 1]--;
cout << "Ticket booked successfully. Ticket Number: " << ticketNumber << endl; 
return;
}
else {
cout << "Sorry, no seats available in Class " << seatClass << endl; return;
}
}
}
cout << " Train not found" << endl;
return; 
} 
void displayPassengerDetails(int ticketNumber) { 
if (ticketNumber > 0 && ticketNumber <= 9) { 
passengers[ticketNumber - 1].displayPassengerDetails();
}
else {
cout << "Invalid Ticket Number" << endl;
}
}
};
int main() { ReservationSystem rs;
rs.initializeTrains();
int choice, trainNumber, age, seatClass, ticketNumber; 
string name, gender; 
while (true) { 
cout << "1. Display Train Details" << endl;
cout << "2. Book Ticket" << endl;
cout << "3. Display Passenger Details" << endl;
cout << "4. Exit" << endl; 
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
8 case 1:
cout << "Enter Train Number: ";
cin >> trainNumber;
rs.displayTrainDetails(trainNumber);
break;
case 2: 
cout << "Enter Train Number: ";
cin >> trainNumber;
cout << "Enter Passenger Name: ";
cin >> name; 
cout << "Enter Age: ";
cin >> age;
cout << "Enter Gender: ";
cin >> gender;
cout << "Enter Seat Class (1, 2, 3): ";
cin >> seatClass; 
rs.bookTicket(trainNumber, name, age, gender, seatClass);
break; case 3: cout << "Enter Ticket Number: "; 
cin >> ticketNumber; 
rs.displayPassengerDetails(ticketNumber);
break;
case 4: exit(0); 
default: cout << "Invalid choice" << endl;
} 
}
return 0;
}
