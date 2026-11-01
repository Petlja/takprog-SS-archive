fpc -O2 -dONLINE_JUDGE -Cs67107839 -otest.exe grader.pas 

IF NOT ERRORLEVEL 1 GOTO aok
echo ERROR
GOTO :eof

:aok
echo OK