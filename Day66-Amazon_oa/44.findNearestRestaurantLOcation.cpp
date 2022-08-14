#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    Solution() {

    }

    vector<vector<int> > findNearestRestaurantLocation(vector<vector<int> > locations, int numRest) {
        if (locations.size() == 0 || numRest <= 0) return {{}};
        //use max heap to store numRest locations
        auto comp = [](vector<int>& a, vector<int>& b) {
            double distanceA = sqrt(pow(a[0], 2) + pow(a[1], 2));
            double distanceB = sqrt(pow(b[0], 2) + pow(b[1], 2));
            if (distanceA != distanceB) return distanceA < distanceB;
            else return abs(a[0]) < abs(b[0]);
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(comp)> pq(comp);
        for (int i = 0; i < locations.size(); i++) {
            pq.push(locations[i]);
            //maintain a max heap of size numRest
            if (pq.size() > numRest) {
                pq.pop();
            }
        }
        //pop out all elements in pq and store it in ans
        vector<vector<int> > ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;



    }


    
};

int main() {
    Solution* ss = new Solution();
    vector<vector<int> > power = {{1, 3}, {0, 2}, {0, -2}};
    vector<vector<int> > ans = ss->findNearestRestaurantLocation(power, 1);
    for (vector<int>& pair : ans) {
        cout << pair[0] << "," << pair[1] << endl;
    }
    
    return 0;
}