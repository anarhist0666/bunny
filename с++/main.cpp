#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    multiset<long long> clans;
    
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        clans.insert(x);
    }
    
    while (clans.size() > 1) {
        auto it = clans.begin();
        long long a = *it;
        clans.erase(it);
        
        it = clans.begin();
        long long b = *it;
        clans.erase(it);
        
        cout << a << " " << b << endl;
        
        clans.insert(a + b);
    }
    
    return 0;
}