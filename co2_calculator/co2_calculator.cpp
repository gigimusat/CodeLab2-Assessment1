// CO2 Calculator - Programming Skills Portfolio
// Calculates CO2 emissions from transport, electricity, and book printing.

#include <iostream> // for cout, cin
using namespace std;// avoid std:: prefix for common names

// Constants for CO2 emissions per unit
const double CAR = 0.20;
const double BUS = 0.10;
const double TRAIN = 0.04;
const double FLIGHT = 0.25;
const double ELECTRICITY = 0.40;
const double BOOK_PAGE = 0.0007;

// Function to read an integer from user input with error checking
int readInt(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();            // reset the error state
        cin.ignore(1000, '\n'); // ignore the rest of the line
        cout << "That is not a number. Try again: ";
    }
    cin.ignore(1000, '\n');
    return value;
}
 
// Function to read a positive double from user input with error checking
double readPositive(string prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value) || value < 0) {
        cin.clear();           // reset the error state
        cin.ignore(1000, '\n'); // ignore the rest of the line
        cout << "Please enter a number that is 0 or more: ";
    }
    cin.ignore(1000, '\n');
    return value;
}

// Function to calculate CO2 emissions from transport
void transport() {
    int type;
    double km;
    cout << "1. Car  2. Bus  3. Train  4. Flight\nChoice: ";
    cin >> type;
    cout << "Distance in km: ";
    cin >> km;
// Calculate and display emissions based on transport type
    if (type == 1) cout << "Emissions: " << km * CAR << " kg CO2e\n";
    else if (type == 2) cout << "Emissions: " << km * BUS << " kg CO2e\n";
    else if (type == 3) cout << "Emissions: " << km * TRAIN << " kg CO2e\n";
    else if (type == 4) cout << "Emissions: " << km * FLIGHT << " kg CO2e\n";
    else cout << "Invalid choice.\n";
}
// Function to calculate CO2 emissions from electricity usage
void electricity() {
    double kwh;
    cout << "kWh used: ";
    cin >> kwh;
    cout << "Emissions: " << kwh * ELECTRICITY << " kg CO2e\n";
}
// Function to calculate CO2 emissions from book printing
void bookPrinting() {
    double pages;
    cout << "Pages printed: ";
    cin >> pages;
    cout << "Emissions: " << pages * BOOK_PAGE << " kg CO2e\n";
}
// Main function: entry point of the program
int main() {
    int choice = -1;
    while (choice != 0) {
        cout << "\n=== CO2 Calculator ===\n";
        cout << "1. Transport\n2. Electricity\n3. Book Printing\n0. Exit\nChoice: ";
        cin >> choice;
// Handle user choices
        if (choice == 1) transport();
        else if (choice == 2) electricity();
        else if (choice == 3) bookPrinting();
        else if (choice != 0) cout << "Invalid choice.\n";
    }
    cout << "Goodbye!\n";
    return 0;
}
