- gcc -g stack_exaple.c
- gdb -q ./a.out
- output:
- (gdb)
- (gdb) disass main
- output: (cpu A4-1500)
Dump of assembler code for function main:
   0x00000000000011a7 <+0>:	push   %rbp
   0x00000000000011a8 <+1>:	mov    %rsp,%rbp
   0x00000000000011ab <+4>:	mov    $0x4,%ecx
   0x00000000000011b0 <+9>:	mov    $0x3,%edx
   0x00000000000011b5 <+14>:	mov    $0x2,%esi
   0x00000000000011ba <+19>:	mov    $0x1,%edi
   0x00000000000011bf <+24>:	call   0x1189 <test_function>
   0x00000000000011c4 <+29>:	mov    $0x0,%eax
   0x00000000000011c9 <+34>:	pop    %rbp
   0x00000000000011ca <+35>:	ret    
End of assembler dump.
- (gdb) disass test_function
- output:
Dump of assembler code for function test_function:
   0x0000000000001189 <+0>:	push   %rbp
   0x000000000000118a <+1>:	mov    %rsp,%rbp
   0x000000000000118d <+4>:	mov    %edi,-0x14(%rbp)
   0x0000000000001190 <+7>:	mov    %esi,-0x18(%rbp)
   0x0000000000001193 <+10>:	mov    %edx,-0x1c(%rbp)
   0x0000000000001196 <+13>:	mov    %ecx,-0x20(%rbp)
   0x0000000000001199 <+16>:	movl   $0x539,-0x4(%rbp)
   0x00000000000011a0 <+23>:	movb   $0x41,-0xe(%rbp)
   0x00000000000011a4 <+27>:	nop
   0x00000000000011a5 <+28>:	pop    %rbp
   0x00000000000011a6 <+29>:	ret    
End of assembler dump.
- (gdb) disass main
- output:
Dump of assembler code for function main:
   0x00000000000011a7 <+0>:	push   %rbp
   0x00000000000011a8 <+1>:	mov    %rsp,%rbp
   0x00000000000011ab <+4>:	mov    $0x4,%ecx
   0x00000000000011b0 <+9>:	mov    $0x3,%edx
   0x00000000000011b5 <+14>:	mov    $0x2,%esi
   0x00000000000011ba <+19>:	mov    $0x1,%edi
   0x00000000000011bf <+24>:	call   0x1189 <test_function>
   0x00000000000011c4 <+29>:	mov    $0x0,%eax
   0x00000000000011c9 <+34>:	pop    %rbp
   0x00000000000011ca <+35>:	ret    
End of assembler dump.
- (gdb) list main
- output:
6		flag = 1337;
7		buffer[0] = 'A';
8	}
9	
10	int main()
11	{
12		test_function(1, 2, 3, 4);
13	}
- (gdb) break 12
- output:
Breakpoint 1 at 0x11ab: file stack_example.c, line 12.
- (gdb) break test_function
- output:
Breakpoint 2 at 0x1199: file stack_example.c, line 6.
- (gdb) run
- output:
Breakpoint 1, main () at stack_example.c:12
12		test_function(1, 2, 3, 4);
- (gdb) i r rsp rbp rip
- output:
rsp            0x7fffffffde80      0x7fffffffde80
rbp            0x7fffffffde80      0x7fffffffde80
rip            0x5555555551ab      0x5555555551ab <main+4>
- (gdb) x/5i %rip
- output:
=> 0x5555555551ab <main+4>:	mov    $0x4,%ecx
   0x5555555551b0 <main+9>:	mov    $0x3,%edx
   0x5555555551b5 <main+14>:	mov    $0x2,%esi
   0x5555555551ba <main+19>:	mov    $0x1,%edi
   0x5555555551bf <main+24>:	call   0x555555555189 <test_function>
- (gdb) cont
- output:
Continuing.

Breakpoint 2, test_function (a=1, b=2, c=3, d=4) at stack_example.c:6
6		flag = 1337;
- (gdb) i r rsp rbp rip
- output:
rsp            0x7fffffffde80      0x7fffffffde80
rbp            0x7fffffffde80      0x7fffffffde80
rip            0x5555555551ab      0x5555555551ab <main+4>
- (gdb) x/5i $rip
- output:
=> 0x5555555551ab <main+4>:	mov    $0x4,%ecx
   0x5555555551b0 <main+9>:	mov    $0x3,%edx
   0x5555555551b5 <main+14>:	mov    $0x2,%esi
   0x5555555551ba <main+19>:	mov    $0x1,%edi
   0x5555555551bf <main+24>:	call   0x555555555189 <test_function>
- (gdb) cont
- output:
Continuing.

Breakpoint 2, test_function (a=1, b=2, c=3, d=4) at stack_example.c:6
6		flag = 1337;
- (gdb) i r rsp rbp rip
- output:
rsp            0x7fffffffde70      0x7fffffffde70
rbp            0x7fffffffde70      0x7fffffffde70
rip            0x555555555199      0x555555555199 <test_function+16>
- (gdb) disass test_function
- output:
 Dump of assembler code for function test_function:
   0x0000555555555189 <+0>:	push   %rbp
   0x000055555555518a <+1>:	mov    %rsp,%rbp
   0x000055555555518d <+4>:	mov    %edi,-0x14(%rbp)
   0x0000555555555190 <+7>:	mov    %esi,-0x18(%rbp)
   0x0000555555555193 <+10>:	mov    %edx,-0x1c(%rbp)
   0x0000555555555196 <+13>:	mov    %ecx,-0x20(%rbp)
=> 0x0000555555555199 <+16>:	movl   $0x539,-0x4(%rbp)
   0x00005555555551a0 <+23>:	movb   $0x41,-0xe(%rbp)
   0x00005555555551a4 <+27>:	nop
   0x00005555555551a5 <+28>:	pop    %rbp
   0x00005555555551a6 <+29>:	ret    
End of assembler dump.
- (gdb) print $rbp-4
- output:
$1 = (void *) 0x7fffffffde6c
- (gdb) print $rbp-32
- output:
$2 = (void *) 0x7fffffffde50
- (gdb) x/16xw $rsp
- output:
0x7fffffffde70:	0xffffde80	0x00007fff	0x555551c4	0x00005555
0x7fffffffde80:	0x00000000	0x00000000	0xf7e057ed	0x00007fff
0x7fffffffde90:	0xffffdf78	0x00007fff	0xf7fca000	0x00000001
0x7fffffffdea0:	0x555551a7	0x00005555	0xffffe2b9	0x00007fff

