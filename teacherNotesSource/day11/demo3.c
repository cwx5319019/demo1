#include<stdio.h>

int main(){
	char* c[4]={"ENTER","NEW","POINT","FIRST"};
	char** cp[4]={c+3,c+2/*c+1*/,c+1,c};
	char*** cpp=cp;

	printf("%s\n",**++cpp);
/*
	cpp -> &(c+3)
	++cpp -> &(c+2)		cpp -> &(c+2)
	*++cpp -> *&(c+2) -> c+2 -> &"POINT"
	**++cpp -> *&"POINT" -> "POINT" -> &'P'
*/

	printf("%s\n",*--*cpp+++1);
/*
	cpp -> &(c+2)
	cpp++ -> &(c+2)		cpp -> &(c+1)
	*cpp++ -> *&(c+2) -> c+2  -> &"POINT"   //c+1   
	--*cpp++ -> c+1 -> &"NEW"
	*--*cpp++ -> *&"NEW" -> "NEW" -> &'N'
	*--*cpp+++1 -> &'N'+1 -> &'E'
*/
	printf("%s\n",*cpp[-2]+3);
/*
	cpp -> &(c+1)
	cpp[-2] -> *(cpp-2) -> *(&(c+1)-2) -> *&(c+3) -> c+3 -> &"FIRST" 
	*cpp[-2] -> *&"FIRST" -> "FIRST" -> &'F'
	*cpp[-2]+3 -> &'F'+3 -> &'S'
*/

	printf("%s\n",cpp[-1][-1]+1);   
/*
	cpp-> &(c+1)
	cpp[-1] -> *(cpp-1) -> *(&(c+1)-1) -> *&(c+1) -> c+1 -> &"NEW"
	cpp[-1][-1] -> *(cpp[-1]-1) -> *(&"NEW"-1) -> *&"ENTER" ->
	&'E'
	cpp[-1][-1]+1 -> &'E'+1 -> &'N'
*/
	return 0;
}
