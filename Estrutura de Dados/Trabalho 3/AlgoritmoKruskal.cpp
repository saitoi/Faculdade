#include <iostream>
#include <algorithm>

template <typename T>
struct MyVector {
    T* a;
    int size;
    int capacity;

    MyVector() {
        size = 0;
        capacity = 15;
        a = new T[capacity];
    }

    MyVector(int n) {
        size = n;
        capacity = std::min(n, 15);
        a = new T[capacity];
    }

    ~MyVector() {
        delete[] a;
    }

    void push_back(const T& x) {
        if(size == capacity) {
            resize(2*capacity);
        }

        a[size] = x;
        size++;
    }

    void resize(int new_capacity) {
        T* new_a = new T[new_capacity];
        int new_size = std::min(new_capacity, size);

        for(int i = 0; i < new_size; i++) {
            new_a[i] = a[i];
        }
        delete[] a;

        a = new_a;
        size = new_size;
        capacity = new_capacity;
    }

    T& operator[](int i) {
        return a[i];
    }
};

template <typename T>
struct pair
{
    T first;
    T second;
};

template <typename T>
struct tuple
{
    T first;
    T second;
    T third;
};

int findParent(int v, int parent[]) {
    if (parent[v] == -1)
        return v;
    return findParent(parent[v], parent);
}

void unionSets(int x, int y, int parent[]) {
    int xSet = findParent(x, parent);
    int ySet = findParent(y, parent);
    parent[xSet] = ySet;
}

int kruskal(MyVector<tuple<int> >& edges, MyVector<MyVector<pair<int> > >& adjacencies, MyVector<MyVector<pair<int> > >& minSpanningTree) {
    int ans = 0;
    int V = adjacencies.size;
    int E = edges.size;
    int parent[V];
    std::fill(parent, parent + V, -1);

    std::sort(edges.a, edges.a + E, [](const tuple<int>& a, const tuple<int>& b) {
        return a.third < b.third;
    });

    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        int weight = edges[i].third;

        int setU = findParent(u, parent);
        int setV = findParent(v, parent);

        if (setU != setV) {
            minSpanningTree[u].push_back({v, weight});
            minSpanningTree[v].push_back({u, weight});
            ans += weight;
            unionSets(setU, setV, parent);
        }
    }

    return ans;
}

int main() {
    int n;
    std::cin >> n;

    MyVector<MyVector<pair<int> > > adjacencies(n), minSpanningTree(n);
    MyVector<tuple<int> > edges;
    int u, v, weight;
    while (std::cin >> u >> v >> weight) {
        edges.push_back({u, v, weight});
        adjacencies[u].push_back({v, weight});
        adjacencies[v].push_back({u, weight});
    }

    std::cout << kruskal(edges, adjacencies, minSpanningTree);

    return 0;
}