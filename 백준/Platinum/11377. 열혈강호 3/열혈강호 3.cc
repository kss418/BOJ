#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2020;

    
struct dinic{
    ll cap[MAX][MAX], fl[MAX][MAX], level[MAX], work[MAX];
    vector <ll> arr[MAX];
    
    void add(ll st, ll en, ll capacity){
        arr[st].push_back(en);
        arr[en].push_back(st);
        cap[st][en] += capacity;
    }
    
    bool bfs(ll st, ll en){
        memset(level, -1, sizeof(level));
        level[st] = 0;
        queue <ll> q;
        q.push(st);
        
        while(!q.empty()){
            ll cur = q.front(); q.pop();
            for(auto nxt : arr[cur]){
                if(level[nxt] == -1 && cap[cur][nxt] - fl[cur][nxt] > 0){
                    level[nxt] = level[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        
        return level[en] != -1;
    }
    
    ll dfs(ll cur,ll en,ll flow){
        if(cur == en) return flow;
        
        for(ll &i = work[cur]; i < arr[cur].size();i++){
            ll nxt = arr[cur][i];
            if(level[nxt] == level[cur] + 1 && cap[cur][nxt] - fl[cur][nxt] > 0){
                ll plus = dfs(nxt, en, min(cap[cur][nxt] - fl[cur][nxt], flow));
                if(plus > 0){
                    fl[cur][nxt] += plus;
                    fl[nxt][cur] -= plus;
                    return plus;
                }
            }
        }
        
        return 0;
    }
    
    ll solve(ll st, ll en){
        ll ret = 0;
        while(bfs(st, en)){
            memset(work, 0, sizeof(work));
            while(1){
                ll flow = dfs(st, en, INF);
                if(!flow) break;
                ret += flow;
            }
        }
        
        return ret;
    }
};



int main() {
	fastio;
    
    cin >> n >> m >> k;
    dinic flow;
    
    for(int i = 1; i <= n;i++){
        cin >> t;
        flow.add(0, i, 1);
        while(t--){
            ll num;
            cin >> num;
            flow.add(i, 1000 + num, 1);
        }
    }
    
    flow.add(0, 2001, k);
    for(int i = 1; i <= m;i++) flow.add(2001, i, 1);
    for(int i = 1; i <= m;i++)flow.add(1000 + i, 2005, 1);
    
    cout << flow.solve(0, 2005);
    
    
	return 0;
}
