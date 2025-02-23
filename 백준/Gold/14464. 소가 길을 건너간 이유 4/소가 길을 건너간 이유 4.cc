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
constexpr ll MAX = 20101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
pll arr[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= m;i++){
        cin >> arr[i].x >> arr[i].y;    
    }
    sort(arr + 1, arr + m + 1);

    ll idx = 1, result = 0;
    for(int i = 1;i <= n;i++){
        while(idx <= m && arr[idx].x <= a[i]){
            pq.push(arr[idx].y); idx++;
        }

        while(!pq.empty() && pq.top() < a[i]) pq.pop();
        if(!pq.empty()) pq.pop(), result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

