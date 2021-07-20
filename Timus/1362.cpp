#include <iostream>
#include <vector>

using namespace std;
vector<int> answers;
vector<int> heights;
vector<vector<int>> graph;
int max_time = 0;

void reHangUp(int root){

}

void calculateHeights(int root){    
    int max_height = 0;
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
        int desc = *it;
        calculateHeights(desc);
        if (heights[desc] > max_height){
            max_height = heights[desc];
        }
    } 
    heights[root] = max_height;      
}

void solve(int root, int time){
    answers[root] = time;
    if (time > max_time)
        max_time = time;
    for (vector<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
        int desc = *it;
        
    }
}


int main(){
    int n, tanya;
    cin >> n;
    
    answers.resize(n + 1, -1);
    heights.resize(n + 1, -1);
    graph.resize(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++){
        int son = -1;
        while (son != 0){
            cin >> son;
            if (son != 0){                
                graph[i].push_back(son);
            }
        }
    }
    cin >> tanya;
    calculateHeights(tanya);
    solve(tanya, 0);
    cout << max_time;
    return 0;
}