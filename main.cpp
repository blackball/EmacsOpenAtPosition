#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum SplitType
{
    SplitType_File = 0,
    SplitType_Line = 1,
    SplitType_Column = 2,
};

static bool
IsNumber(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::vector<std::string>
SplitString(const std::string &s, const char delimiter = ':')
{
    std::vector<std::string> subs;
    const int ssize = s.size();
    int next_pos = 0;

    while (true) {
        int sub_start = 0, sub_end = 0;
        // find next sub
        while (next_pos < ssize && s[next_pos] == delimiter) ++next_pos;
        sub_start = next_pos;
        while (next_pos < ssize && s[next_pos] != delimiter) ++next_pos;
        sub_end = next_pos;

        if (sub_start >= sub_end)
            break;

        subs.push_back(s.substr(sub_start, sub_end - sub_start));

        ++next_pos;
        if (next_pos >= ssize)
            break;
    }
    return subs;
}

static std::string
SplitFile(const std::string &name)
{
    auto ss = SplitString(name);
    if (ss.size() == 0) {
        return {};
    }
    return ss[0];
}

static std::string
SplitLine(const std::string &name)
{
    auto ss = SplitString(name);
    if (ss.size() <= 1 || !IsNumber(ss[1])) {
        return "0";
    }
    return ss[1];
}

static std::string
SplitCloumn(const std::string &name)
{
    auto ss = SplitString(name);
    if (ss.size() <= 2 || !IsNumber(ss[2])) {
        return "0";
    }
    return ss[2];
}

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        return -1;
    }
    const std::string name(argv[2]);

    const int option = atoi(argv[1]);

    if (option == SplitType_File) {
        auto f = SplitFile(name);
        std::cout << f << "\n";
    } else if (option == SplitType_Line) {
        auto l = SplitLine(name);
        std::cout << l << "\n";
    } else if (option == SplitType_Column) {
        auto c = SplitCloumn(name);
        std::cout << c << "\n";
    } else {
        std::cout << ""
                  << "\n";
    }
    return 0;
}
