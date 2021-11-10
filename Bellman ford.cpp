class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>dis(n,INT_MAX);
	    dis[0]=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(auto x:edges)
	        {
	            if(dis[x[0]]==INT_MAX)
	            continue;
	            else
	            if(dis[x[0]]+x[2]<dis[x[1]])
	            {
	                dis[x[1]]=dis[x[0]]+x[2];
	            }
	        }
	    }
	    for(auto x:edges)
	    {
	        if(dis[x[0]]+x[2]<dis[x[1]])
	        return 1;
	    }
	    return 0;
	}
};
