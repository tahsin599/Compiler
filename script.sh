yacc -d -y 2005064.y
g++ -w -c -o y.o y.tab.c
flex 2005064.l
g++ -w -c -o l.o lex.yy.c
g++ y.o l.o -o 2005064
./2005064 input.c
