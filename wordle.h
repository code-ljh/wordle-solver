#include <bits/stdc++.h>
bool truly(std::string s) {
    for (auto i : s)
        if (not ('a' <= i and i <= 'z'))
            return false;
    return true;
}
std::map<char, double> mp({{'a', 8.31958}, {'b', 1.82507}, {'c', 4.65825}, {'d', 3.03649}, {'e', 11.7673}, {'f', 1.51825}, {'g', 2.09552}, {'h', 2.11044}, {'i', 8.6637}, {'j', 0.145483}, {'k', 0.641617}, {'l', 5.68969}, {'m', 2.91432}, {'n', 6.98598}, {'o', 6.77056}, {'p', 3.09431}, {'q', 0.206101}, {'r', 7.65371}, {'s', 5.71394}, {'t', 7.69941}, {'u', 3.74899}, {'v', 1.30468}, {'w', 0.776842}, {'x', 0.319876}, {'y', 2.05448}, {'z', 0.285371}});
double score(std::string s) {
    double res = 0;
    bool vis[256];
    std::fill(vis + 'a', vis + 'z' + 10, false);
    for (auto i : s)
        res += mp[i];
    for (auto i : s) {
        if (vis[i])
            res -= 4;
        vis[i] = true;
    }
    return res;
}
namespace wordle {
    struct Wordle {
        std::string nty, gue;
    };
    struct WordleList {
        std::list<std::string> l;
        WordleList(std::string filename) {
            std::ifstream inf(filename);
            std::string lister;
            while (inf >> lister)
                if (truly(lister))
                    l.emplace_back(lister);
        }
        WordleList(std::string filename, int lx) {
            std::ifstream inf(filename);
            std::string lister;
            while (inf >> lister)
                if (lister.size() == lx and truly(lister))
                    l.emplace_back(lister);
        }
        void Fresh(Wordle x) {
            std::vector<char> vc;
            for (int i = 0; i < x.nty.size(); i++)
                if (x.nty[i] == 'y' or x.nty[i] == 't')
                    vc.emplace_back(x.gue[i]);
            for (int i = 0; i < vc.size(); i++)
                for (int j = 0; j < x.nty.size(); j++)
                    if (vc[i] == x.gue[j] and x.nty[j] == 'n')
                        x.nty[j] = 't';
            for (int i = 0; i < x.nty.size(); i++) {
                if (x.nty[i] == 'y') {
                    for (auto it = l.begin(); it != l.end(); )
                        if ((*it)[i] != x.gue[i])
                            it = l.erase(it);
                        else
                            it++;
                } else if (x.nty[i] == 'n') {
                    for (auto it = l.begin(); it != l.end(); )
                        if ((*it).find(x.gue[i]) != -1)
                            it = l.erase(it);
                        else
                            it++;
                } else if (x.nty[i] == 't') {
                    for (auto it = l.begin(); it != l.end(); )
                        if ((*it).find(x.gue[i]) == -1 or (*it)[i] == x.gue[i])
                            it = l.erase(it);
                        else
                            it++;
                }
            }
        }
        void Shuffle() {
            l.sort([] (std::string a, std::string b) {return score(a) > score(b); });
        }
    };
}
