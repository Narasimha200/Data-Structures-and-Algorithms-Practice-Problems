#include <vector>
#include <set>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> minDist(V, 1e9);
    minDist[S] = 0;
    st.insert({0, S});
    st.erase(st.begin());
    while (!st.empty())
    {
        pair<int, int> nodeAndDist = *st.begin();
        int node = nodeAndDist.second;
        int dist = nodeAndDist.first;

        for(auto &v: adj[node]){
            int adjNode = v[0];
            int adjNodeWeight = v[1];
            if(dist + adjNodeWeight < minDist[adjNode]){
                //if node is already present in the set
                if(minDist[adjNode] != 1e9){
                    st.erase({minDist[adjNode], adjNode});
                }
                minDist[adjNode] = dist + adjNodeWeight;
                st.insert({minDist[adjNode], adjNode});
            }
        }
    }
    return minDist;
}

//TC:- Elog(V)
//SC:- V^2