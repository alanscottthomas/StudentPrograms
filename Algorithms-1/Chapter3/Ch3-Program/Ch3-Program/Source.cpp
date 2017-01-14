/*
AUTHOR: Alan Thomas
PROBLEM - Ch5 Problem 10
CLASS:CSI330
Professor:Dr. Pokorny
DATE CODED 10 / 10 / 2016.
------------------------------------------------------------------------------
USE: This program was supposed to use backtracking to determine the path to a 
goal from a predetermined graph.

Notes: Simply put, the program doesn't work. I'm simply sending the code to
demonstrate that I gave it the best effort I could muster. I attempted probably
close to 10 different approaches to make it work, however, I encountered 
the same problem in all of my designs. That is how do I handle the branch points. 
The closest I came was when I used bools inside of the NODE struct to determine
branch points, but this resulted in additional hurdles I could not figure out.
-----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;


struct NODE
{

	int data;
	NODE* left;
	NODE* middle;
	NODE* right;
};


//STRUCTURE FOR STACK//
typedef struct
{
	int count;
	NODE* top;
}STACK;
//---------------//


//STRUCTURE TO CREATE AN EMPTY STACK//
STACK* createStack(void)
{
STACK* stack;

stack = (STACK*)malloc(sizeof(STACK)); //could use new here, but trying to stick to the presribed code as close as possible
if (stack)
{
stack->count = 0;
stack->top = NULL;
}
return stack;
}
//---------------------------//


//FUNCTION TO PUSH ITEM TO THE STACK//
bool pushStack(STACK* stack, void* dataInPtr)
{
NODE* newPtr;

newPtr = (NODE*)malloc(sizeof(NODE));
if (!newPtr)
{//book code doesn't have braces, may need to remove these
return false;
//newPtr->data = dataInPtr;
newPtr->middle;

(stack->count)++;
return true;
}
}
//----------------------------------------//





//BOOl PUSH FUNCTION//
bool push(NODE** pStackTop, char charIn)
{
	NODE* pNew;
	bool success;

	pNew = (NODE*)malloc(sizeof(NODE));
	if (!pNew)
	{
		success = false;
	}
	else
	{
		pNew->data = charIn;
		pNew->middle = *pStackTop; //will need to work on this for the branch system

		*pStackTop = pNew;
		success = true;
	}
	return success;
}
//----------------------------//


//FUNCTION TO HARD-CODE TREE AS DEMONSTRATED DURING LECTURE//
void SEARCH(NODE* node)
{
	cout << "\n\n\n" << node->data << " " << node->left->data << " " << node->left->left->data << " " << node->left->left->left->data << " " << node->left->left->middle->data;
}

//BOOL POP FUNCTION//
bool pop(NODE** pStackTop, char* charOut)
{
	NODE* pDlt;
	bool success;

	if (*pStackTop)
	{
		success = true;
		*charOut = (*pStackTop)->data;
		pDlt = *pStackTop;
		*pStackTop = (*pStackTop)->middle;
		free(pDlt);
	}
	else
	{
		success = false;
	}
	return success;
}
//-------------------------//

//FULL STACK FUNCTION TO DETERMINE IF THE HEAP IS FULL//
bool fullStack(STACK* stack)
{
NODE* temp;

if ((temp = (NODE*)malloc(sizeof(*(stack->top))))) //slightly confused by this line
{
free(temp);
return false;
}
return true;
}
//------------------------//


//POP Function//
void POP(NODE** node, int* nodenumber)
{
NODE* pDlt;
pDlt = *node;

bool success;
//

if (*node)
{
if (pDlt->left != NULL && pDlt->middle == NULL)
{
success = true;
*nodenumber = (*node)->data;
pDlt = *node;
*node = (*node)->left;
cout << pDlt->data;
free(pDlt);
}



if (pDlt->left != NULL && pDlt->middle != NULL)
{
success = true;
*nodenumber = (*node)->data;
pDlt = *node;
*node = (*node)->left;
cout << pDlt->data;
free(pDlt);
}





else
{
success = false;
}
}
}



void PRINT(NODE** node) {
	NODE* temp = *node;


	while (temp->left != NULL)
	{
		cout << temp->data;
		temp = temp->left;
	}

}


//STACK COUNT FUNCTION TO RETURN NUMBER OF ITEMS IN THE STACK//
int stackCount(STACK* stack)
{
return stack->count;
}
//------------------------------------//

//DESTORY STACK FUNCTION TO FREE UP THE MEMORY THAT THE STACK WAS USING//
STACK* destroyStack(STACK* stack)
{
STACK* temp;
temp = new STACK;
temp = NULL;
if (stack)
{
while (stack->top != NULL)
{
//free(stack->top->data);

//temp = stack->top;
stack->top = stack->top->middle;
free(temp);
}
free(stack);
}
return NULL; //deleting the stack
}




//Insert Function//
void INSERT()
{
	NODE* node;
	node = new NODE;
	bool FIRST = true;
	NODE* current;
	current = new NODE;


	if (FIRST) {
		NODE* next;
		next = new NODE;

		next->data = 1;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		node = next;
		current = next;
		cout << "START: " << next->data << " ";
		FIRST = false;



	}
	if (!FIRST)
	{

		NODE* next;
		next = new NODE;
		next->data = 2;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		//BP_3//
		NODE* BP_3;
		BP_3 = new NODE;
		next = new NODE;
		BP_3 = next;
		next->data = 3;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << "(BP) ";


		next = new NODE;
		next->data = 4;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		//BP_5//
		NODE* BP_5;
		BP_5 = new NODE;
		next = new NODE;
		BP_5 = next;
		next->data = 5;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << "(BP) ";

		next = new NODE;
		next->data = 6;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		//END NODE//
		next = new NODE;
		next->data = 7;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = BP_5;
		cout << next->data << "(END) ";

		//END NODE//
		next = new NODE;
		next->data = 8;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->middle = next;
		current = next;
		current = BP_5;
		cout << next->data << "(END) ";

		next = new NODE;
		next->data = 9;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->right = next;
		current = next;
		cout << next->data << " ";

		next = new NODE;
		next->data = 10;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		//END NODE//
		next = new NODE;
		next->data = 11;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = BP_3;
		cout << next->data << " ";

		next = new NODE;
		next->data = 12;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->middle = next;
		current = next;
		cout << next->data << " ";


		//BP_13//
		NODE* BP_13;
		BP_13 = new NODE;
		next = new NODE;
		BP_13 = next;
		next->data = 13;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << "(BP) ";

		next = new NODE;
		next->data = 14;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		next = new NODE;
		next->data = 15;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " ";

		//END NODE-WANT TO SEEK THIS NODE//
		next = new NODE;
		next->data = 16;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = BP_13;
		cout << next->data << "(END & GOAL) ";


		next = new NODE;
		next->data = 17;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->middle = next;
		current = next;
		cout << next->data << " ";

		next = new NODE;
		next->data = 18;
		next->left = NULL;
		next->middle = NULL;
		next->right = NULL;
		current->left = next;
		current = next;
		cout << next->data << " (END OF GRAPH) ";



	}

	PRINT(&node);


	/*for (int counter = 0; counter < 17; counter++)
	{

	POP(&node, &node->data);
	//SEARCH(node);
	}*/
}
//--------------------------------//




//BEGIN EXECUTION//
int main()
{

	INSERT();
	cout << "\n\n\n";



	system("pause");

	return 0;
}
//---------------//