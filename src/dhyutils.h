/*
*The General Utilities file
*Common functions I personally use frequently in my projects
*##### 2025 ###
* By Ali B. Dhayni
*/

#include <stdlib.h>
#include <stdio.h>

/*
*   			################################
*   			#####LIST RELATED FUNCTIONS#####
*   			################################
*/

 /*##### combines two arrays. 
 *#####  arg0 passed as a reference to a NULL pointer.
 *#####  arg1 and arg3 must be dynamically allocated.
 */
void
dhy_combine_arrays(int** new_array, int* first_array, size_t first_size, int* second_array, size_t second_size)
{
	*(new_array) = (int*)calloc(first_size + second_size, sizeof(int));

	for(int i = 0; i < first_size + second_size; ++i)
		*(*(new_array) + i) = *(first_array + i);	

	for(int i = 0; i < second_size; ++i)
		*(*(new_array) + first_size + i) = *(second_array + i);
	
	return;
}
/*
 *##### initializes and fills a sorted list.
 *##### arg0 must be passed as a reference to a NULL pointer.
 */
void 
dhy_fill_sorted_array(int** array, size_t size)
{
	*(array) = (int*)calloc(size, sizeof(int));
	for(int i = 0; i < size; ++i){
		*(*(array) + i) = i;
	}
	return;
}


/*
*   			################################
*   			#####FILE RELATED FUNCTIONS#####
*   			################################
*/

//getting the size of a file in bytes
size_t 
dhy_file_size(const char* path)
{
	FILE* fileptr = NULL;	
	fileptr = fopen(path, "r");

	if(fileptr == NULL){
		fprintf(stderr, "ERROR: Failed to load file at <%s>\n", path);
		return -1;
	}

	fseek(fileptr, 0, SEEK_END);
	size_t file_size = ftell(fileptr);
	fclose(fileptr);

	return file_size;
}

char*
dhy_read_file(const char* path, size_t size)
{
	FILE* file = NULL;	
	file = fopen(path, "r");
		
	if(!file){
		fprintf(stderr, "ERROR: Failed to load file at <%s>\n", path);
		return NULL;
	}

	char content_array[size];
	int i = 0;
	char c = fgetc(file);
	while(c != EOF){
		content_array[i] = c;	
		c = fgetc(file);
		++i;
	}
	fclose(file);	
	
	char* content = (char*)malloc(size * sizeof(char));
	for(int i = 0; i < size; ++i){
		*(content + i) = content_array[i];
	}

	return content;
}
