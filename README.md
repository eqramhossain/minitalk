# Minitalk

Hello World!
Before starting reading this article about Minitalk you should have a minimum idea about what is a process and signal in unix like operating system. I will be explaining the functions that you need to learn to do this project let's go.

## getpid - get process ID

This function is in the `#include <unistd.h>` library here is a quick look
```C
pid_t getpid(void);
```

Definition:
The function returns a integer value of type pid_t and does not take any arguments. The return value is the process ID of the current process where the function is being called.

Error:
This function is always successful.

Example:
```C
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("pid = %d\n", pid);
	return (0);
}
```

Output:
```C
➜  minitalk ./getpid
pid = 45194

```

## sleep - sleep for a number of seconds

This function make sleep your program. This function is also find in the `#include <unistd.h>` library. 

Prototype:
```C
unsigned int sleep(unsigned int seconds);
```

Definition:
This function sleep your program for the `seconds` amount of time. This function is as simple as water. If you want to go in details you can do you own research i will not go into that.

Example:
```C
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		sleep(i);
		printf("sleeping for %d sec\n", i);
		i++;
	}
	return (0);
}
```

Output: 
```C
➜  minitalk ./sleep
sleeping for 0 sec
sleeping for 1 sec
sleeping for 2 sec
sleeping for 3 sec
sleeping for 4 sec
sleeping for 5 sec

```

## usleep - sleep for a number of microseconds

This function is almost same as the `sleep` function. The difference is instead of sleeping your program for seconds it sleeps the program for micro seconds. This is also found in the `#include <unistd.h>` library.

Prototype:
```C
unsigned int sleep(unsigned int seconds);
```

Example:

💡info 
`1000000` microseconds is equal to `1` seconds.

```C
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;

	i = 1000000;
	// 1000000 micoseconds == 1 seconds
	while (i <= 5000000)
	{
		usleep(i);
		printf("sleeping for %d microsecond\n", i);
		i = i + 1000000;
	}
	return (0);
}
```

Output:
```C
➜  minitalk ./usleep
sleeping for 1000000 microsecond
sleeping for 2000000 microsecond
sleeping for 3000000 microsecond
sleeping for 4000000 microsecond
sleeping for 5000000 microsecond

```

## pause - wait for signal
This function pause the program until a signal is received. It does not take any parameter it is also found in the `#include <unistd.h>`. This function is usful for the sever. As the sever starts up it prints it's PID and the we `pause` until a signal is received.

Prototype:
```C
int pause(void);
```

Example:
```C
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid <= 0)
	{
		printf("PID Error\n");
		return (1);
	}
	printf("Current porcess PID = %d\n", pid);
	printf("Waiting for Signal\n");
	while (1)
		pause();
	return (0);
}
```

Output:
```C
➜  minitalk ./pause
Current porcess PID = 45230
Waiting for Signal

```

## kill - send signal to a process

This function sounds like its dangerous trust me it is not how its sound like.

💡info 
There is actually 2 kill we need to learn one of them is a shell command the other is a function found in the library `#include <signal.h>`

I will be explaining the `kill` function that we will be using in out program. The `kill()` function send signal to any process. It takes 2 things a parameter the `pid` of the process and the signal to be send.

Prototype:
```C
int kill(pid_t pid, int sig);
```

Example:
Remember the `./pause` program above that we did for waiting for a signal. We are going to use the `./pause` program here for this example.
Imagine we are waiting for a signal in the `./pause` program and we will do a program that will send a signal to the process that will terminated the `./pause` program.

```C
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	(void)ac;
	kill(atoi(av[1]), 9);
	return (0);
}
```

Output:

```C
➜  minitalk ./kill 45239

--------------------------------
➜  minitalk ./pause
Current porcess PID = 45239
Waiting for Signal
[1]    45239 killed     ./pause
--------------------------------
```

## signal()
## sigemptyset()
## sigaddset()
## sigaction()
