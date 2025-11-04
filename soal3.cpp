#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<bool> visited(V, false);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int S, K;
    cout << "Node Awal dan Hari Terinfeksi: ";
    cin >> S >> K;

    queue<pair<int, int>> q;
    q.push({S, 0});
    visited[S] = true;

    vector<int> hasil;

    while (!q.empty()) {
        int node = q.front().first;
        int hari = q.front().second;
        q.pop();

        if (hari == K) {
            hasil.push_back(node);
        } else if (hari < K) {
            for (int tetangga : graph[node]) {
                if (!visited[tetangga]) {
                    visited[tetangga] = true;
                    q.push({tetangga, hari + 1});
                }
            }
        }
    }

    cout << "Node terinfeksi: ";
    if (hasil.empty()) {
        cout << "(TIDAK ADA)" << endl;
    } else {
        sort(hasil.begin(), hasil.end());
        for (int id : hasil) {
            cout << id << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
PENJELASAN KODE PROGRAM


Program ini mensimulasikan penyebaran virus dalam jaringan sosial menggunakan algoritma Breadth-First Search (BFS). Setiap node mewakili satu orang, dan edge mewakili hubungan pertemanan antar orang.

🔹 Input:
- Jumlah vertex (V) dan edge (E)
- Daftar pasangan pertemanan (graf tak berarah)
- Node awal yang terinfeksi (S) dan hari ke-K yang ingin dianalisis

🔹 Proses:
- Program membangun graf menggunakan adjacency list
- BFS dimulai dari node awal (S) dengan hari ke-0
- Setiap node yang terinfeksi akan menularkan virus ke semua tetangganya di hari berikutnya
- Node yang baru terinfeksi tepat di hari ke-K akan disimpan dalam hasil

🔹 Output:
- Jika ada node yang terinfeksi di hari ke-K, program mencetak ID mereka dalam urutan menaik
- Jika tidak ada, program mencetak "(TIDAK ADA)"

🔹 Tujuan:
- Mengetahui siapa saja yang baru terinfeksi tepat pada hari ke-K
- Menunjukkan pemahaman tentang BFS dan struktur data graf

*/
