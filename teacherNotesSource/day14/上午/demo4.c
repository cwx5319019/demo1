typedef union Data{
	int a ;
	int b ;
	int c ;
}data_t;

int main(){
	data_t data = {0};
	data.a = 1;
	printf("a = %d\n",data.a);
	data.b = 2;
	printf("a = %d,b = %d\n",data.a,data.b);
	data.c = 3;
	printf("a = %d,b = %d,c = %d\n",data.a,data.b,data.c);

	printf("%lu\n",sizeof(data));
	return 0;
}
