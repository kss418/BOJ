#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;

const ll MAX = 1010;
ll n, t[MAX], s[MAX];
pair <ld, ll> a[MAX];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> s[i];
        a[i].first = (ld)t[i] / (ld)s[i];
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++) cout << a[i].second << " ";
    return 0;
}