#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    vector<string> parseLog(vector<string>& logData, int threshold) {
        unordered_map<string, int> users;
        vector<string> ans;
        //go through each vector in log and parse it
        for (int i = 0; i < logData.size(); i++) {
            vector<string> parsedData;
            parsedData = parseData(logData[i]);
            if (parsedData[0] != parsedData[1]) {
                users[parsedData[0]]++;
                users[parsedData[1]]++;
            }
            else {
                users[parsedData[0]]++;
            }
        }

        for (auto& pair : users) {
            if (pair.second >= threshold) {
                ans.push_back(pair.first);
            }
        }
        
        //do not quite sure its sorting criteria
        sort(ans.begin(), ans.end(), [](string& a, string& b) {
            return stoi(a) < stoi(b);
        });

        return ans;
    }

    vector<string> parseData(string& data) {
        vector<string> ans;
        for (int i = 0; i < data.size(); i++) {
            string temp = "";
            int j = i;
            while (j < data.size() && data[j] != ' ') {
                temp += data[j];
                j++;
            }
            i = j;
            ans.push_back(temp);
            if (ans.size() == 2) return ans;
        }
        return ans;

    }

    

};

int main() {
    Solution* ss = new Solution();
    vector<string> s;
    s.push_back("345366 89921 45");
    s.push_back("029323 38239 23");
    s.push_back("38239 345366 15");
    s.push_back("029323 38239 77");
    s.push_back("345366 38239 23");
    s.push_back("029323 345366 13");
    s.push_back("38239 38239 23");
    
    vector<string> ans = ss->parseLog(s, 3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n' << endl;
    }


}