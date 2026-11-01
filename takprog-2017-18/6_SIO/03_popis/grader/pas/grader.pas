program grader;

uses code;

procedure grade;
var
	n, m, q, v, i, j, t : longint;
	b, x1, y1, x2, y2, o : array[0..100001] of longint;
	a : matrica;
begin
	Read(n, m, q, v);
	for i:=1 to n do
		for j:=1 to m do
			Read(a[i][j]);
	for i:=1 to v do
		Read(b[i]);
	t := 0;
	for i:=1 to q do begin
		read(j);
		if j = 1 then begin
			read(x1[i], y1[i], x2[i], y2[i]);
			t := t + 1;
		end	else begin
			read(x1[i], y1[i], x2[i]);
			y2[i] := -1;
		end;
	end;
	Resi(n, m, q, v, a, b, x1, y1, x2, y2, o);
	for i:=1 to t do
		Writeln(o[i]);
end;

begin
	grade;
end.
