// Overriding insert of an array 

void insert (int v, int pos, int *arr, int* size) {

	for (int i = pos; i < size - 1; ++i)
	{
		A[i+1] = A[i]; // In this case, the last element will be LOST or overridden. We should increase the size first. 
	}	
	A[pos] = v;
	*size++;
}


