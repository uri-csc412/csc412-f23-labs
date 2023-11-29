# Lab 7 - Snake Prep - Assignment 05 Setup
Out Tuesday October 31, 2023

Due Sunday November 7, 2023 11:59 am

### Learning Goals
* Prepare for Assignment 5
* Create your Design Document Early
* Identify Real-World Exampels
* Understand how information is stored in memory
* Become familiar with dynamic memory allocation
* Pass Three Autograder Tests

### Objectives

1. Read the a5.md handout in its entirety. (see EdStem)
2. Complete design.md (i.e., your A5 design doc)
3. Complete examples.md
4. Pass any three autograder tests.

### Some Quick Rules about Snake :)
In A5 and Lab7 you will implement the game Snake in C. The rules of Snake are:
* The playing field is a 2d grid of squares
* The playing field is bordered by walls
* The playing field may have optional internal walls
* The snake is a series of one or more squares
* The player controls the direction of the snake using the arrow keys
* Food appears at random locations within the playing field
  * If the snake's head touches the food, the snake eats it
  * When the snake eats food, another piece of food appears at a different random location

Your task for A5 will be to take the stencil, which does nothing currently, and implement a game with these rules.

The stencil contains several helpful helper functions to get you started. It also contains a complete autograder test suite, see a5.md for more details. 

## Grading

> Do not create any new C or header files for this lab or assignment. 

### Grade Allocation

| Assessment Component			| Percentage  |
| ----------------------------- | ----------- |
| Design Document | 30%
| Read A5 and Identify Difficult Parts | 24%
| Real-World Examples | 16%
| Autograder Unit Tests (pass 3) | 30%

> *** If we find you intentionally hard-coding things to pass these tests we will automatically deduct 30 points from your grade.

### What to Submit

Make sure to run your snake programs and the tests first.

Submit everything inside the labs/lab7 folder to Gradescope. Make sure that includes everything from the stencil and your docs as markdown files this time (design.md and examples.md).
