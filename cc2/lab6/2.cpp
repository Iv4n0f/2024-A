#include <iostream>
#include <string>
#include <vector>
using namespace std;

double stringToDouble(const string &str) {
  double result = 0.0;
  int decimalPosition = -1;
  bool isDecimal = false;
  int digitsAfterDecimal = 0;
  bool isNegative = false;
  int start = 0;

  if (str[0] == '-') {
    isNegative = true;
    start = 1;
  }

  for (int i = start; i < str.length(); i++) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      if (isDecimal) {
        digitsAfterDecimal++;
        result = result * 10 + (c - '0');
      } else {
        result = result * 10 + (c - '0');
      }
    } else if (c == '.' && !isDecimal) {
      isDecimal = true;
      decimalPosition = digitsAfterDecimal;
    } else {
      cout << "No valid conversion to double";
      return -1;
    }
  }

  if (isDecimal) {
    double divisor = 1;
    for (int i = 0; i < digitsAfterDecimal; i++) {
      divisor *= 10;
    }
    result /= divisor;
  }

  if (isNegative) {
    result = -result;
  }

  return result;
}

string removeSpaces(const string &input) {
  string output;
  for (char c : input) {
    if (c != ' ') {
      output += c;
    }
  }
  return output;
}

// Clase generica contenedora
class Element {
public:
  virtual ~Element() {};
};

// Clase para numeros
class Number : public Element {
private:
  double val;

public:
  Number(double _val) : val(_val) {};
  void setVal(double _val) { val = _val; }
  double getVal() const { return val; }
};

// Clase para operaciones
class Operator : public Element {
public:
  virtual ~Operator() {};
  virtual void operate(vector<Element *> &elements, int pos) const = 0;
};

class Exponentiation : public Operator {
public:
  void operate(vector<Element *> &elements, int pos) const override {
    if (pos == 0 || pos >= elements.size() - 1) {
      cout << "Operator in invalid position";
      return;
    }

    Number *l = dynamic_cast<Number *>(elements[pos - 1]);
    Number *r = dynamic_cast<Number *>(elements[pos + 1]);

    if (!l || !r) {
      cout << "No sorrounded by numbers";
      return;
    }

    double base = l->getVal();
    double exponent = r->getVal();
    double result = 1.0;

    if (exponent > 0) {
      for (int i = 0; i < exponent; i++) {
        result *= base;
      }
      l->setVal(result);
    }
    if (exponent < 0) {
      for (int i = 0; i < -exponent; i++) {
        result *= base;
      }
      l->setVal(1.0 / result);
    }
    delete elements[pos];
    delete elements[pos + 1];
    elements.erase(elements.begin() + pos);
    elements.erase(elements.begin() + pos);
  }
};

class Multiplication : public Operator {
public:
  void operate(vector<Element *> &elements, int pos) const override {
    if (pos == 0 || pos >= elements.size() - 1) {
      cout << "Operator in invalid position";
      return;
    }

    Number *l = dynamic_cast<Number *>(elements[pos - 1]);
    Number *r = dynamic_cast<Number *>(elements[pos + 1]);

    if (!l || !r) {
      cout << "No sorrounded by numbers";
      return;
    }

    double result = l->getVal() * r->getVal();
    l->setVal(result);
    delete elements[pos];
    delete elements[pos + 1];
    elements.erase(elements.begin() + pos);
    elements.erase(elements.begin() + pos);
  }
};

class Division : public Operator {
public:
  void operate(vector<Element *> &elements, int pos) const override {
    if (pos == 0 || pos >= elements.size() - 1) {
      cout << "Operator in invalid position";
      return;
    }

    Number *l = dynamic_cast<Number *>(elements[pos - 1]);
    Number *r = dynamic_cast<Number *>(elements[pos + 1]);

    if (!l || !r) {
      cout << "No sorrounded by numbers";
      return;
    }

    if (r->getVal() == 0) {
      cout << "Division by zero";
    }

    double result = l->getVal() / r->getVal();
    delete elements[pos];
    delete elements[pos + 1];
    l->setVal(result);
    elements.erase(elements.begin() + pos);
    elements.erase(elements.begin() + pos);
  }
};

class Addition : public Operator {
public:
  void operate(vector<Element *> &elements, int pos) const override {
    if (pos == 0 || pos >= elements.size() - 1) {
      cout << "Operator in invalid position";
      return;
    }

    Number *l = dynamic_cast<Number *>(elements[pos - 1]);
    Number *r = dynamic_cast<Number *>(elements[pos + 1]);

    if (!l || !r) {
      cout << "No sorrounded by numbers";
      return;
    }

    double result = l->getVal() + r->getVal();
    delete elements[pos];
    delete elements[pos + 1];
    l->setVal(result);
    elements.erase(elements.begin() + pos);
    elements.erase(elements.begin() + pos);
  }
};

