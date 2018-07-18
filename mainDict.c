#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

int main(void){
	int choice;
	char lithuanian[50];
	char english[50];
	char english_find[50];
	struct node* find_result;
	char delete_entry[50];
	int word_count;
	int quit = 0;
	while(!quit){
		printf("Enter choice: \n");
		printf("1 to add new word\n");
		printf("2 to find an English word\n");
		printf("3 to check how many words\n");
		printf("4 to delete an entry\n");
		printf("5 to exit program\n");
		scanf(" %d", &choice);
		switch(choice){
			case(1):
				printf("Enter Lithuanian meaning: \n");
				scanf(" %s", &lithuanian);
				printf("Enter English meaning: \n");
				scanf(" %s", &english);
				insert(lithuanian, english);
				break;
			case(2):
				printf("Enter word to search for: \n");
				scanf("%s", english_find);
				find_result = find(english_find);
				printf("English: %s \n", find_result->english);
				printf("Lithuanian: %s \n", find_result->lithuanian);
				break;
			case(3):
				word_count = size();
				printf("%d\n", word_count);
				break;
			case(4):
				printf("Enter an English entry to delete: \n");
				scanf(" %s", &delete_entry);
				unload(delete_entry);
				break;
			case(5):
				quit = 1;
				break;
		}
	}
	return 0;
}
