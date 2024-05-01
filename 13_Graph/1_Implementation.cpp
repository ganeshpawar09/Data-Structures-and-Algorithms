#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class graph
{
    unordered_map<int, list<int>> adj;
    int vertex;

public:
    graph(int vertex)
    {
        this->vertex = vertex;
    }
    void addEdge(int u, int v, int direction = 0)
    {
        // direction ->0 undirected
        // direction ->1 directed

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print_graph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void bfs()
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < vertex; i++)
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    cout << temp << " ";
                    for (auto j : adj[temp])
                    {
                        if (!visited[j])
                        {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    graph a(5);
    a.addEdge(0, 1);
    a.addEdge(0, 4);
    a.addEdge(1, 2);
    a.addEdge(1, 3);
    a.addEdge(3, 2);
    a.addEdge(4, 3);

    a.print_graph();
    a.bfs();

    return 0;
}
