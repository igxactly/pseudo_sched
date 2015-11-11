#include <lib/dlist.h>
#include <scheduler_skeleton.h>

/* TODO: Declare array or some variables to store information
 * e.g. Global_array named rq_entry_pool_rr
 */

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




/* TODO: assign proper function's address to sched-algo struct */
const struct scheduler sched_rr ={
    .init = NULL,
    .vcpu_register = NULL,
    .vcpu_unregister = NULL,
    .vcpu_attatch = NULL,
    .vcpu_detach = NULL,
    .do_scheduler = NULL
};
