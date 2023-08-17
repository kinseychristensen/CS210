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


int ProduceReport::openFile() {             //opens provided file
    cout << "Gathering produce data..." << endl;

    inFS.open("CS210_Project_Three_Input_File.txt");

    if (!inFS.is_open()) {
        cout << "Could not open input file.  This program will now terminate." << endl;
        return 1;   //1 indicates error
    }
    else {
        cout << "Data gathered. Preparing Backup Report..." << endl;
        return 0;
    }
}


void ProduceReport::createMap() {    //creates map of items and amount
    while (!inFS.eof()) {
        inFS >> produceItem;

        //adds item if not in list
        if (produceMap.count(produceItem) == 0) {
            produceMap.emplace(produceItem, 1);
        }
        //increments item amount
        else {
            produceMap.at(produceItem) = produceMap.at(produceItem) + 1;
        }
    }//end of while loop
}


void ProduceReport::createReport() {
    outFS.open("frequency.dat");

    if (!outFS.is_open()) {
        cout << "Could not create Backup Report." << endl;

    }
    else {
        cout << "Report successfully created. Proceeding to Menu..." << endl;
        cout << endl;
        outFS << "Produce Item";
        outFS << setw(13) << right << "Quantity" << endl;
        outFS << setfill('-') << setw(25) << "" << endl;
        outFS << setfill(' ') << endl;
        for (auto& element : produceMap) {
            outFS << setw(22) << left << element.first << " ";
            outFS << element.second << endl;
        }
        outFS << endl;
    }
}


void ProduceReport::closeFile() {           //closes provided file
    inFS.close();
}


void ProduceReport::closeReport() {         //closes frequency.dat
    outFS.close();
}

void ProduceReport::printReport() {         //prints numeric report
    cout << "Produce Item";
    cout << setw(13) << right << "Quantity" << endl;
    cout << setfill('-') << setw(25) << "" << endl;
    cout << setfill(' ') << endl;
    for (auto& element : produceMap) {
        cout << setw(22) << left << element.first << " ";
        cout << element.second << endl;
    }
    cout << endl;
}

void ProduceReport::printVisualReport() {   //prints visual report
    cout << "Produce Item";
    cout << setw(13) << right << "Quantity" << endl;
    cout << setfill('-') << setw(25) << "" << endl;
    cout << setfill(' ') << endl;
    for (auto& element : produceMap) {
        cout << setw(15) << left << element.first << " ";
        for (int i = 0; i < element.second; ++i) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;
}

void ProduceReport::searchByItem() {              //searches by user item
    cout << "Please enter the item name: ";
    cin >> userChoice;                //reads in user choice
    cout << endl;

    //ensures first character is uppercase
    if (userChoice[0] >= 97 && userChoice[0] <= 122) {
        userChoice[0] = userChoice[0] - 32;
    }

    //ensures all of following characters are lowercase
    for (i = 1; i <= 50; ++i) {      //note: 50 is length of char array
        if (userChoice[i] >= 65 && userChoice[i] <= 90) {
            userChoice[i] = userChoice[i] + 32;
        }
    }

    userChoiceString = userChoice;  //string with corrected case

    //iterates through map checking for matching values
    userItemAmount = 0;     //will update if match is found.
    for (auto& element : produceMap) {
        if (element.first == userChoice) {
            userItemAmount = element.second;
        }
    }

    //Prints results
    if (userItemAmount == 1) {
        cout << "There was 1 " << userChoiceString;
        cout << " transaction in today's purchases." << endl;
    }
    else if (userItemAmount == 0) {
        cout << "No matching purchases found.  Please check that you are";
        cout << " inputting the item name as found in the directory." << endl;
    }
    else {
        cout << "There were " << userItemAmount << " " << userChoiceString;
        cout << " transactions in today's purchases." << endl;
    }
    cout << endl;
}
