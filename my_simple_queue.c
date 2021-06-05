#include <stdio.h>

struct buffer{
	int byte;
	//int buf[100];
	int *buf;
};
struct queue{
	int front;
	int rear;
	int size;
  struct buffer *arr;
	unsigned int capacity;
};

struct queue *createQueue(unsigned int capacity)
{
	struct  queue *queue=(struct queue*)malloc(sizeof (struct queue));
	queue->capacity=capacity;
	queue->front=queue->size= 0;

  queue->rear=-1;
	queue->arr=(struct buffer*)malloc(10*sizeof(struct buffer));
  queue->arr->buf=(int*)malloc(capacity*sizeof(int));
	return queue;

}

int isFull(struct queue *queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(struct queue *queue)
{
	return (queue->size==0);
}

void enqueue(struct queue *queue,int item)
{
	if(isFull(queue)) return;
	queue->rear=(queue->rear+1)% queue->capacity;
	queue->arr[0].buf[queue->rear] = item;
	queue->size =queue->size+1;
	printf("enqueue is %d \n",item);
}

int dequeue(struct queue *queue)
{
	if(isEmpty(queue)) return -1;
	int data = queue->arr[0].buf[queue->front];
	queue->front=(queue->front+1) % queue->capacity;
	queue->size = queue->size -1;
	return data;
}

int main()
{
  struct queue *queue=createQueue(1000);

	enqueue(queue,10);
	enqueue(queue,20);
	int data = dequeue(queue);
  int size=queue->size;
	printf("**data=%d size=%d \n",data,size);
}
