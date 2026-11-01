program grader;

uses code;

var
	N, K, I, J, VV, NQ : longint;
	mat: array[1..1010,1..1010] of longint;

function DajVisinu(I, J: longint): longint; [public, alias : 'DAJV'];
begin
	NQ := NQ + 1;
	if (I >= 1) and (I <= N) and (J >= 1) and (J <= N) then
		DajVisinu := mat[I,J]
	else
		DajVisinu := -1;
end;

begin
	readln(N, K, VV);
	NQ := 0;
	
	for I := 1 to N do
		for J := 1 to N do
			read(mat[I, J]);

	Resi(N, K, VV, I, J);
	writeln(I, ' ', J, ' ', NQ);
end.
