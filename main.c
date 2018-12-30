#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "library.h"
#include "quick_sort.h"
#include "sort.h"
 
void main(){
	FILE *fp = fopen("phone_book.txt", "r+");
	tree_node_t *root; 
	makeNUllTree(&root);
	creatTree(fp, &root);
	char name[30];
	int number, select;
	type_data arr_sort[20];
	// printTree(root);
	fclose(fp);

	// creat arr have 10 element to sort then write into file "sort.txt"
	int arr_size;
	FILE *fp_sort = fopen("phone_book.txt", "r+");
		arr_size = creatArray(fp_sort, arr_sort);
	fclose(fp_sort);

	do{
		printf("1 : search\n2 : insert\n3 : edit \n4 : Bubble sort\n5 : Quick sort\n6 : Delete user\n");
		printf("You select : ");
		scanf("%d", &select);
		
		switch(select){
			case 1:{
				//search
				printf("Enter name to find : \n");
					scanf("%s", name);
				tree_node_t *tmp = (tree_node_t*)malloc(sizeof(tree_node_t));
				tmp = Search(name, root);
				printf("%s\t%d\n", tmp->data.name, tmp->data.number);
				break;
			}

			case 2:{	
				//insert ...
				type_data tmp;
				printf("Enter name want to insert : "); 
					scanf("%s", tmp.name);
				printf("Enter phone number want to insert : ");
					scanf("%d", &tmp.number);
				insertNode(tmp, &root);

				// write ... 
				FILE *fp1 = fopen("phone_book.txt", "w+");
				writeFile(fp1, root);
				fclose(fp1);
				break;
			}

			case 3:{
				// fix
				printf("Enter name want to edit : "); 
				scanf("%s", name);
				tree_node_t *tmp1 = (tree_node_t*)malloc(sizeof(tree_node_t));
				tmp1 = Search(name, root);
				printf("%s\t%d\n", tmp1->data.name, tmp1->data.number);
				printf("Enter new phone number for %s\n", tmp1->data.name);
					scanf("%d", &number);
				tmp1->data.number = number;

				FILE *fp2 = fopen("phone_book.txt", "w+");
				writeFile(fp2, root);
				fclose(fp2);
				break;
			}
			case 4:{
				// bubble sort by name
				for (int i = 0; i < arr_size; ++i)
					printf("%s -> %d\n", arr_sort[i].name, arr_sort[i].number );
				sort(arr_sort, arr_size);

				printf(">> result :\n");
				for (int i = 0; i < arr_size; ++i)
					printf("%s -> %d\n", arr_sort[i].name, arr_sort[i].number );
				break;
			}
			case 5:{
				// quick sort by name
				// printf("%d", arr_size);
				for (int i = 0; i < arr_size; ++i)
					printf("%s -> %d\n", arr_sort[i].name, arr_sort[i].number );
				quicksort(arr_sort, 0, arr_size - 1);
				write_sort(arr_sort, arr_size);
				printf(">> result :\n");
				for (int i = 0; i < arr_size; ++i)
					printf("%s -> %d\n", arr_sort[i].name, arr_sort[i].number );
				break;
			}
			case 6:{
				// delete user
				printf("Enter user'name you want to delete : \n");
					scanf("%s", name);
				deleteNode(name, &root);
				FILE *fp6 = fopen("phone_book.txt", "w+");
				writeFile(fp6, root);
				fclose(fp6);
				break;
			}
		}
	}while(select != 7);
}