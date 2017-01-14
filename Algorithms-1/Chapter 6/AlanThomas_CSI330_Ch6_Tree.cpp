/*
AUTHOR: Alan Thomas
PROBLEM - Ch6 Tree Program
CLASS:CSI330
Professor:Dr. Pokorny
DATE CODED 11 / 02 / 2016.
------------------------------------------------------------------------------
USE: This program builds an intial tree with 10 elements. After building the tree
the user has the ability to print inorder,preorder,postorder, insert, and delete.

Notes: I feel as though I made this more difficult than needed. After completing
the program and looking through the code I see that my logic, more than likely, could
be reduced to simplify the program. Additionally, I believe I covered most of the cases
that would occur in this program,however, I was unable to delete the head without
causing an error. I believe it is due to how I am passing my tree to the function,
but ultimatley I am not sure. Overall the additionally time granted allowed 
me to hash out some issues that I hadn't been able to overcome prior.
-----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

//STRUCT FOR THE NODES//
struct Node {
	int data;                         // The data in this node.
	Node *left = NULL;                // Pointer to the left subtree.
	Node *right = NULL;              // Pointer to the right subtree.
	bool head = false;
	bool dir_left = false;           //bools to assist with the logic
	bool dir_right = false;
};
//-------------------//

//Function to make the initial tree//
void makeTree(Node* root)
{
	Node* current;                  //DECLARING OUR NODES TO BEGIN
	current = new Node;             //BUILDING OUR TREE
	Node* temp_left;
	temp_left = new Node;
	Node* temp_right;
	temp_right = new Node;
	

	root->data = 1;                //SETTING VALUE OF OUR FIRST NODE
	root->head = true;
	root->left = temp_left;
	temp_left->data = 2;           //SETTING THE VALUE OF NODE 2
	temp_left->dir_left = true;
	root->right = temp_right;
	temp_right->data = 3;          //SETTING NODE 3'S VALUE
	temp_right->dir_right = true;
	

	current = temp_left;           //MOVING TO SECOND NODE
	temp_left = new Node;
	current->left = temp_left;
	temp_right = new Node;
	temp_right->data = 5;          //SETTING NODE 5'S VALUE
	temp_right->dir_right = true;
	current->right = temp_right;
	temp_left->data = 4;           //SETTING NODE 4'S VALUE
	temp_left->dir_left = true;

	current = temp_left;          //SETTING CURRENT NODE TO NODE 4
	temp_left = new Node;
	current->left = temp_left;
	temp_right = new Node;
	temp_right->data = 9;         //SETTING NODE 9'S VALUE
	temp_right->dir_right = true;
	current->right = temp_right;
	temp_left->data = 8;          //SETTING NODE 8'S VALUE
	temp_left->dir_left = true;

	current = root->left->right; //SETTING CURRENT TO NODE 5
	temp_left = new Node;
	temp_left->data = 10;        //ADDING LEFT NODE TO NODE 5 WITH A VALUE OF 10
	temp_left->dir_left = true;
	current->left = temp_left;

	current = root->right;       //SETTING CURRENT TO NODE 3
	temp_left = new Node;
	temp_left->data = 6;         //ADDING NODE 6 AS LEFT LEAF TO 3
	temp_left->dir_left = true;
	current->left = temp_left;   //SET CURRENTS LEFT POINTER TO TEMP LEFT
	temp_right = new Node;
	temp_right->data = 7;        //ADDING RIGHT LEAF TO 3 AS NODE 7
	temp_right->dir_right = true;
	current->right = temp_right;
	//return root;
}
//------------------------//

//PREORDER PRINT FUNCTION//
void preorderPrint(Node *root) {

	if (root != NULL) {                 //IF A NODE EXIST DO THE FOLLOWING
		cout << root->data << " ";      //PRINT VALUE OF CURRENT NODE
		preorderPrint(root->left);      //CALL WITH LEFT NODE
		preorderPrint(root->right);     //CALL WITH RIGHT NODE
	}
}
//---------------------//

//POSTORDER PRINT FUNCTION//
void postorderPrint(Node *root) {
	if (root != NULL) {                //IF A NODE EXIST DO THE FOLLOWING
		postorderPrint(root->left);    //CALL WITH LEFT NODE
		postorderPrint(root->right);   //CALL WITH RIGHT NODE
		cout << root->data << " ";     //PRINT VALUE OF CURRENT NODE 
	}
}
//----------------------------//

//INORDER FUNCTION//
void inorderPrint(Node *root) {
	if (root != NULL) {               //IF A NODE EXIST DO THE FOLLOWING
		
			inorderPrint(root->left);     //CALL WITH LEFT NODE
		
		cout << root->data << " ";    //PRINT VALUE OF CURRENT NODE  
		
			inorderPrint(root->right);    //CALL WITH RIGHT NODE
		
		}
}
//------------------//

//INSERT FUNCTION//
void insert(Node* root, Node* trail, char direction, int value)
{
	Node* temp;
	temp = new Node;
	Node* temp_right;
	Node* temp_root;
	temp_right = new Node;
	temp_root = new Node;

	
	if (direction != NULL)                      //IF DIRECTION WAS NOT NULL
	{
		
		if (direction == 'R')                   //IF USER SELECTED RIGHT LEAF
		{
			Node* users_node;                  //MAKING A NEW NODE TO HOLD USER'S VALUE
			users_node = new Node;
			users_node->dir_right = true;
			users_node->right = root->right;   //SETTING THE NEW NODES RIGHT POINTER TO THE CURRENT NODES RIGHT POINTER
			users_node->data = value;          //SETTING THE VALUE OF THE NEW NODE
			root->right = users_node;          //UPDATING THE CURRENT NODE'S RIGHT POINTER TO THE NEW NODE
			cout << "\n";
		}
		
		if (direction == 'L')                 //IF USER SELECTED LEFT LEAF
		{
			Node* users_node;               //MAKING A NEW NODE TO HOLD USER'S VALUE
			users_node = new Node;
			users_node->dir_left = true;     //SET USERS NODE TO THAT OF A LEFT

			users_node->left = root->left; //SETTING THE NEW NODES LEFT POINTER TO THE CURRENT NODES LEFT POINTER
			users_node->data = value;      //SETTING THE VALUE OF THE NEW NODE
			root->left = users_node;       //UPDATING THE CURRENT NODE'S LEFT POINTER TO THE NEW NODE
			cout << "\n";
		}

		 if (direction == 'P' && root->head != true)                  //IF USER SELECTED PARENT AND NOT HEAD
		{
			Node* users_node;                 //MAKING A NEW NODE TO HOLD USER'S VALUE
			users_node = new Node;
			if (root->dir_left == true)         //IF DIRECTION IS LEFT
			{
				
				users_node->data = value;      //SET USERS NODE DATA
				users_node->dir_left = true;   //SET LEFT INDICATOR
				users_node->left = trail->left;   //SET USERS NODE LEFT TO THAT OF TRAILS LEFT
				trail->left = users_node;      //SET TRAILS LEFT 
			}

			else if (root->dir_right == true)    //IF THE DIRECTION IS TO THE RIGHT 
			{
				users_node->data = value;        //SET
				users_node->dir_right = true;    //SET USERS DIR RIGHT TO TRUE
				users_node->right = trail->right;  //SET USERS RIGHT TO TRAIL RIGHT
				trail->right = users_node;    //SET TRAILS RIGHT TO USERS NODE
			}
		}

		 if (direction == 'P' && root->head == true)                  //IF USER SELECTED PARENT
		{
			Node* users_node;                 //MAKING A NEW NODE TO HOLD USER'S VALUE
			users_node = new Node;
			temp_root->data = root->data;    //SET TEMP ROOTS TO ROOTS DATA
			temp = root->left;               //SET TEMP TO ROOTS LEFT
			root->data = value;              //SET ROOTS DATA TO THE USER'S VALUE
			users_node->data = temp_root->data;  //SETTING USERS_NODE DATA TO THAT OF TEMPS DATA
			users_node->head = false;           //ENSURE HEAD IS NOT TRUE
			users_node->dir_left = true;       //SET USERS NODE LEFT INDICATOR AS TRUE
			users_node->left = temp;           //SET USERS NODE POINTER LEFT TO TEMP
			users_node->right = NULL;          //SET USERS NODE RIGHT TO NULL
			root->left = users_node;           //SET ROOTS LEFT TO USERS NODE
		}
	 }
	}
//------------------------------//

//SEARCH FUNCTION FOR INSERT//
void searchTree(Node* root,Node* trail, int data) {
	int node_value;
	char node_direction;
	Node* original;
	original = new Node;
	
	if (root != NULL) {                   //IF THERE IS A TREE DO THE FOLLOWING
		if (root->data == data) {         //CHECKING CURRENT NODES VALUES
			cout << "found " << data << ". (L) for left child, (R) for right child, or (P) to set as parent? ";
			cin >> node_direction;       //GET WHAT KIND OF NODE IT SHOULD BE
			node_direction = (char)toupper(node_direction);   //CHANGING OPTION TO UPPERCASE
			cout << "\nWhat value would you like this node to have?";
			cin >> node_value;           //GETTING THE VALUE FOR THE NODE
			while (cin.fail())           //ERROR DETECTION
			{
				cout << "-Not an integer-\n";
				cout << "Enter the value you would like your node to have: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> node_value;
			}
			//original = root;             //SAVING OUR ORIGINAL TREE INCASE IT IS NEEDED LATER
		
			insert(root, trail, node_direction, node_value);  //CALLING THE INSERT FUNCTION

		}
		else {
			trail = root;                  //SETTING OUR TRAIL TO THE CURRENT NODE
			searchTree(root->left,trail, data);  //CALLING WITH THE LEFT POINTER
			trail = root;
			searchTree(root->right,trail, data); //CALLING WITH THE RIGHT POINTER
		}
	}
}
//----------------------//

//SEARCH FUNCTION TO DELETE//
void searchTree_delete(Node* root, int data, Node* trail) {
	//Node* trail;
	Node* original;
	Node* temp;
	temp = new Node;
	original = new Node;	
	
	if (root != NULL) {                         //IF TREE EXIST
		if (root->data == data && root->head == true)  //IF ROOT'S VALUE IS EQUAL TO THE KEY AND IT'S THE HEAD
		{
			if (root->right == NULL) //root doesn't have a right pointer
			{
				root = root->left;   //SET ROOT TO ROOTS LEFT
				free(root);          //FREE ROOTS MEMORY
			}

			else if (root->left == NULL) //root doesn't have a left pointer
			{
				root = root->right;     //SET ROOT TO ROOTS RIGHT
				free(root);             //FREE ROOTS MEMORY
			}

			else //head points to a left and right pointer
			{
				if (root->left->right == NULL) //if roots left pointer has a null right pointer do this
				{
					root = root->left;               //SET ROOT TO ROOTS LEFT
					free(root);                      //FREE ROOTS MEMORY
				}

				else if (root->left->right != NULL)  //IF THE ROOT'S LEFT>RIGHT POINT EXIST DO THIS
				{
					Node* temp_right;               //MAKE A NEW NODE TO HOLD A TEMPORARY VALUE
					temp_right = new Node;
					temp = root->left;              //SETTING TEMPS LEFT POINTER TO THE LEFT POINTER OF THE ROOT NODE
					temp_right = temp->right;       //SET TEMP RIGHT EQUAL TO THE RIDE SIDE OF THE TREE
					root->data = NULL;              //SET THE ROOT'S DATA TO NULL
					
					root = temp;                   //SET ROOT TO THE TMP NODE
					root->left->left->left = temp_right;  //SETTING NODES LEFT POINTERS TO THE TEMP RIGHT NODE
					root->right = NULL;             //SET ROOTS RIGHT POINTER TO NULL
					free(root);                     //FREE ROOTS MEMORY
				}
			}
		}
	 else if (root->data == data && root->head ==false) {               //CHECKING NODE VALUE
	
		 if (root->left == NULL && root->right == NULL) //CHECKING IF NODE IS A LEAF
			{
				if (root->dir_left == true)                   //IF THE NODE IS LEFT OF THE PARENT
				{
					trail->left = NULL;                       //SET TRAILS LEFT POINTER TO NULL
					free(root);                               //FREE ROOTS MEMORY
				}
				else if (root->dir_right == true)             //IF LEAD IS RIGHT OF THE PARENT
				{
					trail->right = NULL;                     //SET TRAIL RIGHT POINTER TO NULL
					free(root);                              //FREE ROOTS MEMORY
				}
			}
			//------------//

			//deleting inner node with no right pointer
			else if (root->left != NULL && root->right == NULL)  //IF THE NODE POINTS TO THE LEFT AND HAS NO RIGHT POINTER ASSIGNED
			{
				if (root->dir_right == true)       //IF THE NODE IS A RIGHT NODE
				{
					trail->right = root->left;    //SET TRAILS RIGHT POINTER TO ROOTS LEFT
					free(root);                   //FREE ROOTS MEMORY
				}
				else if (root->dir_left == true)  //IF IT IS A LEFT POINTER
				{
					trail->left = root->left;     //SET TRAILS LEFT TO ROOTS LEFT
					free(root);                  //FREE ROOTS MEMORY
				}
			}
			//-----------//

			//deleting inner node with no left pointer//
			else if (root->left == NULL && root->right != NULL)    //IF NODE POINTS RIGHT BUT HAS NO LEFT NODE
			{
				if (root->dir_right == true)                      //IF THE NODE IS RIGHT OF THE PARENT
				{
					trail->right = root->right;                   //SET TRAIL RIGHTS POINTER TO ROOT RIGHT
					free(root);                                  //FREE ROOTS MEMORY 
				} 
				else if (root->dir_left == true)                 //IF THE NODE IS LEFT OF THE PARENT
				{
					trail->left = root->right;                  //SET TRAILS LEFT POINTER TO ROOTS RIGHT
					free(root);                                  //FREE ROOTS MEMORY
				}
			}
			//-----------//

			//inner nodes with left and right pointers//
			else if (root->left != NULL && root->right != NULL)         //NODE HAS A LEFT AND RIGHT POINTER ASSIGNED
			{
				//left side of the tree//
				if (root->dir_left == true && root->left != NULL)      //IF IT IS LEFT OF PARENT AND LEFT IS NOT NULL
				{
					if (root->left->right == NULL)                    //CHECKING IF ROOTS LEFT POINTER POINTS TO RIGHT
					{
						root->left->right = root->right;            //SET ROOT LEFT RIGHT TO ROOTS RIGHT
						trail->left = root->left;                   //SET TRAISL LEFT TO ROOTS LEFT
						free(root);                                 //FREE ROOTS MEMORY

					}
					else
					{
						temp = root->left->right;             //SET TEMP TO ROOTS LEFT RIGHT
						root->left->right = root->right;      //SET ROOTS LEFT RIGHT TO ROOT RIGHT
						root->left->left->right = temp;      //SET ROOTS LEFT LEFT RIGHT TO TEMP
						trail->left = root->left;            //SET TRAILS LEFT TO ROOTS LEFT
						free(root);                          //FREE ROOT
					}
				}
				//--//

				//right side//
				else if (root->dir_right == true && root->left != NULL)      //CHECKING IF RIGHT NODE AND LEFT POINTER IS ASSIGNED
				{
					if (root->left->right == NULL)                  //IF ROOTS LEFT RIGHT IS NULL
					{
						root->left->right = root->right;           //SET ROOTS LEFT RIGHT TO ROOT RIGHT
						trail->right = root->left;                 //SET TRAILS RIGHT TO ROOT LEFT
						free(root);                                //FREE ROOT
					}
					else
					{
						temp = root->left->right;                  //SET TEMP TO ROOTS LEFT RIGHT
						root->left->right = root->right;           //SET ROOTS LEFT RIGHT TO ROOT RIGHT
						root->left->left->right = temp;            //SET ROOTS LEFT LEFT RIGHT TO TEMP NODE
						trail->right = root->left;                 //SET TRAILS RIGHT TO ROOT LEFT
						free(root);                                //FREE ROOT
					}
				}
			}	
		}

		else {
			trail = root;                       //SETTING OUR TRAILING NODE
			searchTree_delete(root->left, data, trail); //RECURSIVE CALL WITH THE LEFT POINTER
			trail = root;
			searchTree_delete(root->right, data, trail);//RECURSIVE CALL WITH THE RIGHT POINTER  
		}

	}
} //end delete function

  //MAIN FUNCTION//
int main()
{
	Node* root;
	root = new Node;
	makeTree(root);    //SENDING OUR EMPTY ROOT NODE TO BE CREATED
	char menuchoice;
	int num;

	Node* trail;
	trail = new Node;
	trail = NULL;

	cout << "--Binary Tree Program--\n";
	cout << "(A) Insert\n";
	cout << "(B) Delete\n";
	cout << "(C) Preorder Print\n";
	cout << "(D) Inorder Print\n";
	cout << "(E) Postorder Print\n";
	cout << "(Q) to exit without printing the queue\n";

	do {                                          //WHILE STATEMENT FOR USER INPUT
		cout << "\nEnter selection: ";
		cin >> menuchoice;
		menuchoice = (char)toupper(menuchoice);   //MAKING INPUT UPPERCASE
		switch (menuchoice)                       //BEGIN SWITCH
		{
			//Insert a node
		case'A':
			cout << "\n\nEnter the node that you would like to alter: ";
			cin >> num;
			while (cin.fail())                   //ERROR DETECTION
			{
				cout << "-Not an integer-\n";
				cout << "\nEnter the node that you would like to alter: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> num;
			}
			searchTree(root,trail, num);             //CALLING SEARCH FUNCTION
			break;

			//delete a node
		case 'B':
			cout << "\n\nEnter the node that you would like to delete: ";
			cin >> num;
			while (cin.fail())                //ERROR DETECTION
			{
				cout << "-Not an integer-\n";
				cout << "\nEnter the node that you would like to delete: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> num;
			}
			searchTree_delete(root, num, trail);    //CALLING SEARCH FUNCTION FOR DELETE
			break;

			//PRINT PREORDER
		case 'C':
			cout << "\n\nThe tree in preorder is: ";
			preorderPrint(root);            //CALL PREORDER FUNCTION WITH OUR TREE
			break;

			//print inorder
		case 'D':
			cout << "\n\nThe tree inorder is: ";

			inorderPrint(root);           //CALL INORDER WITH ROOT
			break;

			//printing contents of the queue
		case 'E':
			cout << "\n\nThe tree in postorder is: ";
			postorderPrint(root);       //CALL POSTORDER FUNCTION WITH ROOT
			break;
		default:
			cout << "\nInvalid input\n\n";
		}
	} while (menuchoice != 'Q');        //IF Q EXIT PROGRAM

	return 0;
}