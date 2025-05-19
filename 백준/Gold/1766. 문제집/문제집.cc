#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 40101;
const ll INF = 1e12;
ll n, m, ind[MAX];
vector <ll> adj[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

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
        if(!ind[i]) pq.push(i);
    }

    while(!pq.empty()){
        ll cur = pq.top(); pq.pop();
        cout << cur << " ";
        for(auto& nxt : adj[cur]){
            if(!--ind[nxt]) pq.push(nxt);
        }
    }

    return 0;
}

