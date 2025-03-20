// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1?page=6&category=Graph&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class DisjointSet{
    private:
        vector<int>rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
           }
        }
        
        int findUPar(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findUPar(parent[node]);
        }
        
        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if(ulp_u == ulp_v)
                return ;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &adj) {
        // code here
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<adj.size();i++)
        {
                int adjNode = adj[i][1];
                int wt = adj[i][2];
                int node =adj[i][0] ;
                
                edges.push_back({wt,{node,adjNode}});
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWt = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWt += wt;
                ds.unionByRank(u,v);
            }
        }
        
        return mstWt;
        
    }
};














//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
