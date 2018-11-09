/*中値記法→逆ポーランド記法*/
/*
・数値,+,-,*,/以外を受け付けない

１．入力受付
２．変換
３．出力
*/
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

int check(char);

int main(void)
{
	//キーボードの入力を初期化
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};
BS:
	printf("式を入力してください。=キーで決定です。\n");

	char user = 0, sign[500] = { 0 };int s = 0, n = 0, hoge = 0, num[20] = {0},i=0;unsigned long long number[500] = {0};

	while (user != '=') {
		user = _getch();

		//数値が入力されている
		if ((user >= '0') && (user <= '9')) {
			num[hoge] = user - '0', putchar(user), hoge++;
			if (hoge > 19) { puts("\n数値が大きすぎます。");goto BS; }
		}
		//演算記号が入力されるべき時に演算記号が入力されている
		else if (hoge > 0) {

			switch (user) {
			case '+': case '-': case '*': case '/':

				//数値があるはずなので数値を正式に読み取る
				for (i = hoge-1;hoge >= 0;hoge--) {
					number[n] += num[i - hoge + 1] * pow(10.0f, hoge - 1);
				}n++;


				sign[s] = user;
				s++;putchar(user);
				hoge = 0;break;

			case '=':if (hoge == 0) { puts("最後は数値で終わらせてください\n");goto BS; }
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
	ここにエラー処理を書こうと思ったけど何が必要かわからない
	*/




	//置換しつつ出力する
	i = 0;s = 0; 
	char stac[500] = {0};

	while (n > 0) {

		//数字はそのまま出力
		printf("%llu ", number[i]);n--;

		//テスト
		hoge = check(stac[s]);


		//スタックに無くなったら入れる
		//スタックの一番上の優先度 < 現在の演算記号の優先度になるように書き出す
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
			//演算記号をスタックに入れる
			stac[s] = sign[i];s++;

		i++;

		}
	//最後に演算記号を出力
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
