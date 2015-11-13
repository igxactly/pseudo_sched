#include <lib/dlist.h>
#include <scheduler_skeleton.h>

/* TODO: Declare array or some variables to store information
 * e.g. Global_array named rq_entry_pool_rr */

typedef enum state_rr {
    DETACHED,
    WAITING,
    RUNNING
} state_rr;

struct rq_entry_rr {
    struct list_head head;
    
    /* TODO: set field types to abstract types */
    int vcpuid; //vcpuid_t
    int tick; //tick_t
    int tick_reset_val; //tick_t
    enum state_rr state;
};

/* Function definitions goes here */

/**
 * Scheduler related data initialization
 *
 * @param
 * @return
 */
int sched_rr_init()
{
    /* Check scheduler config */

    /* Allocate memory for system-wide data */

    /* Initialize data */
    // call sched_policy.init()

    return 0;
}

/**
 * Register a vCPU to a scheduler
 *
 * You have to call sched_vcpu_attach() to \
 * run a vcpu by adding it to runqueue, additionally.
 *
 * @param shed A scheduler definition
 * @param vcpu A vCPU
 * @return
 */
int sched_rr_vcpu_register()
{
    /* call scheduler.register_vcpu() */

    return 0; 
}

/**
 * Unregister a vCPU from a scheduler
 *
 * @param shed A scheduler definition
 * @param vcpu A vCPU
 * @return
 */
int sched_rr_vcpu_unregister()
{
    /* call scheduler.unregister_vcpu() */

    return 0; 
}

/**
 * 
 *
 * @param
 * @return
 */
int sched_rr_vcpu_attach()
{
    /* call scheduler.attach_vcpu() */

    return 0; 
}

/**
 * 
 *
 * @param
 * @return
 */
int sched_rr_vcpu_detach()
{
    /* call scheduler.detach_vcpu() */

    return 0; 
}

/**
 * 
 *
 * @param
 * @return
 */
int sched_rr_do_schedule()
{
    /* determine next vcpu to be run 
     * by calling scheduler.do_schedule() */

    /* update vCPU's running time */

    /* manipulate variables to
     * cause context switch */

    return 0; 
}

/* TODO: assign proper function's address to sched-algo struct */
const struct scheduler sched_rr ={
    .init = sched_rr_init,
    .register_vcpu = sched_rr_vcpu_register,
    .unregister_vcpu = sched_rr_vcpu_unregister,
    .attatch_vcpu = sched_rr_vcpu_attach,
    .detach_vcpu = sched_rr_vcpu_detach,
    .do_scheduler = sched_rr_do_schedule
};
