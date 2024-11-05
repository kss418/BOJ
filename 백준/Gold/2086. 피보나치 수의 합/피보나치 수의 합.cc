#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5;
constexpr ll MOD = 1e9;

class _ms{ //0-based index
public:
    ll n, m;
    vector <vector<ll>> arr, result, tmp;
    vector <ll> num;

    _ms(){}
    _ms(ll n, ll m = 998244353){ 
        this->n = n; this->m = m; 
        arr.resize(n, vector<ll>(n));
        result.resize(n, vector<ll>(n));
        tmp.resize(n, vector<ll>(n));
        num.resize(n);
        for(int i = 0;i < n;i++) result[i][i] = 1;
    }

    void add(ll cy, ll cx, ll val){ arr[cy][cx] = val % m; }
    void fi(ll cx, ll val){ num[cx] = val % m; }

    void cal(bool flag){
        for(int i = 0;i < n;i++) memset(&tmp[i][0], 0, sizeof(tmp[i][0]) * tmp[i].size());
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++) {
                    if(flag) tmp[i][j] += result[i][k] * arr[k][j];
                    else tmp[i][j] += result[i][k] * result[k][j];
                    tmp[i][j] %= m;
                }
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++) result[i][j] = tmp[i][j] % m;
        }
    }
    
    void init(ll k){
        stack <ll> com; 
        while(k > 0){
            com.push(k & 1);
            if(k & 1) k--; else k >>= 1;
        }
        while(!com.empty()){
            bool cur = com.top();
            cal(cur); com.pop();
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                result[i][j] = result[i][j] * num[j];
                result[i][j] %= MOD;
            }
        }
    }

    ll ret(ll cy, ll cx){ return result[cy][cx]; }
};

int main() {
    fastio;

    cin >> n >> m; _ms ms[2];
    for(int i = 0;i <= 1;i++) {
        ms[i] = { 2, MOD }; ms[i].add(0, 0, 1);
        ms[i].add(0, 1, 1); ms[i].add(1, 0, 1);
        ms[i].fi(0, 1);
    }
    ms[0].init(n + 1); ms[1].init(m + 2);

    ll ret = ms[1].ret(1, 0) - ms[0].ret(1, 0);
    if(ret < 0) ret += MOD;

    cout << ret;


    return 0;
    }