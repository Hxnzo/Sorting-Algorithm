#include <iostream>
#include <cmath>



using namespace std;


//functions
void display(int array[], int size);
int extractOdd(int list1[], int size1, int list2[], int size2, int* list3);
int extractEven(int list1[], int size1, int list2[], int size2, int* list3);
int merge(int list1[], int size1, int list2[], int size2, int* list3);
int mergeSort(int list1[], int size1, int list2[], int size2, int* list3);



int main()
{
	int list1Values, list2Values;
	int* list1, * list2, * list3;
	int list3Size = 0;
	int counter1 = 1;
	int counter2 = 1;
	cout << "Enter size of list 1: ";
	cin >> list1Values;
	cout << "Enter size of list 2: ";
	cin >> list2Values;

	list1 = new int[list1Values];
	list2 = new int[list2Values];
	list3 = new int[list1Values + list2Values];

	cout << "\nEnter " << list1Values << " integers for list 1: " << endl;
	for (int i = 0; i < list1Values; i++) 
	{ 
		cout << "Please enter value #" << counter1 << " for List 1: ";
		cin >> list1[i];
		counter1++;
	}

	cout << "\nEnter " << list2Values << " integers for list 2: " << endl;
	for (int i = 0; i < list2Values; i++) 
	{
		cout << "Please enter value #" << counter2 << " for List 2: ";
		cin >> list2[i];
		counter2++;
	}

	//display list 1
	cout << "\nList 1: ";
	display(list1, list1Values);
	//display list 2
	cout << "\nList 2: ";
	display(list2, list2Values);

	//run function and display
	list3Size = extractOdd(list1, list1Values, list2, list2Values, list3);
	cout << "\nList 3 after extracting odds from list 1 and list 2: " << endl;
	display(list3, list3Size);

	//run function and display
	list3Size = extractEven(list1, list1Values, list2, list2Values, list3);
	cout << "\nList 3 after extracting evens from list 1 and list 2: " << endl;
	display(list3, list3Size);

	//run function and display
	list3Size = merge(list1, list1Values, list2, list2Values, list3);
	cout << "\nList 3 after merging data from list 1 and list 2: " << endl;
	display(list3, list3Size);

	//run function and display
	list3Size = mergeSort(list1, list1Values, list2, list2Values, list3);
	cout << "\nList 3 after sorting the merged data from list 1 and list 2 in ascending order: " << endl;
	display(list3, list3Size);

	system("pause");
}


int merge(int list1[], int size1, int list2[], int size2, int* list3) 
{
	//list3 = new int[size1+size2];
	int counter = 0;

	for (int i = 0; i < size1; i++) 
	{
		list3[counter++] = list1[i];
	}

	for (int i = 0; i < size2; i++) 
	{
		list3[counter++] = list2[i];
	}

	return counter;
}

int mergeSort(int list1[], int size1, int list2[], int size2, int* list3) 
{
	int size = merge(list1, size1, list2, size2, list3);

	for (int i = 0; i < size; i++) 
	{
		int minIndex = i;
		for (int j = i; j < size; j++) 
		{
			if (list3[j] < list3[minIndex]) 
			{
				minIndex = j;
			}
		}

		//swap index i with minIndex
		int temp = list3[i];
		list3[i] = list3[minIndex];
		list3[minIndex] = temp;
	}

	return size;
}

//function to display contents of array of given size
void display(int array[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int extractOdd(int list1[], int size1, int list2[], int size2, int* list3) 
{
	//list3 = new int[size1+size2];
	int counter = 0;

	for (int i = 0; i < size1; i++) 
	{
		if (list1[i] % 2 == 1)
		{
			list3[counter++] = list1[i];
		}
	}

	for (int i = 0; i < size2; i++)
	{
		if (list2[i] % 2 == 1)
		{
			list3[counter++] = list2[i];
		}
	}

	return counter;
}



int extractEven(int list1[], int size1, int list2[], int size2, int* list3) 
{
	//list3 = new int[size1+size2];
	int counter = 0;

	for (int i = 0; i < size1; i++) 
	{
		if (list1[i] % 2 == 0)
		{
			list3[counter++] = list1[i];
		}
	}
	for (int i = 0; i < size2; i++) 
	{
		if (list2[i] % 2 == 0)
		{
			list3[counter++] = list2[i];
		}
	}

	return counter;
}

