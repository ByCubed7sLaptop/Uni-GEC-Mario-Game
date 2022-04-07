#pragma once
 
namespace Core {

    template <class T>
    class CircularLinkedList
    {
    public:
        struct Node
        {
            T value;
            Node* next;
        };

        CircularLinkedList (): _size(0), start(nullptr) {}


        // The deconstructor
        ~CircularLinkedList() {
            while (start->next != nullptr)
                remove(start);
            delete start;
        }

        /// <summary>
        /// By default, insert before start, like a queue
        /// </summary>
        /// <param name="data">The data to append</param>
        /// <returns>The node the data was appended to.</returns>
        Node* add(T data)
        {
            Node* newNode = new Node;
            size++;

            // If the list is empty
            if (start == nullptr) {
                start = newNode;
                start->value = data;
                start->next = start;
                return;
            }

            // Move start to the next node
            newNode->value = start->value;
            newNode->next = start->next;

            // Start node is now the new node
            start->value = data;
            start->next = newNode;

            return start;
        }

        /// <summary>
        /// Inserts a node after the selected node
        /// </summary>
        /// <param name="before">The node to add </param>
        /// <param name="data">The data to append to the node</param>
        /// <returns></returns>
        bool insert(Node* before, T data)
        {
            // Create B
            Node* newNode = new Node;
            newNode->value = data;

            //    [b]
            //
            // [a] -> [c]

            // B now points to C
            newNode->next = before->next;

            //    [b]
            //       \
            // [a] -> [c]

            // A now points to B
            before->next = newNode;

            //    [b]
            //   /   \
            // [a]   [c]

            _size++;
            return true;
        }

        /// <summary>
        /// Removes the node in the given list
        /// </summary>
        /// <param name="node">The node to remove</param>
        /// <returns>Whether the list was successfully changed</returns>
        bool remove(Node* node)
        {
            // A case for when there are no nodes left
            if (start == nullptr) return false;

            //          [c]
            //         /   \
            // [a] - [b]   [d]

            // POSSIBLE BUG:
            //    Do we delete B value?

            // Instead of deleting this node 
            // Move the data from the next node here
            Node* temp = node->next;
            node->value = temp->value;
            node->next = temp->next;

            //          [c]
            //             \
            // [a] - [c] - [d]

            // Delete the next node
            delete temp;
   
            // [a] - [c] - [d]

            _size--;
            return true;
        }

        size_t size() {
            return _size;
        }

        bool isEmpty() { return _size == 0; }
        bool isPresent() { return !isEmpty(); }

        // Iteration
        //typedef T* iterator;
        //iterator begin() { return start; }
        //iterator end() { return nullptr; }

    private:
        size_t _size;
        Node* start = nullptr;
    };
}