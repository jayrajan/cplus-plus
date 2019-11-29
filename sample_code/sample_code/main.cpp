//  Portfolio: database_system.cpp
//  Created by Jerin Rajan on 21/08/2019
//  Copyright © 2019 JPR Tech Ltd. All rights reserved.


//*********************
// HEADER FILES
//*********************
#include <iostream>
#include<fstream>
#include<iomanip>
#include "member.hpp"

using namespace std;


//***********************
// FUNCTION DECLARATION
//***********************
void data_display(member k[ENTRYLIMIT],int indx);
int data_entry(member k[ENTRYLIMIT]);
void create_file(std::ofstream& file);       //use std::ofstream& to invoke the copy constructor error
void save_file(std::ofstream& file, member k[ENTRYLIMIT], int indx );
void close_file(std::ofstream& file);                                        //use std::ofstream& to invoke the copy constructor error
//***********************




//*********************
// MAIN FILES
//*********************
int main()
{                                                                               // start of main loop
    
    member k[ENTRYLIMIT];
    int indx;
    ofstream textfile;
    

    indx = data_entry(k);                                                       // trigger data entry
    data_display(k,indx);                                                       // displaying the typed up results
    create_file(textfile);
    save_file(textfile, k, indx);
    close_file(textfile);
    
    return 0;
}                                                                               // end of main loop





//*********************
// FUNCTIONS
//*********************

void data_display(member k[ENTRYLIMIT], int indx)
{                                                                               // start of function data_display
    
cout<<"\n\t ===============";
cout<<"\n\t Data in records";
cout<<"\n\t ===============";
cout<<"\n\n\t Total number of entries you made in database is "<<indx;
cout<<"\n\n\t Please see below:";
cout<<"\n";
    
                                                                                // displaying the inputted results
    for (int i=0; i<indx; i++)
    {
        k[i].showdata(i);
    }
    
    
}                                                                               // end of function data_entry

int data_entry(member k[ENTRYLIMIT])
{                                                                               // Start of function data_entry

char c;
int i;
cout<<"\n\t ===============";
cout<<"\n\t Data Entry Page ";
cout<<"\n\t ===============";
    
                                                                                // Go through loop to enter data
    for (i=0; i<ENTRYLIMIT; i++)
    {                                                                           // start of for-loop
        cout<<"\n\n\t Do you want to enter data? - [Y] or [N] ";
        cin>>c;
        
        if ((c=='Y')||(c=='y')){
            k[i].generateid(i);
            k[i].getdata();
        }
        else if ((c=='N')||(c=='n'))
            break;
    }                                                                           // end of for-loop
    return i;
}                                                                               // End of function data_entry

void create_file(std::ofstream& file)
{
    file.open ("//Users/jay/c++/sample_code/newfile.txt", ios::out | ios::app);
    cout<<"\n\n\t File succesfully created";
}

void save_file(std::ofstream& file, member k[ENTRYLIMIT], int indx )
{
    int i;
    for (i=0; i<indx; i++)
    {
    k[i].savedata(file,i);
    }
}

void close_file(std::ofstream& file)
{
    file.close ();
    cout<<"\n\n\t File successofully closed";
    cout<<"\n";
}


