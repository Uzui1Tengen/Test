#include <stdio.h>
#include <stdlib.h>				//Программа векторный калькулятор
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	long long res,i,k,l,p;
	double *Q,*W;
	int size;
	float a,b;
	char c,t,f;
	FILE* input, * output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	do			//Пока t == y калькулятор будет повторяться.
	{
		res = 1;
		fscanf(input, " %c",&f);		//В переменную 'f' записывается операция
		fscanf(input, " %c",&c);		//Переменная 'c' определяет какой нам нужен калькулятор (Вектор(v) или обычный(s))
		switch(c)
		{
		case 'v':
			fscanf(input, "%i",&size);
			Q =malloc(size*sizeof(int));
			W =malloc(size*sizeof(int));
			for (int i=0; i<size;i++) fscanf(input, "%lf",&Q[i]);
			for (int i=0; i<size;i++) fscanf(input, "%lf",&W[i]);
			fprintf(output,"( ");
			for (int i = 0; i < size; i++) fprintf(output, "%lf ", Q[i]);
			fprintf(output,") %c ",f);
			fprintf(output,"( ");
			for (int i = 0; i < size; i++) fprintf(output, "%lf ", W[i]);
			fprintf(output,") = ( ");
			if (f == '+')		//операция сложения векторов
			{
				for(int m=0;m<size;m++) fprintf(output, "%lf ", Q[m]+W[m]);
			}
			else if (f == '-')		//операция вычитания векторов
			{
				for (int m=0; m<size;m++) fprintf(output, "%lf ",Q[m]-W[m]);
			}
			else if (f == '*')		//операция умножения векторов
			{
				for (int m=0; m<size;m++) fprintf(output, "%lf ",Q[m]*W[m]);
			}
			else fprintf(output, "Ошибка");// если неправильный ввод
			fprintf(output,")");
			free(Q);
			free(W);
			break;
		case 's':
			switch(f)
			{
			case '+': 				//операция сложения
					fscanf(input, " %f",&a);
					fscanf(input, " %f",&b);
				fprintf(output, "%f + %f = %f\n",a,b,a+b);
				break;
			case '-':				//операция вычитания
					fscanf(input, " %f",&a);
					fscanf(input, " %f",&b);
				fprintf(output, "%f - %f = %f\n",a,b,a-b);
				break;
			case '*':				//операция умножения
					fscanf(input, " %f",&a);
					fscanf(input, " %f",&b);
				fprintf(output, "%f * %f = %f\n",a,b,a*b);
				break;
			case '/':				//операция деления
					fscanf(input, " %f",&a);
					fscanf(input, " %f",&b);
				fprintf(output, "%f / %f = %f\n",a,b,a/b);
				break;
			case '!':				//операция 'Логарифм числа'
				fscanf(input, " %lld",&l);
				for (long long n=1;n<=l;n++)
					{
						i = n;
						res = res * i;
					}
				fprintf(output, " !%lld = %lld\n",l,res);
				break;
			case '^':				//операция число в заданой степени
				fscanf(input, " %lld",&k);
				fscanf(input, " %lld",&l);
				p = l;
				while (p != 0)
					{
						res = res * k;
						p = p-1;
					}
				fprintf(output, "%lld ** %lld = %lld\n",k,l,res);
				break;
			default:
				fprintf(output, "Non-existent operation\n");//если неправильный ввод
			}
		}

	fclose(input);
	fclose(output);
	}while (t == 'y');       // Остановка программы
}
