#include <bits/stdc++.h>
using namespace std;

// Merge two sorted parts
void merge(int arr[], int start, int mid, int end) {

    int i = start;
    int j = mid + 1;

    vector<int> temp;

    // Compare elements from both halves
    while (i <= mid && j <= end) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining elements of left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining elements of right half
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }
}

// Merge Sort
void mergeSort(int arr[], int start, int end) {

    // Base case
    if (start >= end) {
        return;
    }

    // Find middle
    int mid = start + (end - start) / 2;

    // Sort left half
    mergeSort(arr, start, mid);

    // Sort right half
    mergeSort(arr, mid + 1, end);

    // Merge both sorted halves
    merge(arr, start, mid, end);
}

int main() {

    int arr[] = {38, 12, 27, 43, 9, 31, 18, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After sorting: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}