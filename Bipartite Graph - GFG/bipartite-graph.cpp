//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start, int color[], int n, vector<int>graph[]){
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
	bool isBipartite(int n, vector<int>adj[]){
        
        //unvisited nodes - not colored - represented by -1
        int color[n];
        for(int i=0;i<n;i++)
            color[i]=-1;
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){//if any node not colored
                if(check(i, color, n, adj)==false)
                    return false;
            }
        }
        
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends