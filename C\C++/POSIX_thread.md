# POSIX Thread

C\C++的多线程编程常用库. (虽然C11有线程库，but还是有很多老古董不用🤡，C++11后有thread库).

## 基础

- 线程操作包括线程创建，终止，同步(link,block)，调度，数据管理和进程间通信. 
- 线程间共享
  - 堆: 初始化进程时分配给进程的内存，运行过程也可以向系统申请额外的堆.
  - 代码区: 保存二进制可执行代码
  - 静态(全局)区
  - 常量区
- 线程间独有
  - 栈: 保存线程的运行状态和局部变量。
  - 寄存器:  对应线程的栈和线程的栈的指针，从一个线程切换到另一个线程时，会保存原有的线程的寄存器集合的状态.
  - 线程ID
  - 优先级
  - 信号屏蔽码: 每个线程所感兴趣的信号不同，所以线程的信号屏蔽码应该由线程自己管理。但所有的线程都共享同样的信号处理器。
  - 错误返回码: 不同的线程有自己的错误返回码变量。

## 线程创建和销毁(Thread Creation and Termination)

```C
    int pthread_create(pthread_t * thread, 
                       const pthread_attr_t * attr,
                       void * (*start_routine)(void *), 
                       void *arg);
	// retval - Return value of thread.
	void pthread_exit(void *retval);
```

## 线程同步(Thread Synchronization)

线程同步有三种实现方式:

- 互斥锁(mutex)
- Join
- 条件变量(wait && signal)

### Mutex