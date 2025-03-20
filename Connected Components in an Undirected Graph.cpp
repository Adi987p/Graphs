//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1?page=5&category=Graph&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class DisjointSet{
    private:
        vector<int>parent,rank;
    public:
        DisjointSet(int v)
        {
            parent.resize(v+1,0);
            rank.resize(v+1,0);
            
            for(int i=0;i<=v;i++)
            {
                parent[i]=i;
            }
        }
        
        int findUlPar(int node)
        {
            if(parent[node]==node)
                return node;
            
            return parent[node]=findUlPar(parent[node]);
        }
        
        void unionByRank(int u,int v)
        {
            int ulp_u = findUlPar(u);
            int ulp_v = findUlPar(v);
            
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
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        DisjointSet ds(v);
        
        for(int i=0;i<edges.size();i++)
        {
           ds.unionByRank(edges[i][0],edges[i][1]); 
        }
        
        map<int,vector<int>>m;
        
        for(int i=0;i<v;i++)
        {
            m[ds.findUlPar(i)].push_back(i);
        }
        
        vector<vector<int>>ans;
        for(auto &it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
