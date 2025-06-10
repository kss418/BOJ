#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
priority_queue <ll> pq;

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i].x;
    for(int i = 1;i <= n;i++) cin >> a[i].y;

    a[n + 1].x = k;
    sort(a + 1, a + n + 1);

    ll result = 0;
    for(int i = 1;i <= n + 1;i++){
        while(!pq.empty() && m < a[i].x){
            m += pq.top(); pq.pop();
            result++;
        }

        if(m < a[i].x){
            result = -1; break;
        }

        pq.push(a[i].y);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}