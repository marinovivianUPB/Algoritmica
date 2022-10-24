#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

string number;
//MODIFICAR DE ACUERDO A EJERCICIO
int dp[20][2][200];

int solve_dp(int pos, int mayor, int sumaDigitos)
{
    if (pos > number.size())
    { 
        return 0;
    }
    //MODIFICAR DE ACUERDO A EJERCICIO
    if (pos == number.size())
    {
        if (sumaDigitos % 5 == 0)
        { 
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[pos][mayor][sumaDigitos] == -1)
    { 
        int tope = number[pos] - '0';
        if (!mayor)
        {                             
            tope = 9; 
        }
        dp[pos][mayor][sumaDigitos] = 0;
        for (int digito = 0; digito <= tope; digito++)
        {
            if (digito == tope)
            {
                dp[pos][mayor][sumaDigitos] += solve_dp(pos + 1, true && mayor, digito + sumaDigitos);
            }
            else
            {
                dp[pos][mayor][sumaDigitos] += solve_dp(pos + 1, false, digito + sumaDigitos);
            }
        }
    }
    return dp[pos][mayor][sumaDigitos];
}

int main()
{
    string a = "0";
    string b = "100";
    number = a;
    memset(dp, -1, sizeof(dp));
    int multiplos_5_hasta_a = solve_dp(0, true, 0);
    memset(dp, -1, sizeof(dp));
    number = b;
    int multiplos_5_hasta_b = solve_dp(0, true, 0);
    cout << multiplos_5_hasta_b - multiplos_5_hasta_a;
    return 0;
}
