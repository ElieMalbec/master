
a.out:     format de fichier elf64-x86-64


Déassemblage de la section .init :

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	repz nop %edx
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <_DYNAMIC+0x1f0>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Déassemblage de la section .plt :

0000000000001020 <puts@plt-0x10>:
    1020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <puts@plt>:
    1030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 4018 <_GLOBAL_OFFSET_TABLE_+0x18>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <_init+0x20>

0000000000001040 <printf@plt>:
    1040:	ff 25 da 2f 00 00    	jmpq   *0x2fda(%rip)        # 4020 <_GLOBAL_OFFSET_TABLE_+0x20>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <_init+0x20>

0000000000001050 <fgets@plt>:
    1050:	ff 25 d2 2f 00 00    	jmpq   *0x2fd2(%rip)        # 4028 <_GLOBAL_OFFSET_TABLE_+0x28>
    1056:	68 02 00 00 00       	pushq  $0x2
    105b:	e9 c0 ff ff ff       	jmpq   1020 <_init+0x20>

0000000000001060 <malloc@plt>:
    1060:	ff 25 ca 2f 00 00    	jmpq   *0x2fca(%rip)        # 4030 <_GLOBAL_OFFSET_TABLE_+0x30>
    1066:	68 03 00 00 00       	pushq  $0x3
    106b:	e9 b0 ff ff ff       	jmpq   1020 <_init+0x20>

Déassemblage de la section .text :

0000000000001070 <_start>:
    1070:	f3 0f 1e fa          	repz nop %edx
    1074:	31 ed                	xor    %ebp,%ebp
    1076:	49 89 d1             	mov    %rdx,%r9
    1079:	5e                   	pop    %rsi
    107a:	48 89 e2             	mov    %rsp,%rdx
    107d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1081:	50                   	push   %rax
    1082:	54                   	push   %rsp
    1083:	4c 8d 05 06 02 00 00 	lea    0x206(%rip),%r8        # 1290 <__libc_csu_fini>
    108a:	48 8d 0d 8f 01 00 00 	lea    0x18f(%rip),%rcx        # 1220 <__libc_csu_init>
    1091:	48 8d 3d 68 01 00 00 	lea    0x168(%rip),%rdi        # 1200 <main>
    1098:	ff 15 42 2f 00 00    	callq  *0x2f42(%rip)        # 3fe0 <_DYNAMIC+0x1e8>
    109e:	f4                   	hlt    
    109f:	90                   	nop

