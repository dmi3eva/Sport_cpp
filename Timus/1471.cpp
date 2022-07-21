#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> graph;
vector<bool> colors;
vector<int> parent;
vector<long long> weights;
vector<long long> time_in;
vector<long long> time_out;
vector<vector<int>> ancestors;


void dfs(int vertex, long long current_time){
    colors[vertex] = true;
    time_in[vertex] = current_time;
    for (int i = 0; i < graph[vertex].size(); i++){
        int neighbour_id = graph[vertex][i].first;        
        if (colors[neighbour_id])
            continue;
        int neighbour_weight = graph[vertex][i].second;
        parent[neighbour_id] = vertex;
        weights[neighbour_id] = weights[vertex] + neighbour_weight;
        current_time++;
        dfs(neighbour_id, current_time);
    }
    time_out[vertex] = current_time + 1;
}

int main(){
    int n, m, u, v, w;
    cin >> n;
    graph.resize(n + 1);
    colors.resize(n + 1, false);
    parent.resize(n + 1);
    time_in.resize(n + 1);
    time_out.resize(n + 1);
    ancestors.resize(n + 1);
    weights.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    int root = 0;
    weights[root] = 0;
    dfs(root, 0);
    
    for (int i = 0; i < n; i++)
        cout << i << ": " << time_in[i] << " " << time_out[i] << endl;

    return 0;
}