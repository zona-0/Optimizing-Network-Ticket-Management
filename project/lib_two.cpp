#include "ticketh.h"

//TODO: Input Ticket
void insertTicket(TreePointer &root, Ticket newTicket) {
    if (!root) {
        root = createNode(newTicket);
    } else {
        if (newTicket.priorityLevel < root->info.priorityLevel) {
            insertTicket(root->left, newTicket);
        } else if (newTicket.priorityLevel > root->info.priorityLevel) {
            insertTicket(root->right, newTicket);
        } else {
            cout << "\n  [!] Ticket with priority level " << newTicket.priorityLevel << " already exists!" << endl;
        }
    }
}

//TODO: Delete Ticket by priority lv
void deleteTicket(TreePointer &root, int priorityLevel) {
    if (!root) {
        cout << "\n  [!] Ticket with priority level " << priorityLevel << " not found!" << endl;
    }

    if (priorityLevel < root->info.priorityLevel) {
        deleteTicket(root->left, priorityLevel);
    } else if (priorityLevel > root->info.priorityLevel) {
        deleteTicket(root->right, priorityLevel);
    } else {
        //TODO: If Node doesnt have child (leaf node)
        if (!root->left && !root->right) {
            root = nullptr;
        }
        //TODO: If node have one child >> Right
        else if (!root->left) {
            root = root->right;
        }
        //TODO: If node have one child >> Left
        else if (!root->right) {
            root = root->left;
        }
        //TODO: If node have 2 child
        else {
            TreePointer successor = findMinimum(root->right);

            root->info = successor->info;
            deleteTicket(root->right, successor->info.priorityLevel);
        }
    }