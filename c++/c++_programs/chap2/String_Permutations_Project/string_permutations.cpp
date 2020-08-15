# include <stdio.h>

int count=0;
 
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int start_index, int n) 
{
   int j; 
   if (start_index == n)
   {
	 count++;
     printf("%d. %s\n", count, a);
   }
   else
   {
       for (j = start_index; j <= n; j++)
       {
          swap((a+start_index), (a+j));
          permute(a, start_index+1, n);
          swap((a+start_index), (a+j)); //backtrack
       }
   }
} 
 
/* Driver program to test above functions */
int main()
{
   char a[] = "1234";  
   permute(a, 0, 3);
   getchar();
  return 0 ;
}