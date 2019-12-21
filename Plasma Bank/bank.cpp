#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

struct Person
{
  string name;
  double accountA;
  double accountB;
  double accountC;
  double accountD;
  int times;
  int lastMonth;
};

struct Data
{
  Person aaron;
  Person zack;
};

void load(Data&);
void save(Data);
void balanceDebts(Data&);
int  timePrice(int);
int  getMonth();

int main()
{
  Data data;

  load(data);
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  int a, b, c;
  int total;
  double d;

  do {
    system("cls");
    cout << "PLASMA BANK:" << endl << endl
         << "  1 - Print" << endl
         << "  2 - Donated" << endl
         << "  3 - Deposit" << endl
         << "  4 - Withdraw" << endl
         << "  5 - Exit" << endl << endl
         << ": ";
    cin >> a;

    switch (a) {
      case 1:
        system("cls");
        cout << "PLASMA BANK:" << endl << endl;
        cout << data.aaron.name << endl
             << "Times: "     << data.aaron.times << endl
             << "Account A: " << data.aaron.accountA << endl
             << "Account B: " << data.aaron.accountB << endl
             << "Account C: " << data.aaron.accountC << endl
             << "Account D: " << data.aaron.accountD << endl << endl;
        cout << data.zack.name << endl
             << "Times: "     << data.zack.times << endl
             << "Account A: " << data.zack.accountA << endl
             << "Account B: " << data.zack.accountB << endl
             << "Account C: " << data.zack.accountC << endl
             << "Account D: " << data.zack.accountD << endl << endl;
        system("PAUSE");
        break;
      case 2:
        system("cls");
        cout << "Who donated: " << endl
             << "  0 - Cancel" << endl
             << "  1 - Both" << endl
             << "  2 - Aaron" << endl
             << "  3 - Zack" << endl << endl
             << ": ";
        cin >> b;

        switch (b) {
          case 1:
            if (data.aaron.lastMonth != getMonth()) {
              data.aaron.times = 1;
              data.aaron.lastMonth = getMonth();
            }
            else {
              data.aaron.times++;
            }
            total = timePrice(data.aaron.times);
            total -= 15;
            data.aaron.accountA += total;
            data.aaron.accountB += 10;
            data.aaron.accountC += 5;

            if (data.zack.lastMonth != getMonth()) {
              data.zack.times = 1;
              data.zack.lastMonth = getMonth();
            }
            else {
              data.zack.times++;
            }
            total = timePrice(data.zack.times);
            total -= 15;
            data.zack.accountA += total;
            data.zack.accountB += 10;
            data.zack.accountC += 5;
            break;
          case 2:
            if (data.aaron.lastMonth != getMonth()) {
              data.aaron.times = 1;
              data.aaron.lastMonth = getMonth();
            }
            else {
              data.aaron.times++;
            }
            total = timePrice(data.aaron.times);
            total -= 15;
            data.aaron.accountA += total;
            data.aaron.accountB += 10;
            data.aaron.accountC += 5;
            break;
          case 3:
            if (data.zack.lastMonth != getMonth()) {
              data.zack.times = 1;
              data.zack.lastMonth = getMonth();
            }
            else {
              data.zack.times++;
            }
            total = timePrice(data.zack.times);
            total -= 15;
            data.zack.accountA += total;
            data.zack.accountB += 10;
            data.zack.accountC += 5;
            break;
        }
        break;
      case 3:
        system("cls");
        cout << "Which person?" << endl
             << "  0 - Cancel" << endl
             << "  1 - Aaron" << endl
             << "  2 - Zack" << endl << endl
             << ": ";
        cin >> b;

        switch (b) {
          case 1:
            system("cls");
            cout << "Which account?" << endl
                 << "  0 - Cancel" << endl
                 << "  1 - A (" << data.aaron.accountA << ")" << endl
                 << "  2 - B (" << data.aaron.accountB << ")" << endl
                 << "  3 - C (" << data.aaron.accountC << ")" << endl
                 << "  4 - D (" << data.aaron.accountD << ")" << endl << endl
                 << ": ";
            cin >> c;
            
            if (c > 0 && c < 5) {
              system("cls");
              cout << "How much do you want to Deposit?" << endl
                   << ": ";
              cin >> d;
            }

            switch (c) {
              case 1:
                data.aaron.accountA += d;
                break;
              case 2:
                data.aaron.accountB += d;
                data.aaron.accountA -= d;
                break;
              case 3:
                data.aaron.accountC += d;
                data.aaron.accountA -= d;
                break;
              case 4:
                data.aaron.accountD += d;
                balanceDebts(data);
                break;
            }
            break;
          case 2:
            system("cls");
            cout << "Which account?" << endl
                 << "  0 - Cancel" << endl
                 << "  1 - A (" << data.zack.accountA << ")" << endl
                 << "  2 - B (" << data.zack.accountB << ")" << endl
                 << "  3 - C (" << data.zack.accountC << ")" << endl
                 << "  4 - D (" << data.zack.accountD << ")" << endl << endl
                 << ": ";
            cin >> c;
            
            if (c > 0 && c < 5) {
              system("cls");
              cout << "How much do you want to Deposit?" << endl
                   << ": ";
              cin >> d;
            }

            switch (c) {
              case 1:
                data.zack.accountA += d;
                break;
              case 2:
                data.zack.accountB += d;
                data.zack.accountA -= d;
                break;
              case 3:
                data.zack.accountC += d;
                data.zack.accountA -= d;
                break;
              case 4:
                data.zack.accountD += d;
                balanceDebts(data);
                break;
            }
            break;
        }
        break;
      case 4:
        system("cls");
        cout << "Which person?" << endl
             << "  0 - Cancel" << endl
             << "  1 - Aaron" << endl
             << "  2 - Zack" << endl << endl
             << ": ";
        cin >> b;

        switch (b) {
          case 1:
            system("cls");
            cout << "Which account?" << endl
                 << "  0 - Cancel" << endl
                 << "  1 - A (" << data.aaron.accountA << ")" << endl
                 << "  2 - B (" << data.aaron.accountB << ")" << endl
                 << "  3 - C (" << data.aaron.accountC << ")" << endl
                 << "  4 - D (" << data.aaron.accountD << ")" << endl << endl
                 << ": ";
            cin >> c;
            
            if (c > 0 && c < 5) {
              system("cls");
              cout << "How much do you want to Withdraw?" << endl
                   << ": ";
              cin >> d;
            }

            switch (c) {
              case 1:
                data.aaron.accountA -= d;
                break;
              case 2:
                data.aaron.accountB -= d;
                data.aaron.accountA += d;
                break;
              case 3:
                data.aaron.accountC -= d;
                data.aaron.accountA += d;
                break;
              case 4:
                data.aaron.accountD -= d;
                data.zack.accountA -= d;
                data.aaron.accountA += d;
                break;
            }
            break;
          case 2:
            system("cls");
            cout << "Which account?" << endl
                 << "  0 - Cancel" << endl
                 << "  1 - A (" << data.zack.accountA << ")" << endl
                 << "  2 - B (" << data.zack.accountB << ")" << endl
                 << "  3 - C (" << data.zack.accountC << ")" << endl
                 << "  4 - D (" << data.zack.accountD << ")" << endl << endl
                 << ": ";
            cin >> c;
            
            if (c > 0 && c < 5) {
              system("cls");
              cout << "How much do you want to Withdraw?" << endl
                   << ": ";
              cin >> d;
            }

            switch (c) {
              case 1:
                data.zack.accountA -= d;
                break;
              case 2:
                data.zack.accountB -= d;
                data.zack.accountA += d;
                break;
              case 3:
                data.zack.accountC -= d;
                data.zack.accountA += d;
                break;
              case 4:
                data.zack.accountD -= d;
                data.aaron.accountA -= d;
                data.zack.accountA += d;
                break;
            }
            break;
        }
        break;
      case 5:
        save(data);
        break;
    }

  } while (a != 5);

  return EXIT_SUCCESS;
}

