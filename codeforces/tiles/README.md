[Link to problem](https://codeforces.com/contest/1178/problem/C)

**Notes**

Single tile can be rotated in four ways. When we add tile to it's side it can be rotated on two ways (to have different colors on side).

We need to notice that when tile is glued to two other tiles there is only one way we can face it.

```
##
## <- There is only a one way this tile can be rotated
```

So we need to consider only the first row and column. In case of `w = 2` and `h = 2` number of possible layouts will be `2^(w + h)`;

```
4 ways -> ## <- 2 ways
2 ways -> ## <- 1 way
```

So `4 * 2 * 2 * 1 = 2 * 2 * 2 * 2 = 2 ^ 4 = 2 ^ (2 + 2)`.

Now we can compute that in O(log(n)) time thanks to binary exponentiation.

---

binary_exponentiation combinatorics
