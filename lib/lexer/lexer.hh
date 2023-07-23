#pragma once

#include <string_view>

/*
 * long flags (--copyfile)
 * short flags (-c)
 * flags with values (both --flag=value --flag value)
 * subcommands (multiple) (ex: dnf install exec )
 * help messages (same as long flags? basically boilerplate)
 * positionals (cp ../f1 ./f2)
 * compound flags (idk wtf this is lol)
 */

enum class TokenKind {
        LONG_FLAG,  // "--"
        SHORT_FLAG, // "-"
        EQUALS,     // "="
        SYMBOL,
        POSITIONAL,
        USELESS,
};

class Token {
public:
        Token(int location);

        Token() = default;
        ~Token() = default;

        // Token kind
        TokenKind kind;
        // argv index
        int location;
        // Token value
        std::string_view content;
};

class Lexer {
public:
        Lexer();
        ~Lexer() = default;

        /**
         * @brief Returns the next token
         */
        Token next(std::string_view content, int location);

private:
        // Index in argv
        size_t current_index;
        // Previous TokenKind
        TokenKind prev;
};