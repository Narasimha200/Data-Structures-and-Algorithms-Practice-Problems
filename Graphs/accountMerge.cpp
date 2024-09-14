#include <bits/stdc++.h>
using namespace std;
// reference link: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
class disjointSet
{
    // use either union by rank or union by size not
    vector<int> rank, parent, size;

public: 
    disjointSet(int n)
    {
        // for support fo 1based indexing
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findUltiParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        int result = findUltiParent(parent[node]);
        // path compression
        parent[node] = result;
        return result;
    }

    void unionByRank(int u, int v)
    {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        // both are already in the same component
        if (ultiParent_u == ultiParent_v)
            return;

        if (rank[ultiParent_u] < rank[ultiParent_v])
        {
            parent[ultiParent_u] = ultiParent_v;
        }
        else if (rank[ultiParent_v] < rank[ultiParent_u])
        {
            parent[ultiParent_v] = ultiParent_u;
        }
        else
        {
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        // both are already in the same component
        if (ultiParent_u == ultiParent_v)
            return;

        if (size[ultiParent_u] < size[ultiParent_v])
        {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        else
        {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    map<string, int> mp;
    disjointSet ds(accounts.size());
    unordered_map<int, vector<string>> mergedAccounts;
    vector<vector<string>> ans;
    for(int i = 0; i < accounts.size(); i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string &mail = accounts[i][j];
            if(mp.count(mail)){
                ds.unionBySize(mp[mail], i);
            }
            else{
                mp[mail] = i;
            }
        }
    }

    for(pair<string, int> &mailToAccount: mp){
        string &mail = mailToAccount.first;
        int account = ds.findUltiParent(mailToAccount.second);
        //if first mail in current account
        if(mergedAccounts.count(account) == 0){
            mergedAccounts[account].push_back(accounts[account][0]);
        }
        mergedAccounts[account].push_back(mail);
    }
    //push all vectors in mergedAccounts to ans
    for(auto &final: mergedAccounts){
        ans.push_back(final.second);
    }
    return ans;
}