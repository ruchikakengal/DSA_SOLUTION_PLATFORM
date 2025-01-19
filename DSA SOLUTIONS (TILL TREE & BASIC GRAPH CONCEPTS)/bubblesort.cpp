<<<<<<< HEAD
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "i = " << i << ", j = " << j << " | Before: ";
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

                cout << "  Swapped " << arr[j] << " and " << arr[j + 1] << " | After:  ";
                for (int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
        cout << endl;  // Separate each pass for clarity
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
=======
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "i = " << i << ", j = " << j << " | Before: ";
            for (int k = 0; k < n; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

                cout << "  Swapped " << arr[j] << " and " << arr[j + 1] << " | After:  ";
                for (int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
        cout << endl;  // Separate each pass for clarity
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
>>>>>>> 7bad0a68daa2c06c9fca1126fc521408b8718bdd
