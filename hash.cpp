/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "hash.h"

using namespace std;

hashClass::hashClass()
{
    // Initializing default values to items
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->Name = "Empty" ;
        HashTable[i]->Number = "Empty" ;
        HashTable[i]->next = NULL ;
    }
}

int hashClass::Hash(string key)
{
    int hash = 0;
    int index;
    
    // Converting char to corresponding ASCII value
    for(int KeyLength = 0; KeyLength < key.length(); KeyLength ++)
    {
        hash = hash + (int)(key[KeyLength]);    // Accumulates ASCII values of charectar
    }
    index = hash % tableSize;
    return index;
}

void hashClass::AddItem(string name, string number)
{
    int index = Hash(name);
    if(HashTable[index]->Name == "Empty")
    {
        HashTable[index]->Name = name;
        HashTable[index]->Number = number;
    }
    else
    {
        item* ptr = HashTable[index];
        item* n = new item;
        n->Name = name;
        n->Number = number;
        n->next = NULL;
        while(ptr->next != NULL)
            ptr = ptr->next;
        
        ptr->next = n;
    }
}

int hashClass::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index]->Name == "Empty")
    {
        return count;
    }
    else
    {
        count++;
        item* ptr = HashTable[index];
        while(ptr->next != NULL)
        {
            count ++;
            ptr = ptr->next ;
            
        }
    }
}

void hashClass::PrintTable()
{
    int number;
    
    for(int i =0; i< tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout<<"-----------------------------\n";
        cout<<"Index = "<<i<<endl;
        cout<<HashTable[i]->Name<<endl;
        cout<<HashTable[i]->Number<<endl;
        cout<<"Number of item : " << number<<endl;
        cout<<"-----------------------------\n";
    }
}

void hashClass::PrintItemsInIndex(int index)
{
    item * ptr = HashTable[index];
    
    if(ptr->Name == "Empty")
    {
        cout<<"Index = "<< index << " is empty"; 
    }
    else
    {
        cout<<"Index "<< index<< " contains the following items"<<endl;
        while(ptr != NULL)
        {
            cout<<"-----------------------------"<<endl;
            cout<<ptr->Name<<endl;
            cout<<ptr->Number<<endl;
            cout<<"-----------------------------"<<endl;
            ptr= ptr->next;
        }
    }
}

void hashClass::FindNumber(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string number;
    
    item * ptr = HashTable[index];
    
    while(ptr != NULL)
    {
        if(ptr->Name == name)
        {
            foundName = true;
            number = ptr->Number;
        }
        
        ptr= ptr->next;
    }
    
    if(foundName == true)
    {
        cout<<"Number is = "<<number<<endl;
    }
    else
    {
        cout<< name << "not found in the table";
    }
}

void hashClass::RemoveItem(string name)
{
    int index = Hash(name);
    
    item * delptr;
    item * p1;
    item * p2;
    
    // case 0 - bucket is empty
    if(HashTable[index]->Name == "Empty" && HashTable[index]->Number == "Empty")
    {
        cout<<name << " was not found in the hash table";
    }
    
    
    // case 1 - only 1 item is in bucket
    else if(HashTable[index]->Name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->Name = "Empty";
        HashTable[index]->Number = "Empty"; 
        
        cout<<name << " was removed from hash table";
    }
    
    // case 2 - match is located in the first item in the bucket but there are mote items in bucket
    else if(HashTable[index]->Name == name)
    {
        delptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delptr;
        
        cout<<name << " was removed from hash table";
    }
    
    // case 3 - Bucket contains items but first item is not a match
    else
    {
        p1 = HashTable[index]->next ;
        p2 = HashTable[index];
        
        while(p1 != NULL && p1->Name != name)
        {
            p2 = p1;
            p1 = p1->next;
            
        }
        
        // case 3.1 - no match
        if(p1 == NULL)
        {
            cout<<name << " was not found in the hash table";
        }
      
        // case 3.2 - match is found
        else
        {
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;
            
            delete delptr;
            
            cout<<name << " was removed from hash table"<<endl;
        }
    }
}