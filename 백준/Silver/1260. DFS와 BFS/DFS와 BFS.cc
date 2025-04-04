#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll n, m, k;
vector <ll> a[MAX];
bool v[MAX];

void bfs(int st){
    queue <int> q;
    // 큐에 시작점 추가 및 방문 처리
    q.push(st); v[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for(auto& nxt : a[cur]){
            // 방문한 정점이면 넘어 감
            if(v[nxt]) continue;
            // 큐에 다음 정점 삽입 및 방문 처리
            v[nxt] = 1;
            q.push(nxt);
        }
    }
}

void dfs(int cur){
    // 방문한 정점으로 표시
    v[cur] = 1;
    cout << cur << " ";
    
    for(auto& nxt : a[cur]){
        // 다음 정점이 방문한 정점이면 넘어 감
        if(v[nxt]) continue;
        dfs(nxt); 
    }
}

void add(int s, int e){
    // 양방향 간선 추가
    a[s].push_back(e);
    a[e].push_back(s);
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m >> k;
    while(m--){
        ll s, e; cin >> s >> e;
        add(s, e);
    }
    for(int i = 1;i <= n;i++) sort(a[i].begin(), a[i].end());

    dfs(k); cout << "\n";
    for(int i = 1;i <= n;i++) v[i] = 0;
    bfs(k);

    return 0;
}