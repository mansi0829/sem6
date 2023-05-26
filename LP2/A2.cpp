#include <bits/stdc++.h>

using namespace std;

void solve(const vector<int>& h_val, const vector<vector<pair<int, int>>>& graph, int src, int goal) {
    priority_queue<pair<int, int>> q;
    q.push({h_val[src], src});
    
    vector<int> dist(goal + 1, numeric_limits<int>::max());
    dist[src] = h_val[src];
    
    vector<int> par(goal + 1, 0);
    int cnt = 0;
    
    while (!q.empty()) {
        cnt++;
        int temp = q.top().first;
        int ver = q.top().second;
        int rada = temp - h_val[ver];
        q.pop();
        
        for (const auto& x : graph[ver]) {
            int new_dist = rada + h_val[x.first] + x.second;
            
            if (dist[x.first] > new_dist) {
                par[x.first] = ver;
                q.push({new_dist, x.first});
                dist[x.first] = new_dist;
            }
        }
    }
    
    cout << "Distances from source to all vertices: ";
    for (auto x : dist) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Optimal path from source to goal: ";
    vector<int> ans;
    ans.push_back(goal);
    
    while (goal != src) {
        ans.push_back(par[goal]);
        goal = par[goal];
    }
    
    reverse(ans.begin(), ans.end());
    
    for (auto x : ans) {
        cout << x << " ";
    }
}

int main() {
    try {
        cout << "Enter the number of vertices and edges: ";
        int vertex, edges;
        cin >> vertex >> edges;
        
        vector<vector<pair<int, int>>> graph(vertex);
        
        cout << "Enter the source vertex: ";
        int src;
        cin >> src;
        
        vector<int> weight(vertex, numeric_limits<int>::max());
        weight[src] = 0;
        
        for (int i = 0; i < edges; i++) {
            cout << "Enter two vertices and the weight of the edge: ";
            int x, y, w;
            cin >> x >> y >> w;
            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }
        
        vector<int> h_val(vertex);
        for (int i = 0; i < vertex; i++) {
            cout << "Enter the h value of vertex " << i << ": ";
            cin >> h_val[i];
        }
        
        solve(h_val, graph, 0, vertex - 1);
    } 
    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }
    return 0;
}
