#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    system("mode con cols=40 lines=10");
    system("color 8E");
    unsigned long long Account, Pass;
    cout << "˜ÎΩ≠∫˛ ”Œœ∑◊¢≤·\n\n«Î ‰»Î’À∫≈:";
    cin >> hex >> Account;
    cout << " ‰»Î√‹¬Î:";
    cin >> Pass;

    if ((Account > 0xfffff) && (Pass > 0xfffff))
    {
        unsigned long long Ver1, Ver2;
        cout << "µ«¬º”Œœ∑\n\n’À∫≈:";
        cin >> Ver1; // —È÷§1
        cout << "√‹¬Î:";
        cin >> Ver2; // —È÷§2
        if ((Ver1 == Account) && (Ver2 == Pass))
        {
            cout << "µ«¬º≥…π¶";
        }
        else
            cout << "’À∫≈ªÚ√‹¬Î¥ÌŒÛ";
    }
    else
        cout << "◊¢≤· ß∞‹£°’À∫≈ªÚ√‹¬Î≤ª◊„ŒÂŒª";

    return 0;
}
