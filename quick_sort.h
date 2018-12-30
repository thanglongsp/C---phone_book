void SWAP(type_data *x, type_data *y){
	type_data stamp;
	if(strcmp(x->name, y->name) > 0){
		stamp = *x;
		*x = *y; 
		*y = stamp;
	}
}

void quicksort(type_data a[], int left, int right){
	int i, j;
	char pivot[20];
	if(left < right){
		i = left;
		j = right + 1;
		strcpy(pivot, a[left].name);
		do{	

			do i++;
				while(i <= right && strcmp(a[i].name, pivot) < 0);
				// printf("%d\n", a[i] );

			do j--;
				while(j >= left + 1 && strcmp(a[j].name, pivot) > 0);
				// printf("%d\n", a[j]);
			if(i < j) SWAP(&a[i], &a[j]);
		}while(i < j);	
	SWAP(&a[left], &a[j]);
	quicksort(a, left, j - 1);
	quicksort(a, j + 1, right);
	}
}

void write_sort(type_data arr_sort[], int arr_size){
	FILE * fp_q_sort = fopen("sort.txt", "w+");
		for (int i = 0; i < arr_size; ++i)
			fprintf(fp_q_sort , "%s\t%d\n", arr_sort[i].name, arr_sort[i].number);
		fclose(fp_q_sort);	
}