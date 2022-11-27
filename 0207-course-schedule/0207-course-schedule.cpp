class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<int>adj[N];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indeg(N, 0);
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){//no of adjacent nodes
	            indeg[it]++;
	        }
        }
        
        queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            //decreasing indegree by one of 
	            //all nodes adjacent to node being removed from queue
	            indeg[it]--;
	            if(indeg[it]==0) q.push(it);
	        }
	    }
	    
	    if(topo.size()==N)
	    return true;
	    
	    return false;
    }
};