00000000000010a0 <deregister_tm_clones>:
    10a0:	48 8d 3d a1 2f 00 00 	lea    0x2fa1(%rip),%rdi        # 4048 <__TMC_END__>
    10a7:	48 8d 05 9a 2f 00 00 	lea    0x2f9a(%rip),%rax        # 4048 <__TMC_END__>
    10ae:	48 39 f8             	cmp    %rdi,%rax
    10b1:	74 15                	je     10c8 <deregister_tm_clones+0x28>
    10b3:	48 8b 05 1e 2f 00 00 	mov    0x2f1e(%rip),%rax        # 3fd8 <_DYNAMIC+0x1e0>
    10ba:	48 85 c0             	test   %rax,%rax
    10bd:	74 09                	je     10c8 <deregister_tm_clones+0x28>
    10bf:	ff e0                	jmpq   *%rax
    10c1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10c8:	c3                   	retq   
    10c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010d0 <register_tm_clones>:
    10d0:	48 8d 3d 71 2f 00 00 	lea    0x2f71(%rip),%rdi        # 4048 <__TMC_END__>
    10d7:	48 8d 35 6a 2f 00 00 	lea    0x2f6a(%rip),%rsi        # 4048 <__TMC_END__>
    10de:	48 29 fe             	sub    %rdi,%rsi
    10e1:	48 89 f0             	mov    %rsi,%rax
    10e4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10e8:	48 c1 f8 03          	sar    $0x3,%rax
    10ec:	48 01 c6             	add    %rax,%rsi
    10ef:	48 d1 fe             	sar    %rsi
    10f2:	74 14                	je     1108 <register_tm_clones+0x38>
    10f4:	48 8b 05 f5 2e 00 00 	mov    0x2ef5(%rip),%rax        # 3ff0 <_DYNAMIC+0x1f8>
    10fb:	48 85 c0             	test   %rax,%rax
    10fe:	74 08                	je     1108 <register_tm_clones+0x38>
    1100:	ff e0                	jmpq   *%rax
    1102:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1108:	c3                   	retq   
    1109:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001110 <__do_global_dtors_aux>:
    1110:	f3 0f 1e fa          	repz nop %edx
    1114:	80 3d 3d 2f 00 00 00 	cmpb   $0x0,0x2f3d(%rip)        # 4058 <completed.0>
    111b:	75 33                	jne    1150 <__do_global_dtors_aux+0x40>
    111d:	55                   	push   %rbp
    111e:	48 83 3d d2 2e 00 00 	cmpq   $0x0,0x2ed2(%rip)        # 3ff8 <_DYNAMIC+0x200>
    1125:	00 
    1126:	48 89 e5             	mov    %rsp,%rbp
    1129:	74 0d                	je     1138 <__do_global_dtors_aux+0x28>
    112b:	48 8b 3d 0e 2f 00 00 	mov    0x2f0e(%rip),%rdi        # 4040 <__dso_handle>
    1132:	ff 15 c0 2e 00 00    	callq  *0x2ec0(%rip)        # 3ff8 <_DYNAMIC+0x200>
    1138:	e8 63 ff ff ff       	callq  10a0 <deregister_tm_clones>
    113d:	c6 05 14 2f 00 00 01 	movb   $0x1,0x2f14(%rip)        # 4058 <completed.0>
    1144:	5d                   	pop    %rbp
    1145:	c3                   	retq   
    1146:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    114d:	00 00 00 
    1150:	c3                   	retq   
    1151:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    1158:	00 00 00 00 
    115c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	repz nop %edx
    1164:	e9 67 ff ff ff       	jmpq   10d0 <register_tm_clones>

