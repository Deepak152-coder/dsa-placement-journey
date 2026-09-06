#include <bits/stdc++.h>
using namespace std;

// 1. Undirected + Unweighted
void undirectedUnweighted(vector<vector<int>> &adjList, int edges)
{
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// 2. Undirected + Weighted
void undirectedWeighted(vector<vector<pair<int, int>>> &adjList, int edges)
{
    int u, v, weight;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }
}

// 3. Directed + Unweighted
void directedUnweighted(vector<vector<int>> &adjList, int edges)
{
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        adjList[u].push_back(v);
    }
}

// 4. Directed + Weighted
void directedWeighted(vector<vector<pair<int, int>>> &adjList, int edges)
{
    int u, v, weight;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        adjList[u].push_back({v, weight});
    }
}

// Print Unweighted List
void printList(vector<vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";

        for (int j : adjList[i])
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

// Print Weighted List
void printWeightedList(vector<vector<pair<int, int>>> &adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";

        for (auto j : adjList[i])
        {
            cout << "{" << j.first << ", " << j.second << "} ";
        }

        cout << endl;
    }
}

int main()
{
    int vertex, edges, choice;

    cout << "Enter number of vertices: ";
    cin >> vertex;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "\nChoose Graph Type:\n";
    cout << "1. Undirected + Unweighted\n";
    cout << "2. Undirected + Weighted\n";
    cout << "3. Directed + Unweighted\n";
    cout << "4. Directed + Weighted\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        vector<vector<int>> adjList(vertex);

        undirectedUnweighted(adjList, edges);

        cout << "\nAdjacency List:\n";
        printList(adjList);

        break;
    }

    case 2:
    {
        vector<vector<pair<int, int>>> adjList(vertex);

        undirectedWeighted(adjList, edges);

        cout << "\nAdjacency List:\n";
        printWeightedList(adjList);

        break;
    }

    case 3:
    {
        vector<vector<int>> adjList(vertex);

        directedUnweighted(adjList, edges);

        cout << "\nAdjacency List:\n";
        printList(adjList);

        break;
    }

    case 4:
    {
        vector<vector<pair<int, int>>> adjList(vertex);

        directedWeighted(adjList, edges);

        cout << "\nAdjacency List:\n";
        printWeightedList(adjList);

        break;
    }

    default:
        cout << "Invalid choice!";
    }

    return 0;
}