// Aisha Muhammad Nawaz 20L-0921 BSCS Section 3E1 Final Exam Q3
#include <iostream>
#include <unordered_map>
using namespace std;
//Using data structure hashMap because it is the most effecient as inserting elements and finding if they already exist taskes least time.
void createmap(unordered_map<int,bool>&mp,int*set1,int *set2,int size1,int size2)
{
    for(int i=0;i<size1;i++)
	mp[set1[i]]=false;

	for(int j=0;j<size2;j++)
	mp[set2[j]]=true;
}

bool IsDisjoint(int*set1,int *set2,int size1,int size2,int&CommonElement)
{
	bool f=false;
unordered_map<int,bool>mp;
createmap(mp,set1,set2,size1,size2);
	
	for (int i=0;i<size1;i++)
	{
		if(mp[set1[i]]==true)
		    {  
			f=true;
			CommonElement=set1[i];
			break;
			}
	}

	if(f)
		cout<<"Not Disjoint. "<<CommonElement<<" is common in two sets."<<endl;
	else
		cout<<"Yes, Disjoint. There is no common element in two sets."<<endl;

	return f;
}

int main ()
{
	int set1[]={12,34,11,9,3};
	int set2[]={2,1,3,5};
	int c=0;
	IsDisjoint(set1,set2,5,4,c);
	
	
	int _set1[]={12,34,11,9,3};
	int _set2[]={7,2,1,5};
	int _c=0;
	IsDisjoint(_set1,_set2,5,4,_c);
	

system("pause");
return 0;
}