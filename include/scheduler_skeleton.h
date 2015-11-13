#ifndef _SCHEDULER_SKELETON_H_
#define _SCHEDULER_SKELETON_H_

#include <stddef.h>

struct scheduler {
    unsigned int sched_id;

    int (*init)(void);
    int (*register_vcpu)(void);
    int (*unregister_vcpu)(void);
    int (*attatch_vcpu)(void);
    int (*detach_vcpu)(void);
    int (*do_scheduler)(void);
};

extern const struct sched_rr;

#endif /* _SCHEDULER_SKELETON_H_ */
