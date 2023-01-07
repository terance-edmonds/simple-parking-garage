/* car node */

/* node structure */
struct car
{
    char plate_num[PLATE_NUM_SIZE];
    int moves;
};

/* create a new car function */
struct car *createCar(char plate[PLATE_NUM_SIZE], int moves)
{
    /* create a new car structure in memory */
    struct car *new_car;
    new_car = malloc(sizeof(struct car));

    if (new_car == NULL)
    {
        printf("Memory allocation failed");
        return NULL;
    }

    /* assign values */
    strcpy(new_car->plate_num, plate);
    new_car->moves = moves;

    /* return the car node address */
    return new_car;
}