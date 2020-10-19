#include <string>
#include <vector>

#include "DeSerializable.h"

namespace Kiwi {
  namespace ObjectSerializer {
    std::vector<DeSerializable*>* DeSerialize(const std::string& filepath);
  }
}
