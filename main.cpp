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
    string name;
    int action;
    
    while(1)
    {
        cout<<"Select your action from the following : "<<"\n";
        cout<<"1 : Add items to phone book"<<endl;
        cout<<"2 : Add items to phone book"<<endl;
        cout<<"3 : Add items to phone book"<<endl;
        cout<<"4 : Add items to phone book"<<endl;
        cout<<"5 : Add items to phone book"<<endl;
        cin>>action;      
        
        switch(action)
        {
            case 1: 
                cout<< "You entered "<<action<<endl;
                break;
        
            case 2: 
                cout<<"You entered "<<action<<endl;
                break;
        
            case 3: 
                cout<<"You entered "<<action<<endl;
                break;
        
            case 4: 
                cout<<"You entered "<<action<<endl;
                break;
        
            case 5: 
                cout<<"You entered "<<action<<endl;
                break;
                
            default : 
                cout<<"Enter a value between 1 to 5"<<endl;
                break;
        }
    }
    
    PhoneDirectory.PrintTable();
    PhoneDirectory.PrintItemsInIndex(3);
    PhoneDirectory.FindNumber("ABC8");
    
    while(name != "exit")
    {
        cout << "Remove ? ";
        cin>>name;
        if(name != "exit")
        {
            PhoneDirectory.RemoveItem(name);
        }
        else
        {
            PhoneDirectory.PrintTable();
        }
    }
}
