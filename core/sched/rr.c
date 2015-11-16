#include <lib/fakedefs.h>

#include <lib/dlist.h>
#include <scheduler_skeleton.h>

typedef enum state_rr {
    DETACHED,
    WAITING,
    RUNNING
} state_rr;

struct rq_entry_rr {
    struct list_head head;

    struct list_head reg_head;
    
    /* TODO: set field types to abstract types */
    int vcpuid; //vcpuid_t
    int tick; //tick_t
    int tick_reset_val; //tick_t
    enum state_rr state;
};

/* TODO: Declare array or some variables to store information
 * e.g. Global_array named rq_entry_pool_rr */

#define MAX_VCPUS 8 /* TODO: Replace this macro with project-wide macro */
struct list_head rq_rr;
struct list_head registered_list_rr;

struct rq_entry_rr rq_entry_pool_rr[MAX_VCPUS];
int pool_front = 0;
int pool_rear = 0;

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
    pool_front = 0;
    pool_rear = 0;
    
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
    /* Check if vcpu is already registered */

    /* Allocate a rq_entry_rr */

    /* Initialize rq_entry_rr instance */

    /* Add it to registerd list */

    return 0; 
}

/**
 * Unregister a vCPU from a scheduler
 *
 * Better NOT to use vcpu_unregister until \
 * dynamic allocation is applied
 *
 * @param shed A scheduler definition
 * @param vcpu A vCPU
 * @return
 */
int sched_rr_vcpu_unregister()
{
    /* Check if vcpu is registered */

    /* Check if vcpu is detached. If not, request detachment.*/

    /* If we have requested detachment of vcpu,
     *   let's wait until it is detached by main scheduling routine */

    /* Remove it from registered list */

    /* Deallocate rq_entry_rr */
    /* FIXME: Deallocation will cause problem as  we are using
     *   array-base pool for now. Dynamic allocation fucntion
     *   is needed. Better NOT to use vcpu_unregister until
     *   this problem is fixed*/

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
    /* Check if vcpu is already attached */

    /* Set rq_entry_rr's fields */

    /* Add it to runqueue */

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
    /* Check if vcpu is attached */

    /* Remove it from runqueue by setting will_detached flag*/

    /* Set rq_entry_rr's fields */

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
    /* determine next vcpu to be run */

    /* update scheduling-related data (like tick) */

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
