#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <windows.h> // для system("cls");

using namespace std;

struct struct_human
{
    string surname; // фамилия
    string name; // имя
    string otechestvo; // отчество
    int num_of_department; // номер отдела
    string rank; // должность
    int experience; // стаж
};

void condition() {
    printf("Информация о сотрудниках содержит ФИО, номер отдела, должность, стаж работы на предприятии.\n");
    printf("Вывести список сотрудников заданного отдела, имеющих стаж работы на предприятии более 20 лет.\n");
    printf("(Шейкер сортировка по (возрастанию).\n");
}
void whoami() {
    printf("\n");
    printf("Выполнил: Жгутов Евгений Дмитриевич\n");
    printf("Группа: 253505\n");
}
// проверки на ввод
int check_number_of_functions()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || a < 1 || a > 8)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "\n";
            std::cout << "Ошибка ввода, повторите ввод!!!\n";
            std::cout << "Выберите функцию:\n";
        }
    }
    return a;
}
int check_number_of_options()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || a < 1 || a > 3)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "\n";
            std::cout << "Ошибка ввода, повторите ввод!!!\n";
            std::cout << "Выберите опцию:\n";
        }
    }
    return a;
}
int check_number()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || a < 0 || a > INT_MAX)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "\n";
            std::cout << "Ошибка ввода, повторите ввод!!!\n";
            std::cout << "Число должно быть положительным:\n";
        }
    }
    return a;
}
int check_number_of_attribute()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || a < 1 || a > 6)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "\n";
            std::cout << "Ошибка ввода, повторите ввод!!!\n";
        }
    }
    return a;
}
int check_of_number_change(int count)
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n' && std::cin.peek() != ' ') || a < 0 || a > count)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        {
            std::cout << "\n";
            std::cout << "Ошибка ввода, повторите ввод!!!\n";
        }
    }

    return a;
}
string check_for_string()
{
    string str;
    int length_of_str;
    int help_of_string = 0;
    int check;
    while (true)
    {
        rewind(stdin);
        getline(std::cin, str);
        length_of_str = str.length();
        check = 1;
        while (help_of_string < length_of_str)
        {
            if (!isalpha(str[help_of_string]))
            {
                check = 0;
                break;
            }
            else if (isalpha(str[help_of_string + 1]) && str[help_of_string] == ' ')
            {
                check = 0;
                break;
            }
            else if (help_of_string == 0 && str[help_of_string] == '\n')
            {
                check = 0;
                break;
            }
            help_of_string++;
        }
        if (length_of_str == 0)
        {
            check = 0;
        }
        if (check == 1)
        {
            break;
        }

        printf("Некорректный ввод, попробуйте снова!\n");
        rewind(stdin);
    }
    return str;
}

