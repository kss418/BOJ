#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
map <int, bool> num;
ll cnt, arr[101], mx;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i]; pq.push(arr[i]);
        num[arr[i]] = 1;
        mx = max(mx, arr[i]);
    }

    while(cnt++ < m - 1){
        ll cur = pq.top(); pq.pop();
        for(int i = 1;i <= n;i++){
            ll nxt = cur * arr[i];
            if(pq.size() > m - cnt && nxt >= mx) continue;
            if(nxt >= (1ll << 31)) continue;
            if(num[nxt]) continue;
            mx = max(mx, nxt);
            num[nxt] = 1; pq.push(nxt);
        }
    }

    cout << pq.top();
    
  
    return 0;
}