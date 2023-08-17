#pragma once
/******************************************************************************
This program analyzes frequency of produce items for Corner Grocer. It creates
a backup report and allows a user to search by term, print a frequency report
with either numbers or a visual representation of units sold.
Created for CS 210 Project Three.

Author: Kinsey Christensen
Date: 08/08/2023
*******************************************************************************/

#ifndef PRODUCEREPORT_H
#define PRODUCEREPORT_H

class ProduceReport {
public:
    void printReport();         //prints numeric report
    void printVisualReport();   //prints visual report
    void searchByItem();        //searches by user item
    int openFile();             //opens provided file
    void createMap();           //creates map
    void createReport();         //creates frequency.dat
    void closeFile();           //closes provided file
    void closeReport();         //closes frequency.dat

private:
    ifstream inFS;          //input file stream
    ofstream outFS;         //output file stream
    string produceItem;     //read in from file
    int itemAmount;         //increments by frequency
    map<string, int> produceMap;    //map of produce items and frequency
    char userChoice[50];    //user entered item
    string userChoiceString;    //user entered item as string
    int userItemAmount;         //item amount for user choice
    int i;                  //for loop

protected:
};

#endif
