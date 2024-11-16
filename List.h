#pragma once
#include <exception>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node
    {
        Node(T value) noexcept
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:
    List() noexcept
    {
        head = nullptr;
        tail = nullptr;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

   //TODO Implement the exists method that checks if the element with a given value is in the list.
		// std::terminate();
    bool exists(T const& value) const noexcept
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

   
    void pushFront(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
    }
};
