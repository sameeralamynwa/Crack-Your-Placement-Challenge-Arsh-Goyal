class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <vector <pair <int, double> > > graph(n, vector <pair <int, double> > {});
        for(int i = 0; i < (int) edges.size(); ++i){
            vector <int> &v = edges[i];
            graph[*v.begin()].push_back({v.back(), succProb[i]});
            graph[v.back()].push_back({*v.begin(), succProb[i]});
        }
        vector <double> maxProbability(n);
        priority_queue <pair <double, int> > pq;
        maxProbability[start] = 1;
        pq.push({1, start});
        while(pq.empty() == false){
            pair <double, int> current = pq.top();
            pq.pop();
            if(current.first < maxProbability[current.second]){
                continue;
            }
            for(pair <int, double> neighbours : graph[current.second]){
                if(maxProbability[neighbours.first] < current.first * neighbours.second){
                    pq.push({current.first * neighbours.second, neighbours.first});
                    maxProbability[neighbours.first] = current.first * neighbours.second;
                }
            }
        }
        return maxProbability[end];
    }
};
