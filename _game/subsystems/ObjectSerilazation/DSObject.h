#include "../DeSerializable.h"

class DSObject : public DeSerializable {
  public:
    DSObject() : DeSerializable(), number(12), flot(14.8f) {};

    ~DSObject() {};
  
  virtual bool AddComponent(const std::string& key, const std::any& anything);

  private:
    int number;
    double flot;
};
