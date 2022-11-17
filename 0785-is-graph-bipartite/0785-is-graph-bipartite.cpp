//USING BFS TRAVERSAL

class Solution {
public:
    bool check(int start, int color[], int n, vector<vector<int>>graph){
        queue<int>q;
        q.push(start);
        color[start]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it: graph[node]){
                //if node it is adjacent and not yet colored
                if(color[it]==-1){
                        color[it]=!color[node];
                        q.push(it);
                }
                //or if node i is adjacent and colored with same color
                else if(color[it]==color[node])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();//no of vertices in the graph
        
        //unvisited nodes - not colored - represented by -1
        int color[n];
        for(int i=0;i<n;i++)
            color[i]=-1;
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){//if any node not colored
                if(check(i, color, n, graph)==false)
                    return false;
            }
        }
        
        return true;
    }
};