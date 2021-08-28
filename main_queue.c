#include "queue.h"

void main()
{
    Queue line;
    Item temp;
    char ch;
    InitializeQueue(&line);
    puts("Enter [a] to add number in queue, [d] to delete and [q] to quite:");
    while ((ch = getchar()) != 'q')
    {
        if (ch == 'a' && ch == 'd')
            continue;
        if (ch == 'a')
        {
            puts("Enter number to add in queue:\n");
            scanf("%d", &temp);
            while (getchar() != '\n')
                continue;
            if (!QueueIsFull(&line))
            {
                printf("[%d] added in queue!\n", temp);
                AddItemQueue(temp, &line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Numbers to delete isn't exist");
            else
            {
                DeleteItemQueue(&temp, &line);
                printf("%d is deleted from queue!", temp);
            }
        }
        printf("%d members in queue!\n\n", QueueItemCount(&line));
        puts("Enter a to add number in queue, d to delete and q to quite:");
    }

    EmptyTheQueue(&line);
    puts("Programm is over!");
}