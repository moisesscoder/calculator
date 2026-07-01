template <typename T>
class Calculator {
 private:
  T number1;
  T number2;

 public:
  Calculator(T n1, T n2) : number1(n1), number2(n2) {}

  inline T add() { return number1 + number2; }

  inline T subtract() { return number1 - number2; }

  inline T multiply() { return number1 * number2; }

  inline T divide() { 
    if (number2 == 0) {
      return 0;
    }
    return number1 / number2; 
  }
};