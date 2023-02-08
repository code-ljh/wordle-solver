#include "wordle.h"
int main() {
    std::cout << "Let's play wordle!\n";
    std::cout << "Pleaze input the length!\n";
    int lth;
    std::cin >> lth;
    wordle::WordleList wl("dict.txt", lth);
    for (; ;) {
        std::string s;
        std::cin >> s;
        if (s == "/addres") {
            wordle::Wordle wor;
            std::cin >> wor.gue >> wor.nty;
            wl.Fresh(wor);
        } else if (s == "/list") {
            if (wl.l.size() > 32)
                std::cout << "To many! :(\n";
            else {
                for (auto i : wl.l)
                    std::cout << i << " ";
                std::cout << "\n";
            }
        } else if (s == "/guess") {
            wl.Shuffle();
            std::cout << wl.l.front() << "\n";
            wordle::Wordle wor;
            std::cin >> wor.nty;
            if (wor.nty == "notfound") {
                std::cout << "okay.\n";
                wl.l.pop_front();
                continue;
            } else if (wor.nty == "skip") {
                std::cout << "okay.\n";
                continue;
            }
            wor.gue = wl.l.front();
            wl.Fresh(wor);
            std::cout << "Done, There are " << wl.l.size() << " words maybe.\n";
        } else if (s == "/basic") {
            std::cout << "There are " << wl.l.size() << " words maybe.\n";
        } else if (s == "/help") {
            std::cout << "There are 5 commands:\n";
            std::cout << "    1. /guess -- use to let me guess a word.\n";
            std::cout << "    2. /addres <str: gue> <str: nty> -- use to add infomation.\n";
            std::cout << "    3. /list -- use to print the list.\n";
            std::cout << "    4. /help -- this one :).\n";
            std::cout << "    5. /basic -- print the basic info.\n";
        } else 
            std::cout << "uhhh, wrong command:(, use '/help' to see the all commands.\n";
    }
    return 0;
}
