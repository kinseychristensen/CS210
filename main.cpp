/******************************************************************************
This program analyzes frequency of produce items for Corner Grocer. It creates
a backup report and allows a user to search by term, print a frequency report
with either numbers or a visual representation of units sold.
Created for CS 210 Project Three.

Author: Kinsey Christensen
Date: 08/08/2023
*******************************************************************************/

#include <iostream>
#include <string>
#include <map> 
#include <iomanip>
#include <fstream>
using namespace std;
#include "ProduceReport.h"



void printMenu() {
    cout << "Corner Grocer Produce Tracker" << endl;
    cout << endl;
    cout << "1 - Search by Item" << endl;
    cout << "2 - Item Frequency Report" << endl;
    cout << "3 - Item Frequency Visual Report" << endl;
    cout << "4 - Quit" << endl;
    cout << endl;
}



int main() {
    char menuChoice = '0';       //menu selection


   //create new class object for produce report
    ProduceReport TodayReport;

    //calls functions to open provided file, create map, create report, then close files
    TodayReport.openFile();
    TodayReport.createMap();
    TodayReport.createReport();
    TodayReport.closeReport();
    TodayReport.closeFile();

    //looping menu
    while (menuChoice != '4') {
        printMenu();
        cin >> menuChoice;

        switch (menuChoice) {
        case '1':       //Prints frequency of user-entered item
            TodayReport.searchByItem();
            break;

        case '2':       //Prints results with numeric counter
            TodayReport.printReport();
            break;

        case '3':       //Prints results with visual counter
            TodayReport.printVisualReport();
            break;

        case '4':       //quit
            break;

        default:        //invalid entry message
            cout << "Please enter a valid menu option." << endl;
            break;
        }//end of switch 

    }//end of menu while loop

    cout << "Thank you for using this service." << endl;
    cout << "A backup file of this report has been saved to your device." << endl;



    return 0;
}