#include <fstream>

int main()
{
    std::ofstream fout("data.txt"); // связываем его с файлом cppstudio.txt
    fout << "Работа с файлами в С++"; // запись строки в файл
    fout.close(); // закрываем файл
    return 0;
}



