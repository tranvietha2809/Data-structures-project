#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASH 1000
#define LENGTH 45
//Define a node

typedef struct node{
    char lithuanian[LENGTH + 1];
    char english[LENGTH +1];
    struct node *next;
}
node;

int hash(const char* hash_word)
{
    unsigned int idx = 0;
    int i;
    int n;
    for (i=0, n=strlen(hash_word); i<n; i++)
        idx = (idx << 2) ^ hash_word[i];
    return idx % HASH;
}


struct node *head = NULL;
struct node *hashtable [HASH];
int count = 0;

struct node* find(char *word_check)
{
    char new_word[strlen(word_check)+1];
    int i;
    for (i =0; i < strlen(word_check)+1; i++){
       new_word[i] = tolower((int) word_check[i]);
    };
    int hash_check = hash(new_word);
    struct node *cursor = hashtable[hash_check];
	while(cursor != NULL){
		if (strcmp(cursor -> english, word_check) == 0){
			return cursor;
		}
		else{
			cursor = cursor -> next;
		};
	}; 
	printf("Cannot find the word! \n");
	exit(0);
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
void insert(char *lithuanian, char *english)
{
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf(stderr, "Error loading ");
        exit(0);
    } 
    int idx = hash(english);
    strcpy(new_node -> lithuanian, lithuanian);
	strcpy(new_node -> english, english); 
	new_node -> next = hashtable[idx];
	hashtable[idx] = new_node;
    count++;
    return;
}


int size(void)
{
    return count;
}


void unload(char* word_check)
{
	char new_word[strlen(word_check)+1];
    int i;
    for (i =0; i < strlen(word_check)+1; i++){
       new_word[i] = tolower((int) word_check[i]);
    };
    int hash_check = hash(new_word);
    struct node *cursor, *temp; 
	cursor = hashtable[hash_check];
	//if head node has the word to remove
	if(cursor -> english == word_check){
		if(cursor -> next == NULL){
			free(cursor);
			cursor == NULL;
			count--;
			return;
		}
		temp = hashtable[hash_check];
		head->english = head->next->english;
		head->lithuanian = head->next->lithuanian;
		cursor = head->next;
		head->next = head->next->next;
		free(cursor);
		count--;
		return;
	}
	while(cursor != NULL){
		if (strcmp(cursor -> english, word_check) == 0){
			temp->next = cursor->next;
			free(cursor);
			count--;
			return;
		}
		else{
			temp = cursor;
			cursor = cursor -> next;
		};
	}; 
	printf("Cannot find the word! \n");
	exit(0);
}
