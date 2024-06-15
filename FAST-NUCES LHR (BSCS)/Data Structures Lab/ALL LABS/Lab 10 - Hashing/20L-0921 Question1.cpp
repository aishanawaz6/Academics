#include <iostream>
using namespace std;

template<typename k,typename v>
class HashItem
{public:
k key;
v value;
int state; // 0 for occupied, 1 for never used, 2 for deleted
HashItem()
{
state=1;
}
};

template<typename k, typename v>
class HashMap
{
HashItem<k,v>* arr;
int capacity;
int totalElements;
//add any required private function
public:
	HashMap()
	{
	arr=new HashItem<k,v>[10];
	capacity=10;
	totalElements=0;
	}
	void doublecapacity()
	{

	HashItem<k,v>*arr2=new HashItem<k,v>[capacity*2];
	int oc=capacity;
	capacity=capacity*2;
	int i=0;

	while(i<oc)
	{
		if(arr[i].state==0)// if occipied
		{
		int findindex=compressionfunction(arr[i].key.hashCode());
		arr2[findindex].key=arr[i].key;
		arr2[findindex].value=arr[i].value;
		}

	i++;	
	}
	delete []arr;
	arr=arr2;
	}
	int compressionfunction(int hashCode)
	{
	return hashCode%capacity;
	}
void insert(k key, v value) //add the remaining required public functions
{

int hashCode = key.hashCode();

//now apply a compression function and then insert the key, value pair.
int index=compressionfunction(hashCode);
int prev=index;

if(arr[index].state==0) // Quadratic Probing here.
{
	int j=0;
	int prev=index;

while(arr[index].state==0)
{
index=(prev+j^2)%capacity;
	j++;
	if(index==prev) // returns at same index from where started
		break;
}
}
     arr[index].key=key;
     arr[index].value=value;
     arr[index].state=0;
     totalElements++;
	float loadFactor=float(totalElements/capacity);

     if(loadFactor>=0.75)
	 doublecapacity();
}
void remove(k key, v value)
{
	int index=compressionfunction(key.hashCode());
	int p=index;
	for (int i=index,int j=0;true;i=(p+j^2)%capacity,j++)
	{
		if(arr[i].state==1) // stop where never used found
			break;

	if(arr[i].key==key)
		{	
			arr[i].state=2;
	         return;
	    }
	if (j==0)
			continue;
	if (i==index)// back to same place
		break;
	}
	cout<<"Remove not possible"<<endl;
		
}

v* getvalue(k key)
{
	int index=compressionfunction(key.hashCode());
	int p=index;
	int j=0;
	
	for (int i=index;;i=(p+j^2)%capacity,j++)
	{
			if(arr[i].state==1) // stop where never used found
			break;
			
	if(key==arr[i].key)
		{	cout<<"found"<<endl;
	return &arr[i].value;
	    }
	if (j==0)
			continue;
	if (i==index)// back to same place
		break;
}
	return nullptr;
}
v* operator [] (k key)
{int index=compressionfunction(key.hashCode());
int p=index;
	for (int i=index,int j=0;true;i=(p+j^2)%capacity,j++)
	{
				if(arr[i].state==1) // stop where never used found
			break;

	if(arr[i].key==key)
		{	
	return &arr[i].value;
	    }
	if (j==0)
			continue;
	if (i==index)// back to same place
		break;
}
	return nullptr;

}
bool hashKey(k key)
{
	int index=compressionfunction(key.hashCode());
int p=index;
	for (int i=index,int j=0;true;i=(p+j^2)%capacity,j++)
	{	if(arr[i].state==1) // stop where never used found
			break;
if(key==arr[i].key)
	return true;
if (j==0)
			continue;
	if (i==index)// back to same place
		break;
	}
	return false;
}
~HashMap()
{
delete []arr;
arr=nullptr;
totalElements=capacity=0;
}
};

struct Integer
{
int integerNum;
int key;
bool operator == (Integer intt)
{
	return key==intt.key;
}
void insert(int k)
{
	k=key;
}
int hashCode()
{
int hashCode = key << 1 | key>> 5; //it’s the bitwise OR between the key shifted 1 time left and the same key shifted 5 times right.
if(hashCode<0)
	hashCode=hashCode*-1;
return hashCode;
}
};
int main ()
{

	HashMap<Integer, string>hashObj;
	Integer obj;
	obj.insert(5);
	hashObj.insert(obj,"Aisha");
hashObj.getvalue(obj);



	system ("pause");
	return 0;
}