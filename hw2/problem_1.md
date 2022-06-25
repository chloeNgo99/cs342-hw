<img src="images/small_step.png"
     width="50%" />

## (50pt) Compound Interest 

### The Background
`
“The eighth wonder of the world. He who understands it, earns it; he who doesn't, pays for it. - Albert Einstein
`

This is the famous quote about compound interest. 

And here's the definition from [Wikipedia](https://en.wikipedia.org/wiki/Compound_interest):

`
Compound interest is the addition of interest to the principal sum of a loan or deposit, or in other words, interest on interest. It is the result of reinvesting interest, rather than paying it out, so that interest in the next period is then earned on the principal sum plus previously accumulated interest.
`

Note: Compound interest is a general kind of effect that applies to more aspects than finance. We ain't just talking about money here.

In simple term, compound interest is about **a repeated small step produces acceleratingly large result over time**. But be aware that this can manifest as angel or evil, meaning it can be really good or really bad for you. There are numerous ways to benefit or suffer from the effect of compound interest, and a larger issue is that many people learn this too late :(

So, let's learn this to stay on the positive side of it, and now.

### The Task (50pt)

The task of this home is to complete a compound interest simulator. **Do not use any math library**.

There are a few distinct features of this task

- The calculator we are writing is based on [this calculator](https://www.investor.gov/financial-tools-calculators/calculators/compound-interest-calculator). Use it to help understand how compound interest works. Lots of our test cases are generated using this calculator. See [this](problem_1_result_comparison.md) for a comparison between the web calculator and our use cases.

- All tests are given. This serves as validation, but more importantly, use it as a *manual* to figure out how the code should work.

- There's only one function for you to write [here](https://github.com/a-teaching-goose/2022-342-sprint-2/blob/ef3c29a4dead1935f3424a9b7b8fd8eff5396fca/src/problem_1.cpp#L4).

- Computation is done in floating point number, so *round-off error* is an issue. See [this](https://en.wikipedia.org/wiki/Round-off_error) for an intro. 

### Extra Credit 1 (5pt)

Write a paragraph in a block of comment in problem_1.cpp describing how you would apply the effect of compound interest to your life in a good way.

### Extra Credit 2 (5pt)

Add a new unit test in unit_test_problem_1.cpp to show how you would apply the effect of compound interest financially, but **DO NOT CHANGE OR REMOVE EXISTING TESTS!** Your test has to pass and make logical sense to get this points.
