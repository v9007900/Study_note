#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>



int str_len(char const *ptr, int i = 0) // 获取字符串长度
{
    for (; *ptr != '\0'; ++ptr, ++i)
        if (*ptr < 0) ++ptr;
    return i;
}


char *My_strstr(char const *src, char const *dest)
{
    for (char const *fsrc = src; *fsrc; ++fsrc) {
        char const *rsrc  = src;
        char const *tdest = dest;

        rsrc = fsrc;
        while (*fsrc == *tdest && *fsrc != '\0') ++fsrc, ++tdest;
        if (*tdest == '\0') return (char *)rsrc;
        fsrc  = rsrc;
        tdest = dest;
    }

    return nullptr;
}



int main()
{
    std::string      Sjjj = "CABACABBACABACA";
    std::vector<int> next(Sjjj.size(), -1);
    for (int i = 1; i < Sjjj.size(); i++) {
        int j = next[i - 1];
        while (j >= 0 && Sjjj[j] != Sjjj[i - 1]) j = next[j];
        next[i] = j + 1;
    }
    for (int i = 0; i < next.size(); i++) std::cout << next[i] << " ";
    std::cout << std::endl;
    return 0;
}