#include <iostream>

using namespace std;

float Grade(string G) {

	if (G == "A+")
		return 4.5;
	else if (G == "A0")
		return 4.0;
	else if (G == "B+")
		return 3.5;
	else if (G == "B0")
		return 3.0;
	else if (G == "C+")
		return 2.5;
	else if (G == "C0")
		return 2.0;
	else if (G == "D+")
		return 1.5;
	else if (G == "D0")
		return 1.0;
	else if (G == "F")
		return 0;
	else if (G == "P")
		return 0;
	
}

// P는 제외.
// 전공 평점 = 학점 * 과목평점 / 학점의 총합
int main() {

	string subject[20];
	string grade[20];
	float Score[20];

	float Add_Grade = 0;
	float Add_Score=0;

	for (int i = 0; i < 20; i++)
	{
		cin >> subject[i] >> Score[i] >> grade[i];
		if (grade[i] != "P") {
			Add_Grade += Score[i] * Grade(grade[i]);// grade를 나눔.;
			Add_Score += Score[i];
		}
	}
	float result = Add_Grade / Add_Score;
	printf("%.6f", result);
}