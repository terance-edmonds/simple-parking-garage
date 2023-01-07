# Simple parking garage application

The laughs parking garage contains a single lane that holds up to ten cars. Cars arrive at the south end of the garage and leave from the orth end. If a customer arrives to pick up a car that is not northernmost, all the cars to the north of his car are moved out, his car is driven ut, and the other cars are restored in the same order that they were in originally.

Whenever a car leaves, all the cars to the south are moved forward. So that at all the times all the empty spaces are in the south part of the garage.

Write a C program to reads a group of input lines. Each line contains an “a” arrival or a “d” departure and a license plate number. Cars are assumed to arrive and depart in the order specified by the input. 

The program should print a message each time that a car arrives or departs. When a car arrives, the massage should specify whether or not there is room for the car in the garage. 

If there is no room for a car, the car waits until there is a room or until a departure line is read for the car. When the room becomes available, another message should be printed. 

When a car departs, the message should include the number of times the car was moved within the garage (including the departure itself but not the arrival), this number is 0 if the car departs from the waiting line.