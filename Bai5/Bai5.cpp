#include <iostream>
#include <string>
#include<cctype>
using namespace std;

// Hàm dùng để tạo key.
string CreateKey(string str, string key)
{
    int x = key.size(), k = 0;
    char temp;
    string keyword;
    for (int i = 0; i < str.size(); i++) {
        // k sẽ trở về 0 nếu như k bằng với chiều dài key ban đầu.
        if (k == x)
            k = 0;
        // nếu str[i] không thuộc bảng alphabet thì temp bằng khoảng trắng.
        if (!isalpha(str[i])) {
            temp = ' ';
        }
        // ngược lại temp bằng với ký tự key[k]. 
        else {
            temp = key[k];
            k++;
        }
        // đẩy ký tự vào cuối chuỗi.
        keyword.push_back(temp);
    }
    return keyword;
}

// Hàm dùng để mã hóa messeage 
string Encyption(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
        char x;
        // Nếu ký tự trong chuỗi không phải khoảng trống, dấu ',' , '.' thì thực hiện chuyển đổi để mã hóa
        if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '-')
        {
             x = (str[i] + key[i]) % 26;
             x += 'A'; // chuyển về ký tự trong ASCII
        }
        // Ngược lại thì giữ nguyên nó, không cần mã hóa
        else {
            if (str[i] == ' ')
                x = ' ';
            if (str[i] == ',')
                x = ',';
            if (str[i] == '.')
                x = '.';
            if (str[i] == '-')
                x = '-';
        }    
        cipher_text.push_back(x);
    }
    return cipher_text;
}

// Hàm dùng để giải mã 
string Decryption(string cipher_text, string key)
{
    string Plain_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        char x;
        if (cipher_text[i] != ' ' && cipher_text[i] != ',' && cipher_text[i] != '.' && cipher_text[i] != '-')
        {
            x = (cipher_text[i] - key[i] + 26) % 26;
            x += 'A'; // chuyển về ký tự trong ASCII
        }
        else {
            if (cipher_text[i] == ' ')
                x = ' ';
            if (cipher_text[i] == ',')
                x = ',';
            if (cipher_text[i] == '.')
                x = '.';
            if (cipher_text[i] == '-')
                x = '-';
        }
        Plain_text.push_back(x);
    }
    return Plain_text;
}
// Hàm dùng chuyển thành các ký tự in hoa
string SolveString(string str) {
   
    for (int i = 0; i <= str.size();i++) {
        
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
 }
int main()
{
    string str, keyword;
    fflush(stdin);
    cout << "Nhap Message: ";
    getline(cin, str);
    fflush(stdin);
    cout << "Nhap Keywords: ";
    getline(cin, keyword);

    string message = SolveString(str);
    string key_solve = SolveString(keyword);
    string key = CreateKey(message, key_solve);
    string cipher_text = Encyption(message, key);

    cout << "\nCiphertext : " << cipher_text << "\n\n";
    cout << "PlainText : " << Decryption(cipher_text, key);
    
    return 0;
}