#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //pre-processing worldlist
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        //begin bfs
        int level = 0;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            //representing current level
            level++;
            int size = q.size();
            //process current nodes
            while (size--) {
                string tmp = q.front();
                q.pop();

                //process its neighbors
                for (int i = 0; i < tmp.length(); i++) {
                    char c = tmp[i];
                    //bug: j <= 'z' instead of j < 'z'
                    for (char j = 'a'; j <= 'z'; j++) {
                        tmp[i] = j;
                        if (wordset.count(tmp)) {
                            if (tmp == endWord) return level + 1;
                            q.push(tmp);
                            wordset.erase(tmp);
                        }
                    }
                    tmp[i] = c;
                }
            }
        }

        return 0;
    }
};
