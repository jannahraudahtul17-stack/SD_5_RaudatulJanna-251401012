#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> kiri(a.begin() + l, a.begin() + m + 1);
    vector<int> kanan(a.begin() + m + 1, a.begin() + r + 1);
    size_t i = 0, j = 0;
    int k = l;

    while (i < kiri.size() && j < kanan.size())
        a[k++] = (kiri[i] <= kanan[j]) ? kiri[i++] : kanan[j++];
    while (i < kiri.size()) a[k++] = kiri[i++];
    while (j < kanan.size()) a[k++] = kanan[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n;
    cout << "Jumlah data: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Jumlah data harus bilangan bulat positif.\n";
        return 1;
    }

    vector<int> data(n);
    cout << "Masukkan " << n << " bilangan : ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> data[i])) {
            cout << "Input harus berupa bilangan bulat.\n";
            return 1;
        }
    }

    cout << "Sebelum:";
    for (int x : data) cout << ' ' << x;
    cout << '\n';

    mergeSort(data, 0, n - 1);

    cout << "Sesudah:";
    for (int x : data) cout << ' ' << x;
    cout << '\n';
    return 0;
}