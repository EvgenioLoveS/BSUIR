extern "C" void asmsolution();
#include<iostream.h>
#include <stdio.h>

void print_binary(double input_number)
{
    long long binary_representation = *(long long*)&input_number;

    for (int bit_position = 63; bit_position >= 0; bit_position--)
    {
        if ((1 << bit_position) & binary_representation) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << "\n";
    return;
}

char* print_hex(double number)
{
    unsigned char* buffer = (unsigned char*)&number;
    int buffer_size = sizeof(double);

    char* hex_representation = new char[buffer_size * 2 + 1];

    int j = 0;
    for (int i = 0; i < buffer_size; ++i)
    {
        sprintf(&hex_representation[j * 2], "%02X", buffer[i]);
        ++j;
    }
    hex_representation[buffer_size * 2] = '\0';

    return hex_representation;
}

void print_root_info(double root, int& root_count)
{
    int bufferSize = sizeof(double) * 2;
    char* nan_pattern = new char[bufferSize + 1];
    char* inf_pattern1 = new char[bufferSize + 1];
    char* inf_pattern2 = new char[bufferSize + 1];

    for (int i = 0; i < bufferSize; i++)
    {
        if (i == 14) {
            nan_pattern[i] = '7';
        }
        else {
            nan_pattern[i] = 'F';
        }
    }
    nan_pattern[bufferSize] = '\0';

    for (int i1 = 0; i1 < bufferSize; i1++)
    {
        if (i1 <= 11 || i1 == 13) {
            inf_pattern1[i1] = '0';
        }
        else {
            inf_pattern1[i1] = 'F';
        }
    }
    inf_pattern1[bufferSize] = '\0';

    for (int i2 = 0; i2 < bufferSize; ++i2)
    {
        if (i2 <= 11 || i2 == 13) {
            inf_pattern2[i2] = '0';
        }
        else {
            if (i2 == 14) {
                inf_pattern2[i2] = '7';
            }
            else {
                inf_pattern2[i2] = 'F';
            }
        }
    }
    inf_pattern2[bufferSize] = '\0';

    char* hex = print_hex(root);
    int check = 0;

    for (int i3 = 0; i3 < 16; i3++)
    {
        if (nan_pattern[i3] != hex[i3]) {
            check = 1;
        }
    }
    if (check == 0) {
        return;
    }
    check = 0;
    for (int i4 = 0; i4 < 16; i4++)
    {
        if (inf_pattern1[i4] != hex[i4]) {
            check = 1;
        }
    }
    if (check == 0) {
        return;
    }
    check = 0;
    for (int i5 = 0; i5 < 16; i5++)
    {
        if (inf_pattern2[i5] != hex[i5]) {
            check = 1;
        }
    }
    if (check == 0) {
        return;
    }

    root_count++;
    //cout<<"NAN "<<nan1<<"\n";
    //cout<<"inf1 "<<inf1<<"\n"; 
    //cout<<"inf2 "<<inf2<<"\n";   
    cout << "Root in decimal\n" << root << "\n";
    cout << "Root in binary\n";
    print_binary(root);
    cout << "Root in hex\n" << hex << "\n";
}

int main() {
    double root1,root2,root3,root4;
    int roots_count = 0;

    asmsolution();
    asm{
    fstp root1
    fstp root2
    fstp root3
    fstp root4
    };

    print_root_info(root1, roots_count);
    print_root_info(root2, roots_count);
    print_root_info(root3, roots_count);
    print_root_info(root4, roots_count);

    if (roots_count == 0) {
        cout << "No Roots";
    }

    cout << "\n";
    cin.get();

    return 0;
}