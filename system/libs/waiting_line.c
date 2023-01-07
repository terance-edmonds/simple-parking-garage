/* waiting line linked list */

/* waiting line node */
struct node
{
    struct car *data;
    struct node *next;
};

/* variables */
struct node *waiting_line_start = NULL; // start value of the linked list

/* fix the link in linked list function */
void waiting_line_rearrange(struct node *pre_ptr, struct node *ptr)
{
    /* check if the pre pointer is empty */
    if (pre_ptr == NULL)
    {
        waiting_line_start = NULL;
    }
    else
    {
        /* assign the ptr (next node of the removing node) value as the next node of the pre_ptr */
        pre_ptr->next = ptr;
    }
}

/* linked list add to end function */
int waiting_line_add_end(struct car *car_node)
{
    struct node *ptr;
    struct node *temp_node;
    ptr = waiting_line_start;

    temp_node = malloc(sizeof(struct node));

    /* create a new linked list node with car details */
    temp_node->data = car_node;
    temp_node->next = NULL;

    /* check if start value is null */
    if (waiting_line_start == NULL)
    {
        /* assign the new linked list node as the start of the linked list node */
        waiting_line_start = temp_node;
    }
    else
    {
        /* loop until its the last node of the linked list */
        while (ptr->next != NULL)
        {
            /* assign the linked list next node to ptr */
            ptr = ptr->next;
        }

        /* assign the new node as the next node of the last node of the linked list */
        ptr->next = temp_node;
    }
}

/* check if car is in the linked list */
int waiting_line_search(char plate_num[PLATE_NUM_SIZE])
{
    struct node *ptr;
    struct car *temp_car;
    ptr = waiting_line_start;

    /* loop until the last node */
    while (ptr != NULL)
    {
        /* assign the current linked list node car details to temp_car node */
        temp_car = ptr->data;

        /* check if the current car plate number matches the given plate number */
        if (strcmp(temp_car->plate_num, plate_num) == 0)
        {
            return 1;
        }

        /* assign the linked list next node to ptr */
        ptr = ptr->next;
    }

    return 0;
}

/* search, return, remove and re-arrange the linked list */
struct car *waiting_line_search_remove(char plate_num[PLATE_NUM_SIZE])
{
    struct node *ptr;
    struct node *pre_ptr;
    struct car *temp_car;
    pre_ptr = NULL;
    ptr = waiting_line_start;

    /* loop until the last node */
    while (ptr != NULL)
    {
        /* assign the current linked list node car details to temp_car node */
        temp_car = ptr->data;

        /* check if the current car plate number matches the given plate number */
        if (strcmp(temp_car->plate_num, plate_num) == 0)
        {
            waiting_line_rearrange(pre_ptr, ptr->next); // fix the link in linked list
            free(ptr);                                  // free the removing node memory
            return temp_car;                            // return the car node
        }

        /* assign the current linked list node to pre_ptr */
        pre_ptr = ptr;
        /* assign the next linked list node to ptr */
        ptr = ptr->next;
    }

    return NULL;
}