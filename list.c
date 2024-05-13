#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list{
	Node * head;
	int size;
};

struct node{
	int iD;
	double dD;
	char cD;
	char * cAD;

	Node * next;
};

List * createList(){
	List * newList = malloc(sizeof(List)); //--Create new list
	newList->head = NULL; //-------------------Set head pointer to NULL
	newList->size = 0; //----------------------Set size of list to 0.

	return newList; //-------------------------Return List
}

Node * createNode(){
	Node * newNode = malloc(sizeof(Node));
	newNode->next = NULL;

	return newNode;
}

int stringComp(char * a, char * b){
	int j = 0, k = 0;

	while(a[j]!='\0') j++;
	while(b[k]!='\0') k++;
	if(j!=k) return 0;

	j=0;
	while(j != k){
		if(a[j] != b[j]){
			return 0;
		}
		j++;
	}
	return 1;
}

void addInt(int a, List * list){
	if(list->size == 0){
		list->head = createNode();
		list->head->iD = a;
		list->size += 1;
	} else{
		Node * current = list->head;
		for(int i = 0; i < (list->size-1); i++){
			current = current->next;
		}
		current->next = createNode();
		current->next->iD = a;
		list->size += 1;
	}
}
void addDouble(double a, List * list){
	if(list->size == 0){
		list->head = createNode();
		list->head->dD = a;
		list->size += 1;
	} else{
		Node * current = list->head;
		for(int i = 0; i < (list->size-1); i++){
			current = current->next;
		}
		current->next = createNode();
		current->next->dD = a;
		list->size += 1;
	}
}
void addChar(char a, List * list){
	if(list->size == 0){
		list->head = createNode();
		list->head->cD = a;
		list->size += 1;
	} else{
		Node * current = list->head;
		for(int i = 0; i < (list->size-1); i++){
			current = current->next;
		}
		current->next = createNode();
		current->next->cD = a;
		list->size += 1;
	}
}
void addString(char * a, List * list){
	int bc = 0; while(a[bc]!='\0'){bc++;}

	if(list->size == 0){
		list->head = createNode();
		list->size += 1;
	} else{
		Node * current = list->head;
		for(int i = 0; i < (list->size-1); i++){
			current = current->next;
		}
		current->next = createNode();
		list->size += 1;
	}

	Node * current = list->head;
	for(int i = 0; i < (list->size-1); i++){
		current = current->next;
	}
	current->cAD = (char*)malloc((bc+1)*sizeof(char));
	for(int i = 0; i < (bc+1); i++){
		current->cAD[i] = a[i];
 	}
}



void insertInt(int a, int pos, List * list){
	if(pos < 0){return;}
	if(list->size == pos){
		addInt(a, list);
	} else if(list->size > pos){ //----------Since pos > 0, list->size is at least 1.
		Node * current = list->head; //--Thus this line is valid.
		for(int i = 0; i < pos; i++){
			current = current->next;
		}

		Node * newNode = createNode();
		newNode->next = current;
		if(pos == 0){
			list->head = newNode;
		} else{
			current = list->head;
			for(int i = 0; i < (pos-1); i++){
				current = current->next;
			}
			current->next = newNode;
		}

		newNode->iD = a;
		list->size += 1;
	} else{
		if(list->size == 0){
			for(int i = 0; i < pos; i++){
				addInt(0, list);
			}
		} else{
			Node * current = list->head;
			for(int i = 0; i < (list->size-1); i++){
				current = current->next;
			}
			for(int i = 0; i < (pos - list->size); i++){
				current->next = createNode();
				current = current->next;
				current->iD = 0;
			}
			list->size = pos;
		}
		addInt(a, list);
	}
}

void insertDouble(double a, int pos, List * list){
	if(pos < 0){return;}
	if(list->size == pos){
		addDouble(a, list);
	} else if(list->size > pos){ //----------Since pos > 0, list->size is at least 1.
		Node * current = list->head; //--Thus this line is valid.
		for(int i = 0; i < pos; i++){
			current = current->next;
		}

		Node * newNode = createNode();
		newNode->next = current;
		if(pos == 0){
			list->head = newNode;
		} else{
			current = list->head;
			for(int i = 0; i < (pos-1); i++){
				current = current->next;
			}
			current->next = newNode;
		}

		newNode->dD = a;
		list->size += 1;
	} else{
		if(list->size == 0){
			for(int i = 0; i < pos; i++){
				addDouble(0, list);
			}
		} else{
			Node * current = list->head;
			for(int i = 0; i < (list->size-1); i++){
				current = current->next;
			}
			for(int i = 0; i < (pos - list->size); i++){
				current->next = createNode();
				current = current->next;
				current->dD = 0;
			}
			list->size = pos;
		}
		addDouble(a, list);
	}
}

