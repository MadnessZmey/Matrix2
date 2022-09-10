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


	void Print()		//Функция вывода
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


	friend std::ostream& operator<< (std::ostream& out, const Matrix& CopyMatrix)		//Вывод (дружественная функция)
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


	Matrix operator+(Matrix B)			//Оператор сложения
	{	
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				B.array[i][j] += array[i][j];
		cout << "результат сложения матриц" << endl;
		return B;
	}


	Matrix operator*(Matrix B)			//Оператор умножения матрицы на матрицу
	{

		Matrix Umno;


		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)

				for (int z = 0; z < 3; z++)
					
						Umno.array[i][j] += B.array[z][j] * array[i][z];

		cout << "результат умножения матрицы на матрицу" << endl;
		return Umno;
	}



	Matrix operator*(double C)			//Оператор умножения матрица на число (число с права)
	{
		Matrix UmnoC;

		/*for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)

				UmnoC.array[i][j] *= C;*/


		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				UmnoC.array[i][j] = array[i][j] * C;


		cout << "результат умножения матрицы на матрицу" << endl;
		return UmnoC;
	}



	//friend double operator*(double A, Matrix B)		//Оператор умножения матрица на число
	//{
	//	Matrix UmnoCN;

	//	for (int i = 0; i < 3; i++)
	//		for (int j = 0; j < 3; j++)
	//			UmnoCN.array[i][j] *= A;


	//	cout << "результат умножения матрицы на матрицу" << endl;
	//	return UmnoCN;
	//}

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
	Slozh = Proba + Copy;
	//Slozh.Print();

	cout << Proba<<"+" << endl <<Copy<<"=" << endl <<Slozh<<endl;

	Matrix UmnozhM;
	UmnozhM = Proba * Copy;

	cout << Proba << "*" << endl << Copy << "=" << endl << UmnozhM << endl;

	Matrix UmnozhCh;
	UmnozhCh = Proba * 8;

	cout << Proba << "*" << endl << "8" << endl << "=" << endl << UmnozhCh << endl;


	cout << endl; 

	//111111
	//11111
	//Zhenya

	system("pause");
}


