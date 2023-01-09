#include <cstdio>
#include <cstdlib>
#include <cstring>

// 计算并返回指定数据的 CRC 值
unsigned int CalculateCRC(const char *data, size_t length) {
  unsigned int crc = 0;
  for (size_t i = 0; i < length; i++) {
    crc ^= data[i];
    for (int j = 0; j < 8; j++) {
      if (crc & 1)
        crc = (crc >> 1) ^ 0xEDB88320;
      else
        crc = crc >> 1;
    }
  }
  return crc;
}

// 检查指定的数据和其 CRC 值是否有效
bool CheckCRC(const char *data, size_t length, unsigned int crc) {
  return CalculateCRC(data, length) == crc;
}

int main() {
  const char *data = "Hello, world!";
  size_t;