void insertChar(char a, int pos, List * list){
	if(pos < 0){return;}
	if(list->size == pos){
		addChar(a, list);
	} else if(list->size > pos){ //----------Since pos > 0, list->size is at least 1.
		Node * current = list->head; //--Thus this line is valid.
		for(int i = 0; i < pos; i++){
			current = current->next;
		}

		Node * newNode = createNode();
		newNode->next = current;
		if(pos == 0){
			list->head = newNode;
		} else{
			current = list->head;
			for(int i = 0; i < (pos-1); i++){
				current = current->next;
			}
			current->next = newNode;
		}

		newNode->cD = a;
		list->size += 1;
	} else{
		if(list->size == 0){
			for(int i = 0; i < pos; i++){
				addChar(0, list);
			}
		} else{
			Node * current = list->head;
			for(int i = 0; i < (list->size-1); i++){
				current = current->next;
			}
			for(int i = 0; i < (pos - list->size); i++){
				current->next = createNode();
				current = current->next;
				current->cD = '\0';
			}
			list->size = pos;
		}
		addChar(a, list);
	}
}
void insertString(char * a, int pos, List * list){
	int aLength = 0; while(a[aLength]!='\0'){aLength++;}

	if(pos < 0){return;}
	if(list->size == pos){
		addString(a, list);
	} else if(list->size > pos){ //----------Since pos > 0, list->size is at least 1.
		Node * current = list->head; //--Thus this line is valid.
		for(int i = 0; i < pos; i++){
			current = current->next;
		}

		Node * newNode = createNode();
		newNode->next = current;
		if(pos == 0){
			list->head = newNode;
		} else{
			current = list->head;
			for(int i = 0; i < (pos-1); i++){
				current = current->next;
			}
			current->next = newNode;
		}

		newNode->cAD = (char*)malloc((aLength+1)*sizeof(char));
		for(int i = 0; i < (aLength+1); i++){
			newNode->cAD[i] = a[i];
		}
		list->size += 1;
	} else{
		if(list->size == 0){
			for(int i = 0; i < pos; i++){
				addInt(0, list);
			}
		} else{
			Node * current = list->head;
			for(int i = 0; i < (list->size-1); i++){
				current = current->next;
			}
			for(int i = 0; i < (pos - list->size); i++){
				current->next = createNode();
				current = current->next;
				current->cAD = (char*)malloc(1);
				current->cAD[0] = '\0';
			}
			list->size = pos;
		}
		addString(a, list);
	}
}

int deletePos(int pos, List * list){
	if(pos >= list->size) return 0;
	if(pos == 0){
		Node * M = list->head;
		Node * RHS = M->next;
		list->head = RHS;
		free(M);
	} else{
		Node * LHS = list->head;
		for(int i = 0; i < pos-1; i++) LHS = LHS->next;
		Node * M = LHS->next;
		Node * RHS = M->next;

		LHS->next = RHS;
		free(M);
	}

	list->size -= 1;
	return 1;
}

void deleteInt(int a, List * list){
	int * positions;
	int numPos = freqInt(a, &positions, list);

	for(int i = 0; i < numPos; i++){
		deletePos(positions[i], list);
		positions[i+1] -= i+1;
	}
}

void deleteDouble(double a, double tol, List * list){
	int * positions;
	int numPos = freqDouble(a, tol, &positions, list);

	for(int i = 0; i < numPos; i++){
		deletePos(positions[i], list);
		positions[i+1] -= i+1;
	}
}

void deleteChar(char a, List * list){
	int * positions;
	int numPos = freqChar(a, &positions, list);

	for(int i = 0; i < numPos; i++){
		deletePos(positions[i], list);
		positions[i+1] -= i+1;
	}
}

void deleteString(char * a, List * list){
	int * positions;
	int numPos = freqString(a, &positions, list);

	for(int i = 0; i < numPos; i++){
		deletePos(positions[i], list);
		positions[i+1] -= i+1;
	}
}

