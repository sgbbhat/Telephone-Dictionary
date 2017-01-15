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
    
    PhoneDirectory.AddItem("ABC1", "11111");
    PhoneDirectory.AddItem("ABC2", "22222");
    PhoneDirectory.AddItem("ABC3", "33333");
    PhoneDirectory.AddItem("ABC4", "44444");
    PhoneDirectory.AddItem("ABC5", "55555");
    PhoneDirectory.AddItem("ABC6", "11116");
    PhoneDirectory.AddItem("ABC7", "22227");
    PhoneDirectory.AddItem("ABC8", "33338");
    PhoneDirectory.AddItem("ABC9", "44449");
    PhoneDirectory.AddItem("ABC10", "555510");
    
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