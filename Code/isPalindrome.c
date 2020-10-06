#include <stdio.h>

int isPalindrome(char *str);
void test();

int main(void)
{
	test();
	return 0;
}

int isPalindrome(char *str)
{
	int succes;
	int len;
	for (len = 0; str[len] != '\0'; len++)
		;

	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

void test()
{
	printf("\n\n-- Tests de la fonction 'isPalindrome(char* str)' --\n");
	printf("Entrees\t\tValeur attendue\tValeur obtenue\tTest reussi\n");

	int testCount = 4;
	char *strInputs[] = {"kayak", "civic", "abba", "daadi"};
	int results[] = {1, 1, 1, 0};

	for (int i = 0; i < testCount; i++)
	{
		int actualResult = isPalindrome(strInputs[i]);
		char *successState = results[i] == actualResult ? "OUI" : "NON";
		printf("\"%s\"\t\t%d\t\t%d\t\t%s\n", strInputs[i], results[i], actualResult, successState);
	}
}