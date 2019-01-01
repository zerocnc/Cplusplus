// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <algorithm>
#include <iterator>
#include <limits>
#include <iostream>

void Merge(int A[], int low, int mid, int high)
{
	int n1 = mid - low + 1 ;
	int n2 = high - mid;

	int *L = new int[n1+1];
	int *R = new int[n2+1];

	for (int i = 0; i < n1; i++)
		L[i] = A[low + i];

	for (int i = 0; i < n2 ; i++)
		R[i] = A[mid + i + 1];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = low; k <= high; k++)
	{
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
	L = nullptr;
	R = nullptr;

	return;
}

void MergeSort(int A[], int low, int high)
{
	int mid = 0;

	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}

	return;
}

void printArray(int x[], int sizeX)
{
	
	for (int ndx = 0; ndx < sizeX; ndx++)
		std::cout << x[ndx] << "\t";
	std::cout << std::endl;

	return;
}

int main()
{
	int x[] = { 3,4,1,2,5,10,8,7,33,12,11,15 };
	//int x[] = { 4,3,1,2 };
	int sizeX = sizeof(x) / sizeof(x[0]) ;

	printf("Given Array is \n");
	printArray(x, sizeX);
	std::cout << "Size is: " << sizeX << std::endl;

	std::cout << "The largest element is " << *std::max_element(x, x + sizeX) << '\n';

	MergeSort(x, 0, sizeX -1 );

	std::cout << "Done" << std::endl;
	printArray(x, sizeX);
	std::cin.get();
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
