#pragma warning(disable:4996)


#include<stdio.h>
#include<math.h>
#include<windows.h>


int gcd(int a, int b)//�����Լ�����㷨

{
	if (a%b == 0)
		return b;
	else;
	return gcd(b, a%b);
}




void add()//�ӷ�����
{	
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt","w");
	int a, b, answer,n,r;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
			a = rand() % r ;	//��ȡ�����
			b = rand() % r;
			answer = a + b;
			fprintf(fp1, "%d . %d + %d = \n",i+1, a, b);
			fprintf(fp2, "%d . %d\n", i+1,answer);
			printf("\n\t\t %d + %d = ", a, b);
	}

}
void minu()//��������
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, answer, n,r;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		a = rand() % r; //������
		b = rand() % r; //����
		if (a < b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}//��ֹ���ֱ�����С�ڼ��������
		answer = a - b;
		fprintf(fp1, "%d . %d - %d = \n", i + 1, a, b);
		fprintf(fp2, "%d . %d\n", i + 1, answer);
		printf("\n\t\t %d - %d = ", a, b);
	}
}

void mul()//�˷�����
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, answer,n,r;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
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
void di()//��������
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int r,n;
	float a, b, answer;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	for (int i = 0; i < n; i++) {
		a = rand() % r+1; //������
		b = rand() % r+1; //����
		answer = a / b;
		fprintf(fp1, "%d . %f / %f = \n", i + 1, a, b);
		fprintf(fp2, "%d . %.1f\n", i + 1,answer );//����һλС��
		printf("\n\t\t %d / %d = ", a, b);
	}


}

void fra_add()//�����ļӷ�����
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator,denominator,x;//xΪ���Լ��
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //��һ�����ķ���
		b = rand() % r + 1; //��һ�����ķ�ĸ
		c = rand() % r + 1; //�ڶ������ķ���
		d = rand() % r + 1; //�ڶ������ķ�ĸ
		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//ȷ���õ������
		numerator = a * d+ b * c;
		denominator = b * d;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d + %d/%d = \n", i + 1, a, b, c, d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator/x, denominator/x);
		printf("\n\t\t %d/%d + %d/%d = ", a, b, c, d);
	}
}

void fra_minu()	//������������ 
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator, denominator, x;//xΪ���Լ��
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //��һ�����ķ���
		b = rand() % r + 1; //��һ�����ķ�ĸ
		c = rand() % r + 1; //�ڶ������ķ���
		d = rand() % r + 1; //�ڶ������ķ�ĸ

		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//ȷ���õ������

		if (a * c - b * d < 0) {	//���������ָ�������������������
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

void fra_mul()         //�����˷�����
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d,n,r, numerator, denominator,x;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r+1; //��һ�����ķ���
		b = rand() % r+1; //��һ�����ķ�ĸ
		c = rand() % r+1; //�ڶ������ķ���
		d = rand() % r+1; //�ڶ������ķ�ĸ
		if (a > b){
				a = a ^ b;
				b = a ^ b;
				a = a ^ b;
		}
		if (c > d) {
				c = c ^ d;
				d = c ^ d;
				c = c ^ d;
		}//ȷ���õ������
		numerator = a * c;
		denominator = b * d;
		x = gcd(numerator, denominator);
		fprintf(fp1, "%d . %d/%d * %d/%d = \n", i + 1, a,b,c,d);
		fprintf(fp2, "%d . %d/%d\n", i + 1, numerator / x, denominator / x);
		printf("\n\t\t %d/%d * %d/%d = ",a ,b ,c , d);
	}

}

void fra_di()	//������������ 
{
	FILE *fp1 = fopen("exercises.txt", "w");
	FILE *fp2 = fopen("answer.txt", "w");
	int a, b, c, d, n, r, numerator, denominator, x;
	srand(time(NULL));
	printf("��������Ŀ������");
	scanf("%d", &n);
	printf("��������ֵ��Χ��");
	scanf("%d", &r);
	int i = n;
	for (int i = 0; i < n; i++) {
		a = rand() % r + 1; //��һ�����ķ���
		b = rand() % r + 1; //��һ�����ķ�ĸ
		c = rand() % r + 1; //�ڶ������ķ���
		d = rand() % r + 1; //�ڶ������ķ�ĸ
		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (c > d) {
			c = c ^ d;
			d = c ^ d;
			c = c ^ d;
		}//ȷ���õ������
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
		printf("\n��ѡ��\n");
		printf("\t\t\t  �����ӷ����㣨������1��\n");
		printf("\t\t\t  �����������㣨������2��\n");
		printf("\t\t\t  �����˷����㣨������3��\n");
		printf("\t\t\t  �����������㣨������4��\n");
		printf("\t\t\t  �����ӷ����㣨������5��\n");
		printf("\t\t\t  �����������㣨������6��\n");
		printf("\t\t\t  �����˷����㣨������7��\n");
		printf("\t\t\t  �����������㣨������8��\n");
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