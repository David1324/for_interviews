#include <iostream>
#include <time.h>
using namespace std;

#define N 10

void swap(int* p_num1, int* p_num2)
{
	int temp = *p_num1;
	*p_num1 = *p_num2;
	*p_num2 = temp;
}

//struct list_el {
//   int val;
//   struct list_el * next;
//};
//
//typedef struct list_el item;
//
//item* find_prev(item* head, item* curr)
//{
//	item* prev = head;
//	if (head == curr) return NULL;
//
//	while (prev->next != curr)
//	{
//		prev = prev->next;
//	}
//
//	return prev;
//}
//
//void reverse_list(item* head)
//{
//	item* temp = head;
//
//
//	while (temp
//	item* last = temp;
//
//	while (last->next != NULL)
//	{
//		last = last->next;
//	}
//
//	swap (&(temp->val), &(last->val));
//}
//
//int main() {
//   item * curr, * head;
//   int i;
//
//   head = NULL;
//
//   for(i=1;i<=10;i++) {
//      curr = (item *)malloc(sizeof(item));
//      curr->val = i;
//      curr->next  = head;
//      head = curr;
//   }
//
//   curr = head;
//
//   while(curr) {
//      printf("%d\n", curr->val);
//      curr = curr->next ;
//   }
//
//    // wait until user is ready before terminating program
//    // to allow the user to see the program results
//    system("PAUSE");
//  return 0 ;
//}

#if 1
int main () {
	int a[N];
	for (int i=0 ; i<N ; i++)
	{
		a[i] = i+1;
	}
	int rand_index;

	srand(time(NULL)); //for the number to be random each time you run the program

	for (int i=0 ; i<N ; i++)
	{
		//cout << "a[" << i << "] = " << a[i] << ", ";
		cout << a[i] << ", ";
	}
	cout << endl;


	//int start_index = 0;
	for (int i=0 ; i<N ; i++)
	{
		rand_index = rand() % (N-i) + i;
		cout << "rand_index (between " << i << " and " << N-1 << ") = " << rand_index << endl;

		if (i != rand_index)
		{
			swap(a[i], a[rand_index]);
		}
	}

	for (int i=0 ; i<N ; i++)
	{
		//cout << "a[" << i << "] = " << a[i] << ", ";
		cout << a[i] << ", ";
	}
	cout << endl;



    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
  return 0 ;
}
#endif

