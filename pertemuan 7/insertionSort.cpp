#include <iostream>
using namespace std;

int main() {
    system("cls");
    int n;

    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    //Insertion sort
    for (int i = 1; i < n; i++){ // 2[j] 6 4[i][key] 7 1
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key){ 
            data[j+1] = data[j];    // 2[j] 6 6[i] 7 1 // 4[key]
            j--;
        }
        data[j+1] = key; // 2[j] 4[key] 6[i] 7 1
    }

    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }
}