/* out of the garage stack */

/* variables */
struct car *garage_out[GARAGE_OUT_SIZE]; // stack of cars in garage
int garage_out_top = -1;                 // garage out stack top value

/* stack is empty function */
int garage_out_isEmpty()
{
    return garage_out_top == -1;
}

/* stack is full function */
int garage_out_isFull()
{
    return garage_out_top == (GARAGE_OUT_SIZE - 1);
}

/* push to garage out stack function */
int garage_out_push(struct car *car_node)
{
    /* check if the garage out is full */
    if (garage_out_isFull())
    {
        return -1;
    }
    else
    {
        /* increase the car moves by 1 */
        car_node->moves++;
        /* push the car node into the garage out stack and increase the garage out top value by 1 */
        garage_out[++garage_out_top] = car_node;
    }
}

/* pop from garage out stack function */
struct car *garage_out_pop()
{
    struct car *temp_car = NULL;

    /* check if the garage out is empty */
    if (!garage_out_isEmpty())
    {
        /* remove the car node from the garage out stack and decrease garage out top value by 1 */
        temp_car = garage_out[garage_out_top--];
        /* increase the car moves by 1 */
        temp_car->moves++;
    }

    return temp_car; // return the top most car node of the stack
}