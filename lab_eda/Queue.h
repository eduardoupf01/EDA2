#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Estructura para un nodo de la cola
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estructura para la cola
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->head = newNode;
        return;
    }
    
    queue->tail->next = newNode;
    queue->tail = newNode;
}

int dequeue(Queue* queue) {
    if (queue->head == NULL) {
        printf("La cola está vacía.\n");
        return -1; // Retorna -1 si la cola está vacía
    }
    
    Node* temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(temp);
    return data;
}

Queue* randomTurns(int totalTurns) {
    Queue* queue = initializeQueue();
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios

    for (int i = 0; i < totalTurns; i++) {
        int turn = rand() % 2 + 1; // Generar un número aleatorio entre 1 y 2
        enqueue(queue, turn);
    }

    return queue;
}