# Bit Manipulation 周总结
1. **Question Overview**题目分类



2. 常用操作
* 运算符是对每个bit的数字进行运算最后返回的是10进制下的int

* The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.  

* The | (bitwise OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. 

* The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. 

* The << (left shift) in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift. 

* The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift. 

* The ~ (bitwise NOT) in C or C++ takes one number and inverts all bits of it. 

3. 常用技巧

* XOR（^）可以用来寻找一串成对出现的数组中唯一一个单独出现的数字

* The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively. 

* 位运算特性（0s和1s分别表示只由0或1构成的二进制数字）：
* x ^ 0s = x
* x ^ 1s = ~x
* x ^ x = 0
* x & 0s = 0
* x & 1s = x
* x & x = x
* x | 0s = x
* x | 1s = 1s
* x | x = x

                