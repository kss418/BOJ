# [Platinum II] Find C - 13891 

[문제 링크](https://www.acmicpc.net/problem/13891) 

### 성능 요약

메모리: 2084 KB, 시간: 4 ms

### 분류

확장 유클리드 호제법, 수학, 정수론

### 제출 일자

2025년 12월 23일 13:16:15

### 문제 설명

<p>Two of your friends Alpha and Beta are at A and B, two integer coordinates in 2D plane. You want to take their picture from another integer coordinate C fulfilling following conditions:</p>

<ol>
	<li>C has to be different from A and B.</li>
	<li>There is no integer coordinate point on the line segment AC other than its end points.</li>
	<li>There is no integer coordinate point on the line segment BC other than its end points.</li>
	<li>Triangle ABC must have positive area, that is, C must not lie on the line going through A and B.</li>
	<li>There is no integer coordinate point strictly inside triangle ABC.</li>
</ol>

<p>Don’t forget this is the era of digital photography where people don’t take only one snap. So you also need to find out K such C for each A and B from where you will take pictures.</p>

<p>A point P having coordinate (x,y) is called integer coordinate if both x and y are integers.</p>

### 입력 

 <p>First line of the input contains number of test cases T (1 ≤ T ≤ 1000).</p>

<p>In following T lines, there are 5 integers: A<sub>x</sub>, A<sub>y</sub>, B<sub>x</sub>, B<sub>y</sub>, K. Coordinates of A and B are (A<sub>x</sub>, A<sub>y</sub>) and (B<sub>x</sub>, B<sub>y</sub>) respectively. A and B are distinct points. (-10<sup>9</sup> ≤ A<sub>x</sub>, A<sub>y</sub>, B<sub>x</sub>, B<sub>y</sub> ≤ 10<sup>9</sup>, 0 ≤ sum of all K ≤ 20 000)</p>

### 출력 

 <p>For each case print K lines each containing coordinate of C in: “C<sub>x</sub> C<sub>y</sub>” format. You may assume that there are at least K such C points. You may output the C points in any order, but these K points has to be distinct. Also all the C<sub>x</sub> and C<sub>y</sub> have to be between -10<sup>14</sup> and 10<sup>14</sup>. For details of output format please consult the sample input output. </p>