int freqInt(int a, int ** positions, List * list){
	int numPos = 0, localPositions[200], i = 0;

	Node * current = list->head;
	while(current != NULL){
		if(current->iD == a){
			localPositions[numPos] = i;
			numPos++;
		}
		i++;
		current = current->next;
	}

	*positions = (int*)malloc(numPos*sizeof(int));
	for(int i = 0; i < numPos; i++){
		(*positions)[i] = localPositions[i];
	}

	return numPos;
}

int freqDouble(double a, double tol, int ** positions, List * list){
	int numPos = 0, localPositions[200], i = 0;
	double lowBound = a - tol, upBound = a + tol;

	Node * current = list->head;
	while(current != NULL){
		if((current->dD < upBound) && (current->dD > lowBound)){
			localPositions[numPos] = i;
			numPos++;
		}
		i++;
		current = current->next;
	}

	*positions = (int*)malloc(numPos*sizeof(int));
	for(int i = 0; i < numPos; i++){
		(*positions)[i] = localPositions[i];
	}

	return numPos;
}

int freqChar(char a, int ** positions, List * list){
	int numPos = 0, localPositions[200], i = 0;

	Node * current = list->head;
	while(current != NULL){
		if(current->cD == a){
			localPositions[numPos] = i;
			numPos++;
		}
		i++;
		current = current->next;
	}

	*positions = (int*)malloc(numPos*sizeof(int));
	for(int i = 0; i < numPos; i++){
		(*positions)[i] = localPositions[i];
	}

	return numPos;
}

int freqString(char * a, int ** positions, List * list){
	int numPos = 0, localPositions[200], i = 0;

	Node * current = list->head;
	while(current != NULL){
		if(stringComp(current->cAD, a) == 1){
			localPositions[numPos] = i;
			numPos++;
		}
		i++;
		current = current->next;
	}

	*positions = (int*)malloc(numPos*sizeof(int));
	for(int i = 0; i < numPos; i++){
		(*positions)[i] = localPositions[i];
	}

	return numPos;
}

int getInt(int pos, List * list){
	Node * current = list->head;
	for(int i = 0; i < pos; i++) current = current->next;
	return current->iD;
}

double getDouble(int pos, List * list){
	Node * current = list->head;
	for(int i = 0; i < pos; i++) current = current->next;
	return current->dD;
}

char getChar(int pos, List * list){
	Node * current = list->head;
	for(int i = 0; i < pos; i++) current = current->next;
	return current->iD;
}

void getString(int pos, char ** entry, List * list){
	Node * current = list->head;
	for(int i = 0; i < pos; i++) current = current->next;
	int i = 0; while(current->cAD[i] != '\0') i++;
	*entry = (char*)malloc((i+1)*sizeof(char));
	for(int j = 0; j < i+1; j++) (*entry)[j] = current->cAD[j];
}

void destroy(List * list){
	while(1){if(deletePos(0, list) == 0) return;}
	list->size = 0;
}

void display(char * a, List * list){
	if(list->size == 0){
		printf("Nothing to display :(\n");
		return;
	}

	Node * current = list->head;
	if(stringComp(a, "integers") == 1){
		printf("All Integers:\n");
		while(current != NULL){
			printf("%d ", current->iD);
			current = current->next;
		} printf("\n");
	} else if(stringComp(a, "doubles") == 1){
		printf("All Doubles:\n");
		while(current != NULL){
			printf("%lf ", current->dD);
			current = current->next;
		} printf("\n");
	} else if(stringComp(a, "strings") == 1){
		printf("All Strings:\n");
		while(current != NULL){
			printf("%s ", current->cAD);
			current = current->next;
		} printf("\n");
	} else if(stringComp(a, "characters") == 1){
		printf("All Characters:\n");
		while(current != NULL){
			printf("%c ", current->cD);
			current = current->next;
		} printf("\n");
	} else{
		printf("Displaying All Contents of List:\n");

		printf("----Integers:\n"); printf("--------");
		while(current != NULL){
			printf("%d ", current->iD);
			current = current->next;
		} printf("\n");

		current = list->head;
		printf("----Doubles:\n"); printf("--------");
		while(current != NULL){
			printf("%lf ", current->dD);
			current = current->next;
		} printf("\n");

		current = list->head;
		printf("----Characters:\n"); printf("--------");
		while(current != NULL){
			printf("%c ", current->cD);
			current = current->next;
		} printf("\n");

		current = list->head;
		printf("----Strings:\n"); printf("--------");
		while(current != NULL){
			printf("%s ", current->cAD);
			current = current->next;
		} printf("\n");
	}
}
