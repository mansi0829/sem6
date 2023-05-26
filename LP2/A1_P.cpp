#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph
{
public:
    map<int, vector<int>> adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int v, map<int, bool>& visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                dfs(i, visited);
            }
        }
    }

    void printAdjacencyList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (int j : i.second)
            {
                cout << j << "-->";
            }
            cout << endl;
        }
    }

    void bfs(int v)
    {
        map<int, bool> visited;
        queue<int> q;
        visited[v] = true;
        q.push(v);
        while (!q.empty())
        {
            v = q.front();
            q.pop();
            cout << v << " ";
            for (auto u : adj[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        if (!(cin >> u >> v))
        {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
            continue;
        }
        g.addEdge(u, v);
    }

    while (true)
    {
        int choice;
        cout << "\nEnter your choice:" << endl;
        cout << "1. Adjacency List" << endl;
        cout << "2. DFS" << endl;
        cout << "3. BFS" << endl;
        cout << "4. Quit" << endl;
        cout << "Choice: ";
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            cout << "Adjacency List:" << endl;
            g.printAdjacencyList();
        }
        else if (choice == 2)
        {
            int startVertex;
            cout << "Enter the starting vertex for DFS: ";
            if (!(cin >> startVertex))
            {
                cout << "Invalid input. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cout << "DFS is: ";
            map<int, bool> visited;
            g.dfs(startVertex, visited);
        }
        else if (choice == 3)
        {
            int startVertex;
            cout << "Enter the starting vertex for BFS: ";
            if (!(cin >> startVertex))
            {
                cout << "Invalid input. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cout << "BFS is: ";
            g.bfs(startVertex);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
