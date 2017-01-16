/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.h
 * Author: shreeganesh
 *
 * Created on April 13, 2016, 6:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#define tableSize   50   // Determines the size of the hash table to work with

using namespace std;

#ifndef HASH_H
#define HASH_H


// Hash Table Structure declaration

class hashClass
{
private:
    
    struct item{
        string Name;
        string Number;
        item* next;
    };
    
    item* HashTable[tableSize];          // Array of tableSize
    
public:
    
    hashClass();                // Constructor for the class
    
    int Hash(string key);       // Hash function - returns an integer based on the string 
    
    void AddItem(string name, string Number);   // To add items to the table
    
    int NumberOfItemsInIndex(int index);        // To track number of items in case of collision
    
    void PrintTable();                          // To display all the elements added
    
    void PrintItemsInIndex(int index);          // To print items in an index
    
    void FindNumber(string name);               // To search number based on name
    
    void RemoveItem(string name);               // To delete the item based on name
};


#endif /* HASH_H */