class Subtraction : public Operator {
public:
  void operate(vector<Element *> &elements, int pos) const override {
    if (pos == 0 || pos >= elements.size() - 1) {
      cout << "Operator in invalid position";
      return;
    }

    Number *l = dynamic_cast<Number *>(elements[pos - 1]);
    Number *r = dynamic_cast<Number *>(elements[pos + 1]);

    if (!l || !r) {
      cout << "No sorrounded by numbers";
      return;
    }

    double result = l->getVal() - r->getVal();
    delete elements[pos];
    delete elements[pos + 1];
    l->setVal(result);
    elements.erase(elements.begin() + pos);
    elements.erase(elements.begin() + pos);
  }
};

void showElements(const vector<Element *> &elements) {
  cout << "elements:" << endl;
  for (const Element *el : elements) {
    if (const Number *num = dynamic_cast<const Number *>(el)) {
      cout << num->getVal() << ", ";
    } else if (const Addition *add = dynamic_cast<const Addition *>(el)) {
      cout << "+"
           << ", ";
    } else if (const Subtraction *sub = dynamic_cast<const Subtraction *>(el)) {
      cout << "-"
           << ", ";
    } else if (const Multiplication *mult =
                   dynamic_cast<const Multiplication *>(el)) {
      cout << "*"
           << ", ";
    } else if (const Division *div = dynamic_cast<const Division *>(el)) {
      cout << "/"
           << ", ";
    } else if (const Exponentiation *exp =
                   dynamic_cast<const Exponentiation *>(el)) {
      cout << "^"
           << ", ";
    } else {
      cout << "Elemento desconocido"
           << ", ";
    }
  }
  cout << endl;
}

bool isDigit(const char &ch) { return ch >= '0' && ch <= '9'; }

string subStr(const string &str, int start, int length) {
  string result;
  for (int i = start; i < start + length && i < str.length(); ++i) {
    result += str[i];
  }
  return result;
}

void stringToVector(vector<Element *> &elements, string line) {
  int i = 0;
  bool lf_number = true;
  while (i < line.length()) {
    if ((isDigit(line[i]) || (line[i] == '-' && isDigit(line[i + 1]))) &&
        lf_number) {
      int start = i;
      bool hasDot = false;
      if (line[i] == '-')
        i++;
      while (i < line.length() &&
             (isDigit(line[i]) || (line[i] == '.' && !hasDot))) {
        if (line[i] == '.')
          hasDot = true;
        i++;
      }
      string numStr = subStr(line, start, i - start);
      double num = stringToDouble(numStr);
      elements.push_back(new Number(num));
      lf_number = false;
    } else {
      char op = line[i];
      switch (op) {
      case '+':
        elements.push_back(new Addition());
        lf_number = true;
        break;
      case '-':
        elements.push_back(new Subtraction());
        lf_number = true;
        break;
      case '*':
        elements.push_back(new Multiplication());
        lf_number = true;
        break;
      case '/':
        elements.push_back(new Division());
        lf_number = true;
        break;
      case '^':
        elements.push_back(new Exponentiation());
        lf_number = true;
        break;
      default:
        cout << "Carácter no válido encontrado: " << op;
        return;
      }
      i++;
    }
  }
}

int main() {
  string line;
  getline(cin, line);

  line = removeSpaces(line);

  vector<Element *> elements;
  stringToVector(elements, line);
  showElements(elements);

  // Potencia
  for (int i = 0; i < elements.size(); ++i) {
    Operator *op = dynamic_cast<Operator *>(elements[i]);
    if (op) {
      Exponentiation *exp = dynamic_cast<Exponentiation *>(op);
      if (exp) {
        op->operate(elements, i);
        --i;
        showElements(elements);
      }
    }
  }

  // Multiplicacion y Division
  for (int i = 0; i < elements.size(); ++i) {
    Operator *op = dynamic_cast<Operator *>(elements[i]);
    if (op) {
      Multiplication *mult = dynamic_cast<Multiplication *>(op);
      Division *div = dynamic_cast<Division *>(op);
      if (mult || div) {
        op->operate(elements, i);
        --i;
        showElements(elements);
      }
    }
  }

  // Sumas y restas
  for (int i = 0; i < elements.size(); ++i) {
    Operator *op = dynamic_cast<Operator *>(elements[i]);
    if (op) {
      Addition *add = dynamic_cast<Addition *>(op);
      Subtraction *sub = dynamic_cast<Subtraction *>(op);
      if (add || sub) {
        op->operate(elements, i);
        --i;
        showElements(elements);
      }
    }
  }

  if (!elements.empty()) {
    Number *resultNum = dynamic_cast<Number *>(elements[0]);
    if (resultNum) {
      cout << "Resultado: " << resultNum->getVal() << endl;
    }
  }

  for (Element *el : elements) {
    delete el;
  }
}
