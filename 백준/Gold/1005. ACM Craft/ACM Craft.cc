#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, k, ind[MAX];
ll a[MAX], dp[MAX];
vector <ll> adj[MAX];
queue <ll> q;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        dp[i] = ind[i] = 0;
        adj[i].clear();
    }

    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        ind[e]++;
    }
    cin >> k;

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push(i);
    }
    
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        dp[cur] += a[cur];
        for(auto& nxt : adj[cur]){
            dp[nxt] = max(dp[nxt], dp[cur]);
            if(!--ind[nxt]) q.push(nxt);
        }
    }

    ll result = 0;
    cout << dp[k] << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) run();

    return 0;
}

