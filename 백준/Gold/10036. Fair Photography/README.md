# [Gold I] Fair Photography - 10036 

[문제 링크](https://www.acmicpc.net/problem/10036) 

### 성능 요약

메모리: 11520 KB, 시간: 52 ms

### 분류

누적 합, 정렬, 두 포인터

### 제출 일자

2025년 5월 8일 13:13:06

### 문제 설명

<p>Farmer John's N cows (1 <= N <= 100,000) are standing at various positions along a long one-dimensional fence.  The ith cow is standing at position x_i (an integer in the range 0...1,000,000,000) and has breed b_i (either 'G' for Guernsey or 'H' for Holstein).  No two cows occupy the same position.</p><p>FJ wants to take a photo of a contiguous interval of cows for the county fair, but we wants all of his breeds to be fairly represented in the photo. Therefore, he wants to ensure that, for whatever breeds are present in the photo, there is an equal number of each breed (for example, a photo with all Holsteins is ok, a photo with 27 Holsteins and 27 Guernseys is ok, but a photo with 10 Holsteins and 9 Guernseys is not ok).  Help FJ take his fair photo by finding the maximum size of a photo that satisfies FJ's constraints.  The size of a photo is the difference between the maximum and minimum positions of the cows in the photo.  It is possible that FJ could end up taking a photo of just a single cow, in which case this photo would have size zero.</p>

### 입력 

 <ul><li>Line 1: The integer N.</li><li>Lines 2..1+N: Line i+1 contains x_i and b_i.</li></ul>

### 출력 

 <ul><li>Line 1: A single integer indicating the maximum size of a fair photo.</li></ul>

