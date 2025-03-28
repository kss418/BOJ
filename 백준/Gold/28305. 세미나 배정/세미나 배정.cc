#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
typedef pair<int, int> pi; typedef pair<ll, ll> pll; 
typedef unsigned long long ull; ll n, m, k, t; string s;
    
const ll INF = 0x3f3f3f3f3f3f3f3f; 
const ll MAX = 201010; 
ll arr[MAX], num[MAX];


ll dt(ll cnt){
    ll ch = 0;
    
    for(int i = 1;i <= n;i++){
        if(i <= cnt) ch = max(arr[i] - m + 1, 1ll);
        else ch = max({arr[i] - m + 1, num[i - cnt] + m, 1ll});
        num[i] = ch;
    }
    
    ll ret = 1;
    for(int i = 1;i <= n;i++){
        ll diff = arr[i] - num[i];
        if(diff >= m || diff < 0) ret = 0;
    }
    
    return ret;
}
    
    
int main() { 
    fastio;
    
    cin >> n >> m;
    for(int i = 1; i <= n;i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    
    ll st = 1, en = n;
    while(st < en){
        ll mid = (st + en) >> 1;
        if(dt(mid)) en = mid;
        else st = mid + 1;
    }

    cout << en;
    
        
    return 0;
}