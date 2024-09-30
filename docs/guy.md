Documentation for guy:

For project01, I created a guy.c file that connects to a guy2.c file containing a graphics library for anyone to use.

All of the functions within user.h under guy.c are available for use directly in any program that you would wish.

When starting up FogOS, you will see the first animation of guy, and you can see more by typing guy.info. You can also use ls or rm to see more animations I added in to xv6.

To create this guy library, I had to add a sleep_ms() system call to the kernel, which uses ceiling division to calculate the number of misk rotations in a milisecond, and in turn, sleep for
one milisecond. This is used within each animation, giving the code time to gather each image before printing it out. I also utilized a clear_screen() function, which works the same way as colors do for
this OS.

The animations execute by running sleep, clear screen and print in a loop. If the CPU is struggling or already handling a lot, sleep_ms may lag some, resulting in a less pretty animation.

To fix this, quit other applications on your machine.
