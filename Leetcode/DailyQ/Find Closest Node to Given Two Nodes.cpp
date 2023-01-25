class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       vector<int> a,b;
        a = bfs(edges, node1);
        b = bfs(edges, node2);
        int ansN=-1;
        int mm=INT_MAX;
        for(int i=0;i<edges.size();i++){
            int x = max(a[i], b[i]);
            if(x<mm){
                mm=x;
                ansN=i;
            }
            else if(x==mm){
                if(ansN>i){
                    ansN=i;
                }
            }
        }
        return ansN;
    }
    
    
    vector<int> bfs(vector<int>& edges, int node1){
        vector<int> dist(edges.size(), INT_MAX);
        queue<int> q;
        dist[node1]=0;
        
        q.push(node1);
        
        while(!q.empty()){
            int n= q.front();
            q.pop();
            if(edges[n]!=-1){
                if(dist[edges[n]]>dist[n]+1){
                dist[edges[n]]=dist[n]+1;
                q.push(edges[n]);
            }
            }
            
        }
        return dist;
        
        
    }
};
