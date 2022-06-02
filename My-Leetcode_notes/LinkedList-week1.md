# LinkedList 周总结
1. **Question Overview**题目分类
* LinkedList 基本操作
* 翻转：基础
   * 使用三个指针，prev，curr，next
   * [206](https://leetcode.com/problems/reverse-linked-list/)

* Merge: 基础
   * 类似两个sorted array的merge
   * [21](https://leetcode.com/problems/merge-two-sorted-lists/)

* Swap nodes: 进阶
   * 这里步骤多且饶，要有一定的抽象想象思维，同时切记是先swap顺序再连入list中
   * [24](https://leetcode.com/problems/swap-nodes-in-pairs/)

* 找交叉：基础的双指针technique
   * 基础的龟兔赛跑双指针法，找到两者路径相同的时候，如果速度一致，那么肯定会在某个同一时间相遇
   * [160](https://leetcode.com/problems/intersection-of-two-linked-lists/)

* 回文数：进阶
   * module题：先用快慢指针找中点，然后翻转剩下一半，然后用双指针比较两半
   * [234](https://leetcode.com/problems/palindrome-linked-list/)

* 去重：
   * 这里的trick是如果有重复，当前指针不需要变化
   * [83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

* 奇偶数重排列：
   * 这里的trick与上题类似，不需要每次判别是奇数还是偶数，间隔交替进行操作即可
   * [328](https://leetcode.com/problems/odd-even-linked-list/)

* 去除第N个元素：
   * 类似快慢指针法，让两指针间距刚好差N
   * [19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

* 排序：
   * module题：先分后合考察merge sort
   * [148](https://leetcode.com/problems/sort-list/)

2. Algorithms
-- LinkedList题目的常用技巧：
   * linked list的基本操作增删查改等要非常熟练！在此基础上可以解决进阶的module题
   * 快慢指针法，利用指针的步调和速度路程时间方程巧妙解决问题
   * 指针有时候可以in place穿插连接，不需要另起空间

**总结**：
       *应付特殊情况的妙招： dummy！*
       *考虑特殊的空list或者一个两个元素的list*
       *如果需要考虑最后一个node那么while循环里面应写成curr != NULL*


                