#include <iostream>
#include "ticketh.h"
using namespace std;

int main()
{
    TreePointer root = nullptr;
    int choice = -1;
    int priorityLevel;
    Ticket newTicket;

    while (choice != 0) {
        cout << "In (1-6): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Input val: ";
            cin >> newTicket.priorityLevel;

            insertTicket(root, newTicket);
        }

        else if (choice == 2) {
            cout << "Search Val: ";
            cin >> priorityLevel;

            if (searchTicket(root, priorityLevel)) {
                cout << "Ticket ad\n";
            } else {
                cout << "Ticket x\n";
            }
        }

        else if (choice == 3) {
            cout << "Delete Val: ";
            cin >> priorityLevel;

            deleteTicket(root, priorityLevel);
        }

        else if (choice == 4) {
            TreePointer mn = findMinimum(root);

            if (mn) {
                cout << "Min: " << mn->info.priorityLevel << endl;
            } else {
                cout << "Min X\n";
            }
        }

        else if (choice == 5) {
            TreePointer mx = findMaximum(root);

            if (mx) {
                cout << "Max: " << mx->info.priorityLevel << endl;
            } else {
                cout << "max X\n";
            }
        }

        else if (choice == 6) {
            cout << "Inorder test: ";
            inorder(root);
            cout << endl;
        }
    }

    return 0;
}
