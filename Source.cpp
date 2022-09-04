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
		cout << "Вызов конструктора Matrix" << endl;

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


	Matrix(const Matrix& a)						//Конструктор копирования
	{

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = a.array[i][j];
		cout << "Вызов Конструктор копирования Matrix" << endl;
	}

	Matrix SetRandom()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				this->array[i][j] = rand() % 10;
		cout << "Установка рандомных значений Matrix" << endl;
		return *this;

	}



	Matrix& operator=(const Matrix& CopyMatrix)			//Оператор копирования
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = CopyMatrix.array[i][j];
		return *this;
		cout << "Вызов Оператор копирования Matrix" << endl;
	}


	friend std::ostream& operator<< (std::ostream& out, const Matrix& CopyMatrix)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				out << CopyMatrix.array[i][j];
				out << "\t";
			}
			out << endl;
		}

		return out;
	}


	Matrix operator+(const Matrix& B)
	{	

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = array[i][j] + B.array[i][j];
		cout << "результат сложения матриц" << endl;
		return *this;

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


	Proba.SetRandom();
	//Proba.Print();
	Copy.SetRandom();
	//Copy.Print();

	Matrix Slozh;
	Slozh=Proba + Copy;
	//Slozh.Print();

	cout << Proba<<"+" << endl <<Copy<<"=" << endl <<Slozh<<endl;




	cout << endl; 

	//111111

	system("pause");
}


