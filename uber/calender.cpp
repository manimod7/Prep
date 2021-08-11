#include <bits/stdc++.h>

using namespace std;

struct Events
{
  int start, end;
  Events(int s, int e)
  {
    start = s;
    end = e;
  }
};

struct User
{
  string name;
  map<string, vector<Events>> eventsForUser;
  User(string s)
  {
    name = s;
  }
};

vector<User> users;
map<string, User> isPresent;
map<string, vector<Events>> allEvents;
map<Events, vector<User>> attendingUsers;

void Register(string s)
{
  if (isPresent.find(s) != isPresent.end())
  {
    cout << "failure" << endl;
    return;
  }
  User *u = new User(s);
  users.push_back(*u);
  isPresent[s] = *u;
  cout << "success" << endl;
}

void CreateEvent(string day, int s, int duration, int n, vector<string> v)
{
  vector<Events> allEvs = allEvents[day];
  int e = s + duration;
  if (e >= 1440)
  {
    cout << "failure" << endl;
    return;
  }
  for (int i = 0; i < allEvs.size(); i++)
  {
    if (e <= allEvs[i].start || s >= allEvs[i].end)
    {
      continue;
    }
    cout << "failure";
    return;
  }
  Events *eve = new Events(s, e);
  for (int i = 0; i < v.size(); i++)
  {
    User a = isPresent[v[i]];
    attendingUsers[*eve].push_back(a);
  }
  cout << "success" << endl;
}