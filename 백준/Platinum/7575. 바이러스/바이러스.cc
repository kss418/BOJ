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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _kmp { // 0-based index
public:
    vector <ll> f, v; ll n;

    _kmp(){}
    _kmp(string& s) : _kmp(move(tf(s))){};
    _kmp(const vector <ll>& v){ this->v = v; this->n = v.size(); }

    void init(const vector <ll>& m){ // fail 함수 계산
        ll nxt = 0; f.clear(); f.resize(m.size(), 0);
        for(int cur = 1;cur < m.size();cur++){
            while(nxt && m[cur] != m[nxt]) nxt = f[nxt - 1];
            if(m[cur] == m[nxt]) f[cur] = ++nxt;
        }
    }
    
    vector <ll> ret(string& s){ return ret(move(tf(s)));}
    vector <ll> ret(const vector <ll>& m){ // index 반환
        init(m); vector <ll> r;
        ll nxt = 0;
        for(int cur = 0;cur < n;cur++){
            while(nxt && v[cur] != m[nxt]) nxt = f[nxt - 1];
            if(v[cur] == m[nxt]) nxt++;
            if(nxt == m.size()){
                r.push_back(cur - nxt + 1);
                nxt = f[nxt - 1];
            }
        }

        return r;
    }

    vector <ll> tf(string& s){
        vector <ll> ret;
        for(auto& i : s) ret.push_back(i);
        return ret;
    }
};

vector <ll> a[MAX];
_kmp kmp[MAX][2];

bool chk(vector <ll>& a){
    bool ret = 0;
    for(int i = 0;i < a.size();i++){
        if(i + m > a.size()) break;
        vector <ll> now;
        for(int j = i;j < i + m;j++){
            now.push_back(a[j]);
        }

        bool flag = 1;
        for(int j = 1;j < n;j++){
            if(kmp[j][0].ret(now).empty() && kmp[j][1].ret(now).empty()) flag = 0;
            if(!flag) break;
        }

        ret |= flag;
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> t; a[i].push_back(t);
        }

        if(!i) continue; 
        kmp[i][0] = {a[i]}; reverse(all(a[i]));
        kmp[i][1] = {a[i]};
    }

    bool result = chk(a[0]);
    reverse(all(a[0]));
    result |= chk(a[0]);

    if(result) cout << "YES";
    else cout << "NO";
    

    return 0;
}