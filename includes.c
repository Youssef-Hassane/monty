/* Main header file for Monty interpreter */
#include "monty.h"
/* Function to release/free the stack */
#include "Free/release_stack.c"
/* Handles the 'add' operation */
#include "Code_Operatiom/add_operation.c"
/* Handles the 'div' operation */
#include "Code_Operatiom/div_operation.c"
/* Handles the 'mod' operation */
#include "Code_Operatiom/mod_operation.c"
/* Handles the 'mul' operation */
#include "Code_Operatiom/mul_operation.c"
/* Handles the 'nop' operation (no operation) */
#include "Code_Operatiom/nop_operation.c"
/* Handles the 'pall' operation to print all values */
#include "Code_Operatiom/pall_operation.c"
/* Handles the 'pchar' operation to print char value */
#include "Code_Operatiom/pchar_operation.c"
/* Handles the 'pint' operation to print int value */
#include "Code_Operatiom/pint_operation.c"
/* Handles the 'pop' operation to remove top element */
#include "Code_Operatiom/pop_operation.c"
/* Handles the 'pstr' operation to print string */
#include "Code_Operatiom/pstr_operation.c"
/* Handles the 'push' operation to push value */
#include "Code_Operatiom/push_operation.c"
/* Handles the 'queue' operation to toggle stack/queue */
#include "Code_Operatiom/queue_operation.c"
/* Handles the 'rotl' operation to rotate stack left */
#include "Code_Operatiom/rotl_operation.c"
/* Handles the 'rotr' operation to rotate stack right */
#include "Code_Operatiom/rotr_operation.c"
/* Handles the 'stack' operation to toggle stack/queue */
#include "Code_Operatiom/stack_operation.c"
/* Handles the 'sub' operation to subtract top two elements */
#include "Code_Operatiom/sub_operation.c"
/* Handles the 'swap' operation to swap top two elements */
#include "Code_Operatiom/swap_operation.c"
/* Utility functions for adding nodes */
/* Function to add node to queue */
#include "Add/AddNodeToQueue.c"
/* Function to add to a node */
#include "Add/addToNode.c"
/* Function to select the appropriate operation */
#include "Select_Function/select_Function.c"
