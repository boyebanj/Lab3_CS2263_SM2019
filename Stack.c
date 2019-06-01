/********************
 * 
 * Sentence reversal program using Linked List based Stack
 * 
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

// create the struct
struct Node_t_t
{
    char *value;
    struct Node_t_t *next;
};

// create the shortform
typedef struct Node_t_t Node_t ;

// function templates
Node_t *newNode(const char *value, Node_t *next);
Node_t *deleteNode(Node_t *current, char **value);
bool pop(Node_t **head, char **value);
bool push(Node_t **head, const char *value);
void List_print(Node_t * head);

/* use void as parameters to silence the gcc warnings */
int main(void)
{
    // initialize our things
    Node_t *Stack = NULL;
    char buffer[BUFFER_SIZE] = { 0 };

    // fill our stack from the user input
   while(1 == scanf("%s", buffer))
   {
        push(&Stack, buffer);

   }
    printf("\n Created Linked list is: "); 
    List_print(Stack);
    

    // write out the sentence in reverse order 
    while(Stack != NULL)
    {
        char *str = NULL;
        bool popped = pop(&Stack, &str);
        if( popped && NULL != str )
        {
	    printf("\n this is working "); 
            printf("%s ", str);
            free(str);
        }
    } 


    return EXIT_SUCCESS;
}

/**************
 * TODO: Finish implementing these functions
 */

/**
 * return a NULL pointer if it failed to allocate memory
 * makes a copy of the string `value` on the heap (see strdup())
 * and stores the pointer in the newly created Node.
 * sets the next node to be the parameter `next`
 */
Node_t *newNode(const char *value, Node_t *next)
{
    Node_t * n = (Node_t*) malloc(sizeof(Node_t));
    if( n == NULL )
    {
       printf("not allocated");
       return NULL;
    }
    else
    {
       char *p1 = strdup(value);
       //printf("%s", p1);
       n -> value = p1;
       n -> next = next;
       return n;
    }
}

/**
 * puts the current node string pointer at the `value` parameter
 * free's the `current` Node.
 * and return the next node.
**/
Node_t *deleteNode(Node_t *current, char **value)
{
        Node_t * p = current;
        if (p == NULL) /* empty list, do nothing */
		return p;
	/* delete the head node */
	else{
        Node_t * q = current->next;
	*value = current->value;
	free (current);
	return q;
	}
}
/**
 * puts the popped string onto `value`
 * Pop the string from the top of the stack using deleteNode
 * update the top of the stack
 * return true on success
 **/
bool pop(Node_t **Stack, char **value)
{
	(*value) = (*Stack)->value;
	Node_t * p = deleteNode(*Stack,value);
	(*Stack) = p;
	return true;
}



 /* Push the string to the top of the stack using newNode
 * update the top of the stack
 * return true if everything is successfull
 **/ 
bool push(Node_t **Stack, const char *value)
{
    Node_t *u = newNode(value,*Stack);
    *Stack = u;
    return true;
}


void List_print(Node_t * head)
{
    while (head != NULL)
    {
       printf("%s", head -> value);
       head = head -> next;
    }
    printf("\n\n");
}
