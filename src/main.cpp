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

    mem[0xFFFC] = 0;
    mem[0xFFFD] = 0;

    mem[0x0000] = cpu6502::LDA_IMM;
    mem[0x0001] = 123;
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
  std::cout << memMap.dumpEntries();

  mem::Mem mem(memMap);

  cpu6502::CPU6502 cpu;

  std::cout << cpu.dumpRegs();
  cpu.execute(mem);
  std::cout << cpu.dumpRegs();
  cpu.execute(mem);
  std::cout << cpu.dumpRegs();
}
