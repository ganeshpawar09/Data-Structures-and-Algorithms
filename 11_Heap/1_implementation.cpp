#include <iostream>
using namespace std;

class max_heap
{
    int arr[100];
    int size;

public:
    max_heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertion(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;
        int index = 1;
        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largest = index;

            if (leftIndex < size && arr[largest] < arr[leftIndex])
            {
                largest = leftIndex;
            }
            if (rightIndex < size && arr[largest] < arr[rightIndex])
            {
                largest = rightIndex;
            }

            if (largest != index)
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }
    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int *arr, int n, int index)
{
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main()
{
    max_heap a;
    a.insertion(50);
    a.insertion(55);
    a.insertion(53);
    a.insertion(52);
    a.insertion(54);
    a.display();
    a.deletion();
    a.display();

    int arr[6] = {-1, 50, 55, 53, 52, 54};
    int n = 5;
    for (int i = n / 2; i > 0; i++)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}