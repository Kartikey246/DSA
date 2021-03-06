class Solution {
public:
    double dfs(int s, vector<vector<int>> &adj, vector<bool>&vis, int time, int target)
    {
        vis[s] = 1;
        if(time == 0)
        {
            return s == target ? 1.0 : 0.0;
        }
        int count = 0;
        double ans;
        double subans = 0.0;
        for(int i = 0; i < adj[s].size(); i++)
        {
            int v = adj[s][i];
            if(vis[v] == 0)
            {
                count++;
                subans += dfs(v, adj, vis, time - 1, target);
            }
        }
        if(count > 0)
        {
            ans = 1.0/(count*1.0);
            ans = ans*subans;
        }
        else
        {
            ans = (s == target) ? 1.0 : 0.0;
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int f = edges[i][0], to = edges[i][1];
			// build undirected graph
            adj[f].push_back(to);
            adj[to].push_back(f);
        }
        vector<bool> vis(n + 1);
        return dfs(1, adj, vis, t, target);
    }
};
