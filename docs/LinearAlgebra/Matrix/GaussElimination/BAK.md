上面的线性方程组可以写成增广矩阵

$$
A =
\begin{bmatrix}
a_{11} &   a_{12} &   a_{13} &   \dots   &   a_{1m}     \\
a_{21} &   a_{22} &   a_{23} &   \dots   &   a_{2m}     \\
a_{31} &   a_{32} &   a_{33} &   \dots   &   a_{3m}     \\
 \quad &    \quad &   \dots  &  \quad   &   \quad       \\
a_{n1} &   a_{n2} &   a_{n3} &   \dots   &   a_{nm}
\end{bmatrix}

\quad

B =
\begin{bmatrix}
b_{1}   \\
b_{2}   \\
b_{3}   \\
\dots   \\
b_{n}
\end{bmatrix}
$$

增广矩阵的左边部分是线性方程组中的矩阵$$ A $$，右边部分是线性方程组中的系数向量$$ B $$。增广矩阵是一个$$ n \times (m+1) $$的矩阵。

高斯消元法的数学含义在于通过初等变化，将线性方程组对应的增广矩阵变化为只有$$ r $$行不全为$$ 0 $$的矩阵（其中$$ r $$为增广矩阵的秩），形如

$$

\begin{bmatrix}
\begin{array} {c|c}
\begin{matrix}
c_{11} &   c_{12} &   c_{13} &   \dots   &   c_{1r} &   \dots   &   c_{1m}     \\
0_{21} &   c_{22} &   c_{23} &   \dots   &   c_{2r} &   \dots   &   c_{2m}     \\
0_{31} &   0_{32} &   c_{33} &   \dots   &   c_{3r} &   \dots   &   c_{3m}     \\
 \quad &  \quad   &  \quad   &   \dots   &  \quad   &  \quad    &  \quad       \\
0_{r1} &   0_{r2} &   0_{r3} &   \dots   &   c_{rr} &   \dots   &   c_{rm}     \\
 \quad &  \quad   &  \quad   &   \dots   &  \quad   &  \quad    &  \quad       \\
0_{n1} &   0_{n2} &   0_{n3} &   \dots   &   0_{nr} &   \dots   &   0_{nm}
\end{matrix}
&
\begin{matrix}
b_{1}   \\
b_{2}   \\
b_{3}   \\
\dots   \\
b_{r}   \\
\dots   \\
0_{n}
\end{matrix}
\end{array}
\end{bmatrix}

$$

经过变换后，不全为$$ 0 $$的行有$$ r $$行，全为$$ 0 $$的行有$$ n - r $$行。当$$ r = n $$时，线性方程组有唯一解，否则有通解。

本问题只考虑$$ r = n $$时有唯一解的线性方程组的解法。

