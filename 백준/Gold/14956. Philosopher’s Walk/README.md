# [Gold II] Philosopher’s Walk - 14956 

[문제 링크](https://www.acmicpc.net/problem/14956) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

분할 정복, 재귀

### 제출 일자

2025년 8월 27일 14:25:41

### 문제 설명

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14956/1.png" style="float:right; height:154px; margin-left:15px; width:246px">In Programming Land, there are several pathways called Philosopher’s Walks for philosophers to have a rest. A Philosopher’s Walk is a pathway in a square-shaped region with plenty of woods. The woods are helpful for philosophers to think, but they planted so densely like a maze that they lost their ways in the maze of woods of a Philosopher’s Walk.</p>

<p>Fortunately, the structures of all Philosopher’s Walks are similar; the structure of a Philosopher’s Walk is designed and constructed according to the same rule in a 2<em><sup>k</sup></em> meter square. The rule for designing the pathway is to take a right-turn in 90 degrees after every 1-meter step when <em>k</em> is 1, and the bigger one for which the integer <em>k</em> is greater than 1 is built up using four sub-pathways with <em>k</em> - 1 in a fractal style. Figure F.1 shows three Philosopher’s Walks for which <em>k</em> is 1, 2, and 3. The Philosopher’s Walk <em>W</em><sub>2</sub> consists of four <em>W</em><sub>1</sub> structures with the lower-left and the lower-right ones are 90 degree rotated clockwise and counter-clockwise, respectively; the upper ones have the same structure with <em>W</em><sub>1</sub>. The same is true for any <em>W<sub>k</sub></em> for which the integer <em>k</em> is greater than 1. This rule has been devised by a mathematical philosopher David Hilbert (1862 – 1943), and the resulting pathway is usually called a HILBERT CURVE named after him. He once talked about a space filling method using this kind of curve to fill up a square with 2<em><sup>k</sup></em> sides, and every Philosophers’ Walk is designed according to this method.</p>

<table class="table" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; width:33%; vertical-align:bottom"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14956/a.png" style="height:133px; width:123px"></td>
			<td style="text-align:center; width:33%; vertical-align:bottom"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14956/b.png" style="height:183px; width:175px"></td>
			<td style="text-align:center; width:34%; vertical-align:bottom"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14956/c.png" style="height:278px; width:276px"></td>
		</tr>
		<tr>
			<td style="text-align:center; width:33%">(a) <em>W</em><sub>1</sub></td>
			<td style="text-align:center; width:33%">(b) <em>W</em><sub>2</sub></td>
			<td style="text-align:center; width:34%">(c) <em>W</em><sub>3</sub></td>
		</tr>
	</tbody>
</table>

<p style="text-align:center">Figure F.1. Three Philosopher's Walks with size (a) 2<sup>1</sup> = 2, (b) 2<sup>2</sup> = 4, and (c) 2<sup>3</sup> = 8, repectively.</p>

<p>Tae-Cheon is in charge of the rescue of the philosophers lost in Philosopher’s Walks using a hot air balloon. Fortunately, every lost philosopher can report Tae-Cheon the number of meter steps he has taken, and Tae-Cheon knows the length of a side of the square of the Philosopher’s Walk. He has to identify the location of the lost philosopher, the (<em>x</em>,<em>y</em>) coordinates assuming that the Philosopher’s Walk is placed in the 1st quadrant of a Cartesian plain with one meter unit length. Assume that the coordinate of the lower-left corner block is (1,1). The entrance of a Philosopher’s Walk is always at (1,1) and the exit is always (<em>n</em>,1) where <em>n</em> is the length of a side. Also assume that the philosopher have walked one meter step when he is in the entrance, and that he always go forward to the exit without back steps.</p>

<p>For example, if the number of meter-steps taken by a lost philosopher in the Philosopher’s Walk in <em>W</em><sub>2</sub> in Figure F.1(b) is 10, your program should report (3,4).</p>

<p>Your mission is to write a program to help Tae-Cheon by making a program reporting the location of the lost philosopher given the number of meter-steps he has taken and the length of a side of the square of the Philosopher’s Walk. Hurry! A philosopher urgently needs your help.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of a single line containing two positive integers, <em>n</em> and <em>m</em>, representing the length of a side of the square of the Philosopher’s Walk and the number of meter-steps taken by the lost philosopher, respectively, where <em>n</em> = 2<em><sup>k</sup></em> and <em>m</em> ≤ 2<sup>2<em>k</em></sup> for an integer <em>k</em> satisfying 0 < <em>k</em> ≤ 15.</p>

### 출력 

 <p>Your program is to write to standard output. The single output line should contain two integers, <em>x</em> and <em>y</em>, separated by a space, where (<em>x</em>,<em>y</em>) is the location of the lost philosopher in the given Philosopher’s Walk.</p>

