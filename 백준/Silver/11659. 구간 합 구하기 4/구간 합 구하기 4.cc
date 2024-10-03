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

class _mos{
public:
    ll sq; vector <ll> result, arr;
    class query{
    public:
        ll l, r, n, sq;
        bool operator <(query& ot){
            if((l / sq) == (ot.l / sq)) return r < ot.r;
            return (l / sq < ot.l / sq);
        }
    };
    vector <query> q;

    _mos(ll n, ll m){ // 배열 크기, 쿼리 크기
        sq = sqrt(n); arr.resize(n + 1);
        result.resize(m + 1);
    }

    void add(ll l, ll r, ll n){ // 쿼리 추가
        q.push_back({l, r, n, sq});
    }

    void con(ll idx, ll val){ // 배열 삽입
        arr[idx] = val;
    }

    void init(){
        sort(q.begin(), q.end());

        ll s = q[0].l, e = q[0].r, cur = 0;
        for(int i = s;i <= e;i++){
            cur += arr[i];
        }
        result[q[0].n] = cur;

        for(int i = 1;i < m;i++){
            while(q[i].l > s) cur -= arr[s++];
            while(q[i].r < e) cur -= arr[e--];
            while(q[i].l < s) cur += arr[--s];
            while(q[i].r > e) cur += arr[++e];
            result[q[i].n] = cur;
        }
    }

    void print(){
        for(int i = 1;i <= m;i++) cout << result[i] << "\n";
    }
};

int main() {
    fastio;

    cin >> n >> m;
    _mos mos(n, m);
    for(int i = 1;i <= n;i++){
        cin >> k;
        mos.con(i, k);
    }

    for(int i = 1;i <= m;i++){
        ll l, r;
        cin >> l >> r;
        mos.add(l, r, i);
    }
    mos.init();
    mos.print();

    return 0;
}
