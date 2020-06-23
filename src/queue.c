#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	// Check if queue is empty. If it is, add proc in as first element.
	if(empty(q)){
		q->proc[0] = proc;
		q->size=1;
	}
	// Else, add proc in right after the last element of the queue.
	else if(q->size < 10){
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	//Check if queue is empty. If it is, return nothing.
	if(empty(q)){
		return NULL;
	}
	//an integer to check the position of the highest priority pcb in the queue
	int check = 0;
	//the return pcb
	struct pcb_t * proc = q->proc[0];
	//Iterate through the queue to find the pcb with highest priority. If there are more than one with same highest, choose the first one.
	//Check the position of the selected pcb
	for(int i = 0; i < q->size; i++){
		if(q->proc[i]->priority > proc->priority){
			check = i;
			proc = q->proc[i];
		}
	}
	//Delete the marked position in the queue, adjust the queue
	for(int i = check; i< q->size; i++){
			q->proc[i] = q->proc[i+1];
	}
	q->proc[q->size] = NULL;
	q->size--;
	//return the selected pcb
	return proc;
	
}

