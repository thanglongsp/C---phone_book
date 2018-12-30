void check_phonenumber(type_data a, tree_node_t **root){
	if(*root == NULL){
		(*root) = (tree_node_t*)malloc(sizeof(tree_node_t));
		(*root)->data = a;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(strcmp(a.name, (*root)->data.name) > 0)
		check_phonenumber(a, &(*root)->right);	
	else check_phonenumber(a, &(*root)->left);
}