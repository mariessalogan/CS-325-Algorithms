#include <iostream>
#include <fstream>
using namespace std;

void merge(int *array, int left, int right, int mid)
{
	//We need to use some iterators so we keep the left, right, and mid variables the same
	int i = left;
	int	j = mid + 1;
	int	k = 0;
	int	temp[144];
	

	
	while (i <= mid && j <= right)// Merge the two parts into temp[].
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = array[j];
			k++;
			j++;
		}
	}

	
	while (i <= mid)// Insert all the remaining values from i to mid into temp[].
	{
		temp[k] = array[i];
		k++;
		i++;
	}

	
	while (j <= right)// Insert all the remaining values from j to right into temp[].
	{
		temp[k] = array[j];
		k++;
		j++;
	}


	
	for (i = left; i <= right; i++)// Assign sorted data stored in temp[] to a[].
	{
		array[i] = temp[i - left];
	}
}
void mergeSort(int *array, int left, int right)//This function is to halve the array and call itself recursively until you get to 1 data point
{
	int mid = 0;//Keep track of the middle of each halving
	if (left < right)
	{
		mid = (left + right) / 2;
		// Split the data into two half.
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		// Merge them to get sorted output.
		merge(array, left, right, mid);
	}
}

void insertSort(int *array, int length) //This function will sort using insertion.
{
	int i;
	int current = 0; //This is going to be the value that we are sorting in the loop
	int j = 0;
	for (i = 0; i < length; i++)
	{
		current = array[i];
		j = i - 1; //We want j to equal the previous number so we can compare
		while (j >= 0 && current < array[j])//We want to only run this if current is not the first number in the array and it is less than the prev number
		{
			array[j + 1] = array[j]; //Make the number after j, the current j, so you can move the larger numbers to the right
			j--;
		}
		array[j+1] = current; //put the current iteration in that spot
	}
}

int main()
{
	ifstream file; //The variable for the file to be read
	int arr[144]; //This is the original array
	int arr1[144]; //Here is the array that will be sorted by merge.  
	int n = 0; //This will keep the count of the array.
	int arr2[144]; //This one will be sorted by insert sort
	file.open("data.txt");
	if (!file)
	{
		cout << "Error, no file read\n";
	}
	else {
		std::cout << "The array from the file is:\n";
		while (!file.eof())
		{
			file >> arr[n];
			std::cout << arr[n] << "\n";
			arr1[n] = arr[n];
			arr2[n] = arr[n];
			n++;
		}
		std::cout << "Your array has " << n << " numbers.\n";
		//merge sort
		mergeSort(arr1, 0, n - 1);//Calll the merge sort function on the arr1
		std::cout << "Merge sort sorted your array to: \n";
		for (int i = 0; i < n; i++)
		{
			cout << arr1[i] << "\n";
		}
		insertSort(arr2, n);//Call the insert sort function on arr2
		std::cout << "Insert sort sorted your array to: \n";
		for (int i = 0; i < n; i++)
		{
			cout << arr2[i] << "\n";
		}
	}
	file.close();
	return 0;
}
