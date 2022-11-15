#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void print_list(struct node* list) {
    while(list != NULL) {
        printf("%d\n", list->data);
        list = list->next;
    }
}

/*
 *  RECURSIVELY swaps the positions of the first and third nodes in each
 *  triplet of nodes in a linked list.
 *  This must be achieved by reassigning/relinking the next attribute
 *  of the list nodes. You may NOT overwrite the data attribute of
 *  existing nodes and you may NOT malloc or free existing nodes.
 *
 *  You may assume that the list length is a multiple of 3.
 *
 *  THIS MUST BE ACHIEVED RECURSIVELY TO EARN FULL CREDIT.
 *  THERE WILL BE A MANUALLY-GRADED COMPONENT WORTH APPROXIMATELY
 *  50% CREDIT FOR THIS PROGRAMMING QUESTION. A RECURSIVE SOLUTION
 *  (CORRECT OR OTHERWISE) WILL AUTOMATICALLY EARN THE MANUAL COMPONENT.
 * 
 *  Example:
 *  before:  A - B - C - D - E - F - G - H - I
 *  after:   C - A - B - F - E - D - I - H - G
 *
 *  @param list - pointer to the first node in a linked list to be rearranged.
 *  @return - pointer to the front of the rearranged list.
 */
struct node* Rearrange(struct node* list) {
  if(list == NULL) { // length of 0
      return NULL;
  }

  struct node* a = list;
  struct node* b = list->next;
  struct node* c = list->next->next;
  struct node* d = list->next->next->next;
  struct node* d_rearranged;

  if (d == NULL) { // length of 3
    a->next = NULL;
    b->next = a;
    c->next = b;
    list = c;

    // printf("Rearrange: \n");
    // print_list(list);
    return list;
  }

  // length >= 3
  a->next = d;
  b->next = a;
  c->next = b;
  list = c;

//   printf("Rearrange: \n");
//   print_list(list);

  
  d_rearranged = Rearrange(d);
  a->next = d_rearranged;
  
  return list;
}



int main(void)
{
  
  struct node C = {3, NULL};
  struct node B = {2, &C};
  struct node A = {1, &B};

  

  struct node* list = &A;


//   printf("list->next->next->next: %p\n", list->next->next->next);
  print_list(list);
  Rearrange(list);

  printf("\nrearranged:\n");
  print_list(list);

  return 0;
}