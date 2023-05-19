#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
class Search{
	private:
	public:
		int BinarySearch(t*,int,int,t);
		int BinaryQuizOne(t*,int,int,t);
		int binaryQuizTwo(t*,int,int,t);
		int binaryQuizThree(t*,int,int,t);		
};

template <class t>
int  Search<t>::BinaryQuizOne(t arr[],int l,int r,t key)
{
	if(l<r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==key)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
		  
		}
		if(arr[mid]>key)
		{
			return BinaryQuizOne(arr,l,mid,key);
		}
		else{
			return BinaryQuizOne(arr,mid,r,key);
		}
	}
}
template <class t>
int  Search<t>::BinarySearch(t arr[],int l,int r,t key)
{
	if(l<r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==key)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
			return mid;
		  
		}
		if(arr[mid]>key)
		{
			return BinarySearch(arr,l,mid-1,key);
		}
		else{
			return BinarySearch(arr,mid+1,r,key);
		}
	}
}

template <class t>
int  Search<t>::binaryQuizTwo(t arr[],int l,int r,t key)
{
	while(l<r)
	{
	
		int mid=(r+l)/2;
		
		if(arr[mid]<arr[mid-1])
		{
			if(arr[mid]>key)
			{
				BinarySearch(arr,mid,r,key);
			}
			else
			{
				BinarySearch(arr,mid,r,key);
			}
			return 0;
		}
		if(arr[mid]<arr[l])
		{
			r=mid+1;
		}
		else{
			l=mid-1;
		}
		
	}
}

template <class t>
int  Search<t>::binaryQuizThree(t arr[],int l,int r,t key)
{
	if(l<=r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==mid)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
		    return mid;
		}
		if(arr[mid]>mid)
		{
			return binaryQuizThree(arr,l,mid-1,key);
		}
		else{
			return binaryQuizThree(arr,mid+1,r,key);
		}
	}
}


int main()
{
	int choose;
	int arr[]={-2,-1,2,3,7,52,62,72,82};
	int x=3;
	Search<int> obj;
	int size=(sizeof(arr)/sizeof(arr[0]));
	do{
		cout<<"Enter the choose \n";
		cout<<"1 for Question one without (mid-1 & mid+1)  \n";
		cout<<"2 for Question two  rotated array \n";
		cout<<"3 for Question three find arr[k]=k \n ";
		cin>>choose;
		switch(choose)
		{
			case 1 :obj.BinaryQuizOne(arr,0,size,x);
			 break;
			case 2 : obj.binaryQuizTwo(arr,0,size,x);
			 break;
			case 3 : obj.binaryQuizThree(arr,0,size,arr[0]);
			 break;
			case 0 :continue;
			 break;
			default:cout<<"wrong choose \n";
			
		}
		
	}while(choose!=0);
	
	getch();
	return 0;
	
}
