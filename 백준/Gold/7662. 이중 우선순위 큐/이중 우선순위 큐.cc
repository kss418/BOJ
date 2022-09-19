#include <iostream>
#include <algorithm>
#include <set>


using namespace std;


int main() {
    int n,m,num;
    char com;
    multiset <int> pq;
    cin >> n;
    while(n--){
        pq.clear();
        cin >> m;
        while(m--){
            cin >> com >> num;
            if(com == 'I'){
                pq.insert(num);
            }
            else{
                if (!pq.empty()){
                    if(num == -1){
                        pq.erase(pq.find(*pq.begin()));
                    }
                    else{
                        auto s = pq.end();
                        s--;
                        pq.erase(pq.find(*s));
                    }
                }
            }
        }
    if(pq.empty()){
        cout << "EMPTY" << "\n";
    }
    else{
        auto s = pq.end();
        s--;
        cout << *s << " " << *pq.begin() << "\n";
    }
    }
}