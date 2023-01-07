/* laugh car garage arrival and departure recording system. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./libs/define_variables.c" // import defined variables
#include "./libs/car_node.c"         // import car node structure
#include "./libs/waiting_line.c"     // import waiting line linked list
#include "./libs/garage_out.c"       // import garage out stack
#include "./libs/garage.c"           // import garage circular queue

/* display car details function */
void display_car(struct car *car_node)
{
    printf("Departure car details:\n");
    printf("Car licence plate number: %s\n", car_node->plate_num);
    printf("Number of moves within the garage: %d\n", car_node->moves);
    printf("\n");
}

int main()
{
    // initiate variables
    char option, plate_num[PLATE_NUM_SIZE];
    struct car *temp_car;

    printf("===============");
    printf(" GARAGE SYSTEM ");
    printf("===============");
    printf("\n\n");

    printf("Options:\n");
    printf("a: arrival\n");
    printf("b: departure\n");
    printf("any other character to exit\n");
    printf("\n");

    /* get user input until the operation is not arrival or departure */
    do
    {
        /* get option (arrival or departure) from user */
        printf("Enter option: ");
        scanf("%c%*c", &option);

        if (option != 'a' && option != 'd')
        {
            exit(0);
        }

        /* check if the garage is full */
        if (option == 'a' && garage_isFull())
        {
            printf("Garage is full. Please wait in the line\n\n");
        }

        /* get plate number from user */
        printf("Enter plate number: ");
        scanf("%s%*c", &plate_num);
        printf("\n");

        /* check the option is arrival */
        if (option == 'a')
        {
            /* check if the car is in the waiting line */
            if (waiting_line_search(plate_num) == 1)
            {
                temp_car = waiting_line_search_remove(plate_num); // get car details
            }
            else
            {
                /* create a car with the plate number */
                temp_car = createCar(plate_num, 0);
            }

            /* check if the garage is full */
            if (garage_isFull())
            {
                /* add the car to the waiting line */
                waiting_line_add_end(temp_car);
            }
            else
            {
                /* add the car to the garage */
                garage_insert(temp_car);
            }
        }
        else
        {
            /* check if the car is in garage */
            if (garage_search(plate_num) == 1)
            {
                temp_car = garage_search_delete(plate_num); // get car details
                display_car(temp_car);                      // display car details

                /* free the memory slot */
                if (temp_car != NULL)
                {
                    free(temp_car);
                }

                /* check and print if there is only one empty space after removing a car */
                if (garage_count == (GARAGE_SIZE - 1))
                {
                    printf("Garage has an available space\n\n");
                }
            }
            /* check if the car is in waiting line */
            else if (waiting_line_search(plate_num) == 1)
            {
                temp_car = waiting_line_search_remove(plate_num); // get car details
                display_car(temp_car);                            // display car details
                free(temp_car);                                   // free the memory slot
            }
            else
            {
                printf("The car with plate number '%s' is not registered in the system\n\n", plate_num);
            }
        }

    } while (option == 'a' || option == 'd');

    return 0;
}