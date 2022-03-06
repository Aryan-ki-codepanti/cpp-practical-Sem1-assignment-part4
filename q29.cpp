#include <iostream>
#include <algorithm>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArrRev(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int *arr = new int[10];
    cout << "Enter 10 elements of array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    cout << "Orignal Array: ";
    printArr(arr, 10);
    sort(arr, &arr[10]);
    cout << "Ascending Order: ";
    printArr(arr, 10);
    cout << "Descending order: ";
    printArrRev(arr, 10);
    return 0;
}