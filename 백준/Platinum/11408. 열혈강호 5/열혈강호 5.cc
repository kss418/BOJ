#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 1010;

    
struct mcmf{
    ll cap[MAX][MAX], fl[MAX][MAX], cost[MAX][MAX];
    vector <ll> arr[MAX];
    
    void add(ll st, ll en, ll capacity, ll co){
        arr[st].push_back(en);
        arr[en].push_back(st);
        cap[st][en] += capacity;
        cost[st][en] += co;
        cost[en][st] -= co;
    }
    
    
    pll solve(ll st, ll en){
        ll min_co = 0, max_fl = 0;
        while(1){
            ll prev[MAX], dist[MAX];
            bool in[MAX];
            queue <ll> q;
            memset(prev, -1, sizeof(prev));
            memset(dist, 0x3f, sizeof(dist));
            dist[st] = 0; in[st] = 1;
            q.push(st);
            
            while(!q.empty()){
                ll cur = q.front(); q.pop();
                in[cur] = 0;
                for(auto nxt : arr[cur]){
                    if(cap[cur][nxt] - fl[cur][nxt] > 0 && dist[nxt] > dist[cur] + cost[cur][nxt]){
                        dist[nxt] = dist[cur] + cost[cur][nxt];
                        prev[nxt] = cur;
                        
                        if(!in[nxt]){
                            q.push(nxt);
                            in[nxt] = 1;
                        }
                    }
                }
            }
            
            if(prev[en] == -1) break;
            
            ll flow = INF;
            for(ll i = en; i != st;i = prev[i]) flow = min(flow, cap[prev[i]][i] - fl[prev[i]][i]);
            max_fl += flow;
            
            for(ll i = en;i != st;i = prev[i]){
                min_co += flow * cost[prev[i]][i];
                fl[prev[i]][i] += flow;
                fl[i][prev[i]] -= flow;
            }
        }
        
        return {max_fl, min_co};
    }
};



int main() {
	fastio;
    
    cin >> n >> m;
    mcmf a;
    
    for(int i = 1; i <= n;i++){
        a.add(0, i, 1, 0);
        cin >> k;
        while(k--){
            ll num, cost;
            cin >> num >> cost;
            a.add(i, num + 500, 1, cost);
        }
    }
    
    for(int i = 1; i <= m;i++) a.add(i + 500, 1001, 1, 0);
    
    pll result = a.solve(0, 1001);
    cout << result.first << "\n" << result.second;
    
    
	return 0;
}
