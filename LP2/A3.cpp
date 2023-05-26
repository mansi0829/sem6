#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int, int> iPair;

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<vector<pair<int, int>>>& adj, int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex \tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    try {
        int V = 9;
        vector<vector<pair<int, int>>> adj(V);

        int choice;
        while (true) {
            cout << "1. Add an edge\n";
            cout << "2. Compute shortest path\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                int u, v, wt;
                cout << "Enter vertices (u v) and weight (wt) of the edge: ";
                cin >> u >> v >> wt;
                addEdge(adj, u, v, wt);
            } else if (choice == 2) {
                int src;
                cout << "Enter the source vertex: ";
                cin >> src;
                shortestPath(adj, V, src);
            } else if (choice == 3) {
                break;
            } else {
                cout << "Invalid choice! Please try again.\n";
            }
            cout << endl;
        }
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
