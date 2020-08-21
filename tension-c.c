#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//global variable for pool size
int n = 0;
    
int add();
int roll();
int addroll();
int clear();

int main (void)
{
    //tension pool
    //Print current pool n
    //Print commands:
    //1. Add one to pool
    //2. Roll current pool
    //3. Add one to pool and roll
    
    srand(time(0));
    
    //int to log user choice
    int input = 0;
    do {
        printf("Current Tension Pool: %i\n", n);
        printf("Commands:\n");
        printf("1. Add one die to the pool.\n");
        printf("2. Roll the current pool.\n");
        printf("3. Add one die to the pool and roll it.\n");
        printf("4. Exit\n");
        
        scanf("%d", &input);
        system("cls");
        
        if (input == 1)
        {
            add(n);
        }
        else if (input == 2)
        {
            roll(n);
        }
        else if (input == 3)
        {
            addroll(n);
        } 
    } while (input != 4);
    
    exit(0);
}

//adds one to pool, clears if n = 6
int add (x)
{
    n++;
    //printf("Pool: %i\n", n);
    if (n == 6)
    {
        clear(n);
    }
    return n;
}

//rolls the current pool
int roll (x)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i: %d\n", i+1, (rand() % 6) + 1);
    }
    //printf("%i\n", n);
    return n;
}

//adds one to pool, rolls pool, clears if n = 6
int addroll (x)
{
    n++;
    //printf("Pool: %i\n", n);
    roll(n);
    if (n == 6)
    {
        n = 0;
    }
    return n;
}

//when n = 6 rolls dice and sets n = 0
int clear (x)
{
    roll(n);
    n = 0;
    //printf("Pool: %i", n);
    return n;
}