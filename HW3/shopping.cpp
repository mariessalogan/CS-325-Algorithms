#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int ShoppingSpree(int N, int F, int *P, int *W, int *M)
{

	if(F == 0)
		return 0;
	int maxPrice = 0; //initialize max price holder
	for(int i = 0 ; i < F; i++) //loop through every family member
	{	
		int ** PRICE;
		int items = N +1;
		int carry = M[i] + 1;
		PRICE = new (nothrow) int *[items];//CREATE A TABLE OF N +1 ITEMS BY M[I]+1 ITEMS
		for(int j = 0; j< items; j++){
		
			PRICE[j] = new int[carry];
		}
		for(int k = 0; k < N; k++)
		{
			for(int l = 0; l < M[i]; i++)
			{
				if(k ==0 || l ==0)
				{	
					PRICE[k][l] = 0; //cover the base case
				}
				else if( W[k-1] <= l) 
				{//if the weight is less than or equal to max person weight
					int max = PRICE[k-1][l];
					if(max < (P[i-1] +PRICE[k-1][l-W[k-1]]))
					{
						max = P[i-1] + PRICE[k-1][l-W[k-1]];
					}
					PRICE[k][l] = max;
				}	
				else
					PRICE[k][l] = PRICE[k-1][l];
				
				maxPrice += PRICE[N][M[i]]; //max price for this person should be in last entry of the array.  
			}	
		}
		
		
	}	
	return maxPrice;
}
int main(){
	ifstream inputFile;
	ofstream outputFile;
	outputFile.open("results.txt");
	inputFile.open("shopping.txt");
	if(!inputFile){
		std::cout << "Error, no file read\n";
	}
	else{
		int T = 0;
		inputFile >> T;
		for(int i = 0; i < T; i++)
		{  //LOOP FOR EACH TEST CASE
			int N = 0;
			inputFile >> N; //this will have the number of items in the file
			int *P;
			int *W;
			P = new (nothrow)int[N];//DYNAMIC ARRAY FOR PRICES
			W = new (nothrow)int[N];//DYNAMIC ARRAY FOR WEIGHT
			int F = 0;
			for(int j = 0; j < N; j++)
			{	
				inputFile >> P[j]; //get price of items in order
				inputFile >> W[j];//get weight of items in order

			}
			inputFile >> F; //get number of family members

			int * M;
			M = new (nothrow)int[F];//dynamic array for family member weight max
			for (int j = 0; j < F; j++)
			{
				inputFile >> M[j]; //READ ALL OF THE MAX WEIGHTS A FAMILY CAN CARRY
			}
			outputFile << "Test case " << i+1 << "\n----------------------\n";
			outputFile << "Max dollar price: " <<ShoppingSpree(N, F, P, W, M) << "\n\n\n"; //send the info to another function	
			outputFile << "Member items\n";
			for(int z = 0; z < F; z++)
			{
				outputFile << z << ": ";
				for(int y = 0; y < N; y++)
				{
					outputFile << " " << P[y];
				}
			}
			outputFile << "\n";
		}
	inputFile.close();
	outputFile.close();
	}
	return 0;
}
