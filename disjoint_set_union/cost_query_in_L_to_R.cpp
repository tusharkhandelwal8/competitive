#include<iostream>
#include<vector>

using namespace std;
//edge
struct Edge
{
    int dot1, dot2, weight;
};
//for qsort 
int compare(const void *a, const void *b) 
{
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}
//number of paths whos weight is no bigger than weight.
struct WeightPaths
{
    long long weight, paths;
};
//disjoint set's find 
int find_root(vector<int> &v, int x)
{
    if (v[x] == x)
        return x;
    else
    {
        v[x] = find_root(v, v[x]);  
        return v[x];
    }
}
//binary search
long long search(vector<WeightPaths> &weightPaths, int n) 
{
    int min = 0, max = weightPaths.size() - 1;
    long long result = 0;
    while (true)
    {
        if (max - min <= 1)
            break;
        int mean = (min + max) / 2;
        if (weightPaths[mean].weight > n)
            max = mean;
        else
            min = mean;
    }
    if (weightPaths[max].weight <= n)
        result = weightPaths[max].paths;
    else
        result = weightPaths[min].paths;
    return result;
}

int main()
{
    int n, q;
    cin >> n >> q;
    Edge * Edges = new Edge[n - 1];
    for (int i = 0;i < n - 1;i++)
        cin >> Edges[i].dot1 >> Edges[i].dot2 >> Edges[i].weight;
    qsort(Edges, n - 1, sizeof(Edge), compare); //sort

    vector<WeightPaths> weightPaths;  
    WeightPaths wp;
    wp.weight = 0;
    wp.paths = 0;
    weightPaths.push_back(wp);

    vector<int> root(n + 1), count(n + 1);  //disjoint set
    for (int i = 1;i < n + 1;i++)
    {
        root[i] = i;
        count[i] = 1;
    }
    int k = 0;
    while (k<n-1)
    {
        wp.weight = Edges[k].weight;
        while (k<n - 1 && Edges[k].weight == wp.weight)
        {
            int dot1 = Edges[k].dot1;
            int dot2 = Edges[k].dot2;
            int r1, r2;
            r1 = find_root(root, dot1);
            r2 = find_root(root, dot2);
            if (r1 != r2)
            {
                wp.paths += (long long)count[r2] * count[r1];  // caculate new paths
                root[r2] = r1;   
                count[r1] += count[r2];
                count[r2] = 0;
            }
            k++;
        }
        weightPaths.push_back(wp);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long ln, rn, p;
        ln = search(weightPaths, l - 1);
        rn = search(weightPaths, r);
        p = rn - ln;
        cout << p << endl;
    }
    return 0;
}
