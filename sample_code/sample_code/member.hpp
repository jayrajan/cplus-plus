//  member.hpp
//  Created by Jerin Rajan on 13/09/2019.
//  Copyright © 2019 JPR Tech Ltd. All rights reserved.


//*********************
// HEADER FILES
//*********************
#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

#define ENTRYLIMIT 100 // Max no: of entries in the database_system

//*********************
// CLASSES
//*********************
class member
{
    int id[ENTRYLIMIT];
    char firstname[50];
    char middlename[50];
    char surname[50];
    
    
public:                         //access_specifier
    int generateid(int);        // function to generate unique ID for each member
    void getdata();             // function to enter data from user
    void showdata(int) const;   // function to show data on screen
    void savedata(std::ofstream&, int);   // Function to save the data in a text file
    int readid(std::istream&, int);
}; // Class ends here



int member::generateid(int i)
{
    id[i] = i;
    return id[i];
};

void member::getdata()
{
    cout<<"\n";
    cout<<"\n\tEnter First Name ";
    cin>>firstname;
    cout<<"\n\tEnter Surname ";
    cin>>surname;
    
};

void member::showdata(int i) const
{
    cout<<"\n\tMembership ID : "<<id[i];
    cout<<"\n\tFirst Name : "<<firstname;
    cout<<"\n\tSurname : "<<surname <<endl;
};


void member::savedata(std::ofstream& database, int i)
{
    database<<"\n\tMembership ID : "<<id[i];
    database<<"\n\tFirst Name : "<<firstname;
    database<<"\n\tSurname : "<<surname <<endl;
};

int member::readid(std::istream& database,int i)
{
    
};


