#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
unordered_set<string> ct1 = {"EUR", "USD", "SGD", "BRL"};
unordered_set<string> ct2 = {"JPY", "ISK", "KRW"};


class occupySpots {
public:
    occupySpots() {


    }

    vector<int> occupySpotRequests(vector<vector<string>> commands, int totalSpots) {
        vector<bool> isAvailable(totalSpots, true);
        vector<int> ans;
        for (vector<string>& command : commands) {
            string type = command[0];
            int startIndex = stoi(command[1]), numberSlots = stoi(command[2]);
            int res = -1;
            if (type == "store") {
                res = store(startIndex, numberSlots, isAvailable);
            } else if (type == "free") {
                res = free(startIndex, numberSlots, isAvailable);
            }
            ans.push_back(res);
        }
        return ans;

    }

private:
    int store(int& startIndex, int& numberSlots, vector<bool>& isAvailable) {
        int n = isAvailable.size();
        vector<bool> visited(n, false);
        bool found = false;
        int tempStart = startIndex;
        int res = -1;

        while (true) {
            int end = tempStart + numberSlots - 1;
            bool found = true;
            for (int i = tempStart; i <= end; i++) {
                if (visited[i]) {
                    return -1;
                } else {
                    visited[i] = true;
                    if (!isAvailable[i]) {
                        tempStart = (i + 1) % n;
                        found = false;
                        break;
                    } 
                }
            }
            if (found) {
                res = tempStart;
                break;
            }

        }

        if (res != -1) {
            for (int i = res; i <= res + numberSlots - 1; i++) {
                isAvailable[i] = false;
            }
        }
        return res;

    }

    int free(int& startIndex, int& numberSlots, vector<bool>& isAvailable) {
        int res = 0;
        int n = isAvailable.size();
        int endIndex = (startIndex + numberSlots - 1) % n; 
        for (int i = startIndex; i <= endIndex; i++) {
            if (!isAvailable[i]) {
                isAvailable[i] = true;
                res++;
            }
        }
        return res;
    }







};


int main() {

}