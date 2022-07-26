# SlidingWindow总结
1. **适用类型**
* 特点1: 连续子串，连续子数组问题
* 特点2: 特定的窗口要求
* 特点3: goal：the longest, the shortest

2. **原理**
* 暴力解法：以每个字符为起点，长度为变量，构成的全部可行解 o(N2) -> o(N)
* ---》 对暴力解进行优化，跳过不必要比较的步骤，比如求最短长度，那么当以一个字符为起点找到可行解时，其后面的长度不需要再考虑；比如滑动左指针经过的字符为起点时，其窗口不满足要求也可以不考虑

3. **模板**
```
   int lengthOfLongestSubstringTwoDistinct(string s) {
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


4. **Question Overview**题目分类
* 159基础：Given a string s, return the length of the longest substring that contains at most two distinct characters.
      * 经典滑动窗口，模板题
      * 用count记录 vs 用map size进行记录不同类型的字符，用erase擦除字符
   * [159](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
   # count增加的case：未存在过或者存在但是freq为0；
   # count减少的case：ele的freq变为0

* prefix sum：进阶
      * 考察要点：利用contiguous的特性解题
      * 思考：如果不是contiguous怎么做？
   * [560](https://leetcode.com/problems/subarray-sum-equals-k/)

* backtrack：难
      * 难在代码逻辑和树图框架以及如何转换为dp问题
   * [698](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

* dp：进阶
      * 预处理和建立dp模型
   * [474](https://docs.google.com/spreadsheets/d/1tA_y12w1tildb8cNsO9GKuiKPcUrXZumyCzplv6kx24/edit#gid=1903144284)

* 层序遍历类型：进阶: 经典zigzag遍历，推荐bfs
      * bfs：考察数据结构的灵活处理，采用一定的数据结构先存储再按序推入
   * [103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

* 树高度类型：基础：最大高度，要掌握bfs和dfs
      * bfs: 数level，掌握层序遍历
      * dfs：代码简单，递归方程和base case简单
   * [104](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

* 树高度类型：进阶：最小高度，推荐bfs
      * bfs: level到达叶子结点即停止搜索，代码简单，层序遍历的进阶
      * dfs：代码不好写，但掌握后非常有利于后续学习：先序遍历，递归方程中要分几类情况考虑（严谨）
   * [111](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

* 树高度类型：进阶：先序遍历+剪枝，推荐dfs
      * dfs：掌握上题后⬅此题；灵活掌握数据结构，一次遍历返回两个信息，特殊情况不需要考虑但需要提前思考保证不错
   * [110](https://leetcode.com/problems/balanced-binary-tree/)

2. Design and Mindset
**important**: 
            - 学会灵活处理想办法
            - dfs的时候不需要去思考递归一层层是如何操作的，只要写好了base case并且考虑完善，写好了递归方程
              即当前层是如何由子节点得到的，就可以了！always believe in leap of faith！

3. Algorithms
-- 本周使用bfs和dfs写了树的几题：
   同样是针对不同题型，bfs和dfs各有优势。

   - 对于层序遍历和两个queue类型的推荐bfs
   - 对于树高度和树型判断的需要掌握好dfs

**总结**：
       *dfs写的时候想好base case，一定注意考虑几种特殊情况（null，叶子，一边为null）*
       *写递归方程的时候也想想特殊情况会不会有影响，需不需要分类考虑*
       *bfs写层序遍历注意level是上一层的，如果返回当前层的记得返回正确的值*

**总结2**

   1、明确 dp 数组所存数据的含义。这一步对于任何动态规划问题都很重要，如果不得当或者不够清晰，会阻碍之后的步骤。

   2、根据 dp 数组的定义，运用数学归纳法的思想，假设 dp[0...i-1] 都已知，想办法求出 dp[i]，一旦这一步完成，整个题目基本就解决了。

   但如果无法完成这一步，很可能就是 dp 数组的定义不够恰当，需要重新定义 dp 数组的含义；或者可能是 dp 数组存储的信息还不够，不足以推出下一步的答案，需要把 dp 数组扩大成二维数组甚至三维数组。
                