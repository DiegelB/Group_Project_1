/*
Programmers: Godwin, Ben, Ana
Program: Total days spent on trip and time of departure and return
Date: 9/18/17
Notes: 
*/

#include<iostream>
#include<cctype>
using namespace std;

// Function prototypes
int getTripLength();
double getDepartArriveTime();

//---------------main--------------
int main(){
    getTripLength();
    getDepartArriveTime();
    return 0;
}
//---------------main--------------

// this function asks the user how long (in days) that they spent on their trip
// it returns an integer
int getTripLength(){
    int numberOfDays;
    cout << "Please enter the amount of days you've spent on your trip.\n>>";
    cin >> numberOfDays;

    while(numberOfDays < 1){
        cout << "\nPlease enter only positive numbers.\n>>";
        cin >> numberOfDays;
    }

    return numberOfDays;
}

/* 
this function asks the user the hour and minute they departed or arrived for their trip
it returns the hours in military time (24-based time ex. 2:30pm = 14:30 military time)
it also rounds up to the nearest hour. if the minutes are above 30 it adds and hour
it returns a double just in case. not necessary.
 */
double getDepartArriveTime() {
    int hours, minutes;
    char userInput;

    /*
    this prompts the user to see if they left in the morning or the evening
    spliting it up like this helps return 24-based time, as well as round to the 
    nearest whole hour. 
    */
    cout << "\nPlease enter the time you departed/arrived for your trip.\n"
         << "Enter (A) if you departed/arrived in the A.M.\n"
         << "Enter (P) if you departed/arrived in the P.M.\n>>";
    cin >> userInput;

    userInput = toupper(userInput); // makes any input uppercase

    if(userInput == 'A'){ // if the user wants to enter an AM time
        cout << "\nPlease enter the hour that you departed/arrived.\n"
             << "Ex. If you left at 10:34 a.m., enter 10.\n>>";
        cin >> hours;

        // input validation, if their hours are less than 0 or more than
        // 12 then it asks for input again
        while(hours <= 0 || hours > 12){
            cout << "\nYou did not enter a correct time.\n"
                 << "Ex. If you left at 10:34 a.m., enter 10.\n>>";
            cin >> hours;
        }
        
        cout << "\nPlease enter the exact minute of the hour you departed/arrived.\n"
             << "Ex. If you left at 10:34 a.m., enter 34.\n>>";
        cin >> minutes;

        // input valdiation, if their minutes are less than 0 or more than
        // 59 it asks again. (the user cannot enter 60 to add another hour)
        while(minutes < 0 || minutes > 59){
            cout << "\nYou did not enter a correct time.\n"
                << "Ex. If you left at 10:00 a.m., enter 0.\n>>";
            cin >> minutes;
        }

        cout << hours << ":" << minutes << endl;

        // if the user's minutes are user 30 it keeps the hours the same
        // if they are equal or over 30 the  there is an extra hour added to their
        // overall hours.
        if(minutes < 30){
            hours = hours;
        }
        else{
            hours = hours + 1;
            cout << hours << endl;
        }
    }//------------------------------------AM/PM-Seperator----------------------------------------------
    else if(userInput == 'P'){
        // if the user wants to enter an PM time
        cout << "\nPlease enter the hour that you departed/arrived.\n"
        << "Ex. If you left at 10:34 p.m., enter 10.\n>>";
        cin >> hours;

        // input validation, if their hours are less than 0 or more than
         // 12 then it asks for input again
        while(hours <= 0 || hours > 12){
            cout << "\nYou did not enter a correct time.\n"
                 << "Ex. If you left at 10:34 p.m., enter 10.\n>>";
            cin >> hours;
        }

        hours = hours + 12; // this converts their hours to 24-based/military time
   
        cout << "\nPlease enter the exact minute of the hour you departed/arrived.\n"
             << "Ex. If you left at 10:34 p.m., enter 34.\n>>";
        cin >> minutes;

        // input valdiation, if their minutes are less than 0 or more than
        // 59 it asks again. (the user cannot enter 60 to add another hour)
        while(minutes < 0 || minutes > 59){
            cout << "\nYou did not enter a correct time.\n"
                 << "Ex. If you left at 10:00 p.m., enter 0.\n>>";
            cin >> minutes;
        }

        cout << hours << ":" << minutes << endl;

        // if the user's minutes are user 30 it keeps the hours the same
        // if they are equal or over 30 the  there is an extra hour added to their
        // overall hours.
        if(minutes < 30){
            hours = hours;
        }
        else{
            hours = hours + 1;
            cout << hours << endl;
        }
    }
    return hours;
}
