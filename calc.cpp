#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* функции сложение, вычитание, умножение, деление: */
float sum(float a, float b) { return a + b; }
float dif(float a, float b) { return a - b; }
float mul(float a, float b) { return a*b; }
float div(float a, float b) { return a / b; }

/*указатели на функции*/
float(*pointerSum)(float a, float b) = &sum;
float(*pointerDif)(float a, float b) = &dif;
float(*pointerMul)(float a, float b) = &mul;
float(*pointerDiv)(float a, float b) = &div;

 /*структура для хранения символа операции и соответствующего ему указателя на функцию*/
struct structFunct{
	char charOperation;
	float(*pointerFunctoon)(float a, float b);
};
/*массив из символов операций и указателей на функции*/
structFunct arrFunct[4]={
	{'+',pointerSum},
	{'-',pointerDif},
	{'*',pointerMul},
	{'/',pointerDiv}};
int main() {
	setlocale(0, "");
	float slag1, slag2;
	char oper; //переменная для символа опереции + - * /
	cout << "Введите два числа" << endl;
	cin >> slag1 >> slag2;
	cout << "Введите операцию (+, -, *, /)" << endl;
	cin >> oper; //ввод символа операции
	 // проверка введенного символа
	if (oper != '+' && oper != '-' && oper != '*' && oper != '/') {
	cout << "Неверный символ операции" << endl;}//если неправильно
	else{                                                   //если правильно
          cout << slag1 << ' ' << oper << ' ' << slag2 << " = ";  // выводим пояснение
	for (int i = 0;i < 4;i++) {                                 //перебираем массив
         if (arrFunct[i].charOperation == oper) {                  //сравнивем символы операции из массива с введеным
cout << arrFunct[i].pointerFunctoon(slag1, slag2);      //если совпадает выполняем            функцию и выводим результат на экран
				break; //выходим из цикла
};
}
cout << endl;
}
system("pause");
return 0;
}
