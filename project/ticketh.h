#ifndef TICKETH_H_INCLUDED
#define TICKETH_H_INCLUDED

#include <iostream>
using namespace std;

struct Ticket{
    int priorityLevel;
    string ticketID, description, customerName, issueType;
};

struct Node{
    Ticket info;
    Node* left;
    Node* right;
};

typedef Node* TreePointer;

//TODO: lib_one file
TreePointer createNode(Ticket newTicket);
TreePointer searchTicket(TreePointer root, int priorityLevel);
TreePointer findMinimum(TreePointer root);
TreePointer findMaximum(TreePointer root);
void inorder(TreePointer root);

//TODO: Lib_two file
void insertTicket(TreePointer &root, Ticket newTicket);
void deleteTicket(TreePointer &root, int priorityLevel);

#endif // TICKETH_H_INCLUDED
