# [Gold III] Bookshelf - 5881 

[문제 링크](https://www.acmicpc.net/problem/5881) 

### 성능 요약

메모리: 2084 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 5월 20일 12:42:21

### 문제 설명

<p>When Farmer John isn't milking cows, stacking haybales, lining up his cows, or building fences, he enjoys sitting down with a good book.  Over the years, he has collected N books (1 <= N <= 2,000), and he wants to build a new set of bookshelves to hold them all.</p><p>Each book i has a width W(i) and height H(i).  The books need to be added to a set of shelves in order; for example, the first shelf should contain books 1...k for some k, the second shelf should start with book k+1, and so on.  Each shelf can have a total width of at most L (1 <= L <= 1,000,000,000).  The height of a shelf is equal to the height of the tallest book on that shelf, and the height of the entire set of bookshelves is the sum of the heights of all the individual shelves, since they are all stacked vertically.</p><p>Please help FJ compute the minimum possible height for the entire set of bookshelves.</p>

### 입력 

 <ul><li>Line 1: Two space-separated integers: N and L.</li><li>Lines 2..1+N: Line i+1 contains two space-separated integers: H(i) and W(i).  (1 <= H(i) <= 1,000,000; 1 <= W(i) <= L).</li></ul>

### 출력 

 <ul><li>Line 1: The minimum possible total height for the set of bookshelves.</li></ul>

