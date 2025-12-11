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

