#include "lexer.hh"

Token::Token(int location) : location(location) {
        // All tokens are useless by default
        this->kind = TokenKind::USELESS;
}

Token Lexer::next(std::string_view content, int location) {
        Token tok(location);

        // If there's nothing, return an empty token.
        if (content.empty())
                return tok;

        // check token SHORT_FLAG
        if (content[0] == '-') {
                switch (content[1]) {
                case '-':
                        tok.kind = TokenKind::LONG_FLAG;
                default:
                        tok.kind = TokenKind::SHORT_FLAG;
                }
        } else {
                tok.kind = TokenKind::POSITIONAL;
        }

        tok.content = content;
        return tok;
}

Lexer::Lexer() {
        this->prev = TokenKind::USELESS;
        // Index in argv
        size_t current_index = 1;
}