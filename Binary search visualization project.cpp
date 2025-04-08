#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to display the array with pointers
void displayArray(const vector<int>& arr, int low, int mid, int high) {
    cout << "Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << setw(3) << arr[i];
    }
    cout << endl;

    // Display markers
    for (int i = 0; i < arr.size(); i++) {
        if (i == low && i == mid && i == high)
            cout << " LMH";
        else if (i == low && i == mid)
            cout << " LM ";
        else if (i == mid && i == high)
            cout << " MH ";
        else if (i == low && i == high)
            cout << " LH ";
        else if (i == low)
            cout << " L  ";
        else if (i == mid)
            cout << " M  ";
        else if (i == high)
            cout << " H  ";
        else
            cout << "    ";
    }
    cout << "\n\n";
}

int binarySearchVisualization(const vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        displayArray(arr, low, mid, high);  // Visualize current step

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int x;

    cout << "Enter the number to search: ";
    cin >> x;

    int result = binarySearchVisualization(arr, x);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}