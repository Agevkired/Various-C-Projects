#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arraysize 10000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int in[], int a, int b)
{
    //in[0]++;
    int current = a+1;
    int pivot = a; //Use first element as pivot
    int n = 0; //Used in for loops
/*
    //Print inputs
    printf("\na: %d b: %d\n", a, b);
    printf(" IN: ");
    for(n=a; n<=b; n++)
    {
        printf("%d ", in[n]);
    }
    printf("\n");
*/
    //If it's just 2 elements
    if(a == b-1)
    {
        if(in[a] > in[b])
        {
            swap(&in[a], &in[b]);
        }
/*
        //Print output
        printf("OUT: ");
        for(n=a; n<=b; n++)
        {
            printf("%d ", in[n]);
        }
        printf("\n");
*/
        return;
    }
    //If it's 1 element or out of bound, ignore and return
    else if(a == b || a > b)
    {
/*
        //Print output
        printf("OUT: ");
        for(n=a; n<=b; n++)
        {
            printf("%d ", in[n]);
        }
        printf("\n");
*/
        return;
    }

    //Partition using 1st element as pivot
    for(current = a+1; current <= b; current++)
    {
        if(in[pivot] > in[current])
        {
            //If pivot and current are next to each other, just swap them
            if(pivot+1 == current)
            {
                swap(&in[pivot], &in[current]);
                pivot++;
            }
            /*EX: [b] is pivot
             *    [d] is current
             *    [b] > [d]
             *[a][b][c][d] -> [a][c][b][d] -> [a][d][b][c]
             *                    |__|            |_____|
             */
            //Swap pivot and next to make space for current
            else
            {
                swap(&in[pivot], &in[pivot+1]);
                pivot++;
                swap(&in[current], &in[pivot-1]);
            }
        }
    }
/*
    //Print output
    printf("OUT: ");
    for(n=a; n<=b; n++)
    {
        printf("%d ", in[n]);
    }
    printf("\n");
    //Print which element was pivot
    printf("pivot: %d\n", pivot);
    //Print which elements are going to be used for recursion
    printf("Recursion       a: %d pivot-1: %d\n", a, pivot-1);
    printf("Recursion pivot+1: %d       b: %d\n", pivot+1, b);
*/
    quicksort(in, a, pivot-1);
    quicksort(in, pivot+1, b);
    return;
}

void bubblesort(int in[], int insize)
{
    int n = 0;
    int sorted = 0;
    //printf("Bubblesort in size: %d\n", sizeof(in)/sizeof(int));
    //printf("Element 9: %d\n", in[8]);
    while(!sorted)
    {
        sorted = 1;
        for(n = 0; n < insize-1; n++)
        {
            if(in[n] > in[n+1])
            {
                sorted = 0;
                break;
            }
        }
        if(!sorted)
        {
            for(n = 0; n < insize-1; n++)
            {
                if(in[n] > in[n+1])
                {
                    swap(&in[n], &in[n+1]);
                }
            }
        }
    }
}

int main()
{
    //int arr[10] = {78, 34, 97, 67,  9, 54, 34, 82, 79, 97};
    //              {34, 67,  9, 54, 34, 78, 97, 82, 79, 97}

    //arraysize currently set to 10000
    int arr[arraysize], arr2[arraysize];
    int n=0;
    int error=0;

    srand(time(NULL));
    for(n=0; n<sizeof(arr)/sizeof(int); n++)
    {
        arr[n] = rand();
        arr2[n] = arr[n];
    }

    printf("arr size: %d\n", sizeof(arr)/sizeof(int));

    //Test swapping
    //swap(&arr[0], &arr[1]);
    //printf("arr[0]: %d\n", arr[0]);

    quicksort(arr, 0, sizeof(arr)/sizeof(int)-1);
    bubblesort(arr2, sizeof(arr2)/sizeof(int));
    //printf("arr[0]: %d\n", arr[0]);

    //Check if array is in order
    error = 0;
    for(n=0; n<sizeof(arr)/sizeof(int)-1; n++)
    {
        printf("arr[%d]: %d\n", n, arr[n]);
        if(arr[n] > arr[n+1])
        {
            printf("ERROR: element %d greater than %d, %d > %d\n", n, n+1, arr[n], arr[n+1]);
            error = 1;
            break;
        }
    }
    if(!error)
    {
        printf("arr[%d]: %d\n", sizeof(arr)/sizeof(int)-1, arr[sizeof(arr)/sizeof(int)-1]);
    }

    //Compare array to bubble sorted array for changes to original elements
    error = 0;
    for(n=0; n<sizeof(arr)/sizeof(int); n++)
    {
        //printf(" arr[%d]: %d\n", n, arr[n]);
        if(arr[n] != arr2[n])
        {
            printf("ERROR: element %d not equal: %d != %d\n", n, arr[n], arr2[n]);
            error = 1;
        }
    }
    if(!error)
    {
        printf("No changes detected. All clear.\n");
    }

    //printf("Hello world!\n");
    return 0;
}
