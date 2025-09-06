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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
bool v[MAX][MAX][MAX];
deque <tll> q;
vector <ll> result;

void push(ll ca, ll cb, ll cc){
    if(v[ca][cb][cc]) return;
    v[ca][cb][cc] = 1;
    q.push_back({ca, cb, cc});
    if(!ca) result.push_back(cc);
}

void run(){
    cin >> n >> m >> k;
    push(0, 0, k);

    while(!q.empty()){
        auto [ca, cb, cc] = q.front(); q.pop_front();
        
        ll mv = min(m - cb, ca);
        push(ca - mv, cb + mv, cc);

        mv = min(k - cc, ca);
        push(ca - mv, cb, cc + mv);

        mv = min(n - ca, cb);
        push(ca + mv, cb - mv, cc);

        mv = min(k - cc, cb);
        push(ca, cb - mv, cc + mv);

        mv = min(n - ca, cc);
        push(ca + mv, cb, cc - mv);

        mv = min(m - cb, cc);
        push(ca, cb + mv, cc - mv);  
    }   

    sort(all(result));
    result.erase(unique(all(result)), result.end());

    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}