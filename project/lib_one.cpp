#include "ticketh.h"

//TODO: Create new Node
TreePointer createNode(Ticket newTicket) {
    TreePointer newNode = new Node;

    newNode->info = newTicket;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//TODO: Value comparison
TreePointer searchTicket(TreePointer root, int priorityLevel) {
    if (!root || root->info.priorityLevel == priorityLevel) {
        return root;
    }

    if (priorityLevel < root->info.priorityLevel) {
        return searchTicket(root->left, priorityLevel);
    } else {
        return searchTicket(root->right, priorityLevel);
    }
}

//TODO: Left Node
TreePointer findMinimum(TreePointer root) {
    if (!root) {
        return nullptr;
    }

    TreePointer current = root;
    while (current->left) {
        current = current->left;
    }
    return current;
}

//TODO: Right Node
TreePointer findMaximum(TreePointer root) {
    if (!root) {
        return nullptr;
    }

    TreePointer current = root;
    while (current->right) {
        current = current->right;
    }
    return current;
}

//TODO: Display val
void inorder(TreePointer root) {
    if (root) {
        inorder(root->left);
        cout << root->info.priorityLevel << " ";
        inorder(root->right);
    }
}

// Soon: Move to lib_two
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
}
