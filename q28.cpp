#include <iostream>
using namespace std;

void reverseArr(int *arr, int n)
{
    int tmp;
    for (int i = 0; i < n / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Array should have atleast one element" << endl;
        exit(1);
    }
    int *a = new int[n];

    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Initial array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    reverseArr(a, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}