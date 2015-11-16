#include <lib/fakedefs.h>
#include <scheduler.h>

int main() {
    printf("Hello World!\n");
        
    sched_init();
    sched_vcpu_register();
    sched_vcpu_unregister();
    sched_vcpu_attach();
    sched_vcpu_detach();
    do_schedule();

    printf("Bye World!\n");

    return 0;
}
