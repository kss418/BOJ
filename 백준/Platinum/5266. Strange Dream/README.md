# [Platinum V] Strange Dream - 5266 

[문제 링크](https://www.acmicpc.net/problem/5266) 

### 성능 요약

메모리: 18980 KB, 시간: 108 ms

### 분류

수학, 다이나믹 프로그래밍, 정수론

### 제출 일자

2025년 11월 2일 16:33:54

### 문제 설명

<p>Dumitru had a very strange dream: he dreamed that he was in a room having its door locked. There he found n boxes each containing exactly m small plates, on each plate being written an integer number greater or equal to 1. He also found a small note containing 2 integer numbers k and l, and specifying the following task:</p>

<ul>
	<li>Step 1: Pick one plate from the first box, write its number in your notebook, change the number on the plate to 1, and put the plate back into the box. Subsequently, in the same way, pick a single plate from the second box, then one from the third box, and so on till the n-th (last) box, inclusive, each time picking a plate from the respective box, writing its number in your notebook, changing the number on that plate to 1 and then placing the plate back into that box.</li>
	<li>Step 2: After this, in the same manner, pick a single plate from the box n – 1, then one from box n – 2, then one from box n – 3, and so on till the second box, inclusive, each time picking a plate from the respective box.</li>
</ul>

<p>To unlock the door of the room and to get out, Dumitru needed to find the number T of different ways of picking plates according to the above scenario, such that the product of the numbers that were written in your notebook is divisible by k. Because T could be extremely large, he needed to return the remainder of T when divided by l.</p>

<p>Dumitru is very confused about this dream and so he tries to find the answer to the above task.</p>

<p>Write a program which will help Dumitru to solve the task.</p>

### 입력 

 <p>Input contains 2 integer numbers on the first line: n and m, separated by a single space. Second line contains 2 integer numbers k and l separated by a single space. Then n lines follow, each containing m integer numbers separated by single spaces. The first of these lines contains the m numbers written on the plates found in the first box, the second of these lines contains the numbers written on the plates found in the second box, and so on.</p>

### 출력 

 <p>Output will contain one integer number that is the remainder of T when divided by l.</p>

