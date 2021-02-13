## Coredump

操作系统记录程序的内存状态到Core文件中，这个行为被称为Coredump。Core文件还记录了关键的程序运行状态(寄存器信息(指针、栈)、内存管理信息、操作系统状态和信息等)

### 设置

##### ulimit

`ulimit`命令用来限制系统用户对shell资源的访问(包括所创建的内核文件的大小、进程数据块的大小、Shell 进程所能使用的最大虚拟内存等)。

```shell
ulimit -c #查看设置
ulimit -c unlimited #开启Core Dump功能
```

##### core文件的名称和生成路径

编辑文件

```shell
/proc/sys/kernel/core_uses_pid #core文件是否添加pid扩展名
/proc/sys/kernel/core_pattern  #core文件保存位置和文件名格式
```

core文件默认的存储位置与对应的可执行程序在同一目录下，文件名是core.

### 编译以及调试

用gcc编译文件要加上-g,增加调试信息。执行会产生错误，生成core文件。

执行gdb <program> core来查看错误，如

```shell
gcc -g coredump.cpp -o coredump
gdb coredump core
```

### 常见问题

1. 内存访问越界
   
   1. 数组访问越界
   
   2. 访问不存在的字符串结束符号
   
   3. 使用strcpy, strcat, sprintf, strcmp,strcasecmp等字符串操作函数，将目标字符串读/写爆。应该使用strncpy, strlcpy, strncat, strlcat, snprintf, strncmp, strncasecmp等函数防止读写越界

2. 多线程程序使用了线程不安全的函数。

3. 多线程读写数据未加锁

4. 非法指针

5. 堆栈溢出