- gcc -g scope3.c
- gdb -q ./a.out
- output:
- (gdb) list 1
- output:
1	#include<stdio.h>
2	
3	int j = 42;  // global value
4	
5	void func3()
6	{
7		int i = 11, j = 999;  // here j - local value func3()
8		printf("\t\t\t[we to func3] i @ 0x%08x = %d\n", &i, i);
9		printf("\t\t\t[we to func3] j @ 0x%08x = %d\n", &j, j);
10	}
- (gdb) break 8
- output:
Breakpoint 1 at 0x11bf: file scope3.c, line 8.
- (gdb) run 
- output:
[we to main] i @ 0xffffde9c = 3
[we to main] j @ 0x55558038 = 42
	[we to func1] i @ 0xffffde7c = 5
	[we to func1] j @ 0x55558038 = 42
		[we to func2] i @ 0xffffde5c = 7
		[we to func2] j @ 0x55558038 = 42
		[we to func2] setting j = 1337

Breakpoint 1, func3 () at scope3.c:8
8		printf("\t\t\t[we to func3] i @ 0x%08x = %d\n", &i, i);
- (gdb) bt
- output:
#0  func3 () at scope3.c:8
#1  0x0000555555555274 in func2 () at scope3.c:19
#2  0x0000555555555318 in func1 () at scope3.c:29
#3  0x00005555555553bc in main () at scope3.c:39
- (gdb) bt full
- output:
#0  func3 () at scope3.c:8
        i = 11
        j = 999
#1  0x0000555555555274 in func2 () at scope3.c:19
        i = 7
#2  0x0000555555555318 in func1 () at scope3.c:29
        i = 5
#3  0x00005555555553bc in main () at scope3.c:39
        i = 3

