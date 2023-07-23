#include "argparse.hh"
#include "lexer/lexer.hh"

#include <iostream>

int main(int argc, char** argv) {
        /*
         * long flags (--copyfile)
         * short flags (-c)
         * flags with values (both --flag=value --flag value)
         * subcommands (multiple) (ex: dnf install exec )
         * help messages (same as long flags? basically boilerplate)
         * positionals (cp ../f1 ./f2)
         * compound flags (idk wtf this is lol)
         */

        Lexer lexer;
        for (int idx = 0; idx < argc; idx++) {
                std::cout << argv[idx] << std::endl;
                Token tok = lexer.next(argv[idx], idx);
        }
}