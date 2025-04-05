#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 20101;
vector <ll> a[MAX];
ll v[MAX], result, n, m;

void dfs(ll cur, ll num){
    v[cur] = num;
    
    for(auto& nxt : a[cur]){
        if(v[nxt] != -1){
            if(v[nxt] != num ^ 1) result = 0;
            continue;
        }
        dfs(nxt, num ^ 1); 
    }
}

void add(int s, int e){
    // 양방향 간선 추가
    a[s].push_back(e);
    a[e].push_back(s);
}

void solve(){
    cin >> n >> m;

    result = 1;
    for(int i = 1;i <= n;i++) {
        a[i].clear(); v[i] = -1;
    }

    while(m--){
        ll s, e; cin >> s >> e;
        add(s, e);
    }

    for(int i = 1;i <= n;i++){
        if(v[i] != -1) continue;
        dfs(i, 0);
    }
    cout << (result ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}