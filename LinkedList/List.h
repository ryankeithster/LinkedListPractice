#ifndef __LIST_H
#define __LIST_H

template <typename T>
class List
{
	struct Node
	{
		T data;
		std::unique_ptr<Node> next;
	};

	std::unique_ptr<Node> head;

	~List()
	{
        // Destroy list nodes sequentially in a loop. 
        // the default destructor would have invoked its `next`'s destructor recursively, which would
        // cause stack overflow for sufficiently large lists.
        while (head)
        {
            head = std::move(head->next);
        }
    }

    void push(int data)
    {
        // Make use of modern move-semantics to insert the new node at the front
        // of the list and "move" the current head
        head = std::unique_ptr<Node>(new Node{ data, std::move(head) });
    }
};

#endif
