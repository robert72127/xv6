#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fs.h"


int thread_create(void (*fcnt)(void *, void *), void *arg1, void *arg2){
    void *stack = malloc(4096);
    return clone(fcnt, arg1,arg2, stack);
}
int thread_join(){
    void *stack;
    int pid;

    pid = join(&stack);
    free(stack);

    return pid;
}