/*
AUTHOR: Alan Thomas
PROBLEM - Ch4 Problem 19
CLASS:CSI330
Professor:Dr. Pokorny
DATE CODED 10 / 15 / 2016.
------------------------------------------------------------------------------
USE: This program is a demonstration of a queue. The abilitity to enqueue/dequeue
are present. Along with the ability to display what is currently in our queue.
And several other misc. functions that were prescribed by the text.

Notes: I encountered an issue with deleting the stack. I'm still not sure if
it is functiong correctly, but it appears to work as intended. Additionally,
I had to typecast much of the printing statments as it presented multiple hurdles when
attempting to change void* to int*. However, everything appears to be in working
order. Lastly, I feel as though there's a bit much in my main function. This could
have been cleaned up through utilizing more functions, but I was trying to 
follow a design that was more easily coded as I've been having issues
wrapping my head around pointers as is, without the added intricacies of an 
additional 8 functions.
-----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;


//struct for node/QUEUE_NODE//
typedef struct node
{
	void* dataPtr; 
	struct node* next;
}QUEUE_NODE;
//--------------------//

//struct for QUEUE//
typedef struct
{
	QUEUE_NODE* front; //points to the element in the front location
	QUEUE_NODE* rear; //points to the last element
	int count;  //counter will keep track of how many nodes we currently have in our queue
}QUEUE;
//---------------//

//CREATE QUEUE//
QUEUE* createQueue(void)
{
	QUEUE* queue;

	queue = new QUEUE;

	if (queue)
	{
		queue->front = NULL; //setting default settings for a new queue
		queue->rear = NULL;
		queue->count = 0;
	}
	return queue; //return our newly minted queue
}
//------------------//


//DESTROY QUEUE//
void destoryQueue(QUEUE* queue)
{
	//QUEUE_NODE* deletePtr;
	//deletePtr = new QUEUE_NODE;

	if (queue)
	{
		while (queue->front->next != NULL) //while we are still pointing to information we will continue to delete
		{
			//free(queue->front->dataPtr);
			QUEUE_NODE* deletePtr = queue->front->next;

			queue->front->next = queue->front->next->next;
			free(deletePtr);
		}
		free(queue->front); //freeing memory
	}
}
//--------------------------//



//ENQUEUE//
bool enqueue(QUEUE* queue, void* itemPtr)
{
	QUEUE_NODE* newPtr;

	if (!(newPtr = new QUEUE_NODE))  //if we cannot create a new node return false
	{
		return false;
	}

	newPtr->dataPtr = itemPtr; //otherwise set dataPtr to the int passed from calling function
	newPtr->next = NULL;

	if (queue->count == 0) //checking if this is our first element
	{
		queue->front = newPtr;
	}

	else
	{
		queue->rear->next = newPtr; //if not we will need to point our rear to the next node
	}

	(queue->count)++; //increment our counter
	queue->rear = newPtr; 
	return true;
}
//-----------------------//

//DEQUEUE//
bool dequeue(QUEUE* queue, void** itemPtr)
{
	QUEUE_NODE* deleteLoc;

	if (!queue->count)  //checking if the queue has any elements, if it doesn't return false
	{
		return false;
	}

	*itemPtr = queue->front->dataPtr;
	deleteLoc = queue->front;

	if (queue->count == 1)
	{
		cout << (int)queue->front->dataPtr; //printing our one and only element
		queue->rear = NULL; 
		queue->front = NULL;
	}

	else
	{
		cout << (int)queue->front->dataPtr; //printing data of the of the removed node. Typecasting due to issues trying to change void** to int
		queue->front = queue->front->next;
	}

	(queue->count)--;  //decrement our count
	free(deleteLoc); //free up the allocated memory 

	return true;
}
//-----------------------------//


//QUEUE FRONT//
bool queueFront(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)
	{
		return false;
	}

	else
	{
		*itemPtr = queue->front->dataPtr;
		cout << (int)queue->front->dataPtr; //printing contents of the front node. Typecasting due to issues trying to change void** to int
		return true;
	}
}
//-------------------//

//QUEUE REAR//
bool queueRear(QUEUE* queue, void** itemPtr)
{
	if (!queue->count)   //if there's no nodes we'll return true
	{
		return true;
	}
	else
	{
		*itemPtr = queue->rear->dataPtr;  
		cout << (int)queue->rear->dataPtr; //printing contents of the rear node. Typecasting due to issues trying to change void** to int
		return false;
	}
}
//------------------//


//EMPTY QUEUE//
bool emptyQueue(QUEUE* queue)
{
	return (queue->count == 0);   //checking if there's any elements that have been placed in the queue
}
//----------------------//

//FULL QUEUE//
bool fullQueue(QUEUE* queue)
{
	QUEUE_NODE* temp;
	temp = new QUEUE_NODE;

	if (temp)    //checking if we can create a new node, if we can we'll return true, otherwise return false
	{
		free(temp);
		return true;
	}
	return false;
}
//------------------//


//QUEUE COUNT//
int queueCount(QUEUE* queue)
{
	return queue->count;  //sending our element count back to the calling function
}
//-------------//

//DISPLAY QUEUE//
void  displayQueue(QUEUE * node)   // traverse and print the queue
{
	QUEUE_NODE * p = node->front;  //setting p to the node->front

	if (node->count == 0)  //checking the count of our queue, if it's 0 a message will be displayed
	{
		cout << "Nothing to print\n\n";
	}
	
	else
	{
		cout << (int)node->front->dataPtr << " ";  //printing the contents of the first element

		while (p->next != NULL)  //checking the next node is null
		{
			p = p->next;
			cout << " " << (int)p->dataPtr << " ";  //typecasting into to be of type int. 
		}
	}
}


//BEGIN EXECUTION//
int main()
{
	QUEUE* first;  //declare our queue
	first = NULL;
	first = createQueue(); //sending queue to create function
	int num = NULL;
	char menuchoice;
	
	//Printing options for user. I didn't include the menu in the loop due to how long the menu is. 
	//Could of cleared the screen, but I think it's more important the user sees past input
	
	cout << "--Queue program--\n";
	cout << "(A) Enqueue\n";
	cout << "(B) Dequeue and print data\n";
	cout << "(C) Print front data\n";
	cout << "(D) Print rear data\n";
	cout << "(E) Print entire queue\n";
	cout << "(F) Print queue status:Empty\n";
	cout << "(G) Print queue status: Full\n";
	cout << "(H) Print number of elements in queue:\n";
	cout << "(Q) to exit without printing the queue\n";

	do {
		cout << "\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);
		switch (menuchoice)
		{
		//place an element into the queue
		case'A':
			cout << "\n\nEnter number to place into the queue: ";
			cin >> num;
			enqueue(first, (void**)num);
			break;
		
		//remove an element from the queue
		case 'B':
			if (emptyQueue(first))
			{
				cout << "There is nothing to dequeue\n\n";
			}

			else {
				cout << "\n\nYou removed an element from the que: ";
				dequeue(first, (void**)&num);
			}
			break;
		
		//print front of the queue
		case 'C':
			cout << "\n\nThe front of the queue is: ";
			queueFront(first, (void**)&num);
			break;
		
		//print rear of the queue
		case 'D':
			cout << "\n\nThe rear of the queue is: ";

			queueRear(first, (void**)&num);
			break;
		
		//printing contents of the queue
		case 'E':
			if (emptyQueue(first)) {
				cout << "\n\nThere is nothing in the queue to display\n\n";
			}
			else {
				cout << "\n\nYour queue contains: ", displayQueue(first), "\n\n";

			}
			break;
		
		//print if queue is empty
		case 'F':
			cout << "\n\nPrint queue status Empty: ";
			if (emptyQueue(first))
			{
				cout << "QUEUE IS EMPTY\n";
			}

			else {
				cout << "QUEUE IS NOT EMPTY";
			}
			break;
		
		//print if queue is full or not
		case 'G':
			cout << "\n\nPrint queue status Full: ";
			if (!fullQueue(first))
			{
				cout << "QUEUE IS FULL\n";
			}

			else {
				cout << "QUEUE IS NOT FULL";
			}
			break;
		
		//number of elements in the queue
		case 'H':
			cout << "\n\nThe number of elements in the queue is: ";
			cout << queueCount(first) << " \n";
			break;

		//invalid input entered
		default:
			cout << "\nInvalid input\n\n";
		}
	} while (menuchoice != 'Q');

	
	//DESTORYING QUEUE BEFORE EXITING//
	if (!emptyQueue(first))
	{
		destoryQueue(first);
		return 0;
	}
	else {

		return 0;
	}
	//--------------//
}

