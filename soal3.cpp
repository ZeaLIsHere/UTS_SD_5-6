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
        auto [node, hari] = q.front();
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
