#include <vector>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        //sort "people" queue in non-increasing order
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            else return a[1] < b[1];
        });

        //insert using list
        list<vector<int> > q;
        for (int i = 0; i < people.size(); i++) {
            list<vector<int> >::iterator r = q.begin();
            advance(r, people[i][1]);
            q.insert(r, people[i]);
        }
        
        return vector<vector<int> >(q.begin(), q.end());
    }

};