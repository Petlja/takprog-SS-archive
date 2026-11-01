program grader;

uses code;

procedure grade;
var
	n, q, i, t, p, k: longint;
begin
	Read(n, q);
	Pocetak(n);
	for i:=1 to q do begin
		Read(t, p, k);
		if t = 1 then
			DodajBombonice(p, k)
		else
			Writeln(Prebroji(p, k));
	end;
end;

begin
	grade;
end.
