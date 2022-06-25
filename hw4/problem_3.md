<img width="316" alt="image" src="https://user-images.githubusercontent.com/252020/167771084-3d07d4e1-424b-401b-a517-f99a9a1454fc.png">

## (30pt) Percentile

This is another "reverse engineering" puzzle task. We are calculating percentile.

Here's the [wiki's definition](https://en.wikipedia.org/wiki/Percentile):


*In statistics, a k-th percentile (percentile score or centile) is a score below which a given percentage k of scores in its frequency distribution falls (exclusive definition) or a score at or below which a given percentage falls (inclusive definition).*

Percentile, as simple as the idea is, is very frequently use in real life software engineering and dev ops to "squeeze" useful information out of data. Usually in terms of [P99, P90, P50, etc.](https://readosapien.com/what-is-p50-p90-p99-latency/). Here are 2 good reads/watches on it:

1. [How NOT to measure latency](https://youtu.be/lJ8ydIuPFeU)
2. [An introduction to 99 percentile for programmers](https://medium.com/@ankur_anand/an-in-depth-introduction-to-99-percentile-for-programmers-22e83a00caf)

This task is to implement the percentil function, and as a comparison, also a mean value function. Similar to the compound interest homework, all tasks are given as a manual, and a [hint of the formula](https://www.calculatorsoup.com/calculators/statistics/percentile-calculator.php) is also given, so all we need to do is to figure out the formula and turn it into code. 

We'll discuss more in the lecture on the use of percentile to understand information from data.
