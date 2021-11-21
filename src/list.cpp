#include <iostream>
#include "../include/list.hpp"

using namespace LinkedList;
using namespace std;

List::List(string name, int inodeNumber) {
    
    List::name = name;
    List::inodeNumber = inodeNumber;

    List::next = nullptr;
    List::head = nullptr;
    List::prev = nullptr;
}

void iterList(List *list) {
    if(list->head == nullptr) {
        list->head = list;
    }

    while(list != nullptr) {
        cout << list->name << endl;
        list = list->next;
    }
}

int countList(List *list) {
    int count = 0;

    if(list->head == nullptr) {
        list->head = list;
    }

    while(list != nullptr) {
        count++;
        list = list->next;
    }

    return count;
}

void appendList(List *list, string name, int inodeNumber) {
    List *newItem = new List(name, inodeNumber);
    
    if(list->head == nullptr) {
        list->head = list;
    }

    int count = countList(list);
    int i = 0;

    while(list != nullptr) {
        i++;
        
        if(count == i) {
            list->prev = list;
            list->next = newItem;
        }
        
        list = list->next;
    }
}

// void freeList(List *list) {
//     if(list->head == nullptr) {
//         list->head = list;
//     }

//     int count = countList(list);
//     int i = 0;

//     while(list != nullptr) {
//         i++;
//         if(count == i) {
//             // reverse iter here
//         }
//         list = list->next;
//     }   
// }
