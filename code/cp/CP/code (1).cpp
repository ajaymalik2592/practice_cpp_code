#include<bits/stdc++.h>

using namespace std;

struct Book{
    int id, score;

    bool operator <(const Book& b) {
      return score > b.score;
    }
};

struct Library{
    int id, n, t, m;
    vector<Book> booksInLibrary;

    long double getThroughput() {
      int daysSpent = t + (booksInLibrary.size() + m - 1) / m;
      long long totalScore = 0;
      for (auto &book: booksInLibrary) totalScore += book.score;
      long double throughput = (long double) totalScore / daysSpent;
      return throughput;
    }

    bool operator <(Library& l) {
      return getThroughput() > l.getThroughput();
    }
};

int main() {
  int b, l, d;
  cin >> b >> l >> d;

  vector<Library> libraries(l);
  vector<Book> books;

  for (int i = 0; i < b; i++) {
    Book b;
    b.id = i;
    cin >> b.score;
    books.push_back(b);
  }

  {
    int id = 0;
    for (auto &lib: libraries) {
      lib.id = id++;
      cin >> lib.n >> lib.t >> lib.m;

      for (int i = 0; i < lib.n; i++) {
        int id;
        cin >> id;
        lib.booksInLibrary.push_back(books[id]);
      }

      sort(lib.booksInLibrary.begin(), lib.booksInLibrary.end());
    }
  }

  sort(libraries.begin(), libraries.end());

  set<int> done;
  vector<vector<int> > output;

  for (auto &lib: libraries) {
    int Y = lib.id;
    vector<int> remainingBooks;
    for (auto &book: lib.booksInLibrary) if (!done.count(book.id)) {
      remainingBooks.push_back(book.id);
    }
    if (remainingBooks.empty()) continue;
    vector<int> cur = {Y, remainingBooks.size()};
    for (int &b: remainingBooks) {
      done.insert(b);
      cur.push_back(b);
    }
    output.push_back(cur);
  }

  cout << output.size() << endl;
  for (auto &row: output) {
    cout << row[0] << " " << row[1] << endl;
    for (int i = 2; i < row.size(); i++) cout << row[i] << " ";
    cout << endl;
  }
}
