<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# Greatest Common Divisor - 最大公约数

--------

#### 最大公约数/最小公倍数

最大公约数$$ gcd $$是最大的能同时被$$ a, b $$整除的正整数。最小公倍数$$ lcm $$是最小的能同时整除$$ a, b $$的正整数。即满足下列等式：

$$
\begin{matrix}
a \bmod gcd = 0 \\
b \bmod gcd = 0 \\
lcm \bmod a = 0 \\
lcm \bmod b = 0
\end{matrix}
$$

$$ 0 $$和另一个正整数$$ b $$的最大公约数为$$ b $$，因为$$ 0 $$除以任何正整数都可以整除。

比如对于$$ a = 36 $$，能被$$ a $$整除的正整数为$$ divisors_{a} = [ 1, 2, 3, 4, 6, 9, 12, 18, 36] $$，能整除$$ a $$的正整数为$$ multiples_{a} = [36, 72, 108 \dots] $$。对于$$ b = 66 $$，能被$$ b $$整除的正整数为$$ divisors_{b} = [ 1, 2, 3, 6, 11, 22, 33, 66] $$，能整除$$ b $$的正整数为$$ multiples_{b} = [66, 132, 198 \dots] $$。那么$$ 36, 66 $$的最大公约数为$$ 6 $$，最小公倍数为$$ 396 $$。

将$$ a = 36, b = 66 $$分解为素数的乘积，可得$$ 36 = 2 \times 2 \times 3 \times 3, 66 = 2 \times 3 \times 11 $$，其中每个素数都称为分解因子。可以把$$ a $$和$$ b $$的分解因子看作两个集合$$ factor_{a} = [2, 2, 3, 3], factor_{b} = [2, 3, 11] $$。则$$ a, b $$的最大公约数为两个正整数分解因子的最大交集，最小公倍数为最小并集：

$$
\begin{matrix}
gcd(a, b) = factor_{a} \bigcap factor_{b}   \\
lcm(a, b) = factor_{a} \bigcup factor_{b}
\end{matrix}
$$

分解因子是一个NP完全问题。
