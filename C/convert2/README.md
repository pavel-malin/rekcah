- gcc convert2.c
- ./a.out 
- output: Repeat 0 times...
- ./a.out test
- output: segmetation fault ./a.out test

 	memory is divided into segments, let's see with the gdb debugger
- gcc -g convert2.c 
- gdb -q ./a.out
- (gdb) run test
- output:
Starting program: /home/haskroot/rekcah/C/convert2/a.out test

Program received signal SIGSEGV, Segmentation fault.
__GI_____strtol_l_internal (nptr=0x0, endptr=endptr@entry=0x0, 
    base=base@entry=10, group=group@entry=0, 
    loc=0x7ffff7f9c4c0 <_nl_global_locale>) at ../stdlib/strtol_l.c:292
292	../stdlib/strtol_l.c: No such file or directory.

- (gdb) where
- output:
#0  __GI_____strtol_l_internal (nptr=0x0, endptr=endptr@entry=0x0, 
    base=base@entry=10, group=group@entry=0, 
    loc=0x7ffff7f9c4c0 <_nl_global_locale>) at ../stdlib/strtol_l.c:292
#1  0x00007ffff7e1ef02 in __strtol (nptr=<optimized out>, 
    endptr=endptr@entry=0x0, base=base@entry=10) at ../stdlib/strtol.c:106
#2  0x00007ffff7e1ba30 in __GI_atoi (nptr=<optimized out>) at atoi.c:27
#3  0x000055555555520c in main (argc=2, argv=0x7fffffffdf88)
    at convert2.c:14
- (gdb) break main
- output:
Breakpoint 1 at 0x5555555551f9: file convert2.c, line 14.
- (gdb) run test
- output:
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/haskroot/rekcah/C/convert2/a.out test

Breakpoint 1, main (argc=2, argv=0x7fffffffdf88) at convert2.c:14
14		count = atoi(argv[2]);  // convert the 2nd argument to an integer
- (gdb) cont
- output: 
Continuing.

Program received signal SIGSEGV, Segmentation fault.
__GI_____strtol_l_internal (nptr=0x0, endptr=endptr@entry=0x0, 
    base=base@entry=10, group=group@entry=0, 
    loc=0x7ffff7f9c4c0 <_nl_global_locale>) at ../stdlib/strtol_l.c:292
292	../stdlib/strtol_l.c: No such file or directory.

