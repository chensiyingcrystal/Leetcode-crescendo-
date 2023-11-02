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

struct ChargeBack {
    string id;
    string name;
    string amount;
    string currency;
    string evidenceDue;
    string reason;

    ChargeBack(string id, string name, string amount, string currency, string evidenceDue, string reason) {
        this->id = id;
        this->name = name;
        this->amount = amount;
        this->currency = currency;
        this->evidenceDue = evidenceDue;
        this->reason = reason;
    }

    string toString() {
        //快速回忆output
        //minor to major
//放里面还是外面慢了            

        string majorAmount = "";
        if (ct1.count(this->currency)) {
            majorAmount = converseToMajor(this->amount);
        } 

        return this->id + "," + this->name + "," + majorAmount + "," + this->currency + "," + this->evidenceDue;
    }

    string converseToMajor(string& c) {
        if (c == "") return "";
        int n = c.length();
        if (n == 1) return "0.0" + c;
        if (n == 2) return "0." + c;
        return c.substr(0, n - 2) + "." + c.substr(n - 2);
    }
};

class StripeChargeBackDispute {

    StripeChargeBackDispute() {

    }



public:
    string parseNetworkChargeBackInfo(vector<string> rows) {
        map<string, ChargeBack*> charges; //map的对应关系记忆
        //parse the rows 
        //filter each block: first row(file name), second row(format), rest rows(data in format storing)
        //回忆input什么样子
        for (int i = 0; i < rows.size(); i++) {
            string fileNameRow = rows[i];
            string fileName = parseFileName(fileNameRow);
            string formatRow = rows[i + 1];
            vector<string> format = parseFormat(formatRow);
            
            int j = i + 2; 
            while (j < rows.size() && parseFileName(rows[j]) == "") {
                pair<string, ChargeBack*> record = processCharge(rows[j], format, fileName);
                if (isValid(record.second)) {
                    //稍微慢了
                    if (record.second->reason == "withdrawn") {
                        if (charges.count(record.second->id)) charges.erase(record.second->id);
                    } 
                    else charges[record.first] = record.second;
                }

                j++;
            }
            i = j - 1;
        }

        //output into string with order
        string ans = "";
        //回忆output什么样子
        for (auto& p : charges) {
            ans += p.second->toString() + "\n";
        }
        ans.pop_back();
        return ans;
    }

private: 
    bool isValid(ChargeBack* c) {
        //慢回忆中
        //currency
        string currency = c->currency;
        if (!ct1.count(currency) || !ct2.count(currency)) return false;

        //amount positive integer
        //eveidence positive integer
        string amount = c->amount;
        string evidenceDue = c->evidenceDue;
        if (!isValidNumber(amount) || !isValidNumber(evidenceDue)) return false;
        return true;
    }
    
    bool isValidNumber(string& a) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] < '0' || a[i] > '9') return false;
        }
        
        if (a.length() == 0 || a[0] == '0') return false;
        return true;
    }

    string parseFileName(string& row) {
        if (row.size() < 4 || row.substr(row.length() - 4) != ".csv") return "";
        string res = "";
        for (int i = 0; i < row.length(); i++) {
            if (row[i] == '_') break;
            res += row[i];
        }
        return res;
    }

    vector<string> parseFormat(string& row) {
        vector<string> res;
        parseByComma(row, res);
        return res;
    }
//模板化
    void parseByComma(string& row, vector<string>& res) {
        for (int i = 0; i < row.length(); i++) {
            int j = i;
            string r = "";
            while (j < row.length() && row[j] != ',') {
                r += row[j];
                j++;
            }
            i = j;
            //没有focus进入，逗号分隔慢，纠结写法
            res.push_back(r);
        }
    }

    pair<string, ChargeBack*> processCharge(string& charge, vector<string>& format, string& fileName) {
        string id = "", name = "", amount = "", currency = "", evidenceDue = "", reason = "";
        vector<string> ps;
        parseByComma(charge, ps);

        for (int i = 0; i < ps.size(); i++) {
            //快速看sample
            if (format[i] == "transaction") {
                id = fileName + ps[i];
            }
            else if (format[i] == "merchant") {
                name = ps[i];
            }
            else if (format[i] == "amount") {
                amount = ps[i];
            }
            else if (format[i] == "currency") {
                currency = ps[i];
            }
            else if (format[i] == "evidence_due_by") {
                evidenceDue = ps[i];
            }
            else if (format[i] == "reason") {
                reason = ps[i];
            }

        }
        //结束了还想了一下存了什么
        ChargeBack* chargeBack = new ChargeBack(id, name, amount, currency, evidenceDue, reason);
        return {id, chargeBack};

    }



};


int main() {

}