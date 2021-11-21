#include <iostream>

// using namespace std;

#ifndef LIST_H
#define LIST_H

namespace LinkedList {

    class List {
        public:
            std::string name;
            int inodeNumber;

            List *next;
            List *prev;
            List *head;

            List(std::string name, int inodeNumber);
    
    };
};

void iterList(LinkedList::List *list);
int countList(LinkedList::List *list);
void appendList(LinkedList::List *list, std::string name, int inodeNumber);
#endif
