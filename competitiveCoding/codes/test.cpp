#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

template <typename T>
class Edge
{
private:
    T node1, node2, weight;

public:
    T getNode1()
    {
        return node1;
    }

    T getNode2()
    {
        return node2;
    }

    T getWeight()
    {
        return weight;
    }

    Edge(T node1, T node2, T weight)
    {
        this->node1 = node1;
        this->node2 = node2;
        this->weight = weight;
    }

    void printData()
    {
        cout << "Node1: " << this->node1 << " Node2: " << this->node2 << " Weight: " << this->weight << endl;
    }
};

template <typename T>
struct DisjointSet
{
    vector<T> parent, size;

    DisjointSet(int maxSize)
    {
        parent.resize(maxSize);
        size.resize(maxSize);

        for (T i = 0; i < maxSize; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void printParentArray()
    {
        cout << "Printing parent array \n";
        for (auto i : parent)
        {
            cout << i << " ";
        }
        cout << "\n parent array done\n";
    }

    T find_set(T curr)
    {
        if (parent[curr] == curr)
            return curr;
        return parent[curr] = find_set(parent[curr]);
    }

    void union_set(T a, T b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int edit_distance(vector<int> &a, vector<int> &b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

vector<Edge<ll>> createDenseGraph(vector<vector<int>> &points)
{
    int size = points.size();
    vector<Edge<ll>> graph;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            graph.push_back(Edge<ll>((ll)i, (ll)j, (ll)edit_distance(points[j], points[i])));
        }
    }
    return graph;
}

vector<Edge<ll>> krushkal(vector<Edge<ll>> &graph)
{
    sort(graph.begin(), graph.end(), [](Edge<ll> a, Edge<ll> b)
         { return a.getWeight() < b.getWeight(); });

    vector<Edge<ll>> result;
    DisjointSet<ll> disjointSet(graph.size() + 1);

    for (auto &edge : graph)
    {
        if (disjointSet.find_set(edge.getNode1()) == disjointSet.find_set(edge.getNode2()))
        {
            cout << "disjoint set is matching";
            continue;
        }
        else
        {
            disjointSet.union_set(edge.getNode1(), edge.getNode2());
            result.push_back(edge);
        }
    }

    return result;
}

int main()
{
    int n, a, b;
    cin >> n;

    vector<vector<int>> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        points[i].push_back(a);
        points[i].push_back(b);
    }

    // for (int i=0; i<n; i++){
    //     cout<<points[i][0]<<" "<<points[i][1]<<"\n";
    // }

    auto denseGraph = createDenseGraph(points);

    auto res = krushkal(denseGraph);
}