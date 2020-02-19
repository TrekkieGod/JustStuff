#pragma once
#include <iostream>
#include <vector>

namespace Joey
{
  class CSVreader final
  {
    public:
      CSVreader(std::istream& stream);

      size_t getRows() const;
      size_t getColumns() const;

      const std::string& operator()(size_t row, size_t column) const;
    private:
      std::vector< std::vector<std::string> > _rows;
  };
}
