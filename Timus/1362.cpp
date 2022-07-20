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

void solve(int root){
    vector<pair<int, int>> child;
    int max_time = -1, min_time = 0, ans_root = 0;
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
    	int desc = *it;
    	solve(desc);
        child.push_back(make_pair(answers[desc], desc));
    }
    sort(child.begin(), child.end());
    int m = child.size();;
    for (int i = 0; i < child.size(); i++){
    	if (ans_root < child[m - 1 - i].first + i + 1){
    		ans_root = child[m - 1 - i].first + i + 1;
    	}
    }
    answers[root] = ans_root;
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
    reHangUp(tanya);
    solve(tanya);
    cout << answers[tanya];
    return 0;
}
