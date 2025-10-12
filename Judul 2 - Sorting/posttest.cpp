#include <iostream>
using namespace std;

void tukar (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    cout << "==Bubble Sort==";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tukar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    
    cout << "Input Berapa Jumlah Elemen :";
    cin >> n;
    
    int x[n];
    
    for (int i = 0; i<n; i++) {
        
    cout << "Input Elemen Ke-" << i + 1 << ": ";
    cin >> x[i];
    }
    
    bubbleSort(x, n);
    
    cout << "Output\n";
    for (int i = 0; i<n; i++) {
        // cout << "Array\n" << x[i] << endl;
        if (x[i] % 2 == 0) {
            cout << x[i] << endl;
        }
    } 
    
    for (int i = 0; i<n; i++) {
        // cout << "Array\n" << x[i] << endl;
        if (x[i] % 2 == 1) {
            cout << x[i] << endl;
        }
    } 

    return 0;
}