/*
puts an element X that belongs to an array A
in the first position A[0], moving all preceeding elements
one position towards the end
example:
A = {2 , 8 , 4 , 6 , 11 , 7}
X = 6
A becomes {6 , 2 , 8 , 4 , 11 , 7}
*/

#include <iostream>
#include <algorithm>
using namespace std;

void put(int key,int* arr,const int SIZE){
	int i = 0 ,temp;
	/*
we move in the array from the beginning towards the end
each time we encounter a number we swap it with position 0
if we found the target we stop
	*/
	while(i < SIZE){
		//swapping
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		if(arr[0] == key)break;
		i++;
	}

}


int main(){
	const int SIZE = 1000000;
	const int begin = 100000;
	int arr[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = i;
	}

	for (int i = begin; i > 0; --i)
	{
		put(i , arr , SIZE);
	}
}