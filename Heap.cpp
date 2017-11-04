#include "Heap.hpp"

#include <iostream>

void Heap::enqueue(HNode* node) {
    tree.push_back(node);
    fix_up(tree.size() - 1);
}

void Heap::fix_up(int index) {
    while (index > 0 ) {
        char indexValue = tree[index]->value;
        char parentValue = tree[parent(index)]->value;
        if (parentValue > indexValue) {
            HNode* temp = tree[index];
            tree[index] = tree[parent(index)];
            tree[parent(index)] = temp;

            index = parent(index);
        } else
            break;
    }
}

void Heap::fix_down(int index) {
    while (index < tree.size() - 1 && leftChild(index) < tree.size() - 1) {
        HNode* parent = tree[index];
        HNode* left = tree[leftChild(index)];
        HNode* right = tree[rightChild(index)];
        if(left->value < parent->value || right->value < parent->value) {
            if(left->value < right->value) {
                tree[index] = left;
                tree[leftChild(index)] = parent;
                index = leftChild(index);
            } else {
                tree[index] = right;
                tree[rightChild(index)] = parent;
                index = rightChild(index);
            }
        } else {
            break;
        }
    }
}

HNode* Heap::dequeue() {
    if(tree.size() > 0) {
        HNode* root = tree[0]; // Save root node to return later
        tree[0] = tree.back(); // Move last node to the root position
        tree.pop_back();

        fix_down(0);

        return root;
    }
}

/*HNode* Heap::dequeue() {
    int size = tree.size() - 1; // There's an empty spot at the beginning of the vector

    HNode* root = tree[1];
    HNode* last = tree.back();
    tree.pop_back();

    if (size > 1) {
        tree[1] = last;
        fix_down(1);
    }

    return root;
}*/

int Heap::parent(int child) {
    if (child == 0)
        return -1;
    else
        return ((child - 1) / 2);
}

int Heap::leftChild(int parent) {
    int child = 2 * parent + 1;
    if (child > tree.size() - 1)
        return -1;
    else
        return child;
}

int Heap::rightChild(int parent) {
    int child = 2 * parent + 2;
    if (child > tree.size() - 1)
        return -1;
    else
        return child;
}

void Heap::print() {
    for (HNode* node : tree) {
        std::cout << node->value << std::endl;
    }
}
