#ifndef _SCHEDULER_SKELETON_H_
#define _SCHEDULER_SKELETON_H_

#include <stddef.h>

struct scheduler {
    unsigned int sched_id;
    
    int (*init)(void);
    int (*vcpu_register)(void);
    int (*vcpu_unregister)(void);
    int (*vcpu_attatch)(void);
    int (*vcpu_detach)(void);
    int (*do_scheduler)(void);
};

#endif /* _SCHEDULER_SKELETON_H_ */

