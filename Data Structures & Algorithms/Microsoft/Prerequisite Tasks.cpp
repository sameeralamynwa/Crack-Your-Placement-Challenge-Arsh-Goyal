class Solution {
    public:
    bool checkCycle(int task, vector <vector <int> > &adj, vector <int> &color){
        color[task] = 1;
        for(int neighbours : adj[task]){
            if(color[neighbours] == 0){
                if(checkCycle(neighbours, adj, color)){
                    return true;
                }
            }
            else if(color[neighbours] == 1){
                return true;
            }
        }
        color[task] = 2;
        return false;
    }
    
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector <vector <int> > adj(n, vector <int> {});
	    vector <int> color(n);
	    for(pair <int, int> p : prerequisites){
	        adj[p.second].push_back(p.first);
	    }
	    for(int task = 0; task < n; ++task){
	        if(color[task] == 0){
	            if(checkCycle(task, adj, color)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};
