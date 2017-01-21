#pragma warning(disable: 4996)
#include <stdio.h>
#define PUSH 1
#define DELETE 2
#define SHOW 3
#define QUIT 4
#define MAX 6

int front = 0;
int rear = 0;

int get_a_cmd()
{
	int cmd;
	printf("Select Order.\n1.Input number in the Queue.\n2.Delete number from the Queue.\n3.Show numbers in the Queue.\n4.Quit.\n");
	scanf("%d", &cmd);
	return cmd;
}

int enqueue(int *queue)
{
	if ((rear + 1) % MAX == front)//full check
	{
		printf("The Queue is full, no more Input.\n");
		return -1;//function end
	}
	else
	printf("Input number.\n");
	scanf("%d", &queue[rear]);//input number.
	printf("The number has been input.\n");
	rear = (++rear) % MAX;//rear move
	return 0;

}

int dequeue(int *queue)
{
	if (front == rear)//empty check
	{
		printf("The Queue is empty.\n");
		return -1;//function end
	}
	else
	printf("The number has been deleted.\n");
	front++;
	front = front%MAX;//front move
	return 0;
}

void show(int *queue)
{
	int i = 0;
	if (front == rear)
	printf("The Quere is empty.\n");
	else
	{
		printf("Front ->");
		for (i = front; i != rear; i = ++i%MAX)//print from front to rear
		{
			printf(" [%d] ", queue[i]);
		}
		printf("<-Rear\n");
	}
}

int main()
{
	int cmd;
	int queue[MAX];
	do
	{
		cmd = get_a_cmd();
		switch (cmd){
			case PUSH: enqueue(queue);
			break;
			case DELETE: dequeue(queue);
			break;
			case SHOW: show(queue);
			break;
			case QUIT: printf("Quitting the program.\n");
			break;
			default: printf("Input again.\n");
			break;
		}
	} while (cmd != QUIT);
}
