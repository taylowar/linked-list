
#include <stdio.h>
#include <stdlib.h>

// Defines the type of the linked list node value 
// !! printf must be adjusted !!
#define LL_VAL size_t 

typedef struct _list {
    LL_VAL val;
    struct _list *next;
} LinkedList;

// Creates a pointer to the linked list node
LinkedList* ll_create(LL_VAL val)
{
    LinkedList *ll = malloc(sizeof(LinkedList));
    ll->val  = val;
    ll->next = NULL;
    return ll;
}

// Recursive version of printing
// Why would anyone print a LL this way?
void ll_print_rec(LinkedList ll, size_t f)
{
    if (f == 0) {
        printf("%zu", ll.val);
    } else {
        printf("->%zu", ll.val);
    }
    
    if (ll.next != NULL) {
        ll_print_rec(*ll.next, ++f);
    } else {
        printf("\n");
    }
}

// Prints a linked list in it's entirety
void ll_print(LinkedList ll)
{
    printf("%zu", ll.val);
    LinkedList *next = ll.next;
    while (next != NULL) {
        printf("->%zu", next->val);
        next = next->next;
    }
    printf("\n");
}

// Inserts a node to the end of a linked list
void ll_add_node(LinkedList *ll, LinkedList *node) 
{
    if(ll->next == NULL) {
        ll->next = node;
        return;
    }
    return ll_add_node(ll->next, node);
}

// Creates a new linked list pointer based on val and inserts it at the end of the given linked list
void ll_push(LinkedList *ll, LL_VAL val)
{
    LinkedList *nl = ll_create(val);
    ll_add_node(ll, nl);
}

int main()
{
    
    LinkedList lh = *ll_create(0);

    for (size_t i = 1; i < 10; ++i) {
        ll_push(&lh, i);
    }

    ll_print(lh);

    return 0;
}