void sheker_sort_function6(struct_human* human, int& count) // Функция Шейкер-сортировки
{
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (human[i].experience > human[i + 1].experience) // если следующий элемент меньше текущего,
            {             // меняем их местами
                int t = human[i].experience;
                human[i].experience = human[i + 1].experience;
                human[i + 1].experience = t;

                string s = human[i].surname;
                human[i].surname = human[i + 1].surname;
                human[i + 1].surname = s;

                string s2 = human[i].name;
                human[i].name = human[i + 1].name;
                human[i + 1].name = s2;

                string s3 = human[i].otechestvo;
                human[i].otechestvo = human[i + 1].otechestvo;
                human[i + 1].otechestvo = s3;

                int x = human[i].num_of_department;
                human[i].num_of_department = human[i + 1].num_of_department;
                human[i + 1].num_of_department = x;

                string s4 = human[i].rank;
                human[i].rank = human[i + 1].rank;
                human[i + 1].rank = s4;

                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (human[i - 1].experience > human[i].experience) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                int t = human[i].experience;

                human[i].experience = human[i - 1].experience;
                human[i - 1].experience = t;

                string s = human[i].surname;
                human[i].surname = human[i - 1].surname;
                human[i - 1].surname = s;

                string s2 = human[i].name;
                human[i].name = human[i - 1].name;
                human[i - 1].name = s2;

                string s3 = human[i].otechestvo;
                human[i].otechestvo = human[i - 1].otechestvo;
                human[i - 1].otechestvo = s3;

                int x = human[i].num_of_department;
                human[i].num_of_department = human[i - 1].num_of_department;
                human[i - 1].num_of_department = x;

                string s4 = human[i].rank;
                human[i].rank = human[i - 1].rank;
                human[i - 1].rank = s4;

                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    cout << "№\t" << "Фамилия\t\t" << "Имя\t" << "Отчество\t" << "Номер отдела\t" << "Должность\t" << "Стаж\t\t" << endl;
    cout << "=====================================================================================" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "\t" << human[i].surname << "\t\t" << human[i].name << "\t" << human[i].otechestvo << "\t\t" << human[i].num_of_department << "\t\t" << human[i].rank << "\t\t" << human[i].experience << endl;
    }
}
struct_human* helpadd_for_option(int count, int plus, struct_human* human) // предварительный варик
{
    for (int i = 0 + plus; i < count; i++)
    {
        printf("\nФамилия:\n");
        human[i].surname = check_for_string();
        printf("Имя:\n");
        human[i].name = check_for_string();
        printf("Отчество:\n");
        human[i].otechestvo = check_for_string();
        printf("Номер отдела:\n");
        human[i].num_of_department = check_number();
        printf("Должность:\n");
        human[i].rank = check_for_string();
        printf("Стаж:\n");
        human[i].experience = check_number();
    }
    return human;
}
// 1.1
struct_human* add_option_one(int count, struct_human* human) // предварительный варик
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "\n" << "Введите " << i + 1 << " структуру: " << "\n";
        printf("Фамилия:\n");
        human[i].surname = check_for_string();
        printf("Имя:\n");
        human[i].name = check_for_string();
        printf("Отчество:\n");
        human[i].otechestvo = check_for_string();
        printf("Номер отдела:\n");
        human[i].num_of_department = check_number();
        printf("Должность:\n");
        human[i].rank = check_for_string();
        printf("Стаж:\n");
        human[i].experience = check_number();
    }
    return human;
}
// 1.2
struct_human* add_option_two(int& count, struct_human* human)
{
    printf("\nПо какому признаку:\n");
    printf("\n1. Фамилия\n2. Имя\n3. Отчество\n4. Отдел\n5. Должность\n6. Стаж\n");
    count = 1;
    struct_human* structure = new struct_human[count];
    string str_option2;
    int k = 0;
    int plus = 0;
    int add = 0;

    int number_of_attribute;
    number_of_attribute = check_number_of_attribute();

    if (number_of_attribute == 1)
    {
        printf("\nВведите фамилию, после которой остановится ввод\n");
        str_option2 = check_for_string();
    }
    else if (number_of_attribute == 2)
    {
        printf("\nВведите имя, после которого остановится ввод\n");
        str_option2 = check_for_string();
    }
    else if (number_of_attribute == 3)
    {
        printf("\nВведите отчество, после которого остановится ввод\n");
        str_option2 = check_for_string();
    }
    else if (number_of_attribute == 4)
    {
        printf("\nВведите номер отдела, после которого остановится ввод\n");
        k = check_number();
    }
    else if (number_of_attribute == 5)
    {
        printf("\nВведите должность, после которой остановится ввод\n");
        str_option2 = check_for_string();
    }
    else if (number_of_attribute == 6)
    {
        printf("\nВведите стаж, после которого остановится ввод\n");
        k = check_number();
    }
    int continuation = 1;
    while (true)
    {
        helpadd_for_option(count, plus, structure);
        if (number_of_attribute == 1)
        {
            if (str_option2 == structure[add].surname)
            {
                continuation = 0;
            }
        }
        else if (number_of_attribute == 2)
        {
            if (str_option2 == structure[add].name)
            {
                continuation = 0;
            }
        }
        else if (number_of_attribute == 3)
        {
            if (str_option2 == structure[add].otechestvo)
            {
                continuation = 0;
            }
        }
        else if (number_of_attribute == 4)
        {
            if (k == structure[add].num_of_department)
            {
                continuation = 0;
            }
        }
        else if (number_of_attribute == 5)
        {
            if (str_option2 == structure[add].rank)
            {
                continuation = 0;
            }
        }
        else if (number_of_attribute == 6)
        {
            if (k == structure[add].experience)
            {
                continuation = 0;
            }
        }

        if (continuation == 1)
        {
            count++;
            for (int i = 0; i < count - 1; i++)
            {
                human[i] = structure[i];
            }
            delete[] structure;

            structure = new struct_human[count];
            for (int i = 0; i < count - 1; i++)
            {
                structure[i] = human[i];
            }
            delete[] human;
            human = new struct_human[count];
            plus++;
            add++;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                human[i] = structure[i];
            }
            delete[] structure;
            break;
        }
    }
    return human;
}
// 1.3
struct_human* add_option_three(int& count, struct_human* human) //  1.3
{
    if (count == 0)
    {
        human = new struct_human[count + 1];
    }
    else
    {
        struct_human* additional_human = new struct_human[count + 1];
        for (int i = 0; i < count; i++)
        {
            additional_human[i] = human[i];
        }
        delete[] human;
        human = additional_human;
        return human;
    }

}
// 3
struct_human* add_function3(int& count, struct_human* human)
{
    printf("\nСколько элементов Вы хотите добавить?\n");
    int number_of_additional_elements; // количество доп элементов
    number_of_additional_elements = check_number_of_attribute();
    struct_human* additional_human = new struct_human[count + number_of_additional_elements];
    for (int i = 0; i < count; i++)
    {
        additional_human[i].surname = human[i].surname;
        additional_human[i].name = human[i].name;
        additional_human[i].otechestvo = human[i].otechestvo;
        additional_human[i].num_of_department = human[i].num_of_department;
        additional_human[i].rank = human[i].rank;
        additional_human[i].experience = human[i].experience;
    }
    for (int i = count; i < count + number_of_additional_elements; i++)
    {
        printf("\nФамилия:\n");
        additional_human[i].surname = check_for_string();
        printf("Имя:\n");
        additional_human[i].name = check_for_string();
        printf("Отчество:\n");
        additional_human[i].otechestvo = check_for_string();
        printf("Номер отдела:\n");
        additional_human[i].num_of_department = check_number();
        printf("Должность:\n");
        additional_human[i].rank = check_for_string();
        printf("Стаж:\n");
        additional_human[i].experience = check_number();
    }
    count += number_of_additional_elements;
    return additional_human;
}
void answer_function4(int& count, struct_human* human) // 4
{
    int count_of_answer = 0; // количество членов массива с 20+ лет стажем
    for (int i = 0; i < count; i++)
    {
        if (human[i].experience >= 20)
        {
            count_of_answer++;
        }
    }
    if (count_of_answer == 0)
    {
        printf("\nНет сотрудников со стажем 20 и больше лет\n");
    }
    else if (count_of_answer > 0)
    {
        int index = 0;
        cout << "№\t" << "Фамилия\t\t" << "Имя\t\t" << "Отчество\t\t" << "Номер отдела\t\t" << "Должность\t\t" << "Стаж\t\t" << endl;
        cout << "=====================================================================================" << endl;
        for (int i = 0; i < count; i++)
        {
            if (human[i].experience >= 20)
            {
                cout << index + 1 << "\t" << human[i].surname << "\t\t" << human[i].name << "\t" << human[i].otechestvo << "\t\t" << human[i].num_of_department << "\t\t" << human[i].rank << "\t\t" << human[i].experience << endl;
                index++;
            }
        }
    }
}
struct_human* change_function5_2(int& count, struct_human* human)
{
    printf("\nВведите номер, который вы хотите изменить\n");
    int number_of_change;
    number_of_change = check_of_number_change(count);
    struct_human* change_human = new struct_human[1];
    printf("\nФамилия:\n");
    change_human[0].surname = check_for_string();
    printf("Имя:\n");
    change_human[0].name = check_for_string();
    printf("Отчество:\n");
    change_human[0].otechestvo = check_for_string();
    printf("Номер отдела:\n");
    change_human[0].num_of_department = check_number();
    printf("Должность:\n");
    change_human[0].rank = check_for_string();
    printf("Стаж:\n");
    change_human[0].experience = check_number();
    human[number_of_change - 1].surname = change_human[0].surname;
    human[number_of_change - 1].name = change_human[0].name;
    human[number_of_change - 1].otechestvo = change_human[0].otechestvo;
    human[number_of_change - 1].num_of_department = change_human[0].num_of_department;
    human[number_of_change - 1].rank = change_human[0].rank;
    human[number_of_change - 1].experience = change_human[0].experience;
    return human;
}
struct_human* delete_function5_1(int& count, struct_human* human)
{
    printf("\nВведите номер элемента массива, который Вы хотите удалить\n");
    int number_of_delete;
    int help_delete = 0;
    number_of_delete = check_of_number_change(count);
    struct_human* delete_human = new struct_human[count - 1];
    for (int i = 0; i < count; i++)
    {
        if (i != number_of_delete - 1)
        {
            delete_human[i + help_delete] = human[i];
        }
        else
        {
            help_delete = -1;
        }
    }
    count--;
    delete[] human;

    return delete_human;
}

