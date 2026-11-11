// Alexa Make a Joke - Programming Skills Portfolio
// Each line of randomJokes.txt is "setup?punchline".


#include <iostream> // used for input/output
#include <fstream> // used to read from a file
#include <string>  // used for string type
#include <vector> // used to store jokes in a dynamic array
#include <cstdlib> // used to generate random numbers
#include <ctime> // used to seed the random number generator
using namespace std; // used to avoid std:: prefix for common names
 
// Joke struct: represents a single joke with a setup and punchline
struct Joke {
    string setup;
    string punchline;
};
// Main function: entry point of the program
int main() {
    vector<Joke> jokes;
// Read jokes from randomJokes.txt
    ifstream file("randomJokes.txt");
    if (!file.is_open()) {
        cout << "Could not open randomJokes.txt\n";
        return 1;
    }
// Read each line from the file and split into setup and punchline
    string line;
    while (getline(file, line)) {
        int pos = line.find('?');  // find the question mark that separates setup and punchline
        if (pos != string::npos) { // if a question mark is found
            Joke j;
            j.setup = line.substr(0, pos + 1); // include the question mark in the setup
            j.punchline = line.substr(pos + 1); // everything after the question mark is the punchline
            jokes.push_back(j); // add the joke to the vector
        }
    }
    file.close(); // close the file after reading all jokes
      //Without any jokes, the program cannot function, so we check if the vector is empty
    if (jokes.size() == 0) {
        cout << "No jokes found in randomJokes.txt\n";
        return 1;
    }

    srand(time(0));  // seed the random number generator with the current time

 // User interaction loop: lets the user request jokes or quit
    string input;
    while (input != "quit") {
        cout << "\nType 'joke' for a joke or 'quit' to exit: "; // prompt the user for input
        getline(cin, input);
// If the user types "joke", select a random joke and display it
        if (input == "joke") {
            Joke j = jokes[rand() % jokes.size()]; // select a random joke from the vector
            cout << "Alexa: " << j.setup << "\n"; // display the setup
            cout << "(press Enter)"; // prompt the user to press Enter before showing the punchline
            getline(cin, input); // wait for the user to press Enter before showing the punchline
            cout << "Alexa: " << j.punchline << "\n"; // display the punchline
        }
    }
    cout << "Goodbye!\n";
    return 0;
}
