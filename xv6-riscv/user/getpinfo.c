#include "kernel/pstat.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void main(){
    struct pstat ps;
    getpinfo(&ps);
    for(int i = 0; i<NPROC; i++){
	if (ps.inuse[i])
        printf("pid: %d, runtime: %d\n, stride lenght: %d\n", ps.pid[i], ps.runtime[i], ps.stride[i]);
    }
    printf("passTotal: %d\n", ps.passTotal); //new: added so that it can print out passTotal for user space.
}