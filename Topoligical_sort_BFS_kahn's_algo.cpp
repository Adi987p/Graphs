class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            adj[second].push_back(first);
        }
        vector<int> topo;
        vector<int> inDegree(numCourses);
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i])
                inDegree[it]++;
        }

        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0)
                s.push(i);
        }

        while (!s.empty()) {
            int temp = s.top();
            s.pop();
            topo.push_back(temp);
            for (auto it : adj[temp]) {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    s.push(it);
            }
        }

        return (topo.size() < numCourses) ? vector<int>{} : topo;
    }
};
