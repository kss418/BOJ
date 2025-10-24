#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt, sum;
deque <pll> q;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cnt = a[1];
    for(int i = 2;i <= n;i++) cnt += max(a[i] - a[i - 1], 0ll);
    reverse(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        if(a[i] > a[i - 1]) q.push_back({i, a[i] - a[i - 1]});
        if(a[i] > a[i + 1]){
            ll now = a[i] - a[i + 1];
            while(!q.empty() && now){
                auto[idx, c] = q.front(); q.pop_front();
                ll mn = min(now, c);
                now -= mn; c -= mn;
                sum += mn * (i - idx + 1) * (i - idx + 1);
                if(c) q.push_front({idx, c});
            }
        }
    }

    cout << cnt << " " << sum;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}