/*���l�L�@���t�|�[�����h�L�@*/
/*
�E���l,+,-,*,/�ȊO���󂯕t���Ȃ�

�P�D���͎�t
�Q�D�ϊ�
�R�D�o��
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

void ppak()
{
	//�P�̂ł������悤��
#include <conio.h>

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

int check(char);

int main(void)
{
	//�L�[�{�[�h�̓��͂�������
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};
BS:
	printf("������͂��Ă��������B=�L�[�Ō���ł��B\n");

	char user = 0, sign[500] = { 0 };int s = 0, n = 0, hoge = 0, num[20] = {0},i=0;unsigned long long number[500] = {0};

	while (user != '=') {
		user = _getch();

		//���l�����͂���Ă���
		if ((user >= '0') && (user <= '9')) {
			num[hoge] = user - '0', putchar(user), hoge++;
			if (hoge > 19) { puts("\n���l���傫�����܂��B");goto BS; }
		}
		//���Z�L�������͂����ׂ����ɉ��Z�L�������͂���Ă���
		else if (hoge > 0) {

			switch (user) {
			case '+': case '-': case '*': case '/':

				//���l������͂��Ȃ̂Ő��l�𐳎��ɓǂݎ��
				for (i = hoge-1;hoge >= 0;hoge--) {
					number[n] += num[i - hoge + 1] * pow(10.0f, hoge - 1);
				}n++;


				sign[s] = user;
				s++;putchar(user);
				hoge = 0;break;

			case '=':if (hoge == 0) { puts("�Ō�͐��l�ŏI��点�Ă�������\n");goto BS; }
				for (i = hoge - 1;hoge >= 0;hoge--) {
				number[n] += num[i - hoge + 1] * pow(10.0f, hoge - 1);
			}n++;putchar(user);hoge = 0;break;

			case '\b':puts("");goto	BS;break;
			}
		}
	}


	putchar('\n');

	//test
/*	printf("%d", number[0]);
	for (i = 1; i < n;i++) {
		putchar(sign[i - 1]);
		printf("%d",number[i]);
	}
*/

	/*
	�����ɃG���[�������������Ǝv�������ǉ����K�v���킩��Ȃ�
	*/




	//�u�����o�͂���
	i = 0;s = 0; 
	char stac[500] = {0};

	while (n > 0) {

		//�����͂��̂܂܏o��
		printf("%llu ", number[i]);n--;

		//�e�X�g
		hoge = check(stac[s]);


		//�X�^�b�N�ɖ����Ȃ���������
		//�X�^�b�N�̈�ԏ�̗D��x < ���݂̉��Z�L���̗D��x�ɂȂ�悤�ɏ����o��
		 if ((s > 0)&&(check(stac[s - 1]) >= check(sign[i])))
		{

			s--;


			while ((check(stac[s]) >= check(sign[i])) && (s >= 0)) { 
				
				putchar(stac[s]);
				stac[s] = 0;
				putchar(' ');
				s--;

			}
			s++;

		}
			//���Z�L�����X�^�b�N�ɓ����
			stac[s] = sign[i];s++;

		i++;

		}
	//�Ō�ɉ��Z�L�����o��
	for (;s >= 0;s--)putchar(stac[s]);

	ppak();
	
	return 0;

}

int check(char s) {

	switch (s) {
	case '+': return 0;
	case '-': return 0;
	case '*': return 1;
	case '/': return 1;
	
	}


}
