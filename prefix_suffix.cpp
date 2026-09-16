#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// PROBLEM 1: Product of Array Except Self
// Prefix Product + Suffix Product
// =====================================================

void productExceptSelf() {

    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> output(n);

    // Prefix Product ***
    prefix[0] = 1;

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    // Suffix Product ***
    suffix[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    // Combine Prefix and Suffix
    for (int i = 0; i < n; i++) {
        output[i] = prefix[i] * suffix[i];
    }

    cout << "Problem 1: Product Except Self" << endl;

    cout << "Output: ";

    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }

    cout << endl << endl;
}


// =====================================================
// PROBLEM 2: Equilibrium Index
// Prefix Sum + Suffix Sum
// =====================================================

void equilibriumIndex() {

    vector<int> arr = {1, 7, 3, 6, 5, 6};
    int n = arr.size();

    vector<int> prefix(n);
    vector<int> suffix(n);

    // Prefix Sum
    prefix[0] = 0;

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // Suffix Sum
    suffix[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + arr[i + 1];
    }

    // Find Equilibrium Index
    for (int i = 0; i < n; i++) {

        if (prefix[i] == suffix[i]) {

            cout << "Problem 2: Equilibrium Index" << endl;
            cout << "Equilibrium Index = " << i << endl;

            return;
        }
    }

    cout << "No Equilibrium Index found" << endl;
}

// ==========================================================
// Problem 3: Maximum Difference Between Left and Right Sums
// ==========================================================
void Max_Difference(){
    vector<int> arr = {3,1,5,2,4};
    int n = arr.size();
    
    vector<int> Prefix(n);
    vector<int> Suffix(n);
    vector<int> Difference(n);

    


}


// =====================================================
// MAIN FUNCTION
// =====================================================

int main() {

    productExceptSelf();

    equilibriumIndex();

    return 0;
}