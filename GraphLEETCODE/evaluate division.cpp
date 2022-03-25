class Solution {
public:
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        // Construct graph
        for (int i = 0; i < n; ++i) {
            double weight = values[i];
            string dst = equations[i][0];
            string src = equations[i][1];
            graph[src][dst] = weight;
            graph[dst][src] = 1/weight;
        }

        // DFS for queries' answer
        for (auto &q : queries) {
            if (graph.count(q[0]) == 0 || graph.count(q[1]) == 0) {
                ans.push_back(-1.0);
                continue;
            }

            visited.clear();
            if (false == dfs(q[0], q[1], 1.0)) {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }

    bool dfs(string &dst, string &src, double value) {
        if (src == dst) {
            ans.push_back(value);
            return true;
        }

        visited.insert(src); // mark visited

        bool isValid = false;

        for (auto &p : graph[src]) {
            auto next = p.first;
            auto weight = p.second;

            if (visited.count(next) > 0) { // visited before
                continue;
            }

            if (true == dfs(dst, next, value*weight)) {
                return true;
            }
        }

        return false;
    }

private:
    vector<double> ans;
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;
};
