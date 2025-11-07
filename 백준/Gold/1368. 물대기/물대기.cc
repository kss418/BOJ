#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX = 303;
ll n, c, result;
bool v[MAX];
vector <pll> adj[MAX];

class node{
public:
    ll s, e, c;
    bool operator > (const node& ot) const{
        return c > ot.c;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> c, adj[0].push_back({i, c});
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> c; if(!c) continue;
            adj[i].push_back({j, c});
        }
    }    

    v[0] = 1;
    for(auto& [e, c] : adj[0]) pq.push({0, e, c});
    
    while(!pq.empty()){
        auto[s, e, c] = pq.top(); pq.pop();
        if(v[e] == 1) continue;
        result += c; v[e] = 1;
    
        for(auto& [nxt, co] : adj[e]){
            if(v[nxt]) continue;
            pq.push({e, nxt, co});
        }
    }

    cout << result;
    return 0;
}