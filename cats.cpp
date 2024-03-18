#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned int ui;

bool check(vector<ui> scale ,ui target) {
    for (int j = 0 ; j < (int)scale.size() ;j++) {
        if (target == scale[j]) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    int n;
    cin >> n;
    vector<ui> sq;
    vector<ui> scale;
    for (int i = 0 ; i < n ;i++) {
        ui temp;
        cin >> temp;
        if (!check(scale, temp)) {
            scale.push_back(temp);
        }
        sq.push_back(temp);
    }


    sort(scale.begin() , scale.end());

    int now = 0;
    while (1) {
        auto it = find(sq.begin() , sq.end() ,scale[0]);
        int index = it-sq.begin();
        if (sq[index] != sq[index-1] && sq[index] != sq[index+1]) {
            sq.erase(remove(sq.begin()+index, sq.end(),sq[index]), sq.end());

        }
        for (int i = 0 ; i < (int)sq.size() ;i++) {
            cout << sq[i] << ' ';
        }
        break;
    }

}
