#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    Solution() {

    }

    vector<int> findMusicDuration(int rideDuration, vector<int> songDurations) {
        //initialize a hash map: key - number, value - index
        unordered_map<int, int> map;
        vector<int> ans;
        //determine target based on the rule of arriving before 30 seconds
        int target = rideDuration - 30;
        if (target < 0 || target > 2002) return {-1, -1};
        //go through the songDurations
        for (int i = 0; i < songDurations.size(); i++) {
            int complement = target - songDurations[i];
            //first determine if the number's complement is in the map
            if (map.count(complement)) {
                if (ans.size() == 0) {
                    ans = {map[complement], i};
                }
                else {
                    //choose the pair with the longest song among multiple possible answers
                    int larger = max(complement, songDurations[i]);
                    int ansLarger = max(songDurations[ans[0]], songDurations[ans[1]]);
                    if (larger > ansLarger) {
                        ans = {map[complement], i};
                    }
                }
            }
                //only throw this number into map if it's not already in the map
            if (!map.count(songDurations[i])) map[songDurations[i]] = i;
        }
        //not found, return {-1, -1}
        vector<int> notFound = {-1, -1};
        return ans.size() == 0 ? notFound : ans;
    }
    
};

int main() {
    Solution* ss = new Solution();
    vector<int> power = {1, 1, 25, 25, 10, 30, 30, 30, 1, 30, 35, 59, 59, 59};
    vector<int> middleMax = ss->findMusicDuration(90, power);
    cout << middleMax[0] << endl;
    cout << middleMax[1] << endl;
    
    return 0;
}