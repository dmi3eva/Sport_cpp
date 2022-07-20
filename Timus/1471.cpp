#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> graph;
vector<bool> colors;
vector<int> parent;
vector<long long> time_in;
vector<long long> time_out;
vector<vector<int>> ancestors;


void dfs(vector<vector<pair<int, int>>> graph, int current_vertex){

}

int main(){
    int n, m, u, v, w;
    cin >> n;
    graph.resize(n + 1);
    colors.resize(n + 1);
    parent.resize(n + 1);
    time_in.resize(n + 1);
    time_out.resize(n + 1);
    ancestors.resize(n + 1);
    for (int i = 0; i < n; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    dfs(graph, 0);
    return 0;
}