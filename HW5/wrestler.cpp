/* ****************Name: Mariessa Logan
*******************Date: 2/17/19
*******************HW Number 5*/
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

bool isHeel( string name,string *heel, int i) //where i = number of heels
{	for(int j = 0; j < i; j++)
	{
		if( name == heel[j])
			return true;
	}
	return false;
}
bool babyHeelAssigned(string *heel, string *babyFace, string name, int i, int j) //where i – number of baby faces and j = number of heels
{
	if(isHeel(name, heel, j) == true)
		return true;
	else
	{
		for(int k  = 0;k < i; k++)
		{
			if name == babyFace[k]
				return true;
		}
	}
	return false;
}
int main()
{
	string *babyface[10]; 
	string *heel[10];
	int  i = 0;
	int j = 0;
	read from file
		baby = name1; //first name in file line will be possibly a baby
		heelCheck = name2; //second name in the file will possibly be a heel
		if(babyHeelAssigned(baby) == false)
		{
			if(babyHeelAssigned(heel) == false)
			{
				babyface[i] = baby;
				heel[j] = heelCheck;
				i++; j++;
			}
			else 
			{
				if(isHeel(heel )== false )
				{
					heel[j] = baby;
					j++;
				}
				else 
				{
					babyFace[i] = baby;
					i++;
				}
			}
		}
		else
		{
			if(babyHeelAssigned(heel) == false)
			{
					if(isHeel(baby) == false)
					{
						heel[j] = heel;
						j++;
					}
					else
					babyFace[i] = heel;
			}
			else
			{
				if( (isHeel(baby) ==true && isHeel(heel) == true) || (isHeel(baby) ==false && isHeel(heel) ==false))
					printf("\n\n!!!!!!!!!!!\nError: Unable to assign heels and baby faces.\n");
			}
		}
}
