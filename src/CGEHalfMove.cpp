#include "CGEHalfMove.hpp"

namespace cgeditor {

CGEHalfMove::CGEHalfMove()
    : MainLine(NULL), IsBlack(false), Number(1), Parent(NULL) {}

CGEHalfMove::CGEHalfMove(CGEHalfMove *parent) {
  CGEHalfMove();
  Parent = parent;
  Parent->MainLine = this;
  if (parent->IsBlack) {
    Number = parent->Number + 1;
    IsBlack = false;
  } else {
    Number = parent->Number;
    IsBlack = true;
  }
}

CGEHalfMove::CGEHalfMove(std::string move)
    : MainLine(NULL), IsBlack(false), Number(0), Parent(NULL) {
  this->move = move;
}

void CGEHalfMove::SetComment(const std::string &c) {
  if (c.size() > 0) {
    NbLineComment = 1;
    for (const char &c : c) {
      if (c == '\n') {
        NbLineComment++;
      }
    }
    this->comment = c;
  }
  else {
    this->comment="";
    NbLineComment=0;
  }
}

std::string CGEHalfMove::GetComment() { return (comment); }

std::uint16_t CGEHalfMove::GetNbLineComment() { return (this->NbLineComment); }

void CGEHalfMove::RemoveChild(CGEHalfMove *m) {
  std::uint32_t i = 0;
  bool found = false;
  for (i; i < variations.size(); i++) {
    if (variations[i] == m) {
      found = true;
      break;
    }
  }
  if (found) {
    variations.erase(variations.begin() + i);
  }
  if (MainLine == m) {
    MainLine = NULL;
  }
}

} // namespace cgeditor