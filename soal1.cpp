#include <iostream>
using namespace std;


void GeserKiri(int arr[], int n, int d) {
    d = d % n; // memastikan rotasi(d) tidak melebihi jumlah array(n) 

    for (int i = 0; i < n; ++i) {
        cout << arr[(i + d) % n];
        if (i < n - 1) cout << " ";
    }//loop untuk mencetak elemen setelah rotasi 

    cout << endl;
}

int main() {
    int n, d;
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;

    int arr_abid[n]; //membuat array dengan nama arr_abid dengan jumlah n

    for (int i = 0; i < n; ++i) {
        cin >> arr_abid[i];
    } //loop untuk meminta user menginput nilai array satu per satu

    GeserKiri(arr_abid, n, d); //menjalankan fungsi rotasi kiri

    return 0;
}

// Program meminta input jumlah elemen array (n) dan jumlah rotasi (d), lalu membaca n nilai ke dalam array arr_abid.
// Kemudian program memanggil fungsi GeserKiri untuk melakukan rotasi kiri secara melingkar (circular).
// Di dalam fungsi, nilai d disesuaikan agar tidak lebih besar dari n dengan operasi d % n.
// Selanjutnya, setiap elemen dicetak menggunakan indeks baru (i + d) % n sehingga elemen bergeser ke kiri
// dan elemen yang keluar di kiri akan muncul kembali di kanan seperti circular array.

