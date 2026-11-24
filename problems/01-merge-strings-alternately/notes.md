# Problem 01.Merge Strings Alternately

**LeetCode:** <https://leetcode.com/problems/merge-strings-alternately/  

**Topic / pattern:** arrays/strings 

**Difficulty:** Easy 

**Date solved:** <2026-11-24>

## Core idea

we use the two pointer approach.
assing a pointer to word 1 and a pointer to word 2. then while both pointers don't exceed their respective word length we add them alternately to the result string and increment the pointers

after that loop exits we run a separate
for each word to ensure that if the inital loop exits early we catch any reaminder letters and append them to the result.

## Algorithm

1. <Step one>
2. <Step two>
3. <Step three>

## Complexity

- **Time:** `O(n+m)` — loop through lengths of both words
- **Auxiliary space:** `O(n+m)` — our result stores length of both words

## Edge cases / test cases

- <Case 1>
- <Case 2>
- <Case 3>

## What I learned / possible alternatives

<Tradeoffs and why this approach is appropriate.>
