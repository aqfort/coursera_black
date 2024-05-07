struct Plate0
{
  int number; // 4B
  char c1;    // 1B
  char c2;    // 1B
  char c3;    // 1B
  int region; // 4B
};

// Plate0: sizeof = 12, alignof = 4

struct Plate1
{
  uint16_t number; // 2B
  char c1;         // 1B
  char c2;         // 1B
  char c3;         // 1B
  uint16_t region; // 2B
};

// Plate1: sizeof = 8, alignof = 2

#pragma pack(push, 1)
struct Plate2
{
  uint16_t number; // 2B
  char c1;         // 1B
  char c2;         // 1B
  char c3;         // 1B
  uint16_t region; // 2B
};
#pragma pack(pop)

// Plate2: sizeof = 7, alignof = 1

const static int N = 12; // Количество используемых символов в Plate
const std::array<char, N> Letters = {
    'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y'}; // Внутри структуры храним индекс на букву

struct Plate3
{ // Упакуем плотно, указывая достаточное количество бит
  uint16_t number : 10;
  uint8_t c1 : 4; // Слились в 1 uint8_t
  uint8_t c2 : 4; // Слились в 1 uint8_t
  uint8_t c3 : 4;
  uint8_t region : 10;
};

// Plate3: sizeof = 6, alignof = 2

struct Plate4
{ // Используем только нужные 32 бита (в сумме ровно 32)
  uint32_t number : 10;
  uint32_t c1 : 4;
  uint32_t c2 : 4;
  uint32_t c3 : 4;
  uint32_t region : 10;
};

// Plate4: sizeof = 4, alignof = 4

static_assert(sizeof(Plate4) == 4, "Wrong size!")
