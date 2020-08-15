#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//char* buff1 = new char[2];
	char buff1[2];
	char buff2[] = "ab";
	char first[] = "123456789012345678901234567890";
	char last[] = "1234567890";
	size_t first_size = strlen(first);
	size_t last_size = strlen(last);
	size_t size = first_size + last_size + 1;
	//char* buff1 = (char*)malloc(size * sizeof(char));
	//char* buff1 = new char[size * sizeof(char)];


	int address_buff1_before_sprintf = (int)&buff1;
	int address_buff2_before_sprintf = (int)&buff2;

	sprintf(buff1, "%s%s", first, last);

	int address_buff1_after_sprintf = (int)&buff1;
	int address_buff2_after_sprintf = (int)&buff2;
	int diff_addr = address_buff2_after_sprintf - address_buff1_after_sprintf;
	

	printf("buff1 address before sprintf = 0x%X\n", address_buff1_before_sprintf);
	printf("buff2 address after sprintf = 0x%X\n", address_buff1_after_sprintf);
	int diff_buff1 = address_buff1_after_sprintf - address_buff1_before_sprintf;
	printf("buff1: after-before = %d = 0x%X\n", diff_buff1, diff_buff1);
	printf("\n\n");

	printf("buff2 address before sprintf = 0x%X\n", address_buff2_before_sprintf);
	printf("buff2 address after sprintf = 0x%X\n", address_buff2_after_sprintf);
	int diff_buff2 = address_buff2_after_sprintf - address_buff2_before_sprintf;
	printf("buff2: after-before = %d = 0x%X\n", diff_buff2, diff_buff2);
	printf("\n\n");

	printf("buff1 address =0x%X\n", address_buff1_after_sprintf);
	printf("buff2 address =0x%X\n", address_buff2_after_sprintf);
	printf("buff2-buff1 = %d = 0x%X\n", diff_addr, diff_addr);
	
	
	printf("\n\n");
	printf("buf1 = %s\n", buff1);
	printf("buf2 = %s\n", buff2);
	getchar();
	return 0;
}

