typedef struct 
{
	char name[30];
	int number;
}type_data;

typedef struct tree_node 
{	
	type_data data;
	struct tree_node *left;
	struct tree_node *right;
}tree_node_t;

// Basic function in tree

// create init tree
void makeNUllTree(tree_node_t **T){
	*T = NULL;
}

// Check empty tree
int emptyTree(tree_node_t *root){
	return root == NULL;
}

// insert node into BST by name
void insertNode(type_data a, tree_node_t **root){
	if(*root == NULL){
		(*root) = (tree_node_t*)malloc(sizeof(tree_node_t));
		(*root)->data = a;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(strcmp(a.name, (*root)->data.name) > 0)
		insertNode(a, &(*root)->right);	
	else insertNode(a, &(*root)->left);
}

// read file to creat tree
void creatTree(FILE *fp, tree_node_t **tree){
	while(1){
		type_data *tmp = (type_data*)malloc(sizeof(type_data));
		fscanf(fp, "%s%*c%d%*c", tmp->name, &tmp->number);
		if(feof(fp)) break;
		insertNode(*tmp, tree);
		free(tmp);	
 	}
}

// read file into arr
int creatArray(FILE *fp, type_data arr_sort[]){
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, "%s%*c%d%*c", arr_sort[i].name, &arr_sort[i].number);
		i ++ ;
	}
	return i - 1;
}

// write into file when insert tree
void writeFile(FILE *fp, tree_node_t *tree){
	if(tree != NULL){
		writeFile(fp, tree->left);
		fprintf(fp , "%s\t%d\n", tree->data.name, tree->data.number);
		writeFile(fp, tree->right);
	}
}

// seach by name, return pointer tree_node
tree_node_t* Search(char *a, tree_node_t *root){
	if(root == NULL) return NULL;
	else if(strcmp(a, root->data.name) == 0){
		printf(">> Status : Found\n"); 
		return root;
	}
	else if(strcmp(a, root->data.name) > 0) 
		Search(a, root->right);
	else Search(a, root->left);
}

// delete most left return string
char* deleteMin(tree_node_t **root){
	char *k = (char*)malloc(30*sizeof(char));
	if((*root)->left == NULL){
		strcpy(k, (*root)->data.name);
		(*root) = (*root)->right;
		return k;
	}
	else
		return deleteMin(&(*root)->left);
}
// delete user
void deleteNode(char *a, tree_node_t **root){
	if(*root != NULL){
		if (strcmp(a, (*root)->data.name) > 0)
			deleteNode(a, &(*root)->right);
		else if(strcmp(a, (*root)->data.name) < 0)
			deleteNode(a, &(*root)->left);
		else if((*root)->left == NULL && (*root)->right == NULL)
			*root = NULL;
		else if((*root)->left == NULL)
			*root = (*root)->right;
		else if((*root)->right == NULL)
			*root = (*root)->left;
		else strcpy((*root)->data.name, deleteMin(&(*root)->right));
	}
}

// print tree
void printTree(tree_node_t *tree){
	if(tree != NULL){
		printTree(tree->left);
		printf("%s\t%d\n", tree->data.name, tree->data.number);
		printTree(tree->right);
	}
}
