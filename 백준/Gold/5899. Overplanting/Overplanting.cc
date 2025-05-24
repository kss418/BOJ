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
constexpr ll MAX = 20101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result;
map <ll, ll> use;
class query{
public:
    ll x, y1, y2, op;
    bool operator < (const query& ot) const{
        if(x == ot.x){
            return op < ot.op;
        }
        return x < ot.x;
    }
}; vector <query> q;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y2 >> x2 >> y1;
        q.push_back({x1, y1, y2, 1});
        q.push_back({x2, y1, y2, -1});
    }
    sort(all(q));

    for(int idx = 0;idx < q.size();idx++){
        auto& [x, y1, y2, op] = q[idx];
        ll cnt = 0, sum = 0;
        if(op != 2){
            use[y1] += op;
            use[y2] -= op;
        }

        ll la = MINF;
        for(auto& [idx, v] : use){
            if(sum > 0) cnt += (idx - la);
            sum += v; la = idx;
        }

        if(idx != q.size() - 1 && x != q[idx + 1].x){
            result += cnt * (q[idx + 1].x - x);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}