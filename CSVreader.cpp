#include "CSVreader.h"
#include <sstream>

using namespace std;
using namespace Joey;

CSVreader::CSVreader(istream& stream)
{
  string line;
  while(getline(stream, line))
  {
    stringstream tokenizer(line);
    vector<string> rowTokens;
    string cell;
    while(getline(tokenizer, cell, ','))
      rowTokens.push_back(cell);
    _rows.push_back(move(rowTokens));
  }
}

size_t CSVreader::getRows() const
{
  return _rows.size();
}

size_t CSVreader::getColumns() const
{
  if(_rows.empty())
    return 0;
  return _rows.front().size();
}

const string& CSVreader::operator()(size_t row, size_t column) const
{
  static const string empty;
  if(row >= _rows.size())
    return empty;
  const auto& current = _rows.at(row);
  if(column >= current.size())
    return empty;
  return current.at(column);
}
