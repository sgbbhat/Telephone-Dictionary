/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: shreeganesh
 *
 * Created on April 13, 2016, 6:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

/* Main program 
 * Uses class defined in hash.h
 * Controls operation of the program
 */
int main(int argc, char** argv) {
    hashClass PhoneBook;
    string name, phoneNumber;
    int action, itemIndex;
    
    while(action != 6) 
    {
        // Options to user 
        
        cout<<"Select your action from the following : "<<"\n";
        cout<<"1 : To ADD items to the phone book"<<endl;
        cout<<"2 : To PRINT the table"<<endl;
        cout<<"3 : To PRINT items in INDEX"<<endl;
        cout<<"4 : To SEARCH a number by name"<<endl;
        cout<<"5 : To REMOVE items from the phone book"<<endl;
        cout<<"6 : To Exit"<<endl;  
        cin>>action;      
        
        // Executes one of the case based on user input
        switch(action)
        {
            case 1:                                         // Addition
                cout<< "You entered "<<action<<endl;
                cout<< "Name to be added : ";
                cin>>name;
                cout<<"Enter corresponding phone number : "<<endl;
                cin>>phoneNumber;
                PhoneBook.AddItem(name, phoneNumber);
                break;
        
            case 2:                                         // Display
                cout<<"You entered "<<action<<endl;
                PhoneBook.PrintTable();
                break;
        
            case 3: 
                cout<<"You entered "<<action<<endl;         // Display 
                cout<< "Enter inIndex of the item to be printed : ";
                cin>>itemIndex;
                PhoneBook.PrintItemsInIndex(itemIndex);
                break;
        
            case 4:                                         // Search
                cout<<"You entered "<<action<<endl;
                cout<<"Enter the name : ";
                cin>>name;
                PhoneBook.FindNumber(name);
                break;
        
            case 5:                                         // Delete
                cout<<"You entered "<<action<<endl;
                cout<<"Enter the name to be removed : ";
                cin>>name;
                PhoneBook.RemoveItem(name);
                break;
            
            case 6:                                         // Exit
                cout<<"You chose exit"<<endl;
                
            default : 
                cout<<"Enter a value between 1 to 5"<<endl;
                break;
        }
    }
}
