#include <stdio.h>
int num[3], fact[200], sum[200];

int main ()
{
	int n, number, hand=0;
	int bNum, bFact, bSum, i, j, x;

	scanf ("%d", &n);
	
	bFact = 1;
	fact[0] = 1;
	for (number=2; number<=n; number++)
	{
		for (i=0,j=number;  j!=0;  num[i]=j%10,j/=10,i++);
		bNum = i;

		for (i=0; i<bNum; i++)
			for (j=0; j<bFact; j++)
				sum[i+j] += num[i]*fact[j];
		bSum = bNum+bFact-1;
	

		hand = 0;
		for (i=0; i<bSum; i++)
		{
			fact[i]=(sum[i]+hand)%10;
			hand = (sum[i]+hand)/10;
			sum[i]=0;
		}
		if (hand) fact[bSum++] = hand;
		bFact = bSum;
	}

	//printf ("bFact=%d\n",bFact);
	for (i=bFact-1; i>=0; i--)
		printf ("%d", fact[i]);
	printf ("\n");
	

	return 0;
}
