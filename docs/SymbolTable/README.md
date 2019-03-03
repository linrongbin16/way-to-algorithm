<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Symbol Table
# 数学符号表

--------

| 符号                            | 名称       | 读法               | 定义                                                                                                          | 举例                                                        |
| ------------------------------- | ---------- | ------------------ | ------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| =                               | 等号       | 等于               | $$ x = y $$                                                                                                   | $$ 1+1 = 2 $$                                               |
| $$ \approx $$                   | 约等号     | 约等于             | $$ x \approx y $$                                                                                             | $$ 1.00001 \approx 1 $$                                     |
| $$ \ne $$                       | 不等号     | 不等于             | $$ x \ne y $$                                                                                                 | $$ 1 + 1 \ne 3 $$                                           |
| $$ \lt $$                       | 小于号     | 小于               | $$ x \lt y $$                                                                                                 | $$ 1 \lt 2 $$                                               |
| $$ \le $$                       | 小于等于号 | 小于等于           | $$ x \le y $$                                                                                                 | $$ 1 \le 1, 1 \le 2 $$                                      |
| $$ \gt $$                       | 大于号     | 大于               | $$ x \gt y $$                                                                                                 | $$ 2 \gt 1 $$                                               |
| $$ \ge $$                       | 大于等于号 | 大于等于           | $$ x \ge y $$                                                                                                 | $$ 2 \ge 1, 1 \ge 1 $$                                      |
| $$ + $$                         | 加号       | 加                 | $$ x + y $$                                                                                                   | $$ 2 + 1 = 3 $$                                             |
| $$ - $$                         | 减号       | 减                 | $$ x - y $$                                                                                                   | $$ 2 - 1 = 1 $$                                             |
| $$ - $$                         | 负号       | 负                 | $$ -y + y = 0 $$                                                                                              | $$ -1 $$                                                    |
| $$ \times $$                    | 乘号       | 乘                 | $$ x \times y \text{:} \sum_{i=1}^{y} x $$                                                                    | $$ 2 \times 3 = 6 $$                                        |
| $$ \cdot $$                     | 乘号       | 乘                 | $$ x \cdot y \text{:} x \times y $$                                                                           | $$ 2 \cdot n = 2n $$                                        |
| $$ \div $$                      | 除号       | 除以               | $$ x \div y = z \text{:} \sum_{i=1}^{z} y $$                                                                  | $$ 15 \div 3 = 5 $$                                         |
| $$ \sum $$                      | 求和符号   | 求和               | $$ \sum_{i=1}^{n} x_{i} \text{:} x_1 + x_2 + \cdots + x_n $$                                                  | $$ \sum_{i=1}^{3} x_{i} = x_{1} + x_{2} + x_{3} $$          |
| $$ \prod $$                     | 求积符号   | 求积               | $$ \prod_{i=1}^{n} x_{i} \text{:} x_1 \cdot x_2 \cdots \x_n $$                                                | $$ \prod_{i=1}^{3} x_{i} = x_{1} \cdot x_{2} \cdot x_{3} $$ |
| $$ \sqrt x $$                   | 根号       | 开方根             | $$ \sqrt [n] x = n \text{:} \prod_{i=1}^{n} x $$                                                              | $$ \sqrt 9 = 3, \sqrt [3] {27} = 3 $$                       |
| $$ \mid \mid$$                  | 绝对值     | 绝对值             | $$ \mid x \mid \text{:} abs(x) $$                                                                             | $$ \mid -1 \mid = 1 $$                                      |
| $$ ! $$                         | 阶乘       | 阶乘               | $$ n! \text{:} \begin{cases} 1 & n=0 \\ 1 \times 2 \times \cdots \times n & n \gt 0 \end{cases} $$            | $$ 0! = 1, 3! = 1 \times 2 \times 3 = 6 $$                  |
| $$ P_{k}^{n} $$                 | 排列       | 排列               | $$ P_{k}^{n} \text{:} \frac{n!}{(n-k)!} $$                                                                    | $$ P_{3}{8} = \frac{8!}{(8-3)!} = 336 $$                    |
| $$ C_{k}^{n} = \binom{n} {k} $$ | 组合       | 组合               | $$ C_{k}^{n} \text{:} \frac{P_{k}^{n}}{k!} = \frac{n!}{k!(n-k)!} $$                                           | $$ C_{3}{8} = \frac{8!}{3! \times (8-3)!} = 56 $$           |
| $$ \wedge $$                    | 逻辑与     | 与                 | $$ x \wedge y \text{:} \begin{cases} 1 & x=1, y=1 \\ 0 & other cases \end{cases} $$                           | $$ 1 \wedge 1 = 1, 1 \wedge 0 = 0 $$                        |
| $$ \vee $$                      | 逻辑或     | 或                 | $$ x \vee y \text{:} \begin{cases} 0 & x=0, y=0 \\ 1 & other cases \end{cases} $$                             | $$ 1 \vee 0 = 1, 0 \vee 0 = 0 $$                            |
| $$ \oplus $$                    | 异或       | 异或               | $$ x \oplus y \text{:} \begin{cases} 0 & x=y \\ 1 & x \ne y \end{cases} $$                                    | $$ 1 \oplus 0 = 1, 0 \oplus 0 = 0 $$                        |
| $$ \in $$                       | 属于       | 属于               | $$ x \in y \text{:} y = {x, \dots } $$                                                                        | $$ 1 \in \{1, 2, 3\} $$                                     |
| $$ \notin $$                    | 不属于     | 不属于             | $$ x \notin y \text{:} y \ne {x, \dots } $$                                                                   | $$ 4 \notin \{1, 2, 3\} $$                                  |
| $$ \forall $$                   | 任意符号   | 对任意的           | $$ \text{for every} x $$                                                                                      | $$ \forall x \in \{1, 2, 3\} $$                             |
| $$ \exists $$                   | 存在符号   | 存在               | $$ \text{has} x $$                                                                                            | $$ \exists x $$                                             |
| $$ \varnothing $$               | 空集       | 空集               | $$ \varnothing \text{:} {} $$                                                                                 | $$ \varnothing \subset \{1\} $$                             |
| $$ \cap $$                      | 交集       | 交                 | $$ x \cap y \text{:} {e, e \in x \wedge x \in y } $$                                                          | $$ \{1, 2, 3\} \cap \{2, 3, 4\}  = \{2, 3\} $$              |
| $$ \cup $$                      | 并集       | 并                 | $$ x \cup y \text{:} {e, e \in x \vee e \in y } $$                                                            | $$ \{1, 2, 3\} \cap \{2, 3, 4\}  = \{1, 2, 3, 4\} $$        |
| $$ \subseteq $$                 | 子集       | 左边是右边的子集   | $$ x \subseteq y \text{:} {e, \forall e \in x \rightarrow e \in y, \exists e \in y \rightarrow e \notin x} $$ | $$ \{1, 2, 3\} \subseteq \{1, 2, 3\} $$                     |
| $$ \supseteq $$                 | 子集       | 右边是左边的子集   | $$ y \supseteq x \text{:} {e, \forall e \in y \rightarrow e \in x, \exists e \in x \rightarrow e \notin y} $$ | $$ \{1, 2, 3\} \supseteq \{1, 2, 3\} $$                     |
| $$ \nsubseteq $$                | 非子集     | 左边不是右边的子集 | $$ x \nsubseteq y \text{:} not x \subseteq y $$                                                               | $$ \{4\} \nsubseteq \{1, 2, 3\} $$                          |
| $$ \nsupseteq $$                | 非子集     | 右边不是左边的子集 | $$ y \nsupseteq x \text{:} not y \subseteq x $$                                                               | $$ \{1, 2, 3\} \nsupseteq \{0\} $$                          |
| $$ \subset $$                   | 真子集     | 左边是右边的真子集 | $$ x \subset y \text{:}  x \neq y, x \subseteq y $$                                                           | $$ \{1\} \subset \{1, 2, 3\} $$                             |
| $$ \supset $$                   | 真子集     | 右边是左边的真子集 | $$ y \supset x \text{:} $$                                                                                    | $$ \{1, 2, 3\} \supset \{1\} $$                             |
| $$ \backslash $$                | 补集       | 除去               | $$ x \backslash y $$                                                                                          | $$ \{1, 2, 3\} \backslash \{3, 4, 5\} = \{1, 2\} $$         |
| $$ \infty $$                    | 无穷       | 无穷               | $$ \infty $$                                                                                                  | $$ -\infty \lt 0 \lt +\infty $$                             |
| $$ \leftarrow $$                | 左箭头     | 向左               | $$ x \leftarrow y $$                                                                                          | $$ x \leftarrow y $$                                        |
| $$ \rightarrow $$               | 右箭头     | 向右               | $$ x \rightarrow y $$                                                                                         | $$ x \rightarrow y $$                                       |
| $$ \uparrow $$                  | 上箭头     | 向上               | $$ \uparrow $$                                                                                                | $$ \uparrow $$                                              |
| $$ \downarrow $$                | 下箭头     | 向下               | $$ \downarrow $$                                                                                              | $$ \downarrow  $$                                           |

--------

#### Symbol Table

* https://en.wikipedia.org/wiki/List_of_mathematical_symbols
