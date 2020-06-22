#include <iostream>

// 定数
const static int width_max = 3;		// 横軸の最大値
const static int height_max = 3;	// 縦軸の最大値 

// 関数
void Initialize();
void Input();
void JudgeButtle();
void Render();


// 列挙
enum class State
{
	// 0,○,×
	None = 0,
	Cirlce,
	Cross
};

// 勝利判定 勝ち　負け　あいこ
enum class Judge
{
	None = 0,
	Circle_win,
	Circle_lose,
	Circle_drow
};

// 変数
State g_array[height_max][width_max];	// 盤面の配列
bool g_turn = false;					// ターンの判定
Judge g_judge = Judge::None;			// 判定

// 
int g_numH = 0;							// 入力用
int g_numW = 0;




int main()
{
	// 初期化
	Initialize();

	// ゲームループ
	// 勝負している間
	while (/*g_judge == Judge::None*/true)
	{
		// 描画処理
		Render();

		// 入力
		Input();

		// 勝利判定
		JudgeButtle();
	}

	//if (g_judge == Judge::Circle_win)
	//{
	//	std::cout << "○の勝ち" << std::endl;
	//}
	//else if (g_judge == Judge::Circle_lose)
	//{
	//	std::cout << "×の勝ち" << std::endl;
	//}
	//else
	//{
	//	std::cout << "引き分け" << std::endl;
	//}



	return 0;
}

// 初期化
void Initialize()
{
	for (int i = 0; i < height_max; i++)
	{
		for (int j = 0; j < width_max; j++)
		{
			g_array[i][j] = State::None;
		}
	}
}

// 入力処理
void Input()
{
	if (g_turn == false)
	{
		std::cout << "【○】置く座標を入力してください" << std::endl;
	}
	else
	{
		std::cout << "【×】置く座標を入力してください" << std::endl;
	}

	std::cin >> g_numH >> g_numW;

	//ターンの入れ替え条件
	if (g_array[g_numH][g_numW] == State::None)
	{
		if (g_numH < 0 || g_numH > 2 && g_numW < 0 || g_numW > 2)//範囲外の時は入力を検知しない
		{
			std::cout << "値が違います" << std::endl;
		}
		else
		{
			if (g_turn == false)
			{
				g_array[g_numH][g_numW] = State::Cirlce;
				g_turn = true;
			}
			else
			{
				g_array[g_numH][g_numW] = State::Cross;
				g_turn = false;
			}

		}
	}
}


// 勝敗判定
void JudgeButtle()
{



}

// 描画
void Render()
{
	// 画面のリセット
	std::system("cls");

	// 横軸の０１２の表示
	std::cout << " ０１２" << std::endl;

	// 盤面の表示
	for (int i = 0; i < height_max; i++)
	{
		std::cout << i;
		for (int j = 0; j < width_max; j++)
		{
			switch (g_array[i][j])
			{
			case State::None:
				std::cout << "・";
				break;
			case State::Cirlce:
				std::cout << "○";
				break;
			case State::Cross:
				std::cout << "×";
				break;

			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

