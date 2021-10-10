#include<stdio.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
struct employee
{
	int identifyNumber;
	char lastname[20];
	float payrate;
	float workhour;
};
void main()
{
	struct employee emp[6] = 
	{
		{3462,"Jones",4.62, 40.0},{6793, "Robbins", 5.83, 38.5}, {6985,"Smith",5.22, 45.5},
		{7834, "Swain",6.89,40.0},{8867,"Timmins",6.43,35.5},{9002,"Williams",4.75,42.0}
	};
	printf("Payroll Report \n");
	for (int i = 0; i < 6; i++)
	{
		printf("Number: %d Name: %s Gross Pay: %f \n", emp[i].identifyNumber, emp[i].lastname, emp[i].payrate * emp[i].workhour);
	}


}