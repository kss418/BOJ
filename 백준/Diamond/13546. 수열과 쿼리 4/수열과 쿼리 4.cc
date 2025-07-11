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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
deque <ll> dq[MAX];
ll sum[505], r[505];
ll sq[MAX], leaf[MAX];

void pl(ll idx, ll v){
    leaf[idx] += v;
    sum[sq[idx]] += v;
}

ll get(){
    ll now = sq[n];
    while(!sum[now] && now > 0) now--;
    if(!sum[now]) return 0;

    now = r[now];
    while(1){
        if(leaf[now]) return now;
        now--;
    }
}

class _mos{
public:
    ll sq, m; vector <ll> result, arr;
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
        result.resize(m + 1); this->m = m;
    }

    void add(ll l, ll r, ll n){ // 쿼리 추가
        q.push_back({l, r, n, sq});
    }

    void con(ll idx, ll val){ // 배열 삽입
        arr[idx] = val;
    }

    void push(ll idx, bool flag){
        ll now = arr[idx];
        if(dq[now].size() >= 2){
            ll diff = dq[now].back() - dq[now].front();
            pl(diff, -1);
        }

        if(!flag) dq[now].push_front(idx); 
        else dq[now].push_back(idx);
        
        if(dq[now].size() >= 2){
            ll diff = dq[now].back() - dq[now].front();
            pl(diff, 1);   
        }
    }

    void pop(ll idx, bool flag){
        ll now = arr[idx];
        if(dq[now].size() >= 2){
            ll diff = dq[now].back() - dq[now].front();
            pl(diff, -1);
        }
        
        if(!flag) dq[now].pop_front(); 
        else dq[now].pop_back();  
        
        if(dq[now].size() >= 2){
            ll diff = dq[now].back() - dq[now].front();
            pl(diff, 1);
        }   
    }

    void init(){
        sort(q.begin(), q.end());

        ll s = q[0].l, e = q[0].r, cur = 0;
        for(int i = s;i <= e;i++) push(i, 1);
        result[q[0].n] = get();

        for(int i = 1;i < m;i++){
            while(q[i].l < s) push(--s, 0);
            while(q[i].r > e) push(++e, 1);
            while(q[i].l > s) pop(s++, 0);
            while(q[i].r < e) pop(e--, 1);
            result[q[i].n] = get();
        }
    }

    void print(){
        for(int i = 1;i <= m;i++) cout << result[i] << "\n";
    }
};

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        sq[i] = i / sqrtl(n);
        r[sq[i]] = max<ll>(r[sq[i]], i);
    }

    cin >> k; _mos mos(n, k);
    for(int i = 1;i <= n;i++) mos.con(i, a[i]);
    for(int i = 1;i <= k;i++){
        ll s, e; cin >> s >> e;
        mos.add(s, e, i);
    }

    mos.init();
    mos.print();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

