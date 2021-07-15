AB沒有LINUX環境 所以去網站做，成功後再複製起來

##假設A.l A.y

#compile bison

bison -d -o y.tab.c A.y

gcc -c -g -I.. y.tab.c

#compile flex

flex -o lex.yy.c A.l

gcc -c -g -I.. lex.yy.c

#compile and link bison and flex

gcc -o A y.tab.o lex.yy.o -ll