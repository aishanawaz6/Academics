//20L-0921 AISHA MUHAMMAD NAWAZ DAA SECTION 4A1 BSCS HOMEWORK #4 
#include <iostream>
using namespace std;

float hw4BruteForce(float n,int&newn, float&sum) //Q1 BRUTE FORCE RECURSIVE SOLUTION
{
	if (n <= 0)
		return 1.0;

	for(int i=0;i<n;i++)
		hw4BruteForce(i, newn, sum);

	while (newn < n - 1)
	{
		newn++;
		sum = sum + hw4BruteForce(n, newn, sum);
	}
	return ((2.0/n)*sum+n);

}
float hw4BruteForce(float n) //Wrapper Function //Q1 BRUTE FORCE RECURSIVE SOLUTION
{
	int  newn = -1;
	float  s = 0.0;
	return hw4BruteForce(n, newn, s);
}

//Top Down recursive(Dynamic Programming) Solution
float hw4TopDownRecDP(int n,float result[])
{
	if (result[n] == -1)
	{
		if (n <= 0)
			result[n] = 1;
		else
		{
			int  newn = -1;
			float  s = 0.0;
			return hw4BruteForce(n, newn, s);
		}
	}
	return result[n];

}
float hw4TopDownRecDP(int n)
{
	float* result = new float[5];
		for (int i = 0; i < 5; i++)
			result[i] = -1;
	
		return hw4TopDownRecDP(n, result);
}
//Q1 Bottom Up (Iterative Dynamic Programming) Solution
float hw4BottomUpItDP(int n) 
{
	if (n <= 0)
		return 1;

	float sum = 0;

	for (int i = 0; i < n; i++)
		sum = sum + hw4BruteForce(i); 



	return ((2.0/n)*sum+n);
}

int main()
{
	//Q1 BRUTE FORCE RECURSIVE SOLUTION
	cout << "Q1 BRUTE FORCE RECURSIVE SOLUTION: " << endl;
	for (float i = 0.0; i < 5.0; i = i + 1.0) 
		cout << "ANS FOR " << i << " is: " << hw4BruteForce(i) << endl;
	
	//Q1 Top Down recursive(Dynamic Programming) Solution
	cout << "Q1 Top Down recursive(Dynamic Programming) Solution: " << endl;
	for (float i = 0.0; i < 5.0; i = i + 1.0)
		cout << "ANS FOR " << i << " is: " << hw4TopDownRecDP(i) << endl;

	//Q1 Bottom Up (Iterative Dynamic Programming) Solution
	cout << "Q1 Bottom Up (Iterative Dynamic Programming) Solution: " << endl;
	for (float i = 0.0; i < 5.0; i = i + 1.0)
		cout << "ANS FOR " << i << " is: " << hw4BottomUpItDP(i) << endl;

	system("pause");
	return 0;
}