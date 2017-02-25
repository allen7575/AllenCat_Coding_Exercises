#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20

typedef struct node Node;

struct node{
	char word[WORD_LEN];
	Node *next;
};

enum State{UNDONE=0,DONE};

int State = UNDONE;

void setState(int newState){
	State = newState;
}

int getState(){
	return State;
}

void print_all(Node *HeadPtr){
	Node *indexPtr = HeadPtr;
	
	printf("\n\n====Begin of list====\n");
	while(indexPtr){
		printf("%s\n",indexPtr->word);
		indexPtr = indexPtr->next;
	}
	
	printf("====end of list====\n\n");
}

void printf_all_position(Node *HeadPtr){
	Node *indexPtr = HeadPtr;
	int index = 0;
	
	printf("\n\n====Begin of list====\n");
	while(indexPtr){
		printf("%d\n",index);
		printf("%s\n",indexPtr->word);
		indexPtr = indexPtr->next;
		index++;
	}
	
	printf("%d\n",index);
	
	printf("====end of list====\n\n");
}

void append_node(Node **HeadDPtr, Node **TailDPtr, char newWord[WORD_LEN]){
	//allocate memory space for a tempNode
	Node *tempNode = (Node*)malloc(sizeof(Node)); 
	//printf("debug_1.\n");
	
	//copy newWord into tempNode->word
	//use sizeof(tempNode->word) to avoid overflow(if newWord is bigger than tempNode->word)
	strncpy(tempNode->word, newWord, sizeof(tempNode->word));
	//printf("debug_2.\n");
	
	//append null terminator
	tempNode->word[sizeof(tempNode->word)-1] = '\n';
	//printf("debug_3.\n");
	
	//set tempNode->next as NULL
	tempNode->next = NULL;
	
	
	if(*TailDPtr == NULL) {
		*TailDPtr = tempNode;
		*HeadDPtr = tempNode;
	}else{
		//TailDPtr->next points to temp node
		(*TailDPtr)->next = tempNode;
		printf("debug_5.\n");
		
		//TailDPtr points to tempNode
		*TailDPtr = tempNode;
	}


	//printf("debug_7.\n");
	//printf("Have appended word \"%s\"\n", (*tailDPtr)->word);
	
	//printf("debug_8.\n");
	print_all(*HeadDPtr);
}

void delete_node(Node **HeadDPtr, Node **TailDPtr, Node *targetPtr){
	Node *beforeTargetPtr = *HeadDPtr;
	
	if(targetPtr == NULL){
		printf("There are no target to be delete.\n");
		return;
	}
	
	if(*HeadDPtr == *TailDPtr){
		printf("target node is the only one node in the list.\n");
		*HeadDPtr = NULL;
		*TailDPtr = NULL;
		free(targetPtr);
		print_all(*HeadDPtr);
		return;
	}
	
	if(targetPtr == *HeadDPtr){
		printf("The target is the Head.\n");
		*HeadDPtr = targetPtr->next;
		free(targetPtr);
		print_all(*HeadDPtr);
		return;
	}
	
	while(beforeTargetPtr->next != targetPtr){
		beforeTargetPtr = beforeTargetPtr->next;
	}
	
	beforeTargetPtr->next = targetPtr->next;
	
	if(targetPtr == *TailDPtr){
		printf("The target is the Tail.\n");
		*TailDPtr = beforeTargetPtr;
	}
	
	free(targetPtr);
	
	print_all(*HeadDPtr);
}

Node* search_node(Node *HeadPtr, char word[WORD_LEN]){
	Node *indexPtr = HeadPtr;
	
	while(indexPtr != NULL && strncmp(indexPtr->word, word, sizeof(indexPtr->word))){
		indexPtr = indexPtr->next;
	}
	
	return indexPtr;
}

void insert_node(Node **HeadDPtr, Node **TailDPtr, char newWord[WORD_LEN], int position){
	Node *tempNode = (Node*)malloc(sizeof(Node));
	Node *targetNode = *HeadDPtr;
	int index = 0;
	
	printf("position = %d\n", position);
	
	strncpy(tempNode->word, newWord, sizeof(tempNode->word));
	tempNode->word[sizeof(tempNode->word)-1] = '\n';
	
	if(position < 0){
		printf("position can not be negtive.\n");
		return;
	}
	
	if(position == 0){
		tempNode->next = *HeadDPtr;
		*HeadDPtr = tempNode;
		print_all(*HeadDPtr);
		return;
	}
	
	for(index = 1; index < position && targetNode->next != NULL; index++){
		targetNode = targetNode->next;
	}
	
	tempNode->next = targetNode->next;
	targetNode->next = tempNode;
	
	if(targetNode == *TailDPtr){
		*TailDPtr = tempNode;
	}
	
	print_all(*HeadDPtr);
}

void free_all(Node **HeadDPtr, Node **TailDPtr){
	Node *tempNode = *HeadDPtr;
	
	printf("free all nodes\n");
	
	while(tempNode){
		*HeadDPtr = tempNode->next;
		free(tempNode);
		tempNode = *HeadDPtr;
	}
	
	*TailDPtr = NULL;
}

void main(){
	Node *HeadPtr = NULL,
		 *TailPtr = NULL;
		 
	char wordBuf[WORD_LEN];
	char positionBuf[WORD_LEN];
	
	while(getState() != DONE){
		printf("Enter (a)ppend, (d)elete, (i)nsert, (f)ree, (s)how, (e)scape \n");
		
		switch(getchar()){
			case 'a':
					printf("append mode\n");
					getchar();
					while((gets(wordBuf))[0] != 0){
						append_node(&HeadPtr, &TailPtr, wordBuf);
					}
					break;
			case 'd':
					printf("delete mode\n");
					getchar();
					while((gets(wordBuf))[0] != 0){
						delete_node(&HeadPtr, &TailPtr, search_node(HeadPtr, wordBuf));
					}
					break;
			case 'i':
					printf("insert mode\n");
					getchar();
					//printf_all_position(HeadPtr);
					//printf("Enter position:\n");
					while((gets(wordBuf))[0] != 0){
						printf_all_position(HeadPtr);
						printf("Enter position:\n");
						//getchar();
						insert_node(&HeadPtr, &TailPtr, wordBuf, atoi(gets(positionBuf)));
					}
					break;
			case 'f':
				getchar();
				free_all(&HeadPtr,&TailPtr);
				break;
			case 's':
				getchar();
				print_all(HeadPtr);
				break;
			case 'e':
				setState(DONE);
				break;
			default:
				break;
		}
	}
	
	free_all(&HeadPtr,&TailPtr);
	
	printf("Program Terminate.\n");
	
	
}