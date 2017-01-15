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

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashClass
{
private:
    static const int tableSize = 5;      // Determines the size of the hash table to work with
    
    struct item{
        string Name;
        string Number;
        item* next;
    };
    
    item* HashTable[tableSize];          // Array of tableSize
    
public:
    
    hashClass();        // Constructor for the class
    
    int Hash(string key);
    
    void AddItem(string name, string Number);
    
    int NumberOfItemsInIndex(int index);
    
    void PrintTable();
    
    void PrintItemsInIndex(int index);
    
    void FindNumber(string name);
    
    void RemoveItem(string name);
};


#endif /* HASH_H */

