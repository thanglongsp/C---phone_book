void sort(type_data arr[], int arr_size){
	type_data stamp;
	for (int i = 0; i < arr_size; ++i)
		for (int j = 0; j <= i; ++j)
		{
			if(strcmp(arr[i].name, arr[j].name) < 0){
				stamp = arr[i];
				arr[i] = arr[j];
				arr[j] = stamp;
			}
		}

	FILE * fp = fopen("sort.txt", "w+");
	for (int i = 0; i < arr_size; ++i)
		fprintf(fp , "%s\t%d\n", arr[i].name, arr[i].number);
	fclose(fp);
}