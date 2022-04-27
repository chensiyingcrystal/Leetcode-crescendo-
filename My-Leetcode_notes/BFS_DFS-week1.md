# BFS DFS 周总结
1. **Question Overview**题目分类

* 两个queue类型：基础：bfs建立两个queue，加入子节点之前判断多重条件
   * [100](https://leetcode.com/problems/same-tree/)

* 两个queue类型：进阶：
      * bfs: 考察bfs基本流程，与上题相似
      * dfs：递归方程简单但base case需考虑多重条件；helper function传入两个参数；
   * [101](https://leetcode.com/problems/symmetric-tree/)

* 层序遍历类型：基础：推荐bfs
      * bfs: 层序遍历基本模板
      * dfs：层序遍历的base case要判断size是否够用
   * [102](https://leetcode.com/problems/binary-tree-level-order-traversal/)

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


                