#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> antrianNormal;
    queue<string> antrianDarurat;

    cout << "--- Sistem Antrian ---" << endl;
    cout << "Format Perintah:" << endl;
    cout << "  DATANG [nama]" << endl;
    cout << "  DARURAT [nama]" << endl;
    cout << "  LAYANI" << endl;
    cout << "----------------------" << endl;

    int n;
    cout << "Masukkan jumlah total perintah (N): ";
    cin >> n;

    string cmd, nama;
    for (int i = 0; i < n; ++i) {
        cout << "Perintah ke-" << (i + 1) << ": ";
        cin >> cmd;

        if (cmd == "DATANG") {
            cin >> nama;
            antrianNormal.push(nama);
        } else if (cmd == "DARURAT") {
            cin >> nama;
            antrianDarurat.push(nama);
        } else if (cmd == "LAYANI") {
            if (!antrianDarurat.empty()) {
                cout << antrianDarurat.front() << endl;
                antrianDarurat.pop();
            } else if (!antrianNormal.empty()) {
                cout << antrianNormal.front() << endl;
                antrianNormal.pop();
            }
        }
    }
    return 0;
}



//Penjelasan :
 // Input:
 //    * Program akan membaca jumlah (n).
 //    * Looping sebanyak n kali untuk membaca setiap perintah.

 // Logika Perintah:
 //    DATANG [Nama]: Jika perintah adalah "DATANG", baca nama pasien, lalu masukkan (push) nama tersebut ke belakang 'antrianNormal'.
 //    DARURAT [Nama]: Jika perintah adalah "DARURAT", baca nama pasien, lalu masukkan (push) nama tersebut ke belakang 'antrianDarurat'.
 //    LAYANI: Jika perintah adalah "LAYANI":
 //        - Cek terlebih dahulu 'antrianDarurat'. Jika antrianDarurat tidak kosong, layani pasien darurat. Cetak nama pasien terdepan lalu keluarkan dari antrian darurat.
 //        - Jika 'antrianDarurat' kosong, baru cek 'antrianNormal'. Jika 'antrianNormal' tidak kosong, layani pasien normal. Cetak nama pasien terdepan lalu keluarkan dari antrian normal.
 //        - Jika kedua antrian kosong, "LAYANI" tidak melakukan apa-apa.
