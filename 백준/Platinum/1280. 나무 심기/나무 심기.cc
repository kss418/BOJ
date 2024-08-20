#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
const ll MOD = 1e9 + 7;


struct seg{
    vector <ll> arr, tree;
    seg(ll n) : arr(n), tree(4 * n) {}
    
    void init(ll idx, ll num){ arr[idx] = num;}
    
    ll con(ll st, ll en, ll node){
        if(st == en) return tree[node] = arr[st];
        
        ll mid = (st + en) >> 1;
        return tree[node] = con(st, mid, node * 2) + con(mid + 1, en, node * 2 + 1);
    }
    
    ll query(ll st, ll en, ll node, ll l, ll r){
        if(l > en || r < st) return 0;
        if(l <= st && r >= en) return tree[node];
        
        ll mid = (st + en) >> 1;
        return query(st, mid, node * 2, l, r) + query(mid + 1, en, node * 2 + 1, l, r);
    }
    
    ll update(ll st, ll en, ll node, ll idx, ll num){
        if(idx < st || idx > en) return tree[node];
        if(st == en) return tree[node] = num;
        
        ll mid = (st + en) >> 1;
        return tree[node] = update(st, mid, node * 2, idx, num) + update(mid + 1, en, node * 2 + 1, idx, num);
    }
    
    void plus(ll st, ll en, ll node, ll idx, ll num){
        if(idx < st || idx > en) return;
        tree[node] += num;
        if(st == en) return;
        
        ll mid = (st + en) >> 1;
        plus(st, mid, node * 2, idx, num);
        plus(mid + 1, en, node * 2 + 1, idx, num);
    }
};


int main() {
	fastio;
	
	cin >> n;
	seg sum(MAX), cnt(MAX);
	
	ll result = 1;
	for(int i = 1; i <= n;i++){
	    cin >> k;
	    k++;
	    ll lc, rc, ls, rs;
	    
	    if(i != 1){
    	    lc = cnt.query(1, MAX - 1, 1, 1, k - 1);
    	    rc = cnt.query(1, MAX - 1, 1, k + 1, MAX - 1);
    	    ls = sum.query(1, MAX - 1, 1, 1, k - 1);
    	    rs = sum.query(1, MAX - 1, 1, k + 1, MAX - 1);
    	    
    	    result *= (k * lc - ls + rs - k * rc) % MOD;
    	    result %= MOD;
	    }
	    
	    cnt.plus(1, MAX - 1, 1, k, 1);
	    sum.plus(1, MAX - 1, 1, k, k);
	}
	
	cout << result % MOD;
	
    
	return 0;
}