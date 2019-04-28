/*
*******************Author: Mariessa Logan
*******************Class: 325
*******************date: 2/3/19
****Pseudocode for greedy algorithm
length = line 1 of file
new 3d array [name], [start], [finish]
for i = 0 and i < length
	name.array[i] = first number
	start.array[i] = second number
	finish.array[i] = 3rd number
sort(array)
new array of scheduled classes [length]
scheduled[length-1] = array[0] //put the last to start at the end of the scheduled array
j = length
for i = 1 and i < length
	 if finish.array[i] <= start.scheduled[i-1] 
		name.scheduled[length-1-i] = name.array[i]
print results	*/
#include <iostream>
#include <fstream>
using namespace std;

class activities{
	int name, start, finish;
	public:
		void set_values(int, int, int);
		int get_name();
		int get_start();
		int get_finish();
};
void activities::set_values(int nameInput, int startInput, int finishInput){
	name = nameInput;
	start = startInput;
	finish = finishInput;
}
int activities::get_name()
{
	return name;
}

int activities::get_start()
{
	return start;
}
int activities::get_finish()
{
	return finish;
}
void merge(activities *array, int left, int right, int mid)
{
	//We need to use some iterators so we keep the left, right, and mid variables the same
	int i = left;
	int	j = mid + 1;
	int	k = 0;
	activities	temp[144];
	int finishI;
	int startI;
	int finishJ;
	int startJ;	

	
	while (i <= mid && j <= right)// Merge the two parts into temp[].
	{
		finishI = array[i].get_finish();
		startI = array[i].get_start();
		finishJ = array[j].get_finish();
		startJ = array[j].get_start();

		if (startI > startJ)
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
void mergeSort(activities *array, int left, int right)//This function is to halve the array and call itself recursively until you get to 1 data point
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

void actSelector(activities *array, activities *scheduled, int length, int *scheduleLength)
{
	scheduled[length-1] = array[0];
	scheduleLength++;
	int startArray=0;
	int startSchedule=0;
	int finishArray=0;
	int finishSchedule=0;
	int nameArray=0;
	int bookmark=0;
	for(int i = 0; i < length; i+=3)
	{
		bookmark = length - *scheduleLength;
		startArray = array[i].get_start();
		finishArray = array[i].get_finish();
		std::cout << "First for loop start\n";
		startSchedule = scheduled[bookmark].get_start();
		std::cout << "First for loop startSchedule\n";
		finishSchedule = scheduled[bookmark].get_finish();
		std::cout << "First for loop before if\n";
		if(finishArray < startSchedule)
		{
			*scheduleLength++;
			scheduled[bookmark] = array[i];
			std::cout << "First for loop in if statement\n";
		}

	}
	for(int j=0; j < *scheduleLength; j++)
		{
			nameArray = scheduled[length - 1 - j].get_name();
			std::cout << "Activities are: " << nameArray << "\n";
		}
}


int main()
{
	ifstream file; //The variable for the file to be read
	int arr[144]; //This is the original array
	activities arr1[144]; //Here is the array that will be sorted by merge.  
	int n = 0; //This will keep the count of the array.
	activities arr2[144]; //This one will be sorted by insert sort
	int *scheduleLength=0;
	file.open("act.txt");
	int bookmark=0;
	if (!file)
	{
		cout << "Error, no file read\n";
	}
	else {
		int set=1;
		int start=0;
		int finish=0;
		int name=0;
		while (!file.eof())
		{
			std::cout << "Set " << set << "\n";
			int numAct = 0; //number of tests in file
			file >> numAct;
			bookmark+= numAct + 1;
			for(int i = 0; i < numAct*3; i++)
			{
				file >> arr[n];
				
				n++;

			}
		mergeSort(arr1, 0, n - 1);//Calll the merge sort function on the arr1
			for(int i = bookmark; i < n; i+=3)
			{
				
				arr1[i].set_values(arr[i], arr[i+1], arr[i+2]);
				start = arr1[i].get_start();
				name = arr1[i].get_name();
				finish = arr1[i].get_finish();
				std::cout << "Iteration: " << i/3 << "\nName: " << name;
				std::cout << "\nStart: " << start << "\nFinish: " << finish << "\n";
			
			}
			set++;
		std::cout << "Set: " << set << "\n";

			//merge sort
			//mergeSort(arr1, 0, n - 1);//Calll the merge sort function on the arr1
			actSelector(arr1, arr2, n, scheduleLength);
		}
	}
	file.close();
	return 0;
}
