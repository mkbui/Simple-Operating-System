#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(empty(q)){
		q->proc[0] = proc;
		q->size=1;
	}
	else if(q->size < 10){
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(empty(q)){
		return NULL;
	}
	int check = 0;
	struct pcb_t * proc = q->proc[0];
	for(int i = 0; i < q->size; i++){
		if(q->proc[i]->priority > proc->priority){
			check = i;
			proc = q->proc[i];
		}
	}
	
	for(int i = check; i< q->size; i++){
			q->proc[i] = q->proc[i+1];
	}
	q->proc[q->size] = NULL;
	q->size--;
	return proc;
	
}

