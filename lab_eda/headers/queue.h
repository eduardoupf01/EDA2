#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue* createQueue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int queueSize(Queue *q);
void freeQueue(Queue *q);

#endif