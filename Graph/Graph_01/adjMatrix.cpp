#include <bits/stdc++.h>
using namespace std;

// 1. Undirected + Unweighted
void undirectedUnweighted(vector<vector<int>> &adjMat, int edges)
{
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
}

// 2. Undirected + Weighted
void undirectedWeighted(vector<vector<int>> &adjMat, int edges)
{
    int u, v, weight;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }
}

// 3. Directed + Unweighted
void directedUnweighted(vector<vector<int>> &adjMat, int edges)
{
    int u, v;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        adjMat[u][v] = 1;
    }
}

// 4. Directed + Weighted
void directedWeighted(vector<vector<int>> &adjMat, int edges)
{
    int u, v, weight;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        adjMat[u][v] = weight;
    }
}

// Print Matrix
void printMatrix(vector<vector<int>> &adjMat)
{
    for (int i = 0; i < adjMat.size(); i++)
    {
        for (int j = 0; j < adjMat[i].size(); j++)
        {
            cout << adjMat[i][j] << " ";
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
        vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

        undirectedUnweighted(adjMat, edges);

        cout << "\nAdjacency Matrix:\n";
        printMatrix(adjMat);

        break;
    }

    case 2:
    {
        vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

        undirectedWeighted(adjMat, edges);

        cout << "\nAdjacency Matrix:\n";
        printMatrix(adjMat);

        break;
    }

    case 3:
    {
        vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

        directedUnweighted(adjMat, edges);

        cout << "\nAdjacency Matrix:\n";
        printMatrix(adjMat);

        break;
    }

    case 4:
    {
        vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

        directedWeighted(adjMat, edges);

        cout << "\nAdjacency Matrix:\n";
        printMatrix(adjMat);

        break;
    }

    default:
        cout << "Invalid choice!";
    }

    return 0;
}