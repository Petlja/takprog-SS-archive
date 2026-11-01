program grader;

uses code;

procedure grade;
var
	n, m, i, j : longint;
	a : array of char;
	l : array of longint;
	b : array of array of char;
	s : ansistring;
begin
	readln(s);
	n := length(s);
	setlength(a, n+2);
	a[0] := chr(0);
	a[n+1] := chr(0);
	for i:=0 to n-1 do
		a[i+1] := s[i];

	readln(m);
	setlength(b, m+1);
	setlength(l, m+1);

	for i:=1 to m do begin
		readln(s);
		l[i] := length(s);
		setlength(b[i], l[i]+2);
		b[i][0] := chr(0);
		b[i][l[i]+1] := chr(0);
		for j:=0 to l[i]-1 do
			b[i][j+1] := s[i];
	end;

	Writeln(Resi(n, a, m, l, b));
end;

begin
	grade;
end.
