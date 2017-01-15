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

/*
 * 
 */
int main(int argc, char** argv) {
    hashClass PhoneDirectory;
    string name, phoneNumber;
    int action, itemIndex;
    
    while(name != "exit") 
    {
        cout<<"Select your action from the following : "<<"\n";
        cout<<"1 : To add items to the phone book"<<endl;
        cout<<"2 : To print the table"<<endl;
        cout<<"3 : To print items in index"<<endl;
        cout<<"4 : To search a number by name"<<endl;
        cout<<"5 : To remove items from the phone book"<<endl;
        cin>>action;      
        
        switch(action)
        {
            case 1: 
                cout<< "You entered "<<action<<endl;
                cout<< "Name to be added : ";
                cin>>name;
                cout<<"Enter corresponding phone number : "<<endl;
                cin>>phoneNumber;
                PhoneDirectory.AddItem(name, phoneNumber);
                break;
        
            case 2: 
                cout<<"You entered "<<action<<endl;
                PhoneDirectory.PrintTable();
                break;
        
            case 3: 
                cout<<"You entered "<<action<<endl;
                cout<< "Enter inIndex of the item to be printed : ";
                cin>>itemIndex;
                PhoneDirectory.PrintItemsInIndex(itemIndex);
                break;
        
            case 4: 
                cout<<"You entered "<<action<<endl;
                cout<<"Enter the name : ";
                cin>>name;
                PhoneDirectory.FindNumber(name);
                break;
        
            case 5: 
                cout<<"You entered "<<action<<endl;
                cout<<"Enter the name to be removed : ";
                cin>>name;
                PhoneDirectory.RemoveItem(name);
                break;
                
            default : 
                cout<<"Enter a value between 1 to 5"<<endl;
                break;
        }
    }
}
