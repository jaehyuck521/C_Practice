// author: 201533667 ¿Â¿Á«ı date: 2021-12-01
// this program is queue practice by using array[10] we can select menu and choose the menu and execute functions enque, dequeue, 
// So 4 functions are executing in main queue_full, queue_empty, enqueue, dequeue
#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
int back = -1;
int front = -1;
int queue[10];
// Declare functions

void enqueue(int);
int dequeue();
int queue_full();
int queue_empty();

void main()
{
    int sel=0;
    int data;
    int run = 1;
    // set the menu
    while (run)
    {
        printf("1.Enqueue 2. Dequeue 3.end\n");
        scanf("%d", &sel);
        if (sel == 1)
        {
            if (queue_full() == 1) // defensive coding
            {
                printf("full queue");
                printf("\n");
            }
            else
            {
                scanf("%d", &data);
                enqueue(data);
            }
        }
        if (sel == 2)
        {
            if (queue_empty() == 1) // defensive coding
            {
                printf("empty queue");
                printf("\n");
            }
            else
            {
                data = dequeue();
                printf("Dequeued data is %d", data);
                printf("\n");
            }
        }
        if (sel == 3) // end
        {
            run = -1;
        }
    }
}


// this function checks the queue is full, when queue full return 1
int queue_full()
{
    // check back >= 9(array size)
    if (back >= 9)
        return 1;

    else
        return 0;
}

// this function checks the queue is empty, when queue empty return 1
int queue_empty()
{
    // check back == -1 (initial value)
    if (back == -1)
        return 1;

    else
        return 0;
}

// this function enqueue the data to array and increment back, when first data is inserted increment front and back after it increment back
void enqueue(int data)
{
    if (front == -1)
    {
        front++;
        back++;  
        queue[back] = data;
    }
    else
    {
        back++;
        queue[back] = data;
    } 
}

// this function dequeue the data from array and decrement back number, and move the array to lower bound. 
int dequeue()
{
    int temp = queue[front];
    // Using the defensive coding
    for (int i = 0; i <= back; i++)
    {
       queue[i - 1] = queue[i];
    }
     back=back-1;
    return temp;  
}
