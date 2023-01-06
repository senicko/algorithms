[Link to problem](https://codeforces.com/contest/1186/problem/C)

## Notes

We have two binary strings `a` and `b` (see the problem for details).

We have to count the number of substrings of `a` where if we compare bits with bits from `b` number of distinct bits is even.

First step is to count how many ones there is in `b`. This takes `O(n)` time.

Then we construct `pref` array with `b.size() + 1` elements and we generate prefix sums, which takes `O(n)` time, to be able to count number of ones on range `[a, b]` for `a` in `O(1)` time.

Finaly we iterate over all substrings of length of `b` in string `a`, which takes at most `O(n)` time. Then we check if `number of ones in b % 2 == number of ones in the substring of a % 2`. We use prefix sums to get number of ones in substring of the `a`.

So the whole thing takes `O(n)` time!

## Section for dummies (myself included)

Why `% 2`? This is how this problem is explained in blog entry with solutions to the contest from which this problem was taken (https://codeforces.com/blog/entry/68027).

The solution states that `It's easy to see that 𝑓(𝑐,𝑑) is even if and only if 𝑐𝑛𝑡𝑏 and 𝑐𝑛𝑡𝑐 have same parity. In other words if 𝑐𝑛𝑡𝑐 % 2 ≡ 𝑐𝑛𝑡𝑑 % 2 then 𝑓(𝑐,𝑑) is even.`

_f(c, d) is a function introduced in the problem description. It is basically number of distinct bits between string `c` and `d` (substring of `a` and `b`)._

Let's analyze that. It is probably stupidly simple for most of people but I had to spend some time to understand this so I will share my thought process.

If two ones are misplaced they create 2 distinct bits (so 1 additional `1` creates 1 more distinct bit)

```
    1
    |
c = 01
d = 10
     |
     2

f(c, d) = 2
```

If ones are aligned they create 0 distinct bits

```
c= 10
d= 10

f(c, d) = 0
```

Now _drum roll please_ when we add 1 to an even number we get an odd one!

_drum roll please_ again ... when we add 2 to an odd number we get an odd number, and when we add 2 to an even number we get an even number!

So as long as length of string c and d is the same or it is different by an even number we will get an even output from f(c, d). Reason for that is when we add one `1` bit to c or d, then number of ones will change it's parity resulting in switching parity of our result (we will have one more match or we will have one more distinct bit which will change our result by one and switching it's parity)

I know this may be overexplained if you are smart, but in my opinion it is important to spend some time on understanding details, connecting dots and making something that seems legit into a fact we understand as it can help to solve other problems.

---

prefix_sum
