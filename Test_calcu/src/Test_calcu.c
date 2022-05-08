#include <stdio.h>
#include <stdlib.h>				//Программа векторный калькулятор
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char t;
	t = 'y';
	while (t == 'y')			//Пока t == y калькулятор будет повторяться.
	{

		long long res,i,k,l,p;
		double *Q,*W;
		int size;
		float a,b;
		char c,op;
		res = 1;
		printf("Select an operation:(+ - * / ^ ! v)");
		scanf(" %c",&c);		//В переменную 'c' записывается операция
		switch(c)
		{
		case 'v':
			printf("Введите размерность векторов: ");
			scanf("%i",&size);
			Q =malloc(size*sizeof(int));
			W =malloc(size*sizeof(int));
			printf("Впишите значения первого вектора: ");
			for (int i=0; i<size;i++) scanf("%lf",&Q[i]);
			printf("Впишите значения второго вектора: ");
			for (int i=0; i<size;i++) scanf("%lf",&W[i]);
			printf("Select an operation:(+ - *) ");
			scanf(" %c",&op);
			if (op == '+')		//операция сложения векторов
			{
				printf("Сложение векторов: ");
				for(int m=0;m<size;m++) printf("%lf ",Q[m]+W[m]);
				printf("\n");
			}
			else if (op == '-')		//операция вычитания векторов
			{
				printf("Разность векторов: ");
				for (int m=0; m<size;m++) printf("%lf ",Q[m]-W[m]);
				printf("\n");
			}
			else if (op == '*')		//операция умножения векторов
			{
				printf("Скалярное произведение векторов: ");
				for (int m=0; m<size;m++) printf("%lf ",Q[m]*W[m]);
				printf("\n");
			}
			else printf("Ошибка");// если неправильный ввод
			free(Q);
			free(W);
			break;
		case '+': 				//операция сложения
			printf("Enter the first number: ");
				scanf(" %f",&a);
			printf("Enter the second number: ");
				scanf(" %f",&b);
			printf("%f + %f = %f\n",a,b,a+b);
			break;
		case '-':				//операция вычитания
			printf("Enter the first number: ");
				scanf(" %f",&a);
			printf("Enter the second number: ");
				scanf(" %f",&b);
			printf("%f - %f = %f\n",a,b,a-b);
			break;
		case '*':				//операция умножения
			printf("Enter the first number: ");
				scanf(" %f",&a);
			printf("Enter the second number: ");
				scanf(" %f",&b);
			printf("%f * %f = %f\n",a,b,a*b);
			break;
		case '/':				//операция деления
			printf("Enter the first number: ");
				scanf(" %f",&a);
			printf("Enter the second number: ");
				scanf(" %f",&b);
			printf("%f / %f = %f\n",a,b,a/b);
			break;
		case '!':				//операция 'Логарифм числа'
			printf("Enter a number: ");
			scanf(" %lld",&l);
			for (long long n=1;n<=l;n++)
				{
					i = n;
					res = res * i;
				}
			printf("Logarithm of a number %lld = %lld\n",l,res);
			break;
		case '^':				//операция число в заданой степени
			printf("Enter a number: ");
			scanf(" %lld",&k);
			printf("Enter the degree: ");
			scanf(" %lld",&l);
			p = l;
			while (p != 0)
				{
					res = res * k;
					p = p-1;
				}
			printf("%lld ** %lld = %lld\n",k,l,res);
			break;
		default:
			printf("Non-existent operation\n");//если неправильный ввод
		}
	printf("\n");
	printf("Продолжить работу калькулятора?(y/n) ");//запрос на продолжение работы калькулятора
	scanf(" %c",&t);
	}
	printf("End of work");//если работа калькулятора завершена
}