0000000000001169 <login>:
    1169:	55                   	push   %rbp
    116a:	48 89 e5             	mov    %rsp,%rbp
    116d:	48 83 ec 10          	sub    $0x10,%rsp
    1171:	48 8d 3d 8c 0e 00 00 	lea    0xe8c(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1178:	b8 00 00 00 00       	mov    $0x0,%eax
    117d:	e8 be fe ff ff       	callq  1040 <printf@plt>
    1182:	bf 10 00 00 00       	mov    $0x10,%edi
    1187:	e8 d4 fe ff ff       	callq  1060 <malloc@plt>
    118c:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1190:	bf 08 00 00 00       	mov    $0x8,%edi
    1195:	e8 c6 fe ff ff       	callq  1060 <malloc@plt>
    119a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    119e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11a2:	c7 00 01 00 00 00    	movl   $0x1,(%rax)
    11a8:	48 8b 15 a1 2e 00 00 	mov    0x2ea1(%rip),%rdx        # 4050 <stdin@@GLIBC_2.2.5>
    11af:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    11b3:	be a0 00 00 00       	mov    $0xa0,%esi
    11b8:	48 89 c7             	mov    %rax,%rdi
    11bb:	e8 90 fe ff ff       	callq  1050 <fgets@plt>
    11c0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11c4:	8b 00                	mov    (%rax),%eax
    11c6:	89 c6                	mov    %eax,%esi
    11c8:	48 8d 3d 46 0e 00 00 	lea    0xe46(%rip),%rdi        # 2015 <_IO_stdin_used+0x15>
    11cf:	b8 00 00 00 00       	mov    $0x0,%eax
    11d4:	e8 67 fe ff ff       	callq  1040 <printf@plt>
    11d9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11dd:	8b 00                	mov    (%rax),%eax
    11df:	85 c0                	test   %eax,%eax
    11e1:	75 0e                	jne    11f1 <login+0x88>
    11e3:	48 8d 3d 34 0e 00 00 	lea    0xe34(%rip),%rdi        # 201e <_IO_stdin_used+0x1e>
    11ea:	e8 41 fe ff ff       	callq  1030 <puts@plt>
    11ef:	eb 0c                	jmp    11fd <login+0x94>
    11f1:	48 8d 3d 41 0e 00 00 	lea    0xe41(%rip),%rdi        # 2039 <_IO_stdin_used+0x39>
    11f8:	e8 33 fe ff ff       	callq  1030 <puts@plt>
    11fd:	90                   	nop
    11fe:	c9                   	leaveq 
    11ff:	c3                   	retq   

0000000000001200 <main>:
    1200:	55                   	push   %rbp
    1201:	48 89 e5             	mov    %rsp,%rbp
    1204:	b8 00 00 00 00       	mov    $0x0,%eax
    1209:	e8 5b ff ff ff       	callq  1169 <login>
    120e:	b8 00 00 00 00       	mov    $0x0,%eax
    1213:	5d                   	pop    %rbp
    1214:	c3                   	retq   
    1215:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    121c:	00 00 00 
    121f:	90                   	nop

0000000000001220 <__libc_csu_init>:
    1220:	f3 0f 1e fa          	repz nop %edx
    1224:	41 57                	push   %r15
    1226:	4c 8d 3d bb 2b 00 00 	lea    0x2bbb(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    122d:	41 56                	push   %r14
    122f:	49 89 d6             	mov    %rdx,%r14
    1232:	41 55                	push   %r13
    1234:	49 89 f5             	mov    %rsi,%r13
    1237:	41 54                	push   %r12
    1239:	41 89 fc             	mov    %edi,%r12d
    123c:	55                   	push   %rbp
    123d:	48 8d 2d ac 2b 00 00 	lea    0x2bac(%rip),%rbp        # 3df0 <__init_array_end>
    1244:	53                   	push   %rbx
    1245:	4c 29 fd             	sub    %r15,%rbp
    1248:	48 83 ec 08          	sub    $0x8,%rsp
    124c:	e8 af fd ff ff       	callq  1000 <_init>
    1251:	48 c1 fd 03          	sar    $0x3,%rbp
    1255:	74 1f                	je     1276 <__libc_csu_init+0x56>
    1257:	31 db                	xor    %ebx,%ebx
    1259:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1260:	4c 89 f2             	mov    %r14,%rdx
    1263:	4c 89 ee             	mov    %r13,%rsi
    1266:	44 89 e7             	mov    %r12d,%edi
    1269:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    126d:	48 83 c3 01          	add    $0x1,%rbx
    1271:	48 39 dd             	cmp    %rbx,%rbp
    1274:	75 ea                	jne    1260 <__libc_csu_init+0x40>
    1276:	48 83 c4 08          	add    $0x8,%rsp
    127a:	5b                   	pop    %rbx
    127b:	5d                   	pop    %rbp
    127c:	41 5c                	pop    %r12
    127e:	41 5d                	pop    %r13
    1280:	41 5e                	pop    %r14
    1282:	41 5f                	pop    %r15
    1284:	c3                   	retq   
    1285:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    128c:	00 00 00 00 

0000000000001290 <__libc_csu_fini>:
    1290:	f3 0f 1e fa          	repz nop %edx
    1294:	c3                   	retq   

Déassemblage de la section .fini :

0000000000001298 <_fini>:
    1298:	f3 0f 1e fa          	repz nop %edx
    129c:	48 83 ec 08          	sub    $0x8,%rsp
    12a0:	48 83 c4 08          	add    $0x8,%rsp
    12a4:	c3                   	retq   
