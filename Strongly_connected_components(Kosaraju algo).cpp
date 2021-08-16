#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	stack<int>s;
	int c=0;
	int vis[6000]={0};
	//Function to find number of strongly connected components in the graph.
    void dfs(int n,vector<int>adj[])
    {
        vis[n]=1;
        for(auto x:adj[n])
        {
            if(vis[x]==0)
            {
                dfs(x,adj);
                
            }
        }
            s.push(n);
    }
    
    void rdfs(int n,vector<int>transpose[])
    {
        vis[n]=1;
        for(auto x:transpose[n])
        {
            //cout<<x<<endl;
            if(vis[x]==0)
            {
                rdfs(x,transpose);
                //c++;
            }
        }
    }
    int kosaraju(int V, vector<int> adj[])
    {
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(i,adj);
        }
        vector<int> transpose[V]; 
	    memset(transpose,0,sizeof(transpose));
	    for(int i = 0;i<V;i++)
	    {
	         vis[i] = 0; 
	         for(auto it: adj[i])
	         {
	            transpose[it].push_back(i); 
	         }
	    }
	   // for(int i=0;i<V;i++)
	   // {
	   //     for(auto x:transpose[i])
	   //     cout<<x<<" ";
	   //     cout<<endl;
	   // }
	    //int c=0;
	    while(s.size()!=0)
	    {
	        int i=s.top();
	       // cout<<i<<endl;
	        s.pop();
	        if(vis[i]==0)
	        {
	            
	            rdfs(i,transpose);
	            c++;
	        }
	    }
	    return(c);
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
