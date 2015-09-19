#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t* first = head;
	list_t* second = head->next;
	uint8_t inserted = 0;
	
	// Check if new_element should go up front	
	if(head->index > new_element->index) {
		new_element -> next = head;
		head = new_element;
		inserted = 1;
	}	
	// Check against each possible move until it's greater then new_element, or quit
	while(second && !inserted) {
		// if new_element fits nicely between the first and second
		if((new_element->index > first->index) && (new_element->index < second-> index)) {
			first -> next = new_element;
			new_element -> next = second;
			inserted = 1;
		}
		// advance second and first
		first = first -> next;
		second = second -> next;
	}

	// Check if new_element should go on the end
	if(!inserted) {
		first->next = new_element;
		new_element->next = NULL;
	}

	// Do my own printing
	list_t* index = head;
	char string_for_int[35];
	while(index) {
		index = index->next;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* first = NULL;
	list_t* second = head;
	list_t* third = head->next;

	while(third) {
		//printf("in loop\n");
		second->next = first;
		first = second;
		second = third;
		third = third->next;
		//printf("finished loop\n");	
	}
	second->next = first;

	// Do my own printing
	//list_t* index = head;
	//char string_for_int[35];
	//while(index) {
	//	index = index->next;
	//}


	return second;
}

