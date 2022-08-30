#include <iostream>
#include <string>
#include <memory>

#include <cpu6502.hpp>
#include <memMap.hpp>
#include <mem.hpp>

using namespace mulator;

#define MAX_MEM 1024 * 64

class MyMem : public mem::MemMapEntry
{
private:
  uint8_t mem[MAX_MEM];

public:
  MyMem(size_t start = 0)
  {
    this->start = start;
    end = MAX_MEM;
  }

  uint8_t get(size_t relativeLoc)
  {
    return mem[relativeLoc];
  }

  void set(size_t relativeLoc, uint8_t val)
  {
    mem[relativeLoc] = val;
  }

  std::string getName()
  {
    return "RAM";
  }
};

int main()
{
  mem::MemMap memMap;
  memMap.addEntry<MyMem>();

  mem::Mem mem(memMap);

  std::cout << memMap.dumpEntries();

  cpu6502::CPU6502 cpu(memMap);
  cpu.reset();
}
