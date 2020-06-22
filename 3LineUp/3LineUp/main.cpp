#include <iostream>

// �萔
const static int width_max = 3;		// �����̍ő�l
const static int height_max = 3;	// �c���̍ő�l 

// �֐�
void Initialize();
void Input();
void JudgeButtle();
void Render();


// ��
enum class State
{
	// 0,��,�~
	None = 0,
	Cirlce,
	Cross
};

// �������� �����@�����@������
enum class Judge
{
	None = 0,
	Circle_win,
	Circle_lose,
	Circle_drow
};

// �ϐ�
State g_array[height_max][width_max];	// �Ֆʂ̔z��
bool g_turn = false;					// �^�[���̔���
Judge g_judge = Judge::None;			// ����

// 
int g_numH = 0;							// ���͗p
int g_numW = 0;




int main()
{
	// ������
	Initialize();

	// �Q�[�����[�v
	// �������Ă����
	while (/*g_judge == Judge::None*/true)
	{
		// �`�揈��
		Render();

		// ����
		Input();

		// ��������
		JudgeButtle();
	}

	//if (g_judge == Judge::Circle_win)
	//{
	//	std::cout << "���̏���" << std::endl;
	//}
	//else if (g_judge == Judge::Circle_lose)
	//{
	//	std::cout << "�~�̏���" << std::endl;
	//}
	//else
	//{
	//	std::cout << "��������" << std::endl;
	//}



	return 0;
}

// ������
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

// ���͏���
void Input()
{
	if (g_turn == false)
	{
		std::cout << "�y���z�u�����W����͂��Ă�������" << std::endl;
	}
	else
	{
		std::cout << "�y�~�z�u�����W����͂��Ă�������" << std::endl;
	}

	std::cin >> g_numH >> g_numW;

	//�^�[���̓���ւ�����
	if (g_array[g_numH][g_numW] == State::None)
	{
		if (g_numH < 0 || g_numH > 2 && g_numW < 0 || g_numW > 2)//�͈͊O�̎��͓��͂����m���Ȃ�
		{
			std::cout << "�l���Ⴂ�܂�" << std::endl;
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


// ���s����
void JudgeButtle()
{



}

// �`��
void Render()
{
	// ��ʂ̃��Z�b�g
	std::system("cls");

	// �����̂O�P�Q�̕\��
	std::cout << " �O�P�Q" << std::endl;

	// �Ֆʂ̕\��
	for (int i = 0; i < height_max; i++)
	{
		std::cout << i;
		for (int j = 0; j < width_max; j++)
		{
			switch (g_array[i][j])
			{
			case State::None:
				std::cout << "�E";
				break;
			case State::Cirlce:
				std::cout << "��";
				break;
			case State::Cross:
				std::cout << "�~";
				break;

			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

