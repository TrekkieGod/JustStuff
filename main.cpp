#include "CSVreader.h"
#include <fstream>
#include <iomanip>

using namespace std;
using namespace Joey;

enum ErrorCodes
{
  OK,
  IncorrectUsage
};

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    cerr << "USAGE: " << argv[0] << " <filename>" << endl;
    return IncorrectUsage;
  }

  ifstream csvFile(argv[1]);
  CSVreader reader(csvFile);

  cout << left;
  for(size_t row = 0; row < reader.getRows(); ++row)
  {
    for(size_t column = 0; column < reader.getColumns(); ++column)
      cout << setw(15) << reader(row, column) << ' ';
    cout << endl;
  }
  return OK;
}
