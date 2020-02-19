#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

void init (LinkedList *list){
	list->first = NULL;
	list->size =0;
}
 
 bool isEmpty(LinkedList *list){
 	return(list->size == 0);
 }
 
int enqueue(LinkedList *list, void * data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL) return -1;
	newNode->data = data;
	newNode->next = NULL;
	if(isEmpty(list)){
		list->first = newNode;
	}
	else{
		Node *aux = list->first;
		while(aux->next != NULL)
			aux = aux->next;
		aux->next = newNode;
	}
	list->size++;
	return 1;
}
void* first(LinkedList *list){
	return(isEmpty(list))?NULL:list->first->data;
}
void* last(LinkedList *list){
	void *data = NULL;
	if(isEmpty(list)){
		Node *aux = list->first;
		while (aux->next != NULL)
			aux = aux->next;
		data = aux->data;	
	}
	return data;
}
int dequeue (LinkedList *list){
	if(isEmpty(list)) return NULL;
	Node *trash = list->first;
	list->first = list->first->next;
	void *data = trash->data;
	free(trash);
	list->size--;
	return data;
	
}
void* pop(LinkedList *list){
	return dequeue(list);
}
void* top(LinkedList *list){
	return first(list);
}
int push(LinkedList *list,void *data){
	Node *newNode = (Node*) malloc(sizeof(Node));
	if(newNode==NULL) return -1;
	newNode->data = data;
	newNode->next = NULL;
	
	if(isEmpty(list)){
		list->first = newNode;
	}
	else{
		newNode->next = list->first;
		list->first= newNode;
	}
	list->size++;
	return 1;
}
*Node getNodeByPos(LinkedList *list,int pos){
	if(isEmpty(list)|| pos>=list->size) return NULL;
	
	Node *aux = list->first;
	
	for(int count = 0; (aux!=NULL && count < pos );count++, aux=aux->next);
    return aux;
}
void *getPos(LinkedList *list, int pos){
    Node *aux = getNodeByPos(list,pos);
    if(aux == NULL) return NULL;
    else
    return aux->data;
}
int add(LinkedList *list , int pos , void *data){
    if(pos <= 0) return push(list,data);
    Node *aux= getNodeByPos(list,pos(-1));
    if(aux==NULL) return -2;
    Node *newNode = (Node*) malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = aux->next;
    aux->next = newNode;

    list->size++;
    return 1;
}




//http://www.jppreti.com/2019/07/15/lista-simplesmente-ligada/