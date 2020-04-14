#pragma warning(disable:4996)


#include<stdio.h>
#include<math.h>
#include<windows.h>


int gcd(int a, int b)//求最大公约数的算法

{
	if (a%b == 0)
		return b;
	else;
	return gcd(b, a%b);
}




void add()//加法运算
{	
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt","w");
	int a, b, answer,n,r;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
			a = rand() % r ;	//获取随机数
			b = rand() % r;
			answer = a + b;
			fprintf(fp1, "%d . %d + %d = \n",i+1, a, b);
			fprintf(fp2, "%d . %d\n", i+1,answer);
			printf("\n\t\t %d + %d = ", a, b);
	}

}
void minu()//减法运算
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, answer, n,r;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		a = rand() % r; //被减数
		b = rand() % r; //减数
		if (a < b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}//防止出现被减数小于减数的情况
		answer = a - b;
		fprintf(fp1, "%d . %d - %d = \n", i + 1, a, b);
		fprintf(fp2, "%d . %d\n", i + 1, answer);
		printf("\n\t\t %d - %d = ", a, b);
	}
}

void mul()//乘法运算
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, answer,n,r;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		a = rand() % r;
		b = rand() % r;
		answer = a * b;
		fprintf(fp1, "%d . %d * %d = \n", i + 1, a, b);
		fprintf(fp2, "%d . %d\n", i + 1, answer);
		printf("\n\t\t %d * %d = ", a, b);
	}
}
void di()//除法运算
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int r,n;
	float a, b, answer;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		a = rand() % r+1; //被除数
		b = rand() % r+1; //除数
		answer = a / b;
		fprintf(fp1, "%d . %f / %f = \n", i + 1, a, b);
		fprintf(fp2, "%d . %.1f\n", i + 1,answer );//保留一位小数
		printf("\n\t\t %d / %d = ", a, b);
	}


}

void fra_add()//分数的加法运算
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator,denominator,x;//x为最大公约数
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //第一个数的分子
		b = rand() % r + 1; //第一个数的分母
		c = rand() % r + 1; //第二个数的分子
		d = rand() % r + 1; //第二个数的分母
		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//确保得到真分数
		numerator = a * d+ b * c;
		denominator = b * d;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d + %d/%d = \n", i + 1, a, b, c, d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator/x, denominator/x);
		printf("\n\t\t %d/%d + %d/%d = ", a, b, c, d);
	}
}

void fra_minu()	//分数减法运算 
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator, denominator, x;//x为最大公约数
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //第一个数的分子
		b = rand() % r + 1; //第一个数的分母
		c = rand() % r + 1; //第二个数的分子
		d = rand() % r + 1; //第二个数的分母

		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//确保得到真分数

		if (a * c - b * d < 0) {	//如果运算出现负数，则两个分数互换
			a = a ^ c;
			c = a ^ c;
			a = a ^ c;

			b = b ^ d;
			d = b ^ d;
			b = b ^ d;
		}
		numerator = a * d - b * c;
		denominator = b * d;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d - %d/%d = \n", i + 1, a, b, c, d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator / x, denominator / x);
		printf("\n\t\t %d/%d - %d/%d = ", a, b, c, d);
	}

}

void fra_mul()         //分数乘法运算
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d,n,r, numerator, denominator,x;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r+1; //第一个数的分子
		b = rand() % r+1; //第一个数的分母
		c = rand() % r+1; //第二个数的分子
		d = rand() % r+1; //第二个数的分母
		if (a > b){
				a = a ^ b;
				b = a ^ b;
				a = a ^ b;
		}
		if (c > d) {
				c = c ^ d;
				d = c ^ d;
				c = c ^ d;
		}//确保得到真分数
		numerator = a * c;
		denominator = b * d;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d * %d/%d = \n", i + 1, a,b,c,d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator / x, denominator / x);
		printf("\n\t\t %d/%d * %d/%d = ",a ,b ,c , d);
	}

}

void fra_di()	//分数除法运算 
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator, denominator, x;
	srand(time(NULL));
	printf("请输入题目数量：");
	scanf("%d", &n);
	printf("请输入数值范围：");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //第一个数的分子
		b = rand() % r + 1; //第一个数的分母
		c = rand() % r + 1; //第二个数的分子
		d = rand() % r + 1; //第二个数的分母
		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//确保得到真分数
		numerator = a * d;
		denominator = b * c;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d / %d/%d = \n", i + 1, a, b, c, d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator / x, denominator / x);
		printf("\n\t\t %d/%d / %d/%d = ", a, b, c, d);
	}
}

void main()
{
	FILE *fp;
	int choise,answer;
	while (1)
	{
		printf("\n请选择：\n");
		printf("\t\t\t  整数加法运算（请输入1）\n");
		printf("\t\t\t  整数减法运算（请输入2）\n");
		printf("\t\t\t  整数乘法运算（请输入3）\n");
		printf("\t\t\t  整数除法运算（请输入4）\n");
		printf("\t\t\t  分数加法运算（请输入5）\n");
		printf("\t\t\t  分数减法运算（请输入6）\n");
		printf("\t\t\t  分数乘法运算（请输入7）\n");
		printf("\t\t\t  分数除法运算（请输入8）\n");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			add();
			break;
		case 2:
			minu();
			break;
		case 3:
			mul();
			break;
		case 4:
			di();
			break;
		case 5:
			fra_add();
			break;
		case 6:
			fra_minu();
			break;
		case 7:
			fra_mul();
			break;

		case 8:
			fra_di();
			break;
		}
	}
}