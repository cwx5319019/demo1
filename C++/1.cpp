#include <iostream>
using namespace std;

void* copy(void* str,void* ptr ,size_t len)
{
	char* pstr = static_cast(str);
	char* pptr = static_cast(ptr);
	int i = 0,j = 0;
	if(pstr > pptr && pstr){
		for(i = 0;i<len;i++){
			pstr[i] = pptr[i];
		}	 
	}else{
		for(j = 0;j<len;j++){
			pptr[i] = pstr[i];
		}
	
	}
	return 

}

int main(void)
{
	int str[] = {0,1,2,3,4,5};
	int ptr[6] = {0,0,0,0,0,0};
	copy(ptr,str,sizeof(str));




	return 0;
}



