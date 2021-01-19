# POSIX Thread

C\C++的多线程编程常用库. (虽然C11有线程库，but还是有很多老古董不用🤡，C++11后有thread库).

本文档参考https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html.

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

```c
   pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
   pthread_mutex_lock( &mutex1 );
   counter++;
   pthread_mutex_unlock( &mutex1 );
```

### Join

```c
pthread_create( &thread_id, NULL, thread_function, NULL );
// 等待thread_id线程结束
pthread_join( thread_id, NULL); 
```

### 条件变量(Wait&Signal)

```C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;

void *functionCount1();
void *functionCount2();
int  count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

main()
{
   pthread_t thread1, thread2;

   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   exit(0);
}
void *functionCount1()
{
   for(;;)
   {
      pthread_mutex_lock( &condition_mutex );
      while( count >= COUNT_HALT1 && count <= COUNT_HALT2 )
      {
         pthread_cond_wait( &condition_cond, &condition_mutex );
      }
      pthread_mutex_unlock( &condition_mutex );

      pthread_mutex_lock( &count_mutex );
      count++;
      printf("Counter value functionCount1: %d\n",count);
      pthread_mutex_unlock( &count_mutex );

      if(count >= COUNT_DONE) return(NULL);
    }
}
void *functionCount2()
{
    for(;;)
    {
       pthread_mutex_lock( &condition_mutex );
       if( count < COUNT_HALT1 || count > COUNT_HALT2 )
       {
          pthread_cond_signal( &condition_cond );
       }
       pthread_mutex_unlock( &condition_mutex );

       pthread_mutex_lock( &count_mutex );
       count++;
       printf("Counter value functionCount2: %d\n",count);
       pthread_mutex_unlock( &count_mutex );

       if(count >= COUNT_DONE) return(NULL);
    }
}
```

输出(除了count=3到6时为线程2，其他都是不确定的):

```c
Counter value functionCount1: 1
Counter value functionCount1: 2
Counter value functionCount1: 3
Counter value functionCount2: 4
Counter value functionCount2: 5
Counter value functionCount2: 6
Counter value functionCount2: 7
Counter value functionCount1: 8
Counter value functionCount1: 9
Counter value functionCount1: 10
Counter value functionCount2: 11
```

## 线程调度(Thread Scheduling)

## 线程陷阱(Thread Pitfalls)