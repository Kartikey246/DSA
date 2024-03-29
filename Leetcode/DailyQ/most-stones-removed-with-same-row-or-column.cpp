// bas groups identify karne hai, ans is total stones - no.of groups


class Solution {
public:
    
    // store same row or col cords index in Rowlist and Collist
    unordered_map<int,vector<int>>Rowlist;
    unordered_map<int,vector<int>>Collist;
    
    void dfs (int index, vector<bool>&visited, vector<vector<int>>&stones)
    {
        visited[index] = true;
        
        for(int i=0;i<Rowlist[stones[index][0]].size();i++)
        {
            if(visited[Rowlist[stones[index][0]][i]])continue;
            dfs(Rowlist[stones[index][0]][i],visited,stones);
        }

        for(int i=0;i<Collist[stones[index][1]].size();i++)
        {
            if(visited[Collist[stones[index][1]][i]])continue;
            dfs(Collist[stones[index][1]][i],visited,stones);
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        // total stones
        int n = stones.size();
        
        // visited stones track
        vector<bool>visited(n,false);

        // store same row or col cords index in Rowlist and Collist 
        for(int i=0;i<n;i++)
        {
            Rowlist[stones[i][0]].push_back(i);
            Collist[stones[i][1]].push_back(i);
        }
        
        // count the connected components 
        int c = 0;
        
        // loop through stones and call DFS for unvisited stones 
        // and count number of connected components
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            dfs(i,visited,stones);
            c++;
        }
        
        // total stones - no of connected components
        return n-c;
    }
};
