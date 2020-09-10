// min heap comparator
class Compare
{
public:
    bool operator() (pair<int, int>& a, pair<int, int>& b){
        return a.first >= b.first;
    }
};

vector <int> dijkstra(vector<vector<int>> g, int src, int V){
    vector<int> dist(V);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    
    vector<bool> vis(V, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
    pq.push(make_pair(0, src));
    
    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();
        
        vis[x] = true;
        
        for (int i=0; i<V; i++){
            if (g[x][i] && x != i && !vis[i] && dist[x]+g[x][i] < dist[i] ){
                dist[i] = dist[x]+g[x][i];
                pq.push(make_pair(dist[i], i));
            }
        }
    }
    
    
    return dist;
}
