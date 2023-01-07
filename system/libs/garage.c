/* garage circular queue */

/* variables */
struct car *garage[GARAGE_SIZE]; // queue of cars in garage
int garage_front = 0;            // garage queue front position
int garage_rear = 0;             // garage queue back position
int garage_count = 0;            // garage cars count

/* queue is empty function */
int garage_isEmpty()
{
    return (garage_count == 0);
}

/* queue is full function */
int garage_isFull()
{
    return (garage_count == GARAGE_SIZE);
}

/* insert to queue function */
int garage_insert(struct car *car_node)
{
    /* check if the garage is full */
    if (garage_isFull())
    {
        printf("Garage is full\n");
        return -1;
    }
    else
    {
        garage[garage_rear] = car_node; // add new car to the garage queue

        garage_count++;                                // increase garage count by 1
        garage_rear = (garage_rear + 1) % GARAGE_SIZE; // increase garage rear value
    }
}

/* re-arrange queue function */
void garage_rearrange()
{
    struct car *temp_car;

    /* while the garage out is empty move the cars back into the garage */
    while (!garage_out_isEmpty())
    {
        temp_car = garage_out_pop(); // get the front most car from the garage out stack
        garage_insert(temp_car);     // insert the retrieved car to the garage
    };
}

/* check if car is in the queue */
int garage_search(char plate_num[PLATE_NUM_SIZE])
{
    struct car *temp_car;
    int count = 0, index = garage_front;

    while (count < garage_count)
    {
        temp_car = garage[index]; // assign the current indexed car node to temp car node

        /* check if the current car plate number matches the given plate number */
        if (strcmp(temp_car->plate_num, plate_num) == 0)
        {
            return 1;
        }

        index = (index + 1) % GARAGE_SIZE; // increase the index
        count++;                           // increase the count
    }

    return 0;
}

/* search, return, remove and re-arrange the queue */
struct car *garage_search_delete(char plate_num[PLATE_NUM_SIZE])
{
    struct car *temp_car, *selected_car = NULL, *car_node;

    while (garage_count != 0)
    {
        temp_car = garage[garage_front];

        garage_front = (garage_front + 1) % GARAGE_SIZE; // reduce the queue rear value
        garage_count--;                                  // reduce the garage count by 1

        /* check if the current car plate number matches the given plate number */
        if (strcmp(temp_car->plate_num, plate_num) == 0)
        {
            temp_car->moves++;
            selected_car = temp_car; // assign the current car as the selected car
        }
        else
        {
            garage_out_push(temp_car);
        }
    }

    /* if the selected car is not null re-arrange the garage */
    if (selected_car != NULL)
    {
        garage_rearrange();
    }

    return selected_car; // return the searched car
}