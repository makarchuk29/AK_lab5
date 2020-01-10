#include <getopt.h>
#include <iostream>

int num = 100;
float delta = 5.34299;

void PrintHelp()
{
    std::cout <<
            "--cite  (-c):              Print cite \n"
            "--num   (-n) <n>:          Set number of program\n"
            "--delta (-d) <val>:        Set delta of program\n"
            "--help  (-h):              Show help\n";
    exit(1);
}

void ProcessArgs(int argc, char** argv)
{
    const char* const short_opts = "n:d:c:h";
    const option long_opts[] = {
            {"num", required_argument, nullptr, 'n'},
            {"delta", required_argument, nullptr, 'd'},
            {"help", no_argument, nullptr, 'h'},
            {"cite", no_argument, nullptr, 'c'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'n':
            num = std::stoi(optarg);
            std::cout << "Num set to: " << num << std::endl;
            break;

        case 'd':
            delta = std::stof(optarg);
            std::cout << "Delta set to: " << delta << std::endl;
            break;
        
        case 'c':
            std::cout << "You can't teach an old dog new tricks" << std::endl;
            break;

        case 'h':
        case '?':
        default:
            PrintHelp();
            break;
        }
    }
}

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);
    return 0;
}