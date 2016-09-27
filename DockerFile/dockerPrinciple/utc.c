//
// Created by ubuntu on 16-9-27.
//

/*************************************************************************
	> File Name: uts.c
	> Author:
	> Mail:
	> Created Time: 2016年09月27日 星期二 08时06分11秒
 ************************************************************************/

#define _GNU_SOURCE

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];
char *const child_args[] = {
        "/bin/bash",
        NULL
};

int child_main(void *args) {
    printf("在子进程中");
    sethostname("NewHostName", 12);
    execv(child_args[0], child_args);
    return 1;
}

int main() {
    printf("程序开始:\n");
    int child_pid = clone(child_main, child_stack + STACK_SIZE, SIGCHLD, CLONE_NEWUTS | SIGCHLD, NULL);
    waitpid(child_pid, NULL, 0);
    printf("已退出\n");
    return 0;
}


