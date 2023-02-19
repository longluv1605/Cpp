#include <iostream>
#include <string>
#include <stack>
#include <queue>

class ChuyenDoiBieuThuc
{
private:
    std::string input;
    std::stack<std::string> key;
    std::queue<std::string> output;

    bool checkUuTien(std::string t, std::string s)
    {
        if (t == "+")
        {
            if (s == "*" || s == "/" || s == "-" || s == "+")
                return true;
        }
        if (t == "-")
        {
            if (s == "*" || s == "/" || s == "+" || s == "-")
                return true;
        }
        if (t == "*")
        {
            if (s == "*" || s == "/")
                return true;
        }
        if (t == "/")
        {
            if (s == "*" || s == "/")
                return true;
        }

        return false;
    }

    void changeTTtoHT()
    {
        // Rà soát input.
        for (int i = 0; i < (int)input.size(); i++)
        {
            std::string strChar, strNum;

            // Nếu là lấy ra toán hạng thì push vào output.
            if ((input[i] >= '0' && input[i] <= '9'))
            {
                strNum = "";
                if (i == 1 && input[i - 1] == '-') {
                    strNum += input[i - 1];
                }
                else if (i > 1 && input[i - 1] == '-' &&  input[i - 2] == '(') {
                    strNum += input[i - 1];
                }
                
                while (input[i] >= '0' && input[i] <= '9')
                {
                    strNum += input[i];
                    i++;
                }
                output.push(strNum);
                
                if (!(input[i] >= '0' && input[i] <= '9') && input[i] != ' ')
                    i--;
            }

            // Nếu lấy ra "(" thì push nó vào key.
            else if (input[i] == '(')
            {
                key.push("(");
            }

            // Nếu lấy ra ")" thì pop dần các phần tử ở đỉnh của key ra
            // và push vào output (trừ "(") tới khi gặp "(".
            else if (input[i] == ')')
            {
                while (key.top() != "(")
                {
                    output.push(key.top());
                    key.pop();
                }
                key.pop();
            }

            // Nếu lấy ra toán tử t thì push dần các toán tử có độ ưu tiên >= t
            // ở đỉnh key vào output và sau đó push t vào key.
            else
            {
                if(input[i] == '-' && (i == 0 || input[i - 1] == '(')) continue;
                
                strChar = "";
                strChar += input[i];

                while (!key.empty() && checkUuTien(strChar, key.top()))
                {
                    output.push(key.top());
                    key.pop();
                }
                key.push(strChar);
            }
        }

        // Push các phần tử còn lại của key vào output.
        while (!(key.empty()))
        {
            output.push(key.top());
            key.pop();
        }
    }

public:
    void setInput(std::string input)
    {
        this->input = input;
    }
    
    void printTT()
    {
        std::cout << input << std::endl;
    }
    
    void printHT()
    {
        changeTTtoHT();
        while (!(output.empty()))
        {
            if((output.front()).size() > 1 && (output.front())[0] == '-') {
                std::cout << "(" << output.front() << ") ";
            }
            else std::cout << output.front() << " ";
            output.pop();
        }
    }
};

int main()
{
    ChuyenDoiBieuThuc *res = new ChuyenDoiBieuThuc();
    res->setInput("-9*3+4*((7-5)+1)/2");
    res->printHT();

    return 0;
}