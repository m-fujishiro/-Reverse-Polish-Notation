#include<stdio.h>
#include<conio.h>
#include<math.h>

int plus(int, int);
int minus(int, int);
int multiply(int, int);
int divide(int, int);

void ppak()
{
	//�L�[�{�[�h�ɓ����Ă��镶����̏�����
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

	//�L�[���͂��������烋�[�v�𔲂���
	while (1) {
		if (_kbhit()) { _getch(); break; }
	};
}

int main(void)
{
	//�L�[�{�[�h�̓��͂�������
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

BS:
	printf("������͂��Ă��������BEnter�L�[�Ō���ł��B�v�f�̓X�y�[�X�L�[�ŋ�؂��Ă��������B\n");

	char user = 0; int formula[1000] = { 0 }, num[5] = { 0 }, i = 0, j = 0, n = 0;

	//���s�����͂��ꂽ��I��
	while (user != '\r') {

		user = _getch();

		//���l�̏ꍇ
		if ((user >= '0') && (user <= '9')) {
			num[i] = user;
			putchar(num[i]);
			num[i] -= '0';
			i++;
		}

		//�X�y�[�X�L�[�̏ꍇ
		else if (user == ' ') {

			putchar(' ');

			//���l�𔻒f���ē����,�L��������̂�5�𑫂�
			if (i > 0) {

				i--; j = i;
				for (; i >= 0; i--)formula[n] += num[i] * pow(10, j - i);
				i = 0; formula[n] += 5; n++;

			}

		}

		//���Z�L����BS�L�[�̏ꍇ
		else {
			switch (user)
			{
			case '+': formula[n] = 1; n++; putchar('+'); break;
			case '-': formula[n] = 2; n++; putchar('-'); break;
			case '*': formula[n] = 3; n++; putchar('*'); break;
			case '/': formula[n] = 4; n++; putchar('/'); break;
			case '\b': for (; n != 0; n--)printf("\b \b\b \b"); goto BS; break;
			}
		}
	}
	putchar('\n');

	if (i > 0) {
		i--; j = i;
		for (; i >= 0; i--)formula[n] += num[i] * pow(10, j - i);
		i = 0; formula[n] += 5; n++;
	}

	/*�ϐ�,�����Ă���͂��̒l
	i == 0
	n == ���̈�ԍŌ�+1
	formula[n] == 0
	(formula[n-1] >= 1) && (formula[n-1]<= 4)
	formula[0] >= 5;
	formula[1] >= 5;
	formula == ��;
	*/

	/*�e�X�g�p*/
/*
	for (i = 0;i < n;i++) {

	switch (formula[i]) {
	case 1:putchar('+');break;
	case 2:putchar('-');break;
	case 3:putchar('*');break;
	case 4:putchar('/');break;
	default:printf("%d", formula[i] - 5);break;
	}

	putchar(' ');

	}
	*/


	/*�K��̌`���ȊO�G���[��f����������Œǉ�����*/

	/*���l�̌� == ���Z�L���̌� + 1*/
	//i = ���l�̌�,j = ���Z�L���̌�
	for (i = 0, j = 0; i < n; i++) {
		if (formula[i] < 5)j++;
	}

	i = n - j;

	//printf("���l��%d��,���Z�L����%d��", i, j);

	if (i != j + 1) {
		printf("error!���Z�L���͐��l������Ȃ����ɂ��Ă��������B\n");
		printf("������͂��Ă��������BEnter�L�[�Ō���ł��B\n"); goto BS;
	}

	/*�t�|�[�����h�L�@�ɂȂ��Ă��Ȃ�*/

	if ((formula[n - 1] < 1) || (formula[n - 1] > 4)) {
		printf("error!���̍Ō�͉��Z�L���ɂ��Ă�������\n");
		printf("������͂��Ă��������BEnter�L�[�Ō���ł��B\n"); goto BS;
	}

	if ((formula[0] < 5) || (formula[1] < 5)) {
		printf("error!���̍ŏ��̂Q�͐��l�ɂ��Ă�������\n");
		printf("������͂��Ă��������BEnter�L�[�Ō���ł��B\n"); goto BS;
	}


	//�v�Z����
	do {
		//i = �L���̈ʒu
		while (i < n) { if (formula[i] < 5) break; i++; }

		//�v�Z
		switch (formula[i])
		{

		case 1:num[0] = plus(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 2:num[0] = minus(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 3:num[0] = multiply(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 4:num[0] = divide(formula[i - 1] - 5, formula[i - 2] - 5); break;
			//case 0 : �I��
		}

		//���̐��ɂȂ��Ă��܂����ꍇ
		if (num[0] < 5) {
			puts("�\���󂲂����܂��񂪁A���̐��ɂ͑Ή����Ă���܂���");
			puts("������͂��Ă��������BEnter�L�[�Ō���ł��B"); goto BS;
		}

		//���̍ĕҐ�
		//j = �������ʒu
		j = i - 2;

		//formula[j] = �v�Z����
		formula[j] = num[0] + 5; j++;

		//formula�̑劇�ʓ��̈ʒu���Q���炷
		while (j + 2 < n)	formula[j] = formula[j + 2], j++;
		//�v�f�̌������炷
		n -= 2;

		i = 0;
	} while (n > 1);

	printf("������ %d �ł��B\n", formula[0] - 5);

	printf("Please press any key to exit.");
	ppak();

}

int plus(int i, int j)
{
	int x = 0;
	x = j + i;
	return x;
}
int minus(int i, int j)
{
	int x = 0;
	x = j - i;
	return x;
}
int multiply(int i, int j)
{
	int x = 0;
	x = j * i;
	return x;
}
int divide(int i, int j)
{
	int x = 0;
	x = j / i;
	return x;
}

/*
�d�l�Ƃ������̌�����

����Z�̓������؂�̂ĂɂȂ�̂�C����̎d�l�ł��I
�r���ŕ��̐��ɂȂ����ꍇ�͍l���Ă��܂���ł�������B
*/