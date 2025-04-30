#include <vector> 
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <optional>
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

// Lexing stage

typedef enum
{
  OPEN_PAREN = 1,
  CLOSE_PAREN,
  OPEN_BRACK,
  CLOSE_BRACK,
  OPEN_CURLY,
  CLOSE_CURLY,
  COMMA,
  PLUS,
  MINUS,
  SLASH,
  STAR,
  AT,
  DOT,
  SPACE,
  END_OF_LINE,
  KEYWORD,
  IDENTIFIER,
  DWORD,
  QWORD,
  STRING_LITERAL,
  INTEGER_LITERAL,
  NUL,
} Token_Type;

typedef struct
{
  Token_Type Type;
  string Value;
} Token;

char* Specials = (char*)"%$@= +-*/.\"\n\t,(){}[]";

bool In_Character_Array(char C, char* Characters)
{
  for(int i = 0; i < strlen(Characters); i++)
  {
    if (Characters[i] == C)
    {
      return true;
    }
  }
  return false;
}

typedef vector<Token> Tokens;
typedef Token_Type    Type;
#define r return

string Type_To_String(Type type)
{
  switch(type)
  {
    case Type::OPEN_PAREN: r "OPEN_PAREN";
    case Type::CLOSE_PAREN: r "CLOSE_PAREN";
    case Type::OPEN_BRACK: r "OPEN_BRACK";
    case Type::CLOSE_BRACK: r "CLOSE_BRACK";
    case Type::OPEN_CURLY: r "OPEN_CURLY";
    case Type::CLOSE_CURLY: r "CLOSE_CURLY";
    case Type::COMMA: r "COMMA";
    case Type::PLUS: r "PLUS";
    case Type::MINUS: r "MINUS";
    case Type::SLASH: r "SLASH";
    case Type::STAR: r "STAR";
    case Type::AT: r "AT";
    case Type::DOT: r "DOT";
    case Type::SPACE: r "SPACE";
    case Type::END_OF_LINE: r "END_OF_LINE";
    case Type::KEYWORD: r "KEYWORD";
    case Type::IDENTIFIER: r "IDENTIFIER";
    case Type::DWORD: r "DWORD";
    case Type::QWORD: r "QWORD";
    case Type::STRING_LITERAL: r "STRING_LITERAL";
    case Type::INTEGER_LITERAL: r "INTEGER_LITERAL";
    default: r "NONE";
  }
}

bool Is_Special(char C)
{
  if(In_Character_Array(C, Specials))
  {
    return true;
  }
  return false;
}

Tokens QIL_Lexer(string Input)
{
  Tokens Output;

  bool In_String = false;

  string String;
  string Buffer;

  for(char C : Input)
  {
    if(Is_Special(C))
    {
      // String Literal Parsing (Lexing):
      if(C == '"')
      {
        if(!In_String)
        {
          In_String = true;
        } else
        {
          In_String = false;
          Output.push_back({Type::STRING_LITERAL, String + C});
          String.clear();
          Buffer.clear();
        }
      }
      if(!In_String)
      {
        try
        {
          std::stoi(Buffer);
          Output.push_back({Type::INTEGER_LITERAL, Buffer});
        } catch (const std::exception& e) {
          // Keyword Parsing (Lexing)
          if(Buffer == "func")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "ret")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "call")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "data")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "loadd")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "loadq")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "push")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "pop")
          {
            Output.push_back({Type::KEYWORD, Buffer});
          } else if(Buffer == "d")
          {
            Output.push_back({Type::DWORD, Buffer});
          } else if(Buffer == "q")
          {
            Output.push_back({Type::QWORD, Buffer});
          } else if(Buffer != "" && Buffer != "\t")
          {
            Output.push_back({Type::IDENTIFIER, Buffer});
          }
        }

        // Parsing Other Special Characters (Lexing):

        if(C == '@')
        {
          Output.push_back({Type::AT, ""});
        }

        if(C == '(')
        {
          Output.push_back({Type::OPEN_PAREN, ""});
        }
        if(C == ')')
        {
          Output.push_back({Type::CLOSE_PAREN, ""});
        }

        if(C == '[')
        {
          Output.push_back({Type::OPEN_BRACK, ""});
        }
        if(C == ']')
        {
          Output.push_back({Type::CLOSE_BRACK, ""});
        }

        if(C == '{')
        {
          Output.push_back({Type::OPEN_CURLY, ""});
        }
        if(C == '}')
        {
          Output.push_back({Type::CLOSE_CURLY, ""});
        }

        if(C == '\n')
        {
          Output.push_back({Type::END_OF_LINE, ""});
        }
        if(C == '\t')
        {
          Output.push_back({Type::SPACE, ""});
        }

        if(C == ' ')
        {
          Output.push_back({Type::SPACE, ""});
        }

        Buffer.clear();
      }
    }

    if(In_String)
    {
      String.push_back(C);
    } else if(!In_Character_Array(C, Specials))
    {
      Buffer.push_back(C);
    }
  }

  return Output;
}

int main()
{
  string program = "func d main()\n\t@begin\n\t\tret 0\n\t@end\n";
  Tokens tokens = QIL_Lexer(program);
  for(Token token : tokens)
  {
    cout << Type_To_String(token.Type) << ": " << token.Value << endl;
  }
}
