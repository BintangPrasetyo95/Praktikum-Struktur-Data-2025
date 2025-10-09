#include <iostream>
using namespace std;

void tukar(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

void cetak(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(float arr[], int n) {
    cout << "\n=== Bubble Sort ===\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tukar(&arr[j], &arr[j + 1]);
            }
        }
        cout << "Iterasi " << i + 1 << ": ";
        cetak(arr, n);
    }
}

void exchangeSort(float arr[], int n) {
    cout << "\n=== Exchange Sort ===\n";
    int iter = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                tukar(&arr[i], &arr[j]);
            }
        }
        cout << "Iterasi " << iter++ << ": ";
        cetak(arr, n);
    }
}

void insertionSort(float arr[], int n) {
    cout << "\n=== Insertion Sort ===\n";
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;

        cout << "Iterasi " << i << ": ";
        cetak(arr, n);
    }
}

void selectionSort(float arr[], int n) {
    cout << "\n=== Selection Sort ===\n";
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            tukar(&arr[i], &arr[pos]);
        }
        cout << "Iterasi " << i + 1 << ": ";
        cetak(arr, n);
    }
}

int main() {
    int n, pilihan;
    float arr[1005], backup[1005];

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    cout << "Masukkan IPK mahasiswa:\n";
    
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ": ";
        cin >> arr[i];
        backup[i] = arr[i]; // arr asli
    }

    do {
        for (int i = 0; i < n; i++) {
            arr[i] = backup[i];
        }

        cout << "\nPilih metode sorting:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Exchange Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Selection Sort\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: bubbleSort(arr, n); break;
            case 2: exchangeSort(arr, n); break;
            case 3: insertionSort(arr, n); break;
            case 4: selectionSort(arr, n); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
