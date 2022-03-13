class Solution {
public:

bool bipartiteBFS(vector<vector<int>>& graph,int src,vector<int>& color){
    queue<int> q;
    q.push(src);
    color[src] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int& x:graph[node]){
            if(color[x] == -1){
                color[x] = !color[node];
                q.push(x);
            }
            else{
                if(color[x] == color[node]){
                    return false;
                }
            }
        }
        
        
    }
    return true;
}

bool bipartiteDFS(vector<vector<int>>& graph,int src,vector<int>& color,int c){
    color[src] = c;
    int next_color = 1-c;
    
    for(int& x:graph[src]){
        if(color[x] == -1){
            if(!bipartiteDFS(graph,x,color,next_color)) return false;
        }
        else{
            if(color[x] == color[src]) return false;
        }
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int  V = graph.size();
    vector<int> color(V,-1);
    
    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(bipartiteBFS(graph,i,color) == false) return false;
        }
    }
    return true;
}
};
