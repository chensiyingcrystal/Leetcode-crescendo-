# 总结
1. **搜索适用类型**
* BFS: 最短路径问题，拓扑排序，染色，判断图中是不是有环，许多人同时从不同点出发谁先到终点, 棋盘交换（八数码）, 查找图中的根节点；
* DFS: 
* 

2. **原理**
* 

3. **模板**
* 模板1（记录答案在左指针滑动刮出无效字符后）
```
   int xxx(string s) {
      int n = s.length();
      int left = 0, right = 0; //often write right as the last character pointer
      unordered_map<char, int> map; //record each element's frequency(might need another counter: distinct...)
      int ans = INT_MIN/INT_MAX; // don't forget to check out special case(don't even go into the loop or never updated in the loop)
      
      while (right < n) {
         //do something to this current element pointed by right(e.g.record its freq.)
         

         //move left pointer until it becomes valid
         while (//condition: the indicator of invalid/valid window) { 
               //discard this element so we need to retrieve all the changes

               left++;
         }
         
         //record ans after a valid window checking
         //this checking part could also be in the while loop above
         //depending on the status in the while loop(is valid window or invalid)
         //one thing for sure: our ans is only for recording valid window
         ans = ...;
         
         right++;
      }
      
      return ans;  // check ans here!!
   }
```

* 模板2（有效窗口在左指针滑动排除多余字符内，此时左指针滑动是为了达到最小串的目标，所有在循环内的窗口都是有效）
```
   int xxx(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";

        //需要的资源：指针，记录本，（对照本）， counter， 对照计数器
        int left = 0, right = 0;
        vector<int> freq_t(128, 0);
        vector<int> freq_s(128, 0); //record each (valid) character's frequency
        int count = 0, need = 0; // record the number of valid character
        int minLength = INT_MAX, start = 0; //结果记录，看清楚需要什么类型的结果

        while (right < m) {
            //记录当前字符，对记录本和counter信息产生什么影响？
            char c = s[right];
            

            while (count == need) { //condition：满足窗口要求（一定是必要条件）！！
                //更新结果（不需要条件， 更短即可）
               
               //撤回即将pass的字符对信息的更新

                left++;
            }

            right++;
    }

        return minLength == INT_MAX? xxx : xxx; //看清楚答案要的是什么
   }
```


4. **Question Overview**题目分类

**第一类**：Substring 可变窗口

* 159基础：Given a string s, return the length of the longest substring that contains at most two distinct characters.
      * 经典滑动窗口，模板题：限定的不同字符个数
      * 用count记录 vs 用map size进行记录不同类型的字符，用erase擦除字符 vs 用count+vector固定size
   * [159](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
   *#* count增加的case：未存在过或者存在但是freq为0；
   *#* count减少的case：ele的freq变为0
   *#*  用vector记录：cover所有字符 初始频率为0

* 340基础--159的直接变形题： Given a string s, return the length of the longest substring that contains at most k distinct characters.
   * [340](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)

* 3最经典系列1：Given a string s, find the length of the longest substring without repeating characters.
   * 模板题：限定了每个字符的频率
   * [3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

* 76最经典系列2：Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
   * 模板题：限定了每个字符的频率, 是通过另一个字符确定的
   * 目标（最短，包含所有t中字符, 达到要求的频率， 尽量缩减字符频率）
   * 仅限定了频率，但是没有限定顺序(follow up 727)
   * **一定要清楚count的定义**（需不需要count，是用来记录不同字符的个数，还是达标字符的个数）
   * 记录不需要的字符也可，判定清楚即可，不要纠结
   * [76](https://leetcode.com/problems/minimum-window-substring/) 

* 438---76变形：Given two strings s and p, return an array of all the start indices of p's anagrams in s.
   * 目标（包含所有t中字符, 字符频率要完全一致）
   * 不能包含多余字符（没有在t中的字符，数量超过t数量的字符）
   * 难点在于如何处理多余字符
      * 类型不再是返回最长或者最短，而是返回全部起始点，是套哪个模板？
   * 解法一：套用模板一，但是要分开处理两类多余字符，不需要的直接跳过（**注意过程改动的变量一次性清零**用map清零而不是vector）
   * 解法二：套用模板二（反常规），将大窗口视作都有效，在收缩过程中排除多余字符并仅记录有效结果（类似76）
   * [438](https://leetcode.com/problems/find-all-anagrams-in-a-string/) 

* 567---438直接变形：Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
   * 目标（包含所有t中字符, 字符频率要完全一致）
   * 不能包含多余字符（没有在t中的字符，数量超过t数量的字符）
   * 解法二：套用模板二（反常规但代码好写），将大窗口视作都有效，在收缩过程中排除多余字符并仅记录有效结果（类似76）
   * [567](https://leetcode.com/problems/permutation-in-string/) 

5. **总结**：
       *第一次尽量用map做不会错，知道会用vector优化即可*
       *一套思路想不通换另一套*
       *直接跳过字符的情况下，注意将过程记录本和counter清零*