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
      int daysSpent = t + (booksInLibrary.size() + m - 1 + 10) / m;
      long long totalScore = 0;
      for (auto &book: booksInLibrary) totalScore += book.score;
      long double throughput = (long double) totalScore / daysSpent;
      return throughput;
    }

    bool operator <(Library& l) {
      return getThroughput() > l.getThroughput();
    }
};


pair<long double, vector<int> > scorable(int startTime, int endTime, Library &lib, vector<bool> &done) {
  int curTime = startTime + lib.t;
  if (curTime > endTime) return {0.0, {}};
  long long score = 0;
  vector<int> booksDoable;
  vector<int> scores;
  for (auto &b: lib.booksInLibrary) if (!done[b.id]) {
    booksDoable.push_back(b.id);
    scores.push_back(b.score);
  }
  booksDoable.resize(min((long long)booksDoable.size(), (long long) lib.m * (endTime - curTime + 1)));
  scores.resize(booksDoable.size());
  long long totalScore = 0;
  for (int &i: scores) totalScore += i;
  long double throughput = totalScore / (long double) (lib.t);
  return {throughput, booksDoable};
}

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

  //sort(libraries.begin(), libraries.end());

  vector<bool> done(b, false);
  set<int> remainingLibraries;
  for (int i = 0; i < l; i++) remainingLibraries.insert(i);


  vector<vector<int> > output;

  int inserted = 0;

  vector<Library> finalLibraries;
  int tym = 0;
  while (tym <= d && !remainingLibraries.empty()) {
    if (remainingLibraries.size() % 100 == 0) cerr << remainingLibraries.size() << " remaining\t" << inserted << " inserted\t" << d - tym << " days remaining\n";
    int bestLibrary = -1;
    long double bestThroughput = 0;
    vector<int> bestBooks;
    for (auto &id: remainingLibraries) {
      pair<long long, vector<int> > cur = scorable(tym, d, libraries[id], done);
      if (bestLibrary == -1 || cur.first > bestThroughput) {
        bestThroughput = cur.first;
        bestLibrary = id;
        bestBooks = cur.second;
      }
    }

    if (bestThroughput <= 0) break;

    tym += libraries[bestLibrary].t;

    vector<int> cur = {bestLibrary, bestBooks.size()};
    int go = 
    for (int &b: bestBooks) {
      done[b] = true;
      cur.push_back(b);
    }
    output.push_back(cur);
    remainingLibraries.erase(bestLibrary);
    inserted += (int)cur.size() - 2;
  }

  /*
  //set<int> done;
  vector<vector<int> > output;

  for (auto &lib: finalLibraries) {
    int Y = lib.id;
    vector<int> remainingBooks;
    for (auto &book: lib.booksInLibrary) if (!done[book.id]) {
      remainingBooks.push_back(book.id);
    }
    if (remainingBooks.empty()) continue;
    vector<int> cur = {Y, remainingBooks.size()};
    for (auto &b: remainingBooks) {
      done[b] = true;
      cur.push_back(b);
    }
    output.push_back(cur);
  }
  */

  cout << output.size() << endl;
  for (auto &row: output) {
    cout << row[0] << " " << row[1] << endl;
    for (int i = 2; i < row.size(); i++) cout << row[i] << " ";
    cout << endl;
  }
}
