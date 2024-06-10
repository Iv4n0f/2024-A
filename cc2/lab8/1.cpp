#include <iostream>

class Date {
private:
  int day;
  int month;
  int year;
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
  Date(int d = 1, int m = 1, int y = 1900) {
    if (m >= 1 && m <= 12) {
      month = m;
    } else {
      std::cout << "Month must be between 1-12" << std::endl;
    }

    if (y >= 0 && y <= 2100) {
      year = y;
    } else {
      std::cout << "Year must be between 1-2100" << std::endl;
    }

    // test for a leap year
    if ((m == 2 && biciesto(year) && d >= 1 && d <= 29) ||
        (d >= 1 && d <= days[m])) {
      day = d;
    } else {
      std::cout << "Day out of month" << std::endl;
    }
  };

  void setDate(int d, int m, int y) {
    if (m >= 1 && m <= 12) {
      month = m;
    } else {
      std::cout << "Month must be between 1-12" << std::endl;
    }

    if (y >= 0 && y <= 2100) {
      year = y;
    } else {
      std::cout << "Year must be between 1-2100" << std::endl;
    }

    // test for a leap year
    if ((m == 2 && biciesto(year) && d >= 1 && d <= 29) ||
        (d >= 1 && d <= days[m])) {
      day = d;
    } else {
      std::cout << "Day out of month" << std::endl;
    }
  };

  int getDay() const { return day; }

  int getMonth() const { return month; }

  int getYear() const { return year; }

  void print() const {
    std::cout << day << '/' << month << '/' << year << std::endl;
  }

  static bool biciesto(int ty) {
    return (ty % 400 == 0 || (ty % 100 != 0 && ty % 4 == 0));
  };

  bool fin_de_mes(int td) const {
    if (month == 2 && biciesto(year)) {
      return td == 29;
    } else {
      return td == days[month];
    }
  };

  void increment() {
    if (!fin_de_mes(day)) {
      day++;
    } else {
      if (month < 12) {
        month++;
        day = 1;
      } else {
        year++;
        month = 1;
        day = 1;
      }
    }
  }

  Date &operator++() {
    increment();
    return *this;
  }

  void decrement() {
    if (!(day == 1)) {
      day--;
    } else {
      if (month > 1) {
        month--;
        if (month == 2 && biciesto(year)) {
          day = 29;
        } else {
          day = days[month];
        }
      } else {
        year--;
        month = 12;
        day = 31;
      }
    }
  }

  Date &operator--() {
    decrement();
    return *this;
  }

  Date &operator+=(Date &other_date) {
    int increment_days = 0;
    Date aux = other_date;
    Date primer(1, 1, 0);
    while (aux.getDay() != primer.getDay() ||
           aux.getMonth() != primer.getMonth() ||
           aux.getYear() != primer.getYear()) {
      increment_days++;
      aux.decrement();
    }
    for (int i = 0; i <= increment_days; i++) {
      increment();
    }
    return *this;
  }

  Date &operator-=(Date &other_date) {
    int increment_days = 0;
    Date aux = other_date;
    Date primer(1, 1, 0);
    while (aux.getDay() != primer.getDay() ||
           aux.getMonth() != primer.getMonth() ||
           aux.getYear() != primer.getYear()) {
      increment_days++;
      aux.decrement();
    }
    for (int i = 0; i <= increment_days; i++) {
      decrement();
    }
    return *this;
  }
};

int main() {
  Date date(4, 10, 2024);
  --date;
  date.print();
  ++date;
  date.print();
  Date date2(3, 10, 2024);
  date -= date2;
  date.print();
  Date date3(2, 4, 1998);
  date += date3;
  date.print();
}
