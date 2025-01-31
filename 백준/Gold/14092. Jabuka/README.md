# [Gold V] Jabuka - 14092 

[문제 링크](https://www.acmicpc.net/problem/14092) 

### 성능 요약

메모리: 6116 KB, 시간: 48 ms

### 분류

애드 혹, 구현, 시뮬레이션

### 제출 일자

2025년 2월 1일 03:21:03

### 문제 설명

<p>Mirko i Slavko bave se izradom mobilnih aplikacija. Nakon izrade neočekivano dobro prihvaćene aplikacije FotoLektira koja na temelju nekoliko rečenica radi stilsku analizu knjige, ekipa je odlučna napraviti još jednu uspješnicu.</p>

<p>Protitip nove igre koju razvijaju ima R x S ploču na kojoj su polja ili prazna ili zablokirana. Jedno od polja sadrži jabuku koja uvijek pada u smjeru gravitacije. U svakoj sekundi igrač može ekran okrenuti za 90 stupnjeva u smjeru kazaljke na satu, za 90 stupnjeva obrnuto od smjera kazaljke na satu ili može pričekati (ne napraviti ništa). Nakon toga jabuka padne jedno polje prema dolje (u smjeru gravitacije), ali samo ako polje ispod jabuke postoji (nije izvan ploče) i prazno je - inače jabuka ostaje na mjestu.</p>

<p>Vaš zadatak je napraviti simulator igre, odnosno za početno stanje i niz koraka ispisati konačno stanje. Sljedeća tablica ilustrira jedan jednostavni primjer ove igre. U tablici znak ‘#’ označava blokirano polje, znak ‘.’ označava prazno polje, dok znak ‘J’ označava poziciju jabuke.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/14092/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-02%20%EC%98%A4%ED%9B%84%204.33.58.png" style="height:280px; width:500px"></p>

### 입력 

 <p>U prvom retku nalaze se prirodni brojevi R i S (3 ≤ R, S ≤ 1000), broj redaka i stupaca ploče. U sljedećih R redaka nalazi se niz od točno S znakova gdje je svaki znak veliko slovo ‘J’, ‘.’ (točka) ili ‘#’. Na ploči će se nalaziti točno jedan znak ‘J’.</p>

<p>U posljednjem retku ulaza nalazi se niz od najviše 1 000 000 znakova -- niz koraka. Svaki znak toga niza bit će jedan od sljedećih:</p>

<ul>
	<li>‘R’ - označava okret ekrana u smjeru kazaljke na satu</li>
	<li>‘L’ - označava okret ekrana u smjeru obrnutom od smjera kazaljke na satu</li>
	<li>‘P’ - označava čekanje </li>
</ul>

### 출력 

 <p>Ispišite R x S ili S x R tablicu (ovisno o konačnoj rotaciji) krajnjeg stanja ploče. </p>

