#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
        Node* next = nullptr;

    public:
        Node(int d)
        {
            data = d;
        }

    friend class LinkedList;
};

class LinkedList
{
    private:
        Node* head = nullptr;

    
    public:
        void add_node(int idata)
        {
            Node* temp = new Node(idata);
            if(head == nullptr)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }

        void remove_node()
        {
            if(head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void traverse_list()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                temp = temp->next;
            }
        }

        void print_list()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        void add_node_middle(int d, int location)
        {
            Node* current = head;
            int count = 1;
            while(current->next != nullptr && count < location -1)
            {
                current = current->next;
                count += 1;
            }

            Node* temp = new Node(d);
            temp->next = current->next;
            current->next = temp;
        }

        void purge()
        {
            while(head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};


int main()
{
    LinkedList list;
    list.add_node(40);
    return 0;
}
