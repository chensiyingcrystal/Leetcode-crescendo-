#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {

public:
    Solution() {

    }

    vector<int> findDataLocations(vector<int>& locations, vector<int>& movedFrom, vector<int>& movedTo) {
        //insert all data locations into a set
        unordered_set<int> locationSet;
        for (int& loc : locations) {
            locationSet.insert(loc);
        }
        //remove previous locations and insert new locations in the set
        for (int i = 0; i < movedFrom.size(); i++) {
            locationSet.erase(movedFrom[i]);
            locationSet.insert(movedTo[i]);
        }
        //add set into a new vector and sort in ascending order
        vector<int> ans;
        for (auto& new_loc : locationSet) {
            ans.push_back(new_loc);
        }
        sort(ans.begin(), ans.end());
        return ans;

    }






    }
};