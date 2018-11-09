#include<stdio.h>
#include<conio.h>
#include<math.h>

int plus(int, int);
int minus(int, int);
int multiply(int, int);
int divide(int, int);

void ppak()
{
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

int main(void)
{
	//キーボードの入力を初期化
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

BS:
	printf("式を入力してください。Enterキーで決定です。要素はスペースキーで区切ってください。\n");

	char user = 0; int formula[1000] = { 0 }, num[5] = { 0 }, i = 0, j = 0, n = 0;

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

			//数値を判断して入れる,記号があるので5を足す
			if (i > 0) {

				i--; j = i;
				for (; i >= 0; i--)formula[n] += num[i] * pow(10, j - i);
				i = 0; formula[n] += 5; n++;

			}

		}

		//演算記号やBSキーの場合
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

	/*変数,入っているはずの値
	i == 0
	n == 式の一番最後+1
	formula[n] == 0
	(formula[n-1] >= 1) && (formula[n-1]<= 4)
	formula[0] >= 5;
	formula[1] >= 5;
	formula == 式;
	*/

	/*テスト用*/
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


	/*規定の形式以外エラーを吐く処理を後で追加する*/

	/*数値の個数 == 演算記号の個数 + 1*/
	//i = 数値の個数,j = 演算記号の個数
	for (i = 0, j = 0; i < n; i++) {
		if (formula[i] < 5)j++;
	}

	i = n - j;

	//printf("数値は%d個,演算記号は%d個", i, j);

	if (i != j + 1) {
		printf("error!演算記号は数値より一つ少ない個数にしてください。\n");
		printf("式を入力してください。Enterキーで決定です。\n"); goto BS;
	}

	/*逆ポーランド記法になっていない*/

	if ((formula[n - 1] < 1) || (formula[n - 1] > 4)) {
		printf("error!式の最後は演算記号にしてください\n");
		printf("式を入力してください。Enterキーで決定です。\n"); goto BS;
	}

	if ((formula[0] < 5) || (formula[1] < 5)) {
		printf("error!式の最初の２つは数値にしてください\n");
		printf("式を入力してください。Enterキーで決定です。\n"); goto BS;
	}


	//計算処理
	do {
		//i = 記号の位置
		while (i < n) { if (formula[i] < 5) break; i++; }

		//計算
		switch (formula[i])
		{

		case 1:num[0] = plus(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 2:num[0] = minus(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 3:num[0] = multiply(formula[i - 1] - 5, formula[i - 2] - 5); break;
		case 4:num[0] = divide(formula[i - 1] - 5, formula[i - 2] - 5); break;
			//case 0 : 終了
		}

		//負の数になってしまった場合
		if (num[0] < 5) {
			puts("申し訳ございませんが、負の数には対応しておりません");
			puts("式を入力してください。Enterキーで決定です。"); goto BS;
		}

		//式の再編成
		//j = 代入する位置
		j = i - 2;

		//formula[j] = 計算結果
		formula[j] = num[0] + 5; j++;

		//formulaの大括弧内の位置を２つずらす
		while (j + 2 < n)	formula[j] = formula[j + 2], j++;
		//要素の個数を減らす
		n -= 2;

		i = 0;
	} while (n > 1);

	printf("答えは %d です。\n", formula[0] - 5);

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
仕様という名の言い訳

割り算の答えが切り捨てになるのはC言語の仕様です！
途中で負の数になった場合は考えていませんでした･･･。
*/