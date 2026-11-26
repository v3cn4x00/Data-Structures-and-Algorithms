#include <iostream>

using namespace std;

int main()
{
    const int v = 10;
    int arr[v] = {0, 56, 23, 89, 12, 45, 67, 34, 78, 90};

    for(int i = v - 1; i > 0; i--)
    {
        bool swapped = false;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }


    cout << "Sorted array: ";
    for(int i = 0; i < v; i++)
    {
        cout << arr[i] << " ";
    }
}
