#include <iostream>
#include <fstream>
using namespace std;



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
		array[j + 1] = current; //put the current iteration in that spot
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
