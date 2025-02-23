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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], d[401010];

ll num(const vector<ll>& v){
    ll ret = 0;
    for(auto& i : v) ret *= 5, ret += i;
    return ret;
}

class node{
public:
    vector <ll> arr; ll cnt;
};
deque <node> q;
vector <vector <ll>> arr;

void run(){
    cin >> n >> m; node cur; cur.cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> k; cur.arr.push_back(k);
    }

    while(m--){
        cin >> k; vector <ll> now;
        for(int i = 1;i <= k;i++){
            ll num; cin >> num;
            now.push_back(num - 1);
        }
        arr.push_back(now);
    }

    q.push_back(cur); memset(d, 0x3f, sizeof(d));
    while(!q.empty()){
        auto[ca, cc] = q.front(); q.pop_front();
        if(d[num(ca)] <= cc) continue;
        d[num(ca)] = cc;

        for(int i = 0;i < arr.size();i++){
            vector <ll> na = ca;
            for(auto& j : arr[i]) na[j] += (i + 1), na[j] %= 5;
            q.push_back({na, cc + 1});
        }
    }

    ll result = INF;
    for(int i = 0;i < 5;i++){
        vector <ll> now;
        for(int j = 1;j <= n;j++) now.push_back(i);
        result = min(result, d[num(now)]);
    }

    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

