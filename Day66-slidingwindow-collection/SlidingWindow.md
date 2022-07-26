# SlidingWindow总结
1. **适用类型**
* 特点1: 连续子串，连续子数组问题
* 特点2: 特定的窗口要求
* 特点3: goal：the longest, the shortest

2. **原理**
* 暴力解法：以每个字符为起点，长度为变量，构成的全部可行解 o(N2) -> o(N)
* ---》 对暴力解进行优化，跳过不必要比较的步骤，比如求最短长度，那么当以一个字符为起点找到可行解时，其后面的长度不需要再考虑；比如滑动左指针经过的字符为起点时，其窗口不满足要求也可以不考虑
* 左指针滑动的目标为其中之一：要么在找有效窗口（pass无效的，记录结果应该在左指针滑动循环之后）；要么就是在实现最短的目标（此时循环内
的窗口都是有效的，需要在每次循环内记录ans）

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
            freq_s[c]++;
            if (freq_t[c] != 0 && freq_t[c] == freq_s[c]) count++;

            while (count == need) {
                if (right - left + 1 < minLength) {
                    start = left;
                    minLength = right - left + 1;
                }

                char c1 = s[left];
                if (freq_t[c1] != 0 && freq_s[c1] == freq_t[c1]) count--;
                freq_s[c1]--;
                left++;
            }

            right++;
    }

        return minLength == INT_MAX? "" : s.substr(start, minLength);
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
   * **一定要清楚count的定义（需不需要count，是用来记录不同字符的个数，还是达标字符的个数）
   * 记录不需要的字符也可，判定清楚即可，不要纠结
   * [76](https://leetcode.com/problems/minimum-window-substring/) 
