#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 20101;
ll dp[MAX]; vector <ll> arr[MAX]; bool result;


void dfs(ll cur,ll p,ll c){
    if(dp[cur] != -1){
        if(c != dp[cur]){
            result = 0;
        }
        
        return;
    }
    
    dp[cur] = c;
    for(auto nxt : arr[cur]){
        if(nxt == p) continue;
        dfs(nxt,cur,c ^ 1);
    }
}


int main() {
	fastio;
	
	cin >> t;
	while(t--){
	    cin >> m >> n;
	    result = 1;
	    for(int i = 1; i <= m;i++) arr[i].clear();
	    memset(dp,-1,sizeof(dp));
	    for(int i = 1; i <= n;i++){
	        ll st,en;
	        cin >> st >> en;
	        arr[st].push_back(en);
	        arr[en].push_back(st);
	    }
	    
	    for(int i = 1; i <= m;i++){
	        if(dp[i] != -1) continue;
	        dfs(i,0,0);
	    }
	    
	    if(result) cout << "YES\n";
	    else cout << "NO\n";
	}
   
    
	return 0;
}