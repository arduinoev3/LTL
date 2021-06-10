#pragma once

#ifndef STRING_LTD
#define STRING_LTD

#include <string>

namespace ltd {
	typedef std::string string;

    string to_string(const char* conv) {
        return string(conv);
    }
    string to_string(char* conv) {
        return string(conv);
    }
    string to_string(string conv) {
        return conv;
    }
    string to_string(char conv) {
        string ans = "";
        ans += conv;
        return ans;
    }
    string to_string(int conv) {
        string ans = "";
        if (conv == 0)
            ans = "0";
        else {
            if (conv < 0) {
                ans += '-';
                conv = -conv;
            }
            while (conv) {
                char toInsert = (conv % 10) + '0';
                ans.insert(0, 1, toInsert);
                conv /= 10;
            }
        }
        return ans;
    }
}

#endif