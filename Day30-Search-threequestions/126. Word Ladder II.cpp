#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
//官方题解
//Time complexity: O(NK^2 + α)
//Space complexity: O(NK)
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;
    
    vector<string> findNeighbors(string &word, unordered_set<string>& wordList) {
        vector<string> neighbors;
        
        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];   
            
            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                // skip if the character is same as original or if the word is not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }
    
    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }
    
    void bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        queue<string> q;
        q.push(beginWord);
        
        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }
        
        unordered_map<string, int> isEnqueued;
        isEnqueued[beginWord] = 1;
        
        while (!q.empty())  {
            // visited will store the words of current layer
            vector<string> visited;
            
            for (int i = q.size() - 1; i >= 0; i--) {
                string currWord = q.front(); 
                q.pop();

                // findNeighbors will have the adjacent words of the currWord
                vector<string> neighbors = findNeighbors(currWord, wordList);
                for (auto word : neighbors) {
                    visited.push_back(word);
                    // add the edge from currWord to word in the list
                    adjList[currWord].push_back(word);
                    
                    if (isEnqueued.find(word) == isEnqueued.end()) {
                        q.push(word);
                        isEnqueued[word] = 1;
                    }
                }
            }
            // removing the words of the previous layer
            for (int i = 0; i < visited.size(); i++) {
                if (wordList.find(visited[i]) != wordList.end()) {
                    wordList.erase(wordList.find(visited[i]));
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bfs(beginWord, endWord, copiedWordList);
        
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);
        
        return shortestPaths;
    }

//另一个题解的写法（不推荐，但是有些点值得学习）
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        //if endWord is not in dict, then return empty list
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
    
        //BFS: construct graph
        //Need 1 map for recording key：word，value：level
        unordered_map<string, int> steps = {{beginWord, 0}};
        //Need 2nd map for recording the word and its parent word
        unordered_map<string, unordered_set<string> > from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        //initialize queue
        queue<string> q = queue<string>{{beginWord}};
        dict.erase(beginWord);
        int wordLen = beginWord.length();
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                // find childs/neighbors
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        //if added before
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        dict.erase(nextWord);
                        q.push(nextWord);
                        from[nextWord].insert(currWord);
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        //dfs: from end to start
        if (found) {
            vector<string> path = {endWord};
            dfs(res, endWord, from, path);
        }
        return res;
    }

    void dfs(vector<vector<string> > &res, const string &node, unordered_map<string, unordered_set<string> > &from,
             vector<string> &path) {
        if (from[node].empty()) {
            res.push_back({path.begin(), path.end()});
            return;
        }
        for (const string &parent: from[node]) {
            path.push_back(parent);
            dfs(res, parent, from, path);
            path.pop_back();
        }
    }
};

