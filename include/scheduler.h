#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

int sched_init();
int sched_vcpu_register();
int sched_vcpu_unregister();
int sched_vcpu_attach();
int sched_vcpu_detach();
int do_schedule();

#endif /* _SCHEDULER_H_ */

