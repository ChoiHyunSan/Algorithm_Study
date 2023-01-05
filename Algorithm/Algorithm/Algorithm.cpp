#include <iostream>
#include <vector>

using namespace std;

int solution(string Pos)
{
	int result = 0;
	int x = Pos[0] - 'a'; // 0~8
	int y = Pos[1] - '1'; // 0~8

	int move[][2] = {
		{2,1},
		{2,-1},
		{-2,1},
		{-2,-1},
		{1,-2},
		{-1,-2},
		{1, 2},
		{-1, 2}
	};

	for (int i = 0; i < 8; i++)
	{
		if (x - move[i][0] < 0 || y - move[i][1] < 0)
		{
			continue;
		}
		result++;
	}

	return result;
}

// N : 세로 크기
// M : 가로 크기

enum class VEC
{
	UP = 0,
	LEFT,
	DOWN,
	RIGHT,
};

int solution_1()
{
	int result = 1;
	// 입력값 받음
	int cur_Y = 1;
	int cur_X = 1;
	VEC cur_Vec = VEC::UP;

	// 입력값 받음
	int map[4][4]
	{
		{1,1,1,1},
		{1,0,0,1},
		{1,1,0,1},
		{1,1,1,1}
	};
	int count = 0;
	while (true)
	{
		int Vec[2];
		switch (cur_Vec)
		{
		case VEC::UP:
			Vec[0] = -1; Vec[1] = 0;
			break;
		case VEC::DOWN:
			Vec[0] = 1; Vec[1] = 0;
			break;
		case VEC::LEFT:
			Vec[0] = 0; Vec[1] = -1;
			break;
		case VEC::RIGHT:
			Vec[0] = 0; Vec[1] = 1;
			break;
		}

		// 바라보는 방향으로 이동한 곳이 바다인 경우
		if (map[cur_Y + Vec[0]][cur_X + Vec[1]] == 1 || map[cur_Y][cur_X] == 2)
		{
			count++;

			// 4방향을 돌렸음에도 육지가 갈 곳이 없다면 뒤로 이동
			if (count == 4)
			{
				count = 0;

				if (map[cur_Y - Vec[0]][cur_X - Vec[1]] == 1)
					break;

				cur_Y -= Vec[0];
				cur_X -= Vec[1];
			}

			// 반시계로 방향 변환
			cur_Vec = (VEC)(((int)cur_Vec + 1) % 4);
		}
		// 육지인 경우
		else
		{
			result++;
			// 다녀갔음을 표시
			map[cur_Y][cur_X] = 2;
			
			cur_Y += Vec[0];
			cur_X += Vec[1];

			count = 0;
		}
	}
	return result;
}

int main()
{
	//cout << solution("a1");
	cout << solution_1();
}

