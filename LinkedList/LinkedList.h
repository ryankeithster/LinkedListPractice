#pragma once
#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H
#include <iostream>

template <typename T>
struct ListNode
{
    T value;
    std::shared_ptr<ListNode<T>> next;
};

template<typename T>
std::shared_ptr<ListNode<T>> find(std::shared_ptr<ListNode<T>> L, T key)
{
    while (L && L->value != key)
    {
        L = L->next;
    }

    // If key was not present, L will be null
    return L;
}

template <typename T>
void deleteNode(std::shared_ptr<ListNode<T>> L, T key)
{
    std::shared_ptr<ListNode<T>> prevNode = NULL;

    while (L && L->value != key)
    {
        prevNode = L;
        L = L->next;
    }

    if (L != NULL)
    {
        if (prevNode != NULL)
        {
            prevNode->next = L->next;
        }

        L.reset();
    }
}

template <typename T>
void insertAfter(std::shared_ptr<ListNode<T>>& node, std::shared_ptr<ListNode<T>> newNode)
{
    if (node && newNode)
    {
        newNode->next = node->next;
        node->next = newNode;
    }
}

template <typename T>
void insert(std::shared_ptr<ListNode<T>> node, T value)
{
    std::shared_ptr<ListNode<T>> temp = node;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ListNode<int> newNode = { value, NULL };
    temp->next = std::make_shared<ListNode<int>>(newNode);
    temp.reset();
}

template <typename T>
void printList(std::shared_ptr<ListNode<T>> list)
{
    while (list)
    {
        std::cout << list->value;

        if (list->next)
        {
            std::cout << "->";
        }
        
        list = list->next;
    }
    std::cout << std::endl;
}

#endif