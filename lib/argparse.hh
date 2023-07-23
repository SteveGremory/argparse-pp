#pragma once

/*
 * help messages (same as long flags? basically boilerplate)
 * long flags (--copyfile)
 * short flags (-c)
 * flags with values (both --flag=value --flag value)
 TODO: subcommands (multiple) (ex: dnf install exec)
 TODO: positionals (cp ../f1 ./f2)
 TODO: compound flags (idk wtf this is lol)
 */

class ArgParser {
public:
        ArgParser(int argc, char** argv);
        ~ArgParser() = default;

        void set_long_flag();
        void set_short_flag();
        void set_value_flag();

private:
};