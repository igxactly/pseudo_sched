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

    /* TODO:(igkang) set field types to abstract types */
    int vcpuid; //vcpuid_t
    int tick; //tick_t
    int tick_reset_val; //tick_t
    enum state_rr state;
};


struct list_head *current = NULL;
struct list_head rq_rr;
struct list_head registered_list_rr;

/* TODO:(igkang) Declare array or some variables to store information
 * e.g. Global_array named rq_entry_pool_rr */
#define MAX_VCPUS 8 /* TODO:(igkang) Replace this macro with project-wide macro */
struct rq_entry_rr rq_entry_pool_rr[MAX_VCPUS];
int pool_front = 0;
int pool_rear = 0;


/* Function definitions goes here */
/* !! Funtions called by primary functions goes here !! */

struct rq_entry_rr *pool_alloc()
{
    if (pool_rear < MAX_VCPUS)
        return &rq_entry_pool_rr[pool_rear++];

    else
        return (struct rq_entry_rr *) NULL;
}

void printall_rr(void)
{
    struct rq_entry_rr *e;
    int cur_vcpuid = -1;

    /* print current running vCPU */
    if (current != NULL) {
        e = list_entry(current, struct rq_entry_rr, head);
        cur_vcpuid = e->vcpuid;
    }
    PRINTH("RR CURRENT: %d\n", cur_vcpuid);

    /* print registered vCPU list */
    PRINTH("RR REG_LIST Entries:");
    list_for_each_entry(e, &registered_list_rr, reg_head) {
        PRINTH(" %d", e->vcpuid);
    }
    PRINTH("\n");

    /* print attached vCPU list */
    PRINTH("RR RUNQUEUE Entries:");
    list_for_each_entry(e, &rq_rr, head) {
        PRINTH(" %d", e->vcpuid);
    }
    PRINTH("\n");
}


/* !! Primary function impmentation goes here !! */

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

    current = NULL;
    INIT_LIST_HEAD(&rq_rr);
    INIT_LIST_HEAD(&registered_list_rr);

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
int sched_rr_vcpu_register(int vcpuid)
{
    struct rq_entry_rr *newent;

    PRINTH("RR_VCPU_REGISTER\n");
    /* Check if vcpu is already registered */


    /* Allocate a rq_entry_rr */
    newent = pool_alloc();

    /* Initialize rq_entry_rr instance */
    INIT_LIST_HEAD(&newent->reg_head);
    INIT_LIST_HEAD(&newent->head);

    /* FIXME: should use function parameter's value for tick_reset_val init. */
    newent->vcpuid = vcpuid;
    newent->tick_reset_val = 5;
    newent->tick = newent->tick_reset_val;

    newent->state = DETACHED;

    /* Add it to registerd vcpus list */
    list_add_tail(&newent->reg_head, &registered_list_rr);

    printall_rr();
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
int sched_rr_vcpu_attach(int vcpuid)
{
    struct rq_entry_rr *entry = NULL;
    struct rq_entry_rr *registered_entry = NULL;

    PRINTH("RR_VCPU_ATTACH\n");
    /* To find entry in registered entry list */
    list_for_each_entry(entry, &registered_list_rr, reg_head) {
        if (entry->vcpuid == vcpuid) {
            PRINTH("Found %d\n", vcpuid);
            registered_entry = entry;
            break;
        }
    }

    if (registered_entry == NULL)
        return -1; /* error: not registered */

    if (registered_entry->state != DETACHED)
        return -2; /* error: already attached */

    /* Set rq_entry_rr's fields */
    registered_entry->state = WAITING;

    /* Add it to runqueue */
    list_add_tail(&registered_entry->head, &rq_rr);

    printall_rr();

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
 * Main scheduler routine in RR policy implmentation
 *
 * @param
 * @return next_vcpuid
 */
int sched_rr_do_schedule()
{
    int will_be_switched = false;
    struct rq_entry_rr *next_ent = NULL;
    int next_vcpuid = -1;

    /* check pending attach list
     *      then attach them to rq_rr */
    /* TODO:(igkang) write code to attach pending attach requests */

    /* TODO:(igkang) improve logical code structure to make it more readable */
    /* determine next vcpu to be run
     *  - if there is an detach-pending vcpu than detach it. */
    if (current == NULL) { /* No vCPU is running */
        if (!list_empty(&rq_rr)) /* and there are some vcpus waiting */
            will_be_switched = true;
    } else { /* There's a vCPU currently running */
        struct rq_entry_rr *cur_ent = NULL;

        /* check & decrease tick. if tick was <= 0 let's switch */
        cur_ent = list_entry(current, struct rq_entry_rr, head);

        /* if tick is still left */
        if (cur_ent->tick) {
            cur_ent->tick -= 1;
        }
        /* tick's over */
        else {
            will_be_switched = true;

            /* reset tick for next scheduling */
            cur_ent->tick = cur_ent->tick_reset_val;

            /* put current entry back to rq_rr */
            cur_ent->state = WAITING;
            list_add_tail(current, &rq_rr);
            current = NULL;
        }
    }

    /* update scheduling-related data (like tick) */
    if (will_be_switched) {
        /* move entry from rq_rr to current */
        current = list_first(&rq_rr);
        list_del_init(current);

        next_ent = list_entry(current, struct rq_entry_rr, head);
        next_ent->tick -= 1;
    }

    /* vcpu of current entry will be the next vcpu */
    if (current != NULL) {
        next_ent = list_entry(current, struct rq_entry_rr, head);
        next_ent->state = RUNNING;

        /* set return next_vcpuid value */
        next_vcpuid = next_ent->vcpuid;
    }

    PRINTH("\n### DO_SCHEDULE_RR\n");
    printall_rr();

    return next_vcpuid;
}

/* TODO:(igkang) assign proper function's address to sched-algo struct */
const struct scheduler sched_rr = {
    .init = sched_rr_init,
    .register_vcpu = sched_rr_vcpu_register,
    .unregister_vcpu = sched_rr_vcpu_unregister,
    .attach_vcpu = sched_rr_vcpu_attach,
    .detach_vcpu = sched_rr_vcpu_detach,
    .do_schedule = sched_rr_do_schedule
};
