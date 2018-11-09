#include<stdio.h>
#include<conio.h>
#include<math.h>

void ppak()
{
	//単体でも動くように
#include <conio.h>

	//キーボードに入っている文字列の初期化
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

	//キー入力があったらループを抜ける
	while (1) {
		if (_kbhit()) { _getch(); break; }
	};
}

int main(void){

		//キーボードの入力を初期化
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

BS:
	puts("式を入力してください。Enterキーで決定です。\n数値はスペースキーで区切ってください。");

	char user = 0,sign[500]= {0};int formula[1000] = { 0 }, num[5] = { 0 }, i = 0,j = 0, n = 0,s = 0;
	
	//改行が入力されたら終了
	while (user != '\r') {
		
		user = _getch();
	
		//数値の場合
		if ((user >= '0') && (user <= '9')) {
			num[i] = user;
			putchar(num[i]);
			num[i] -= '0';
			i++;
		}

		//スペースキーの場合
		else if (user == ' ') {
			
			putchar(' ');

	//数値を判断して入れる
			if (i > 0) {

				i--;j = i;
				for (;i >= 0;i--)formula[n] += num[i] * pow(10,j - i); 
				i = 0;n++;
			
			}

		}
		
		//演算記号やBSキーの場合
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


	//エラー処理
	if (i != 0) {
		puts("error!式の最後は演算記号にしてください\n"); goto BS;
	}

		/*数値の個数 == 演算記号の個数 + 1*/
		//s == 演算記号の個数,n == 全体の要素数
		/*数値の個数 == 全体の要素数-演算記号の個数*/

		if (n - s != s + 1) {
			puts("error!演算記号は数値より一つ少ない個数にしてください。\n"); goto BS;
		}

	/*逆ポーランド記法になっていない*/

		if (formula[0] == -1) {
			puts("error!式の最初の２つは数値にしてください\n"); goto BS;
		}

			/*テスト用*/
/*	
	for (i = 0,s = 0;i < n;i++) {

		switch (formula[i]) {
			case -1: putchar(sign[s]);s++;break;
			default:printf("%d", formula[i]);break;
		}

		putchar(' ');
	
	}
*/

		//置換部分ここから

		s = 0;j=0;

		while(1){
		
		//i = 記号の位置		
		for(;i < n;i++) if (formula[i] < 0) break;
		
		if(j == 0){
		
			//とりあえず足し算引き算は全部くくっとく
			//いつかやる
		if((sign[s]== '+')||(sign[s] == '-'))	printf("("),j=1;
		else j=0;
		
		}else if((sign[s] != '+')&&(sign[s] != '-')) j=0,printf(")");

		printf("%d%c%d",formula[i - 2],sign[s],formula[i - 1]);

		}


	ppak();


	return 0;
}
