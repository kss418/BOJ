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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

class _kmp { // 0-based index
public:
    string s; ll n;
    vector <ll> f;

    _kmp(string& s) {
       this->s = s; this->n = s.size();
    }

    void init(string& m){
        ll nxt = 0; f.resize(m.size(), 0);
        for(int cur = 1;cur < m.size();cur++){
            while(nxt && m[cur] != m[nxt]) nxt = f[nxt - 1];
            if(m[cur] == m[nxt]) f[cur] = ++nxt;
        }
    }

    vector <ll> ret(string& m){ // index 반환
        init(m); vector <ll> r;
        ll nxt = 0;
        for(int cur = 0;cur < n;cur++){
            while(nxt && s[cur] != m[nxt]) nxt = f[nxt - 1];
            if(s[cur] == m[nxt]) nxt++;
            if(nxt == m.size()){
                r.push_back(cur - nxt + 1);
                nxt = f[nxt - 1];
            }
        }

        return r;
    }
};

int main() {
    fastio;

    string a,b;
    getline(cin, a);
    getline(cin, b);
    _kmp kmp(a);
    
    vector <ll> ret = kmp.ret(b);
    cout << ret.size() << "\n";
    for(auto& i : ret) cout << i + 1 << " ";


    return 0;
}