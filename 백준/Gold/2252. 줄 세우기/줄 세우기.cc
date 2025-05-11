#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 50101;
const ll INF = 1e12;
ll n, m, ind[MAX];
vector <ll> adj[MAX];
queue <ll> q;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cout << cur << " ";
        for(auto& nxt : adj[cur]){
            if(!--ind[nxt]) q.push(nxt);
        }
    }

    return 0;
}

