#include "iostream"

using namespace std;

class Matrix
{
private:
	double array[3][3];

public:

	Matrix()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = 0;
		cout << "����� ������������ Matrix" << endl;

	}
	/*~Matrix()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			delete[] array[j];
		}
		delete[] array;
	}*/


	void Print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << array[i][j];
				cout << "\t";
			}
			cout << endl;
		}
	}


	Matrix(const Matrix& a)						//����������� �����������
	{

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = a.array[i][j];
		cout << "����� ����������� ����������� Matrix" << endl;
	}

	Matrix SetRandom()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				this->array[i][j] = rand() % 10;
		cout << "��������� ��������� �������� Matrix" << endl;
		return *this;

	}



	Matrix& operator=(const Matrix& CopyMatrix)			//�������� �����������
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = CopyMatrix.array[i][j];
		return *this;
		cout << "����� �������� ����������� Matrix" << endl;
	}
};







void main()
{

	setlocale(LC_ALL, "ru");

	Matrix Proba;

	Proba.Print();
	cout << endl;

	Proba.SetRandom();

	Proba.Print();
	cout << endl;

	Matrix Copy(Proba);
	Copy.Print();
	cout << endl;

	Proba.SetRandom();
	Proba.Print();
	cout << endl;

	Copy = Proba;
	Copy.Print();
	cout << endl;


	system("pause");
}


