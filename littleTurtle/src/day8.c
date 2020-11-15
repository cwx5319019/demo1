/*
	typedef 的使用



*/

typedef int (*PTR_TO_ARRRY)[3] //定义一个数组指针变量

typedef int (*PTR_TO_FUN)(void)  //函数指针

typedef int* (*)()

int fun(void)
{
	return 520;
}

int main(void)
{
	int array[3] = {1,2,3};
	PTR_TO_ARRAY ptr_to_array = &array;

	PTR_TO_FUN ptr_to_fun = &fun;
	printf("%d\n",(*ptr_to_fun)()); //注意这个输出的方法

	return 0;
}
