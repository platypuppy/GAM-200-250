#include <string>
#include <vector>

#include "DeSerializable.h"

namespace ObjectSerializer {
  std::vector<DeSerializable*>* DeSerialize(const char* filepath);
}
