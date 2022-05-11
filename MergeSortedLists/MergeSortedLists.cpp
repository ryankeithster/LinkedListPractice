// MergeSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../LinkedList/LinkedList.h"

template <typename T>
void mergeSortedLists(std::shared_ptr<ListNode<T>> L1, std::shared_ptr<ListNode<T>> L2)
{
    if (L1 == NULL)
    {
        return;
    }

    std::shared_ptr<ListNode<T>> prev = NULL;
    std::shared_ptr<ListNode<T>> tempL2 = NULL;
    while (L1->next != NULL)
    {
        if (L1->value < L2->value)
        {
            prev = L1;
            L1 = L1->next;
        }
        else // L1->value >= L2->value
        {
            if (prev != NULL)
            {
                prev->next = L2;
            }

            tempL2 = L2->next;
            L2->next = L1;
            L2 = tempL2;
        }
    }

    L1->next = L2;

    prev.reset();
    tempL2.reset();
}

int main()
{
    ListNode<int> myList1 = { 2, NULL };
    std::shared_ptr<ListNode<int>> ptr1 = std::make_shared<ListNode<int>>(myList1);
    insert(ptr1, 5);
    insert(ptr1, 7);

    ListNode<int> myList2 = { 3, NULL };
    std::shared_ptr<ListNode<int>> ptr2 = std::make_shared<ListNode<int>>(myList2);
    insert(ptr2, 11);

    mergeSortedLists(ptr1, ptr2);

    printList(ptr1);

    ptr1.reset();
    ptr2.reset();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