void input_struct(int& count, struct_human* human)
{
    printf("\nФамилия:\n");
    human[count].surname = check_for_string();
    printf("Имя:\n");
    human[count].name = check_for_string();
    printf("Отчество:\n");
    human[count].otechestvo = check_for_string();
    printf("Номер отдела:\n");
    human[count].num_of_department = check_number();
    printf("Должность:\n");
    human[count].rank = check_for_string();
    printf("Стаж:\n");
    human[count].experience = check_number();

}
void output_struct(int& count, struct_human* human)
{
    cout << "№\t" << "Фамилия\t\t" << "Имя\t" << "Отчество\t" << "Номер отдела\t" << "Должность\t" << "Стаж\t\t" << endl;
    cout << "=====================================================================================" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "\t" << human[i].surname << "\t\t" << human[i].name << "\t" << human[i].otechestvo << "\t\t" << human[i].num_of_department << "\t\t" << human[i].rank << "\t\t" << human[i].experience << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    condition();
    whoami();
    struct_human* human = new struct_human[1];
    int iter = 0;
    bool temp = true;
    while (temp != false)
    {
        printf("\nВыберите действие:\n");
        printf("1 - Записать структуру.\n");
        printf("2 - Просмотр содержимого структуры.\n");
        printf("3 - Дополнение уже существующего массива структур новыми структурами.\n");
        printf("4 - Ответ (сотрудники с 20+тилетним стажем).\n");
        printf("5 - Изменение структуры.\n");
        printf("6 - Удаление.\n");
        printf("7 - Шейкер сортировка по возрастанию.\n");
        printf("8 - Выход.\n");
        int number_of_function;
        int number_of_options;
        int count;
        number_of_function = check_number_of_functions();
        if (number_of_function == 1)
        {
            printf("\n1 - Ввод заранее заданного количества структур.\n");
            printf("2 - Ввод до появления структуры с заданным признаком.\n");
            printf("3 - Диалог с пользователем о необходимости продолжать ввод.\n");

            bool x = true;
            while (x)
            {

                number_of_options = check_number_of_options();

                if (number_of_options == 1)
                {
                    system("cls");
                    printf("Введите количество структур\n");
                    count = check_number_of_attribute();
                    delete[] human;
                    human = new struct_human[count];
                    human = add_option_one(count, human);
                    iter = count;
                    break;
                }
                else if (number_of_options == 2)
                {
                    delete[] human;
                    count = 1;
                    human = new struct_human[count];
                    add_option_two(count, human);
                    iter = count;
                    break;
                }
                else if (number_of_options == 3)
                {
                    delete[] human;
                    count = 0;
                    human = new struct_human[count];
                    int yes_or_no = 1;
                    while (yes_or_no == 1)
                    {
                        human = add_option_three(count, human);
                        input_struct(count, human);
                        count++;
                        iter = count;
                        printf("\nХотите ли вы продолжить ввод?\n");
                        printf("1 - Да");
                        printf("\n");
                        printf("2 - Нет");
                        printf("\n");
                        while ((yes_or_no != 0 && yes_or_no != 1) || !(cin >> yes_or_no) || (cin.peek() != '\n'))
                        {
                            cin.clear();
                            while (cin.get() != '\n')
                            {
                                printf("\nОшибка ввода, повторите ввод!!!\n");
                            }
                        }
                    }
                    break;
                }

            }
        }
        else if (number_of_function == 2)
        {
            output_struct(count, human);
        }
        else if (number_of_function == 3)
        {
            if (iter == 0)
            {
                printf("\nМассив не создана, сначала создайте ее с помощью блока номер 1.\n");
                temp = true;
            }
            else if (iter > 0)
            {
                human = add_function3(count, human);
                iter = count;
            }
        }
        else if (number_of_function == 4)
        {
            answer_function4(count, human);
            iter = count;
        }
        else if (number_of_function == 5)
        {
            if (iter == 0)
            {
                printf("\nСтруктура пуста, менять нечего.\n");
                temp = true;
            }
            else if (iter > 0)
            {
                human = change_function5_2(count, human);
                iter = count;
                output_struct(count, human);
            }
        }
        else if (number_of_function == 6)
        {
            if (iter == 0)
            {
                printf("\nСтруктура пуста, менять нечего.\n");
                temp = true;
            }
            else if (iter > 0)
            {
                human = delete_function5_1(count, human);
                iter = count;
            }

        }
        else if (number_of_function == 7)
        {
            sheker_sort_function6(human, count);
        }
        else if (number_of_function == 8)
        {
            return 0;
        }
    }
    return 0;
}