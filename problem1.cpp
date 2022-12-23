#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class node
{

public:
    int data;
    node *link;
    node(int data, node *link)
    {
        this->data = data;
        this->link = link;
    }
};
node *p = NULL, *q = NULL;

void insert_node(int data)
{

    node *new_node = new node(data, NULL);
    if (p == NULL)
    {
        p = new_node;
        q = p;
    }
    else
    {
        q->link = new_node;
        q = new_node;
    }
}

void removeDupWord(string str, int a[])
{
    string word = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            stringstream geek(word);

            int x = 0;
            geek >> x;

            a[i] = x;
            cout << a[i];
            word = "";
        }
        else
        {
            word = word + str[i];
        }
    }
}

string removeDuplicates(string s, int i){
    char a = s[i];
    if(i == -1) return a + "";
    while(i > 0 && s[i] == s[i - 1]) i--;
    i--;
    return removeDuplicates(s, i) + a;
}

void removeConsecutiveDuplicates(char *input) {
    string s = input;
    int i = 0, j = 0, n = sizeof(input) / sizeof(char);
    cout<<n<<endl;
    s = "";
    while(i < n - 1){
        if(input[i] != input[i + 1])
            s += input[i];
        i++;
    }
    s += input[n - 1];
    cout<<s<<endl;
    for(j = 0; j < s.size(); j++)
        input[j] = s[j];
    input[j] = '\0';
}

int main()
{
    char input[] = "baabbsbbahsahbahshhbhsjjjj"; 
    removeConsecutiveDuplicates(input);
    for(int i = 0; i < sizeof(input) / sizeof(char); i++)
        cout<<input[i];
}