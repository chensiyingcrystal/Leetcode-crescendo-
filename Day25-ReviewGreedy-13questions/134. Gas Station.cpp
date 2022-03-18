#include <vector>

using namespace std;

class Solution {
public:
/* solution：start at 0, and if curr_tank < 0, then from the last starting station
 * to i, they would fail too if starting from them; set the new starting station to i+ 1
 */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int curr_tank = 0;
        //bug: start default is 0
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }
        return total_tank < 0? -1 : start;
    }
        
};