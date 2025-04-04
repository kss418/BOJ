#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
ll n, a[MAX];
priority_queue <ll> pq1;
priority_queue <ll, vector<ll>, greater<ll>> pq2;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x; cin >> x;
        if(i % 2) pq1.push(x);
        else pq2.push(x);

        if(!pq2.empty() && pq1.top() > pq2.top()){
            ll t1 = pq1.top();
            ll t2 = pq2.top();
            pq1.pop(); pq2.pop();
            pq1.push(t2); pq2.push(t1);
        }

        cout << pq1.top() << "\n";
    }
}

