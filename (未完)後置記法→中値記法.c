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

int main(void){

		//�L�[�{�[�h�̓��͂�������
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

BS:
	puts("������͂��Ă��������BEnter�L�[�Ō���ł��B\n���l�̓X�y�[�X�L�[�ŋ�؂��Ă��������B");

	char user = 0,sign[500]= {0};int formula[1000] = { 0 }, num[5] = { 0 }, i = 0,j = 0, n = 0,s = 0;
	
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

	//���l�𔻒f���ē����
			if (i > 0) {

				i--;j = i;
				for (;i >= 0;i--)formula[n] += num[i] * pow(10,j - i); 
				i = 0;n++;
			
			}

		}
		
		//���Z�L����BS�L�[�̏ꍇ
		else {
	
			if (i > 0) {

				i--;j = i;
				for (;i >= 0;i--)formula[n] += num[i] * pow(10,j - i); 
				i = 0;n++;
			
			}
		
			switch (user)
			{
				case '+' : case '-' : case '*' : case '/' :sign[s] = user;s++; formula[n] = -1;n++;putchar(user);break;
				case '\b': for (;n != 0;n--)puts("");goto BS;break;
			}		
		}
	}

	putchar('\n');


	//�G���[����
	if (i != 0) {
		puts("error!���̍Ō�͉��Z�L���ɂ��Ă�������\n"); goto BS;
	}

		/*���l�̌� == ���Z�L���̌� + 1*/
		//s == ���Z�L���̌�,n == �S�̗̂v�f��
		/*���l�̌� == �S�̗̂v�f��-���Z�L���̌�*/

		if (n - s != s + 1) {
			puts("error!���Z�L���͐��l������Ȃ����ɂ��Ă��������B\n"); goto BS;
		}

	/*�t�|�[�����h�L�@�ɂȂ��Ă��Ȃ�*/

		if (formula[0] == -1) {
			puts("error!���̍ŏ��̂Q�͐��l�ɂ��Ă�������\n"); goto BS;
		}

			/*�e�X�g�p*/
/*	
	for (i = 0,s = 0;i < n;i++) {

		switch (formula[i]) {
			case -1: putchar(sign[s]);s++;break;
			default:printf("%d", formula[i]);break;
		}

		putchar(' ');
	
	}
*/

		//�u��������������

		s = 0;j=0;

		while(1){
		
		//i = �L���̈ʒu		
		for(;i < n;i++) if (formula[i] < 0) break;
		
		if(j == 0){
		
			//�Ƃ肠���������Z�����Z�͑S���������Ƃ�

			/*�����̎��̓��O�A�E�g���܂���*/
			/*�����̎��A�C�����I*/
		if((sign[s]== '+')||(sign[s] == '-'))	printf("("),j=1;
		else j=0;
		
		}else if((sign[s] != '+')&&(sign[s] != '-')) j=0,printf(")");

		printf("%d%c%d",formula[i - 2],sign[s],formula[i - 1]);

		}


	ppak();


	return 0;
}