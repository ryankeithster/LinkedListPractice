// PracticeProblemsCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../LinkedList/LinkedList.h"

/// <summary>
/// Reverse the specified subsection of the singly linked list
/// </summary>
/// <param name="list"></param>
/// <param name="start"></param>
/// <param name="end"></param>
/// <returns></returns>
std::shared_ptr<ListNode<int>> reverseSublist(std::shared_ptr<ListNode<int>> list, unsigned start, unsigned end)
{
    if (list == NULL)
    {
        return list;
    }

    unsigned position = 1;

    // Move to the node just before the start of the sequence
    while (position < start - 1 && list != NULL)
    {
        list = list->next;
        ++position;
    }

    if (list == NULL)
    {
        return list;
    }

    // Save a reference to the node just before the start of the sequence so that we
    // can update it's successor at the end
    std::shared_ptr<ListNode<int>> head = list;

    // Move to the node just after the end of the sequence
    while (position < end + 1 && list != NULL)
    {
        list = list->next;
        ++position;
    }

    // Set the first "prev" value to the node just after the end of the sequence to reverse
    // This ensures that the node that is currently at the beginning of our sequence
    // ends up at the end of our sequence with its "next" value pointing to the node just
    // past the end
    std::shared_ptr<ListNode<int>> prev = list;
    
    std::shared_ptr<ListNode<int>> next = NULL;
    
    // Reset our pointer back to the start of the sequence to reverse
    list = head->next;

    position = start;

    while (position <= end)
    {
        next = list->next;
        list->next = prev;
        
        prev = list;
        list = next;
        
        ++position;
    }

    // Finally point the node just before the beginning of the sequence to its
    // new successor
    head->next = prev;

    return head;
}

int main()
{
    ListNode<int> myList1 = { 11, NULL };
    std::shared_ptr<ListNode<int>> ptr1 = std::make_shared<ListNode<int>>(myList1);
    insert(ptr1, 3);
    insert(ptr1, 5);
    insert(ptr1, 7);
    insert(ptr1, 2);
    insert(ptr1, 8);

    printList(ptr1);

    std::shared_ptr<ListNode<int>> ptr2 = reverseSublist(ptr1, 2, 5);

    printList(ptr2);
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
