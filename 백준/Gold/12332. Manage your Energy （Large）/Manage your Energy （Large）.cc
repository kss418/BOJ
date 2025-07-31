#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], tc, nxt[MAX];
stack <pll> st;

void run(){
    cin >> n >> m >> k; 
    memset(nxt, 0x3f, sizeof(nxt));
    while(!st.empty()) st.pop();

    for(int i = 1;i <= k;i++) cin >> a[i];  
    for(int i = k;i >= 1;i--){
        while(!st.empty() && st.top().x <= a[i]) st.pop();
        if(!st.empty()) nxt[i] = st.top().y;
        st.push({a[i], i});
    }

    ll result = 0, now = n;
    for(int i = 1;i <= k;i++){
        ll d = nxt[i] - i, mn = max(min(d * m - n + now, now), 0ll);
        if(nxt[i] == INF) result += now * a[i], now = 0;
        else result += mn * a[i], now -= mn;
        
        if(now + m > n){
            result += min(now + m - n, now);
            now = n - m;
        }

        now += m;
    }
    
    cout << "Case #" << ++tc << ": " << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

