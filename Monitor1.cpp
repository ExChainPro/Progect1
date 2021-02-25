#include <iostream>
#include <windows.h>                     //Два файла с определениями, макросами
#include <windowsx.h>                  //и прототипами функций Windows
#include <tchar.h>      // Для ухода от LPWSTR LPSTR и иже с ними
#include<TCHAR.H>
using namespace std;
//глобальные переменные для рисования окна
HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs; int nWinMode;
/*Прототип используемой в программе оконной функции */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

LPWSTR CharToLPWSTR(LPCSTR char_string)
{
    LPWSTR res;
    DWORD res_len = MultiByteToWideChar(1251, 0, char_string, -1, NULL, 0);
    res = (LPWSTR)GlobalAlloc(GPTR, (res_len + 1) * sizeof(WCHAR));
    MultiByteToWideChar(1251, 0, char_string, -1, res, res_len);
    return res;
}
/*Произвольный класс*/
class exemple
{
public:
    /*Главная функция приложения WinMain*/
    int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
        LPSTR lpszArgs, int nWinMode) {
        //char  chWinName[] = "123/0";      //Произвольное имя класса главного окна
        char  szWinName[] = "WinName";  // chWinName;
        char  szTitle[] = "szTitle";               //Произвольный заголовок окна
        MSG msg;                    //Структура msg типа MSG для получения сообщений Windows
        WNDCLASS wc;                                  //Структура wc типа WNDCLASS для задания 
                                    //характеристик окна
        /*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
        ZeroMemory(&wc, sizeof(wc));                             //Обнуление всех членов структуры wc
        wc.hInstance = hInstance;                                       // Дескриптор приложения
        wc.lpszClassName = CharToLPWSTR(szWinName);                           // Имя класса окна
        wc.lpfnWndProc = WindowFunc;                           // Определение оконной функции 
        wc.style = 0;                                                            // Стиль по умолчанию
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);           //Стандартная пиктограмма
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);              //Стандартный курсор мыши
        wc.hbrBackground = GetStockBrush(WHITE_BRUSH);         // Белый фон окна
        wc.lpszMenuName = NULL;                                  // Без меню
        wc.cbClsExtra = 0;                                                  // Без дополнительной информации
        wc.cbWndExtra = 0;                                                // Без дополнительной информации
        /*Регистрация класса главного окна*/
        if (!RegisterClass(&wc))                                         //Если класс окна не регистрируется
        {                                    // выводим сообщение и заканчиваем выполнение программы
            MessageBox(NULL, _T("Окно нерегестрируется"), _T("Ошибка"), MB_OK);
            return 1;
        }                                                           // возвращаем код ошибки

        MessageBox(0, _T("And text here"), _T("MessageBox caption"), MB_OK);
/*Создание главного окна и отображение его на мониторе*/
        HWND hwnd = CreateWindow(                           //Вызов функции API для создания ок-на
            CharToLPWSTR(szWinName),                                             // имя класса главного окна
            CharToLPWSTR(szTitle), //LPWSTR(szTitle),                                                       // заголовок окна
            WS_OVERLAPPEDWINDOW,                  // Стиль окна 
            100,                                                            // x-координата левого угла окна
            100,                                                            // y-координата левого угла окна
            500,                                                            // Ширина окна
            100,                                                            // Высота окна
            HWND_DESKTOP,                                  // Без родительского окна
            NULL,                                                       // Без меню
            hInstance,                                                  // Дескриптор приложения
            NULL);                                                     // Без дополнительных аргументов
        ShowWindow(hwnd, SW_SHOWNORMAL);       //  Вызов функции API
                                            // для отображения окна 
        /*Организация цикла обнаружения сообщений*/
        while (GetMessage(&msg, NULL, 0, 0))               // Если есть сообщение, передать его
                    // нашему приложению
            DispatchMessage(&msg);                               //и вызвать оконную функцию WindowFunc 
        return 0;                                                     //После выхода из цикла вернуться в Windows
    }                                                                    //Конец функции WinMain 

};

/*Оконная функция WindowFunc главного окна, вызываемая Windows и получающая в качестве параметра сообщение из очереди сообщений данного приложения */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
    WPARAM wParam, LPARAM lParam) {
    switch (message) {                                      // выбор по значению сообщения (message)
    case WM_DESTROY:                           //При завершении приложения пользователем
        PostQuitMessage(0);                           //вызвать функцию API завершения приложения
        break;
    default:                                    // Все сообщения, не обрабатываемые данной функцией,
                                                // направляются на обработку по умолчанию 
        return DefWindowProc(hwnd, message, wParam, lParam);
    }                                                           //Конец оператора switch
    return 0;
}
//главная функция консольного приложения
int main(void)
{

    setlocale(LC_ALL, "Russian_Russia.1251");//изменения кодировки для вывода русского языка 
SYSTEMCRASH: //точка возврата
    std::cout << "Введите 1 что бы нарисовать окно, \nдля выхода нажмите клавишу 2 :";
    char ch_chose = '\0';
    std::cin >> ch_chose;
    class exemple val;
    switch (ch_chose)
    {
    case '2':
        exit(0);
        break;
    case '1':
        val.WinMain(hInstance, hPrevInst,
            lpszArgs, nWinMode);
        break;
    default:
        std::cout << "Недопустимый символ попробуйте ещё! \n";
        goto SYSTEMCRASH;
    }


}


// Monitor1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#if defined(_WIN64)
//
//    #if defined(_AMD64_)
//    #define PROBE_ALIGNMENT( _s ) TYPE_ALIGNMENT( DWORD )
//    #elif defined(_IA64_)
//    #define PROBE_ALIGNMENT( _s ) (TYPE_ALIGNMENT( _s ) > TYPE_ALIGNMENT( DWORD ) ? \
//                                  TYPE_ALIGNMENT( _s ) : TYPE_ALIGNMENT( DWORD ))
//    #else
//    #error "No Target Architecture"
//    #endif
//#endif
//#pragma warning(disable : 4996)
//
//#include <Windows.h>
//#include <iostream>
////#include <winbase.h>
//#include <winuser.h>
//#include <string> 
//
//
//int main()
//{
//    bool Mon;
//    BOOL State;
//    HWND h = FindWindow(0, 0);
//
//    Mon =  GetDevicePowerState(h, &State);
//
//    if (State)
//        std::cout << "Monitor is on\n";
//
//        // MessageBox::Show("Any text here");
//        //  MessageBox(0, _T("Monitor Light"), _T("MessageBox caption"), MB_OK);
//    else
//        //MessageBox(0, _T("Monitor Off") , T("MessageBox caption"), MB_OK);
//        std::cout << "Monitor is on\n";
//    Pause    
//    //sprintf()
//    //std::cout << "Hello World!\n" + std::to_string( timeBeginPeriod);
//    std::cout << "Hello World!\n" + std::to_string(45644);
//    
//    SendMessage(h, WM_SYSCOMMAND, SC_MONITORPOWER, 2);//2 (the display is being shut off)
//    SendMessage(h, WM_SYSCOMMAND, SC_MONITORPOWER, 1);//1 (the display is going to low power)
//    Sleep(11111);
//    SendMessage(h, WM_SYSCOMMAND, SC_MONITORPOWER, -1);
//    std::cout << "Exit\n";
//}
//
//// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
//// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
//
//// Советы по началу работы 
////   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
////   2. В окне Team Explorer можно подключиться к системе управления версиями.
////   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
////   4. В окне "Список ошибок" можно просматривать ошибки.
////   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
////   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
