#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <limits>

const long double MAX_LONG_DOUBLE = std::numeric_limits <long double> ::max();
using namespace std;

struct Human
{
    string country;
    string name_of_team;
    string fio;       // ФИО
    long double nomer;
    long double age;
    long double heigth;
    long double weigth;
};
//меню
void condition() {
    printf("Информация об участниках спортивных соревнований содержит:\n");
    printf("наименование страны, название команды, Ф.И.О. игрока, игровой номер, возраст, рост, вес.\n");
    printf("Вывести информацию о самой молодой команде.\n");
}
void whoami() {
    printf("\n");
    printf("Выполнил: Жгутов Евгений Дмитриевич\n");
    printf("Группа: 253505\n");
    printf("\n");
}
// проверка на ввод
int check_number_of_functions()
{
    int number_of_functions;
    while (!(std::cin >> number_of_functions) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number_of_functions < 1 || number_of_functions > 11)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return number_of_functions;
}
int check_number_of_attribute()
{
    int number_of_attribute;
    while (!(std::cin >> number_of_attribute) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number_of_attribute < 1 || number_of_attribute > 7)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return number_of_attribute;
}
int check_amount_struct()
{
    int amount_struct;
    while (!(std::cin >> amount_struct) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || amount_struct < 1 || amount_struct >= INT_MAX)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return amount_struct;
}
int check_number_int()
{
    int number_int;
    while (!(std::cin >> number_int) || (std::cin.peek() != '\n') || number_int <= 0 || number_int >= INT_MAX)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return number_int;
}
long double check_number_long_double()
{ 
    long double number_long_double;
    while (!(std::cin >> number_long_double) || (std::cin.peek() != '\n') || number_long_double <= 0 || number_long_double >= MAX_LONG_DOUBLE)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return number_long_double;
}
string check_string_name_of_team(Human* human, int i)
{
    string string_name_of_team;
    rewind(stdin);
    getline(std::cin, string_name_of_team);
    return string_name_of_team;
}
string check_string_name_of_team2(Human* human)
{
    string string_name_of_team2;
    rewind(stdin);
    getline(std::cin, string_name_of_team2);
    return string_name_of_team2;
}
string check_string_name_of_country(Human* human, int i)
{
    string string_name_of_country;
    int length_string_name_of_country;
    int temp_check = 0, check;
    while (true)
    {
        rewind(stdin);
        getline(std::cin, string_name_of_country);
        length_string_name_of_country = string_name_of_country.length();
        check = 1;
        while (temp_check < length_string_name_of_country)
        {
            if (!isalpha(string_name_of_country[temp_check]))
            {
                check = 0;
                break;
            }
            else if (isalpha(string_name_of_country[temp_check + 1]) && string_name_of_country[temp_check] == ' ')
            {
                check = 0;
                break;
            }
            else if (temp_check == 0 && string_name_of_country[temp_check] == '\n')
            {
                check = 0;
                break;
            }
            temp_check++;
        }
        if (length_string_name_of_country == 0)
        {
            check = 0;
        }
        if (check == 1)
        {
            break;
        }

        std::cout << "Некорректный ввод, попробуйте снова!\n";

        rewind(stdin);
    }
    return string_name_of_country;

}
string check_string_name_of_country2(Human* human)
{
    string string_name__of_country2;
    int length_string_name_of_country2;
    int temp_check = 0, check;
    while (true)
    {
        rewind(stdin);
        getline(std::cin, string_name__of_country2);
        length_string_name_of_country2 = string_name__of_country2.length();
        check = 1;
        while (temp_check < length_string_name_of_country2)
        {
            if (!isalpha(string_name__of_country2[temp_check]))
            {
                check = 0;
                break;
            }
            else if (isalpha(string_name__of_country2[temp_check + 1]) && string_name__of_country2[temp_check] == ' ')
            {
                check = 0;
                break;
            }
            else if (temp_check == 0 && string_name__of_country2[temp_check] == '\n')
            {
                check = 0;
                break;
            }
            temp_check++;
        }
        if (length_string_name_of_country2 == 0)
        {
            check = 0;
        }
        if (check == 1)
        {
            break;
        }

        std::cout << "Некорректный ввод, попробуйте снова!\n";

        rewind(stdin);
    }
    return string_name__of_country2;

}
string check_name_of_student(Human* information, long long i, bool search)
{
    std::string name_of_student;
    while (true)
    {
        rewind(stdin);
        bool check = 1, space_in_a_row = 0, not_enough_names = 0;
        int times = 0, space = 0, names = 0;
        name_of_student;

        if (!search)
        {
            std::cout << "Введите ФИО студента под номером " << i + 1 << "\n";
            getline(std::cin, name_of_student);
            information[i].fio = name_of_student;
        }
        else
        {
            getline(std::cin, name_of_student);
            information[i].fio = name_of_student;
        }

        long long dlina = information[i].fio.length();
        name_of_student = information[i].fio;

        while (times < dlina)
        {
            space_in_a_row = 0;
            not_enough_names = 0;
            if (!isalpha(name_of_student[times]) && times == 0)

            {
                check = 0;
                break;
            }

            if (!isalpha(name_of_student[times]) && name_of_student[times] != ' ')
            {
                check = 0;
                break;
            }

            if (name_of_student[times] == ' ' && name_of_student[times + 1] == ' ')
            {
                check = 0;
                space_in_a_row = 1;
                break;
            }

            if (name_of_student[times] == ' ')
            {
                space++;
            }

            times++;

            if (times == dlina && space != 2)
            {
                check = 0;
                not_enough_names = 1;
                break;
            }

            if (!isalpha(name_of_student[dlina - 1]))
            {
                check = 0;
                not_enough_names = 1;
                break;
            }
        }
        if (check)
        {
            break;
        }
        std::cout << "Некорректный ввод, попробуйте снова!\a\n";

        if (space_in_a_row)
        {
            std::cout << "Между фамилией именем и отчеством должен быть только 1 пробел!\n";
        }

        if (not_enough_names)
        {
            std::cout << "Надо обязательно писать и имя, и фамилию, и отчество!(последним символом не может быть пробел)\n";
        }

        information[i].fio.erase(0, dlina);
        rewind(stdin);
    }
    return name_of_student;
}
// Number 1.1
Human* addition_function1_option1(Human* obj, int& amount, int& min)
{
    obj = new Human[amount];
    for (int i = 0; i < amount; i++)
    {
        cout << "Название страны: ";
        obj[i].country = check_string_name_of_country(obj, i);
        cout << "Название команды: ";
        obj[i].name_of_team = check_string_name_of_team(obj, i);
        cout << "Введите ФИО ";
        obj[i].fio = check_name_of_student(obj, i, false);
        cout << "Введите Номер игрока: ";
        obj[i].nomer = check_number_int();
        cout << "Введите возраст(лет): ";
        obj[i].age = check_number_long_double();
        cout << "Введите рост(см): ";
        obj[i].heigth = check_number_long_double();
        cout << "Введите вес(кг): ";
        obj[i].weigth = check_number_long_double();
        printf("\n");
        if (obj[i].age < min)
        {
            min = obj[i].age;
        }
    }
    return obj;
}
// Number 1.2
void help_addition_function1_option2(Human* obj, int& count, int plus, int& min)
{
    for (int i = 0 + plus; i < count; i++)
    {
        cout << "Название страны: ";
        obj[i].country = check_string_name_of_country(obj, i);
        cout << "Название команды: ";
        obj[i].name_of_team = check_string_name_of_team(obj, i);
        cout << "Введите ФИО ";
        obj[i].fio = check_name_of_student(obj, i, false);
        cout << "Введите Номер игрока: ";
        obj[i].nomer = check_number_int();
        cout << "Введите возраст(лет): ";
        obj[i].age = check_number_long_double();
        cout << "Введите рост(см): ";
        obj[i].heigth = check_number_long_double();
        cout << "Введите вес(кг): ";
        obj[i].weigth = check_number_long_double();
        printf("\n");
        if (obj[i].age < min)
        {
            min = obj[i].age;
        }
    }
}
Human* addition_function1_option2(Human* obj, int& amount, int& min)
{
    amount = 1;
    Human* structure = new Human[amount];
    string temp_string;
    long double temp_variable = 0;
    int choice = 0;
    int plus = 0;
    int add = 0;
    printf("\nПо какому признаку будем смотреть?\n");
    printf("1. По стране\n");
    printf("2. По названию команда\n");
    printf("3. По ФИО\n");
    printf("4. По номеру игрока\n");
    printf("5. По возрасту\n");
    printf("6. По росту\n");
    printf("7. По весу\n");
    choice = check_number_of_attribute();

    if (choice == 1)
    {
        printf("Введите страну. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_string = check_string_name_of_country(obj, 0);
    }
    else if (choice == 2)
    {
        printf("Введите название команды. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_string = check_string_name_of_team(obj, 0);
    }
    else if (choice == 3)
    {
        printf("Введите ФИО. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_string = check_name_of_student(structure, 0, false);
    }
    else if (choice == 4)
    {
        printf("Введите номер игрока. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_variable = check_number_int();
    }
    else if (choice == 5)
    {
        printf("Введите возраст. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_variable = check_number_long_double();
    }
    else if (choice == 6)
    {
        printf("Введите рост. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_variable = check_number_long_double();
    }
    else if (choice == 7)
    {
        printf("Введите вес. Когда в структуре появится такой же признак, ввод закончится: ");
        temp_variable = check_number_long_double();
    }
    int again = 1;
    while (true)
    {
        help_addition_function1_option2(structure, amount, plus, min);
        if (choice == 1)
        {
            if (temp_string == structure[add].country)
            {
                again = 0;
            }
        }
        else if (choice == 2)
        {
            if (temp_string == structure[add].name_of_team)
            {
                again = 0;
            }
        }
        else if (choice == 3)
        {
            if (temp_string == structure[add].fio)
            {
                again = 0;
            }
        }
        else if (choice == 4)
        {
            if (temp_variable == structure[add].nomer)
            {
                again = 0;
            }
        }
        else if (choice == 5)
        {
            if (temp_variable == structure[add].age)
            {
                again = 0;
            }
        }
        else if (choice == 6)
        {
            if (temp_variable == structure[add].heigth)
            {
                again = 0;
            }
        }
        else if (choice == 7)
        {
            if (temp_variable == structure[add].weigth)
            {
                again = 0;
            }
        }

        if (again == 1)
        {
            amount++;
            for (int i = 0; i < amount - 1; i++)
            {
                obj[i] = structure[i];
            }
            delete[] structure;

            structure = new Human[amount];
            for (int i = 0; i < amount - 1; i++)
            {
                structure[i] = obj[i];
            }
            delete[] obj;
            obj = new Human[amount];
            plus++;
            add++;
        }
        else
        {
            for (int i = 0; i < amount; i++)
            {
                obj[i] = structure[i];
            }
            delete[] structure;
            break;
        }
    }

    return obj;
}
// Number 1.3
Human* addition_function1_option3(Human* obj, int amount)
{
    if (amount == 0)
    {
        obj = new Human[amount + 1];	// выделение памяти для первой структуры
    }
    else
    {
        Human* tempObj = new Human[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = obj[i];	    // копируем во временный объект
        }
        delete[] obj;

        obj = tempObj;
    }
    return obj;
}
// Просмотр
void view_function2(Human* human, int& count)
{
    system("cls");
    cout << "Номер" << "     " << "Название страны" << "     " << "Название команды" << "            " << "ФИО" << "           " << "Номер игрока" << "   " << "Возраст(лет)" << "   " << "Рост(см)" << "   " << "Вес(кг)" << '\n';
    cout << "________________________________________________________________________________________________________________________" << '\n';
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << setw(24) << human[i].country << setw(21) << human[i].name_of_team << setw(16) << human[i].fio << setw(22) << human[i].nomer << setw(15) << human[i].age << setw(11) << human[i].heigth << setw(10) << human[i].weigth << '\n';
    }
    cout << "________________________________________________________________________________________________________________________" << '\n';
}
// Добавление
void help_addition_function3(Human* obj, int& amount, int add, int i, int& min)
{
    for (int i = amount; i < amount + add; i++)
    {
        cout << "Название страны: ";
        obj[i].country = check_string_name_of_country(obj, i);
        cout << "Название команды: ";
        obj[i].name_of_team = check_string_name_of_team(obj, i);
        cout << "Введите ФИО ";
        obj[i].fio = check_name_of_student(obj, i, false);
        cout << "Введите Номер игрока: ";
        obj[i].nomer = check_number_int();
        cout << "Введите возраст(лет): ";
        obj[i].age = check_number_long_double();
        cout << "Введите рост(см): ";
        obj[i].heigth = check_number_long_double();
        cout << "Введите вес(кг): ";
        obj[i].weigth = check_number_long_double();
        printf("\n");
        if (obj[i].age < min)
        {
            min = obj[i].age;
        }
    }
}
Human* addition_function3(Human* human, int& amount, int dobav, int& min)
{
    Human* addition_struct = new Human[amount + dobav];
    for (int i = 0; i < amount + dobav; i++)
    {
        if (i == amount)
        {
            help_addition_function3(addition_struct, amount, dobav, i, min);
            break;
        }
        addition_struct[i] = human[i];
    }
    delete[] human;
    amount += dobav;
    human = new Human[amount];
    human = addition_struct;

    return human;
}
// Ответ
void answer_function4(Human* human, int& amount, int& min)
{
    for (int i = 0; i < amount; i++)
    {
        if (human[i].age == min)
        {
            cout << "Номер" << "     " << "Название страны" << "     " << "Название команды" << "            " << "ФИО" << "           " << "Номер игрока" << "   " << "Возраст(лет)" << "   " << "Рост(см)" << "   " << "Вес(кг)" << '\n';
            cout << "________________________________________________________________________________________________________________________" << '\n';
            cout << i + 1 << setw(24) << human[i].country << setw(21) << human[i].name_of_team << setw(16) << human[i].fio << setw(22) << human[i].nomer << setw(15) << human[i].age << setw(11) << human[i].heigth << setw(10) << human[i].weigth << '\n';
            cout << "________________________________________________________________________________________________________________________" << '\n';
        }

    }
}
// изменение
int help2_change_function5(int& amount)
{
    int number;
    while (!(std::cin >> number) || (std::cin.peek() != '\n' && std::cin.peek() == ' ') || number < 1 || number > amount)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            printf("\n");
            printf("Некорректный ввод, попробуйте снова!\n");
        }
    }
    return number;
}
void help_change_function5(Human* obj, int amount, int& min)
{
    min = INT_MAX;
    cout << "Название страны: ";
    obj[amount].country = check_string_name_of_country2(obj);
    cout << "Название команды: ";
    obj[amount].name_of_team = check_string_name_of_team2(obj);
    cout << "Введите ФИО ";
    obj[amount].fio = check_name_of_student(obj, 0, false);
    cout << "Введите Номер игрока: ";
    obj[amount].nomer = check_number_int();
    cout << "Введите возраст(лет): ";
    obj[amount].age = check_number_long_double();
    cout << "Введите рост(см): ";
    obj[amount].heigth = check_number_long_double();
    cout << "Введите вес(кг): ";
    obj[amount].weigth = check_number_long_double();
    printf("\n");
    for (int i = 0; i < amount; i++)
    {
        if (obj[i].age < min)
        {
            min = obj[i].age;
        }
    }
}
Human* change_function5(Human* human, int& amount, int& min)
{
    printf("\nВведите номер который надо изменить:");
    int change_elememts_of_struct;
    change_elememts_of_struct = help2_change_function5(amount);

    for (int i = 0; i < amount; i++)
    {
        if (i == change_elememts_of_struct - 1)
        {
            help_change_function5(human, i, min);
            break;
        }
    }

    return human;
}
// Удаление
Human* delete_function6(Human* human, int& amount, int& min)
{
    printf("\nВведите номер(по порядку) который хотите убрать: ");
    int delete_elememts_of_struct;
    delete_elememts_of_struct = help2_change_function5(amount);
    Human* dop = new Human[amount - 1];
    int dopoln = 0;
    for (int i = 0; i < amount; i++)
    {
        if (i != delete_elememts_of_struct - 1 && i < amount)
        {
            dop[i + dopoln] = human[i];
        }
        else
        {
            dopoln = -1;
        }
    }
    delete[] human;
    amount--;
    human = new Human[amount];
    for (int i = 0; i < amount; i++)
    {
        human[i] = dop[i];
    }
    min = INT_MAX;
    for (int i = 0; i < amount; i++)
    {
        if (human[i].age < min)
        {
            min = human[i].age;
        }
    }
    return human;
}
// сортировка
void help_swap_function10(Human* human, int i)
{
    long double buff;
    buff = human[i].age;
    human[i].age = human[i - 1].age;
    human[i - 1].age = buff;

    string s;
    s = human[i].country;
    human[i].country = human[i - 1].country;
    human[i - 1].country = s;

    s = human[i].name_of_team;
    human[i].name_of_team = human[i - 1].name_of_team;
    human[i - 1].name_of_team = s;

    s = human[i].fio;
    human[i].fio = human[i - 1].fio;
    human[i - 1].fio = s;

    buff = human[i].nomer;
    human[i].nomer = human[i - 1].nomer;
    human[i - 1].nomer = buff;

    buff = human[i].heigth;
    human[i].heigth = human[i - 1].heigth;
    human[i - 1].heigth = buff;

    buff = human[i].weigth;
    human[i].weigth = human[i - 1].weigth;
    human[i - 1].weigth = buff;
}
void sotr_function10(Human* human, int& amount)
{
    int leftMark = 1;
    int rightMark = amount - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
            if (human[i - 1].age > human[i].age)
                help_swap_function10(human, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
            if (human[i - 1].age > human[i].age)
                help_swap_function10(human, i);
        rightMark--;
    }

}



// С файлом
void zapis(Human* human, int& count);
void PrintInfo();
// Файл ответ
void zapis2(Human* human, int& count, int& min);
void PrintInfo2();
// Основной ФАЙЛ
void file1(Human* information, int& size);
Human* file_enter(int& size, Human* information);


int main()
{
    setlocale(LC_ALL, "ru");
    int amount_struct = 0, number_of_options{}, j{};
    int amount_addition_struct = 0;
    int min_age = INT_MAX;
    Human* human = new Human[amount_struct];
    condition();
    whoami();
    while (true)
    {
        printf("Выберите функцию:\n");
        printf("1. Записать структуры(и файла).\n");
        printf("2. Просмотр содержимого структуры.\n");
        printf("3. Дополнения уже существующего массива структур новыми структурами.\n");
        printf("4. Ответ на задание (информация о самой молодой команде).\n");
        printf("5. Изменение структуры.\n");
        printf("6. Удаления структуры.\n");
        printf("7. Вывод информации из файла.\n");
        printf("8. Запись в файл(ответ на задание)\n");
        printf("9. Вывод из файла(ответ на задание)\n");
        printf("10. Сортировка\n");
        printf("11. Выход из программы\n\n");

        int number_of_functions;
        number_of_functions = check_number_of_functions();

        if (number_of_functions == 1)
        {
            printf("1. Ввод заданного количества струкрут\n");
            printf("2. Ввод до появления структуры с заданным признаком\n");
            printf("3. Диалог с пользователем о необходимости продолжать ввод\n");
            number_of_options = check_number_of_functions();
            bool temp = true;
            while (temp)
            {
                if (number_of_options != 1 && number_of_options != 2 && number_of_options != 3)
                {
                    printf("Такого варианта нет\nПовторите попытку: ");
                    temp = true;
                }
                else if (number_of_options == 1)
                {
                    printf("Введите количество структур\n");
                    amount_struct = check_amount_struct();
                    delete[] human;
                    human = new Human[amount_struct];
                    human = addition_function1_option1(human, amount_struct, min_age);
                    zapis(human, amount_struct);
                    file1(human, amount_struct);
                    break;
                }
                else if (number_of_options == 2)
                {
                    delete[] human;
                    int j = 100;
                    amount_struct = 0;
                    human = new Human[j];
                    human = addition_function1_option2(human, amount_struct, min_age);
                    zapis(human, amount_struct);
                    break;
                }
                else if (number_of_options == 3)
                {
                    delete[] human;
                    amount_struct = 0;
                    human = new Human[amount_struct];
                    int YesOrNot = 1;
                    while (YesOrNot)
                    {
                        human = addition_function1_option3(human, amount_struct);
                        help_change_function5(human, amount_struct, min_age);
                        amount_struct++;
                        zapis(human, amount_struct);
                        cout << "Продолжить ввод данных:" << "\n";
                        cout << "1 - да" << "\n";
                        cout << "2 - нет" << "\n";
                        while ((YesOrNot != 0 && YesOrNot != 1) || !(std::cin >> YesOrNot) || (std::cin.peek() != '\n'))
                        {
                            std::cin.clear();
                            while (std::cin.get() != '\n');
                            {
                                printf("Некорректный ввод\n");
                                printf("Попробуйте снова: ");
                            }
                        }
                    }
                    break;
                }
                cin >> number_of_options;
            }
        }

        else if (number_of_functions == 2)
        {
            if (amount_struct == 0)
            {
                human = file_enter(amount_struct, human);
                view_function2(human, amount_struct);
            }
            else
            {
                view_function2(human, amount_struct);
            }
        }

        else if (number_of_functions == 3)
        {
            printf("Введите, сколько структур вы хотите добавить: ");
            amount_addition_struct;
            amount_addition_struct = check_number_int();
            human = addition_function3(human, amount_struct, amount_addition_struct, min_age);
            zapis(human, amount_struct);
            zapis2(human, amount_struct, min_age);
            file1(human, amount_struct);
        }

        else if (number_of_functions == 4)
        {
            if (amount_struct == 0)
            {
                printf("Структура пуста\n\n");
            }
            else
            {
                answer_function4(human, amount_struct, min_age);
            }
        }

        else if (number_of_functions == 5)
        {
            if (amount_struct == 0)
            {
                printf("Структура пуста\n\n");
            }
            else
            {
                human = change_function5(human, amount_struct, min_age);
                zapis(human, amount_struct);
                file1(human, amount_struct);
            }
        }

        else if (number_of_functions == 6)
        {
            if (amount_struct == 0)
            {
                printf("Структура пуста, менять нечего\n\n");
            }
            else
            {
                human = delete_function6(human, amount_struct, min_age);
                zapis(human, amount_struct);
                file1(human, amount_struct);
            }
        }

        else if (number_of_functions == 7)
        {
            file1(human, amount_struct);
        }

        else if (number_of_functions == 8)
        {
            if (amount_struct == 0)
            {
                printf("Ничего нельзя записать(пусто)\n\n");
            }
            else
            {
                printf("Записано в файл, чтобы вывести, нажмите 9\n\n");
                zapis2(human, amount_struct, min_age);
            }
        }

        else if (number_of_functions == 9)
        {
            PrintInfo2();
        }

        else if (number_of_functions == 10)
        {
            if (amount_struct == 0)
            {
                printf("Сортировать нечего\n\n");
            }
            else
            {
                sotr_function10(human, amount_struct);
                zapis(human, amount_struct);
                printf("Cтруктура отсортирована\n\n");
            }
        }

        else if (number_of_functions == 11)
        {
            printf("\nПрограмма завершена.\n\n");
            return 0;
        }

        else if (number_of_functions == 12)
        {

        }

    }

}


// C файлом
void zapis(Human* human, int& count)
{
    ofstream fout;
    fout.open("AllInfa.txt");
    fout << "\nВся информация:\n\n";
    for (int i = 0; i < count; i++)
    {
        fout << "Страна: ";
        fout << human[i].country;
        fout << '\n';
        fout << "Команда: ";
        fout << human[i].name_of_team;
        fout << '\n';
        fout << "ФИО: ";
        fout << human[i].fio;
        fout << '\n';
        fout << "Номер игрока: ";
        fout << human[i].nomer;
        fout << '\n';
        fout << "Возраст: ";
        fout << human[i].age;
        fout << '\n';
        fout << "Рост: ";
        fout << human[i].heigth;
        fout << '\n';
        fout << "Вес: ";
        fout << human[i].weigth;
        fout << '\n' << '\n';
    }
    fout.close();
}
void PrintInfo()
{
    ifstream fin;
    fin.open("AllInfa.txt");
    if (fin.is_open())
    {
        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
    }
    else
    {
        cout << "Не открыт";
    }
}

// Файл ответ
void zapis2(Human* human, int& count, int& min)
{
    ofstream file;
    file.open("Otvet.txt");
    file << "Ответ\n\n";
    for (int i = 0; i < count; i++)
    {
        if (human[i].age == min)
        {
            file << "Страна: ";
            file << human[i].country;
            file << '\n';
            file << "Команда: ";
            file << human[i].name_of_team;
            file << '\n';
            file << "ФИО: ";
            file << human[i].fio;
            file << '\n';
            file << "Номер игрока: ";
            file << human[i].nomer;
            file << '\n';
            file << "Возраст: ";
            file << human[i].age;
            file << '\n';
            file << "Рост: ";
            file << human[i].heigth;
            file << '\n';
            file << "Вес: ";
            file << human[i].weigth;
            file << '\n' << '\n';
        }
    }
    file.close();
}
void PrintInfo2()
{
    ifstream th;
    th.open("Otvet.txt");
    if (th.is_open())
    {
        char yu;
        while (th.get(yu))
        {
            cout << yu;
        }
    }
    else
    {
        printf("Не открыт");
    }
}

// Основной ФАЙЛ
void file1(Human* information, int& size)
{
    std::ofstream EndFile;
    EndFile.open("file_end.txt", std::ios::out);
    for (int i = 0; i < size; i++)
    {
        EndFile << information[i].country << '\n';
        EndFile << information[i].name_of_team << '\n';
        EndFile << information[i].fio << '\n';
        EndFile << information[i].nomer << '\n';
        EndFile << information[i].age << '\n';
        EndFile << information[i].heigth << '\n';
        EndFile << information[i].weigth << '\n';
        EndFile << '\n';
    }
}
Human* file_enter(int& size, Human* information)
{
    std::ifstream file_start;
    file_start.open("file_end.txt", std::ios::in);

    std::string string;
    int num_of_files = 0;
    while (!file_start.eof())
    {
        std::getline(file_start, string);
        if (string != "\0")
        {
            num_of_files++;
        }
    }
    file_start.close();
    file_start.open("file_end.txt", std::ios::in);
    num_of_files /= 7;
    size = num_of_files;
    delete[] information;
    information = new Human[num_of_files];
    for (int i = 0; i < size; i++)
    {
        getline(file_start, information[i].country);
        getline(file_start, information[i].name_of_team);
        getline(file_start, information[i].fio);
        file_start >> information[i].nomer;
        file_start >> information[i].age;
        file_start >> information[i].heigth;
        file_start >> information[i].weigth;
        int l = file_start.tellg(); // Возвращает позицию текущего символа во входном потоке.
        if (file_start.peek() == ' ' || file_start.peek() == '\0' || file_start.peek() == '\n') // Eсли пустая
        {
            l += 4;
        }
        file_start.seekg(l, std::ios_base::beg); // Устанавливает позицию следующего символа, который будет извлечен из входного потока.
    }
    file_start.close();

    return information;
}
