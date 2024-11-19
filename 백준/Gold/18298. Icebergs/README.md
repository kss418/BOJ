# [Gold V] Icebergs - 18298 

[문제 링크](https://www.acmicpc.net/problem/18298) 

### 성능 요약

메모리: 5160 KB, 시간: 12 ms

### 분류

기하학, 다각형의 넓이

### 제출 일자

2024년 11월 19일 15:00:27

### 문제 설명

<p>Tania is a marine biologist. Her goal is to measure the impact of climate change on the population of Macaroni penguins. As most species of penguins, Macaroni penguins live in the southern hemisphere, near Antarctica. Tania is primarily focused on the population of Macaroni penguins near the “Îles Nuageuses” (in English, “Cloudy Islands”).</p>

<p>During summer, the ice around the islands melt and the islands becomes too small to host all the birds. Some penguins live on the icebergs floating around. For her study, Tania needs to measure the area of those icebergs.</p>

<p>Using satellite imagery and image recognition, Tania has obtained a map of the icebergs and your goal is to measure their area. The island studied by Tania is quite small and the Earth can locally be approximated as a flat surface. Tania’s map thus uses the usual 2D Cartesian coordinate system, and areas are computed in the usual manner. For instance, a rectangle parallel to the axes defined by the equations x<sub>1</sub> ≤ x ≤ x<sub>2</sub> and y<sub>1</sub> ≤ y ≤ y<sub>2</sub> has an area of (x<sub>2</sub> − x<sub>1</sub>) × (y<sub>2</sub> − y<sub>1</sub>).</p>

<p>In Tania’s representation, an iceberg is a polygon represented by its boundary. For each iceberg Tania has noted the sequence of points p<sub>1</sub>, . . . , p<sub>k</sub> defining the border of the iceberg. The various icebergs never touch each other and they never overlap. Furthermore the boundary p<sub>1</sub>, . . . , p<sub>k</sub> of an iceberg is always a “simple” polygon, i.e. no two segments in [p<sub>1</sub>; p<sub>2</sub>], . . . , [p<sub>k</sub>; p<sub>1</sub>] cross each other.</p>

### 입력 

 <p>The input consists of the following lines:</p>

<ul>
	<li>on the first line, an integer N, describing the number of polygons;</li>
	<li>then N blocks of lines follow, each describing a polygon and composed of:
	<ul>
		<li>on the first line, an integer P, the number of points defining the polygon border,</li>
		<li>on the next P lines, two space-separated integers x and y, the coordinates of each border point.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>The output should contain a single integer: the total area rounded to the nearest integer below. In other words, the output should be a single line containing a single integer I such that the total area A of the polygons described in the input is comprised between I included and I + 1 excluded (I ≤ A < I + 1).</p>

