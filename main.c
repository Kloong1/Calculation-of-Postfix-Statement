#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isOperand(char);
int Calculate(int, int, char);
int convertToInt(char);

int main(){
	STACK* s = (STACK*)malloc(sizeof(STACK));
	s->top = -1;

	FILE* fp = NULL;
	fp = fopen("postfix.txt", "r");
	
	char op = 0;
	int operandA = 0;
	int operandB = 0;
	int result = 0;

	while(1){
		fscanf(fp, "%c", &op);
		if(op == '#') break; //End of postfix statement

		/*when op is operand*/
		
		if(isOperand(op)){
			Push(s,convertToInt(op));
			continue;
		}

		/*when op is operator*/

		operandB = Top(s);
		Pop(s);
		operandA = Top(s);
		Pop(s);

		result = Calculate(operandA,operandB,op);
		Push(s, result);
	}

	printf("Result: %d\n", Top(s));
	Pop(s);

	if(!isEmpty(s)){
		printf("Error: Wrong postfix statement!");
	}

	free(s);
	fclose(fp);
	return 0;
}

int isOperand(char c){
	return (c >= '0' && c <= '9');
}

int Calculate(int operandA, int operandB, char operator){
	switch (operator) {
		case '+':
			return operandA + operandB;
			break;
		case '-':
			return operandA - operandB;
			break;
		case '*':
			return operandA * operandB;
			break;
		case '/':
			return operandA / operandB;
			break;
		case '%':
			return operandA % operandB;
			break;
		default:
			printf("Error: Wrong operator!\n");
			return -1;
	}
}

int convertToInt(char c){
	return (int)(c - '0');
}
