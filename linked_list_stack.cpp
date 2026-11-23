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
        void new_node(int n_data)
        {
            Node* temp = new Node(n_data);
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

        int get_head_node()
        {
            if(head != nullptr)
            {
                return head->data;
            }
            else
            {
                cout << "List is empty" << endl;
                return -1;
            }
        }

        ~LinkedList()
        {
            while(head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

class Link_Stack
{
    private:
        LinkedList stack;
        int num_items = 0;

    public:
        bool isEmpty()
        {
            return num_items == 0;
        }

        void push(int x)
        {
            stack.new_node(x);
            num_items++;
        }

        int pop()
        {
            if(!isEmpty())
            {
                int temp = stack.get_head_node();
                stack.remove_node();
                num_items--;
                return temp;
            }
            else
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
        }

        int top()
        {
            if(!isEmpty())
            {
                return stack.get_head_node();
            }
            else
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
        }

        int size()
        {
            return num_items;
        }
};

int main()
{
    Link_Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
}
