/*
I MADE THESE COMMENTS TO SEE IF THERE IS SUCH A THING AS TOO MANY COMMENTS

Rajpreet Judge
CSE 222
Nick Macias
02/01/2020

Same functionality as PA1 it involves inserting into a linked list in a sorted order and delete
search for numbers, when deleting it will free the allocated memory and at the end of them program
when the user exits the program it will release all the memory allocated.
*/


#include<stdio.h>  //this coding stuff doesnt work with this
#include<stdlib.h> //or this

struct node{  //making a struct node with 
  int data;  //data field
  struct node *next;  //and next field
}; //this is a closing curly brace

struct node *init();              //done; creates the sentinel and thats it called at start of main
int add(struct node*, int);      //done; add into the list sorted
void print(struct node*);       //done; prints the whole list
int delete(struct node*, int); //done; deletes a number
int search(struct node*, int);//done; searches for a num  
void allfree(struct node*);     //done; frees the whole list after the user exits
void error();

//--------------------------------------------------------------------------------------------------------------------

void main () { //this is the main body of the program it will be doing the heavy lifting here...like ronnie coleman in his prime

  struct node *list; //creating a node to set up as a sentinel
  
  list = init(); //calling init to create the sentinel node

  char letter[120], extra[120]; //just some arrays to capture input from user
  int num, result; //declaring 2 variables named num and result as type ints

  printf(">"); // this here is a critical part of the program...I dont think it will work without printing this sideways carrot/hat
  fgets(letter,120,stdin); //grabbing the users input...I swear if you enter anything thats not valid I WILL EXPLODE
 			  // blank space
  while(letter[0] != 'x') { //Main while loop...

    switch(letter[0]) { //switch statement start at this for only cases of I P D S X
      case 'i': //adding into the list  
      		//blank space again MAN this wont go away
        if(sscanf(letter,"i %d%s", &num, extra) == 1) { //checcking the number entered to see if the entry is even valid
	  if(search(list, num) == 1) { //calling search for the number first
            printf("NODE ALREADY IN LIST\n"); //found the number
            break; //break out of the case... dont break your computer
          }  //curly brace
          if(add(list, num) != 0) { //calling add and passing it the list and number
            printf("SUCCESS\n"); //SUCCCCCCESSSSSSS is printed if added
          } else { //ELSE in the statement
            printf("OUT OF MEMORY\n"); //out of memory, I havent tested this part to be honest...but running through the code by hand it would work.
          } //closing the else for some random reason...its a 1 line
        } else //elsey else
            error(); //calling error to print error messages.. SAW YOU DO THIS AND IT REALLY HELPED MAKE MY MAIN LOOK SO MUCH CLEANER
      break; //breaking out of this case...PLEASE DONT BREAK YOUR COMPUTER
 			// more blank space
      case 'p': //printing
        if(letter[1] == '\n') { //checking to see if there was any input after 'p' 
          print(list); //calling print to print the list
        } //closing curly brace
        else { //start of the else incase extra stuff was entered
          error(); //calling error to print the prompts again
        } //me closing more 1 line elses :^|
      break; //breaking out of this case
     
      case 's': //search
        if(sscanf(letter,"s %d%s", &num, extra) == 1) { //checking for the number and if extra stuff was added.
          if(search(list, num) == 1) { //calling search to find number
            printf("FOUND NUMBER\n"); //print prompt...found that number NICK!
          } //closing this off
          else { //more curly braces on a 1 line else wdf
            printf("NOT FOUND\n"); //didnt find so print this
          } //i need to stop this lmaooo too many curly braces
        } else error(); //extra stuff was entered after the number so print prompts
      break; //break out of the case
      
      case 'd': //delete
        if(sscanf(letter,"d %d%s", &num, extra) == 1) { //checking to see if extra stuff was being entered DANG USERS
          if(search(list, num) == 0) { //searching to see if number is even in the list before deleteing
            printf("NUMBER NOT IN LIST\n"); //printing this if the number was not found
            break; //break out of the case
          } //closing this curly brace
        delete(list, num); //calling delete to actually delete the number
        printf("SUCCESS\n"); //printing this prompt after deleteing
        } //this curly brace makes this look very weird but idk
        else //LOOK I STOPPED THE BRACES FOR 1 LINE ELSES
        error(); //printing error prompts
      break; //breaking out of the case
	    //empty space like an initialized array but is storing only 0 :(
      case 'x': //exit for x
        if(letter[1] == '\n') //checking to see if you entered extra
          break; //break out of statement
        else //else
          error(); //you entered incorrect please read the prompts
      break; //break out
  	    //I need to fill empty spaces while I listen to spanish music I cant understand but I can vibe/groove to it
      default: error(); //default case if anything other than the specified letters are entered
    } // ending curly for switch statements
    printf(">"); //printing the carrot again but insde the while
    fgets(letter,120,stdin); //getting the user input inside of while
  } //closing this curly brace
  allfree(list); //calling allfree which will free all the memory that was allocated for this program after you exit
} //closing the main with this curly brace

//--------------------------------------------------------------------------------------------------------------------

struct node * init() { //this init will create the senitel node

  struct node *sentinel; //creating variable type of struct node named sentinel
  sentinel = malloc(sizeof(struct node)); //calling malloc to allocate memory for the node called sentinel
  sentinel->data=2408;sentinel->next = NULL; //assigning the data to some random value and next pointer to NULL
  return(sentinel); //returning the sentinel node created back to the main function to be used throughtout the program
}

//--------------------------------------------------------------------------------------------------------------------

