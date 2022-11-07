#pragma once
#include"less0n-3.h"

Matrix::Matrix(const Matrix& pMatrix, const size_t& stringIndex) : determinant(nullopt), size(pMatrix.size - 1)
{
	matrix.reserve(size);
	for (size_t i = 0; i < size; i++)
	{
		matrix.push_back(vector<int>());
		matrix[i].reserve(size);
		for (size_t j = 0; j < pMatrix.size; j++)
		{
			if (stringIndex != j)
				matrix[i].push_back(pMatrix.matrix[i + 1][j]);
		}
	}
	Calculate();
}

void Matrix::Calculate()
{
	switch (size)
	{
	case 1:
		determinant = matrix[0][0];
		break;
	case 2:
		determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
		break;
	default:
		minors.reserve(size);
		determinant = 0;
		for (size_t i = 0; i < size; i++)
		{
			minors.push_back(Matrix(*this, i));
			determinant.emplace() = determinant.value() + matrix[0][i] * minors[i].determinant.value() * (i % 2 == 0 ? 1 : (-1));
		}
		break;
	}
}

Matrix::Matrix(istream& stream) : determinant(nullopt)
{
	cout << "Введите размер матрицы: ";
	size = getUserInput<size_t>(cin, true, true, false, false).value_or(0);
	matrix.reserve(size);
	for (size_t i = 0; i < size; i++)
	{
		matrix.push_back(vector<int>());
		matrix[i].reserve(size);
		for (size_t j = 0; j < size; j++)
		{
			optional n = getUserInput<int>(stream, true, true, false, false);
			if (n) matrix[i].push_back(n.value());
			else
			{
				cout << endl;
				for (size_t k = 0; k <= i; k++)
				{
					for (size_t l = 0; l < ((k < i) ? size : j); l++)
					{
						cout << setw(3) << matrix[k][l] << setw(2) << "";
					}
					if (k < i) cout << endl;
				}
				j--;
			}
		}
	}
	clearStream(stream);
	Calculate();
}

template <typename T>
optional<T> getUserInput(istream& stream, bool aZero, bool aNegative, bool chAll, bool needClear)
{
	while (true)
	{
		T input;
		stream >> input;
		if (stream.fail() || (input < 0) && !aNegative || (input == 0) && !aZero)
		{
			cout << "Ошибка, повторите ввод!";
			stream.clear();
			stream.ignore(numeric_limits<streamsize>::max(), '\n');
			return nullopt;
		}
		else
		{
			if ((stream.peek() != stream.widen('\n')) && chAll)
			{
				cout << "Ошибка, повторите ввод!";
				stream.clear();
				stream.ignore(numeric_limits<streamsize>::max(), '\n');
				return nullopt;
			}
			else
			{
				if (needClear)
				{
					stream.clear();
					stream.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				return input;
			}
		}
	}
}

void clearStream(istream& stream)
{
	stream.clear();
	stream.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Matrix::PrintMatrix()
{
	for (const auto& i : matrix)
	{
		for (const auto& j : i)
		{
			cout << setw(3) << j << setw(2) << "";
		}
		cout << endl;
	}
}

void Matrix::PrintDet()
{
	if (determinant) cout << "Определитель матрицы равен " << determinant.value();
	else cout << "Определитель не найден!";
	cout << endl;
}