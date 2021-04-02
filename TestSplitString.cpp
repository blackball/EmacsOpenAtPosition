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

// static std::string

std::vector<std::string>
SplitString(const std::string &s, const char delimiter = ' ')
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

static bool
Same(const std::vector<std::string> &a, const std::vector<std::string> &b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

static void
Print(const std::string &s, const std::string &tail)
{
    std::cout << s << tail;
}

static void
Print(const std::vector<std::string> &s, const std::string &tail)
{
    std::cout << "{";
    for (const auto i : s) {
        std::cout << i << ",";
    }
    std::cout << "}" << tail;
}

static void
TestCase(const std::string &s, const std::vector<std::string> &expected)
{
    const std::vector<std::string> str_vec = SplitString(s, ':');

    if (!Same(str_vec, expected)) {
        Print(s, "=>");
        Print(str_vec, "=>");
        Print(expected, "\n");
    } else {
        std::cout << "Pass\n";
    }
}

int
main(int argc, char *argv[])
{
    TestCase("a", {"a"});
    TestCase("", {});
    TestCase("1:", {"1"});
    TestCase("1:2", {"1", "2"});
    TestCase("1:2:", {"1", "2"});
    return 0;
}
