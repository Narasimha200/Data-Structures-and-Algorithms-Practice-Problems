#include <bits/stdc++.h>
using namespace std;
//reference link: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
class disjoinSet{
    //use either union by rank or union by size not
    vector<int> rank, parent, size;
    public:
    disjoinSet(int n){
        //for support fo 1based indexing
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findUltiParent(int node){
        if(node == parent[node]){
            return node;
        }
        int result = findUltiParent(parent[node]);
        //path compression
        parent[node] = result;
        return result;
    }

    void unionByRank(int u, int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        //both are already in the same component
        if(ultiParent_u == ultiParent_v) return;

        if(rank[ultiParent_u] < rank[ultiParent_v]){
            parent[ultiParent_u] = ultiParent_v;
        }
        else if(rank[ultiParent_v] < rank[ultiParent_u]){
            parent[ultiParent_v] = ultiParent_u;
        }
        else{
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        //both are already in the same component
        if(ultiParent_u == ultiParent_v) return;

        if(size[ultiParent_u] < size[ultiParent_v]){
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        else{
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
    }
};

int main(){
    disjoinSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if(ds.findUltiParent(3) == ds.findUltiParent(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;
    ds.unionBySize(3, 7);
    if(ds.findUltiParent(3) == ds.findUltiParent(7)) cout << "Same" << endl;
    else cout << "Not Same" << endl;
}
//TC:- n * alpha(n)
//SC:- O(n)