void load(Data& data)
{
  fstream fs;
  fs.open("data.txt", fstream::in);

  fs >> data.aaron.name;
  fs >> data.aaron.lastMonth;
  fs >> data.aaron.times;
  fs >> data.aaron.accountA;
  fs >> data.aaron.accountB;
  fs >> data.aaron.accountC;
  fs >> data.aaron.accountD;

  fs >> data.zack.name;
  fs >> data.zack.lastMonth;
  fs >> data.zack.times;
  fs >> data.zack.accountA;
  fs >> data.zack.accountB;
  fs >> data.zack.accountC;
  fs >> data.zack.accountD;

  fs.close();
}

void save(Data data)
{
  fstream fs;
  fs.open("data.txt", fstream::out);

  fs << data.aaron.name << endl;
  fs << data.aaron.lastMonth << endl;
  fs << data.aaron.times << endl;
  fs << data.aaron.accountA << endl;
  fs << data.aaron.accountB << endl;
  fs << data.aaron.accountC << endl;
  fs << data.aaron.accountD << endl;

  fs << data.zack.name << endl;
  fs << data.zack.lastMonth << endl;
  fs << data.zack.times << endl;
  fs << data.zack.accountA << endl;
  fs << data.zack.accountB << endl;
  fs << data.zack.accountC << endl;
  fs << data.zack.accountD << endl;

  fs.close();
}

void balanceDebts(Data& data)
{
  if (data.aaron.accountD >= data.zack.accountD) {
    data.aaron.accountD -= data.zack.accountD;
    data.zack.accountD = 0;
  }
  if (data.zack.accountD >= data.aaron.accountD) {
    data.zack.accountD -= data.aaron.accountD;
    data.aaron.accountD = 0;
  }
}

int timePrice(int time)
{
  switch (time) {
    case 1:
      return 25;
    case 2:
      return 30;
    case 3:
      return 25;
    case 4:
      return 30;
    case 5:
      return 35;
    case 6:
      return 40;
    case 7:
      return 35;
    case 8:
      return 40;
    case 9:
      return 40;
    case 10:
      return 40;
  }
  if (time > 10)
    return 40;
  return 0;
}

int getMonth()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
  cout << timePtr->tm_mon << endl;
  system("PAUSE");
  return timePtr->tm_mon;
}