int search(struct node*list, int num) { //function called for searching for numbers

  struct node *ptr; //creating var of type struct node called ptr

  ptr = list->next; //setting ptr to equal the next field of the sentinel passed into function

  while(ptr != NULL) { //while condition is while ptr doesnt equal the NULL
    if(ptr->data == num) { // checking to see if that data value at current node matches number searched for
      return (1); //returning 1 for found number
    }
    ptr = ptr->next; //stepping through the linked list
  }
  return (0); //return statement that is returning the number interget equal to 0;
} //closing curly brace

//--------------------------------------------------------------------------------------------------------------------

void print(struct node *list) { //printing contents of the list
  		    //more blannk space 
  struct node *ptr; //creating var ptr of type struct node *
  ptr = list->next; //setting ptr to equal the nest field of the sentinel passed into function
                    //blank space
  while(ptr != NULL) { //looping until ptr equals NULL
    printf("%d\n", ptr->data); //printing data values of where ptr is
    ptr = ptr->next; //stepping through the list
  }                  // mia mia mia too many comments nick??
  return; //this is a return statement
}    //this is a closing curly brace

//--------------------------------------------------------------------------------------------------------------------

void allfree(struct node *list) { //frees all the allocated memory

  struct node *temp, *freeme; //creating the variables of type struct node
  temp = list->next; //setting temp to point where the sentinel is pointing

  while(temp != NULL) { //while temp which is pointing to the node ahead doesnt equal NULL BUDDY!!!
    freeme = temp; //freeme is the node we will free because we need a temp storage or eslse we ill free our pointer
    temp = temp->next; //next field of the temp node
    free(freeme); //quiero tirarnos fotos y que se hagan viral
  } //curly brace
  free(list); // dile que tu eres mia, mia tu sabe que eres mia, mia
} //more curly braces

//--------------------------------------------------------------------------------------------------------------------

int delete(struct node *list, int num) { //delete function that deletes obviously and also frees the memory of the deleted node
					//I love this commenting but I hope i dont lose points for all these... you did say can never have too many comments
  struct node *prev, *curr, *comp; //creating variables of struct node type
					//blank space im gunna make all these look super nice!!! REMYYYY
  if(search(list,num) == 0) //searching for the number to see if its even int he lsit MIA MIA MIA
    return (0); //if not found 0 is returned Haciendo!!!

  prev = list; //prev is now basically sentinel
  curr = prev->next; //curr is now pointing one ahead of the sentinel (or prev)
			//blank space man this never ends like an infinite loop huh?!?
  while(curr != NULL) { //while we dont hit NULL or find a node that points to NULL...those kinda say the same LOL
    if(curr->data == num) {  //if the data at this curr node is the same as the number we want to delete then you will go into the if
      prev->next = curr->next; //make prev just skip over that node
      free(curr); //free that node by calling free
      return (1); //return 1 for node deleted
    } //closing the if
  prev = curr; //making prev point to curr
  curr = curr->next; //curr point to the next node
  } //closing while
} //closing the function

//----------------------------------------------------------------------------------------------------------------------

int add(struct node *list,int num) { //this is the add function that almost made me jump off my roof...AFTER ENDLESS HOURS OF DEBUGGING AND BANGING MY HEAD AGAINST GDB here we go!!
				    //this blank space is very important to our space time continum...(been awake for about 19ish hours now and these comments about 90% of them are absolutely useless
  struct node *newnode, *prev, *curr, *swap, *place; //making variables of struct node type I probably didnt use some
  newnode = malloc(sizeof(struct node)); //getting a new node

  if(newnode == NULL) //if we run of a space is the only way I see this pointing to NULL
    return 0; //returning 0 for OUT OF MEMORY

  newnode->data = num; //putting the data value into the new created node from get_node()
  if(list == NULL) { //if we dont even have anything in our list to begin with i.e sentinel points to NULL
    list->next = newnode; //make the sentinel point to the new first node
    newnode->next = NULL; //make the first node point to the NULL
    return (1); //return 1 for SUCCESS
  } //close that curly

  prev = list; //making prev equal to the sentinel 
  curr = list->next; //assigning curr to equal the pointer to the next field or node ahead
  
  while((curr != NULL) && (curr->data < num)) {  //looping until we find spot where number ahead node data is smaller than number passed
    prev = curr; //reassigning the pointers
    curr = curr->next; //making curr move one node down
  }

  swap = prev->next; //swapping the pointers
  prev->next = newnode; //pointing the prev next value to the new node
  newnode->next = swap; //making the new node point to curr

  return (1); //returning 1 for success
}

//-----------------------------------------------------------------------------------------------------------------------

void error() {  														 //the one function that actually brought me peace
 														         	//this made my main smaller by like 40 lines LOL could actually read the code!!
  printf("i number (where number is any legal integer).\n"); 								       //i mean i dont think I need to comment these but its what ever
  printf("p This will print the list in order, on one line, with the numbers separated by spaces.\n");                        //ill still do it wihle i listen to spanish music while
  printf("s number, This searches for the given number, and prints either FOUND or NOT FOUND.\n");                           //lacking the ability to actually understand spanish
  printf("d number, This deletes the node containing the given number, and prints either SUCCESS or NODE NOT FOUND.\n");    //i love it anyways
  printf("x, This should cause the program to exit.\n"); 								   //I could literally fall asleep face first into this laptop and here I am commenting this like a madman....
															  //
  return; 														 //return from this and maybe it will return my sanity with it
} 															//end of the error function

