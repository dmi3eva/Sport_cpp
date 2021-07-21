#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;
vector<int> answers;
vector<int> parents;
vector<int> heights;
vector<vector<int>> graph;
int max_time = 0;

void reHangUp(int root){
    while (parents[root] != -1){
        int prev_root = root;
        root = parents[root];
        graph[prev_root].push_back(root);
        int root_ind = 0;
        while (graph[root][root_ind] != prev_root)
            root_ind++;
        graph[root].erase(graph[root].begin() + root_ind);
    }
}

void calculateHeights(int root){    
    int max_height = 0;
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
        int desc = *it;
        calculateHeights(desc);
        if (heights[desc] + 1 > max_height){
            max_height = heights[desc] + 1;
        }
    } 
    heights[root] = max_height + graph[root].size();      
}

void solve(int root, int time){    
    answers[root] = time;
    if (time > max_time)
        max_time = time;
    vector<pair<int, int>> child;
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
        int desc = *it;
        child.push_back(make_pair(heights[desc], desc));
    }
    sort(child.begin(), child.end());  
    
    for (int i = child.size() - 1; i >= 0; i--){         
        solve(child[i].second, time + 1);
        time++;
    }        
}

void print_graph(){
    cout << "--- GRAPH ---" << endl;
    for (int i = 1; i < graph.size(); i++){
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

void print_vector(vector<int> v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main(){
    int n, tanya;
    cin >> n;
    
    answers.resize(n + 1, -1);
    heights.resize(n + 1, -1);
    parents.resize(n + 1, -1);
    graph.resize(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++){
        int son = -1;
        while (son != 0){
            cin >> son;
            if (son != 0){                
                graph[i].push_back(son);
                parents[son] = i;
            }
        }
    }
    cin >> tanya;
    // print_graph();
    reHangUp(tanya);
    // print_graph();
    calculateHeights(tanya);
    // print_vector(heights);
    solve(tanya, 0);
    // print_vector(answers);
    cout << max_time;
    return 0;
}