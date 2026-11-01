program grader;

uses code;

var
	n, i, sol : longint;
	a : array[0..500005] of longint;

BEGIN

	readln(n);
	for i := 1 to n do
		read(a[i]);
	sol := TamanPodela(n, a);

	writeln(sol);
	
END.
