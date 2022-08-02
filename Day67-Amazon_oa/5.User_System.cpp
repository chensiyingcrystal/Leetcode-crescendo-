#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    Solution() {

    }

    unordered_map<string, pair<string, bool> > map;

    vector<string> implementAPT(vector<string>& logs) {
        vector<string> ans;
        for (string& log : logs) {
            vector<string> request = parseLog(log);
            if (request[0] == "register") {
                ans.push_back(userRegister(request[1], request[2]));
            }
            else if (request[1] == "login") {
                ans.push_back(userLogin(request[1], request[2]));
            }
            else if (request[2] == "logout") {
                ans.push_back(userLogout(request[1]));
            }
        }
        return ans;
    }

    vector<string> parseLog(string& req) {
        vector<string> ans;
        string type = "";
        int i = 0;
        while (req[i] != ' ') {
            type += req[i];
            i++;
        }
        ans.push_back(type);

        i += 2;
        string username = "";
        while (req[i] != '>') {
            username += req[i];
            i++;
        }
        ans.push_back(username);
        if (type == "logout") return ans;

        i += 3;
        string password = "";
        while (req[i] != '>') {
            password += req[i];
            i++;
        }
        ans.push_back(password);
        return ans;
    }

    vector<string> parseLogBySpace(string& request) {
        vector<string> ans;
        int n = request.length();
        for (int i = 0; i < n; i++) {
            string temp = "";
            while (i < n && request[i] != ' ') {
                temp += request[i];
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }

    string userRegister(string& username, string& password) {
        if (map.count(username)) {
            return "Username already exists";
        }

        map[username] = {password, false};
        return "Registered Successfully";
    }

    string userLogin(string& username, string & password) {
        if (!map.count(username) || map[username].first != password || map[username].second == true) {
            return "Login Unsuccessful";
        }

        map[username].second = true;
        return "LoggedIn Successfully";

    }

    string userLogout(string& username) {
        if (!map.count(username) || map[username].second == false) {
            return "Logout Unsuccessful";
        }

        map[username].second = false;
        return "LoggedOut Successfully";
    }










    }
};