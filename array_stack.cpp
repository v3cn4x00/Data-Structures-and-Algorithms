#include <iostream>

using namespace std;

class Stack
{
    private:
        int arr[10];
        int num_items;

    public:
        Stack()
        {
            num_items = 0;
        }

        bool isEmpty()
        {
            return num_items == 0;
        }

        bool isFull()
        {
            return num_items == 10;
        }

        void push(int x)
        {
            if(isFull())
            {
                cout << "Stack is full" << endl;
                return;
            }
            else
            {
                arr[num_items] = x;
                num_items++;
            }
        }

        int pop()
        {
            if(isEmpty())
            {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            else
            {
                num_items--;
                return arr[num_items];
            }
        }

        int top()
        {
            if(isEmpty())
            {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            else
            {
                return arr[num_items - 1];
            }
        }

        int size()
        {
            return num_items;
        }
};

int main()
{
    Stack array_stack;
    array_stack.push(1);
    array_stack.push(2);
    array_stack.push(3);
    array_stack.push(4);
    array_stack.push(5);
    
    cout << "Top element: " << array_stack.top() << endl;
}
