#include <lib/dlist.h>

#include <scheduler_skeleton.h>
#include <scheduler.h>

/**
 * Scheduler related data initialization
 *
 * @param
 * @return
 */
int sched_init()
{
    /* Check scheduler config */

    /* Allocate memory for system-wide data */

    /* Initialize data */
    // call sched_policy.init() for each policy implementation

    return 0;
}

/**
 * Register a vCPU to a scheduler
 *
 * You have to call sched_vcpu_attach() to \
 * run a vcpu by adding it to runqueue, additionally.
 *
 * @param shed A scheduler definition
 * @param vcpuid ID of vCPU
 * @return
 */
int sched_vcpu_register()
{
    /* call scheduler.register_vcpu() */

    return 0;
}

/**
 * Unregister a vCPU from a scheduler
 *
 * You have to detach vcpu first.
 *
 * @param shed A scheduler definition
 * @param vcpuid ID of vCPU
 * @return
 */
int sched_vcpu_unregister()
{
    /* call scheduler.unregister_vcpu() */

    return 0;
}

/**
 * Attach a vcpu from scheduler runqueue
 *
 * You have to register the vcpu first
 *
 * @param shed A scheduler definition
 * @param vcpuid ID of vCPU
 * @return
 */
int sched_vcpu_attach()
{
    /* call scheduler.attach_vcpu() */

    return 0;
}

/**
 * Detach a vcpu from scheduler runqueue
 *
 * @param shed A scheduler definition
 * @param vcpuid ID of vCPU
 * @return
 */
int sched_vcpu_detach()
{
    /* call scheduler.detach_vcpu() */

    return 0;
}

/**
 * Main scheduler routine
 *
 * @param
 * @return
 */
int do_schedule()
{
    /* determine next vcpu to be run
     * by calling scheduler.do_schedule() */

    /* update vCPU's running time */

    /* manipulate variables to
     * cause context switch */

    return 0;
}
